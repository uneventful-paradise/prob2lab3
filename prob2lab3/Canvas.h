#pragma once
class Canvas {
	int w;
	int h;
	char canvas[100][100];
public:
	Canvas(int width, int height) {
		w = width, h = height; //nu pot declara char canvas[][100]?
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				canvas[i][j] = '-';
		//canvas[100][100] = { 'a' };???
	}
	void DrawCircle(int x, int y, int ray, char ch);
	void FillCircle(int x, int y, int ray, char ch);
	void DrawCircle2(int x, int y, int ray, char ch);
	void DrawRect(int left, int top, int right, int bottom, char ch);
	void FillRect(int left, int top, int right, int bottom, char ch);
	void SetPoint(int x, int y, char ch);
	void DrawLine(int x1, int y1, int x2, int y2, char ch);
	void Print(); // shows what was printed
	void Clear(); // clears the canvas
};

