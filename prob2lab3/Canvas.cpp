#include "Canvas.h"
#include <iostream>
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int rowIndex = y - ray; rowIndex < y; ++rowIndex)//NV
	{
		bool markedLine = false;
		for (int colIndex = x - ray; colIndex < x and !markedLine; ++colIndex)
			if (((rowIndex - y) * (rowIndex - y)) + ((colIndex - x) * (colIndex - x)) <= (ray * ray) and !markedLine)//+a value to account for int error and pixel size
				this->canvas[rowIndex][colIndex] = ch, markedLine = true;;
	}//simetric ce face aici?
	for (int rowIndex = y; rowIndex < y+ray; ++rowIndex)//SV
	{
		bool markedLine = false;
		for (int colIndex = x-ray; colIndex < x and !markedLine; ++colIndex)
			if (((rowIndex - y) * (rowIndex - y)) + ((colIndex - x) * (colIndex - x)) <= (ray * ray) and !markedLine)//+a value to account for int error and pixel size
				this->canvas[rowIndex][colIndex]=ch, markedLine = true;;
	}
	for (int rowIndex = y-ray; rowIndex < y; ++rowIndex)//NE
	{
		bool markedLine = false;
		for (int colIndex = x + ray; colIndex > x and !markedLine; --colIndex)
			if (((rowIndex - y) * (rowIndex - y)) + ((colIndex - x) * (colIndex - x)) <= (ray * ray) and !markedLine)//+a value to account for int error and pixel size
				this->canvas[rowIndex][colIndex] = ch, markedLine = true;;
	}
	for (int rowIndex = y; rowIndex < y+ray; ++rowIndex)//SE
	{
		bool markedLine = false;
		for (int colIndex = x + ray; colIndex > x and !markedLine; --colIndex)
			if (((rowIndex - y) * (rowIndex - y)) + ((colIndex - x) * (colIndex - x)) <= (ray * ray) and !markedLine)//+a value to account for int error and pixel size
				this->canvas[rowIndex][colIndex] = ch, markedLine = true;;
	}
	//dat fiind centrul si raza,gaseste formula pentru coordonatele arcelor de cerc
}
void Canvas::DrawCircle2(int x, int y, int ray, char ch)
{
	for (int rowIndex = y - ray; rowIndex < y + ray; ++rowIndex) {//SE?
		for (int colIndex = x - ray; colIndex < x + ray; ++colIndex) {
			if (((rowIndex - y) * (rowIndex - y)) + ((colIndex - x) * (colIndex - x)) <= (ray * ray)) {
				if (colIndex != x - ray and colIndex != x + ray -1 and rowIndex != y - ray and rowIndex != y + ray-1) {
					if ((((rowIndex - y) * (rowIndex - y)) + ((colIndex - x - 1) * (colIndex - x - 1)) > (ray * ray)
						or ((rowIndex - y) * (rowIndex - y)) + ((colIndex - x + 1) * (colIndex - x + 1)) > (ray * ray)))//+a value to account for int error and pixel size
						this->canvas[rowIndex][colIndex] = ch;
				}
				else
					this->canvas[rowIndex][colIndex] = ch;
			}
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int rowIndex = y-ray; rowIndex < y + ray; ++rowIndex)//SE?
		for (int colIndex = x-ray; colIndex < x + ray; ++colIndex)
			if (((rowIndex-y) * (rowIndex-y)) + ((colIndex-x) * (colIndex-x)) <= (ray * ray))//+a value to account for int error and pixel size
				this->canvas[rowIndex][colIndex] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i)
		this->canvas[i][left] = this->canvas[i][right] = ch;
	for (int j = left; j <= right; ++j)
		this->canvas[top][j] = this->canvas[bottom][j] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i)
		for (int j = left; j <= right; ++j)
			this->canvas[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	//??
	this->canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int decide;
	if (dx > dy) {
		decide = 0;
	}
	else {
		decide = 1;
	}
	int pk = 2 * dy - dx;
	for (int i = 0; i <= dx; i++) {
		//std :: cout << x1 << "," << y1 << '\n';
		this->canvas[x1][y1] = ch;
		x1 < x2 ? x1++ : x1--;
		if (pk < 0) {
			pk = pk + 2 * dy;
			
		}
		else {
			y1 < y2 ? y1++ : y1--;
			pk = pk + 2 * dy - 2 * dx;
		}
	}
}
void Canvas::Print() // shows what was printed
{
	for (int i = 0; i < this->h; ++i, std::cout << "\n")
		for (int j = 0; j < this->w; ++j)
			std::cout << canvas[i][j] << " ";
}
void Canvas::Clear() // clears the canvas
{
	for (int i = 0; i < this-> h; ++i)
		for (int j = 0; j < this -> w; ++j)
			this -> canvas[i][j] = { '0' };
}
