#include <iostream>
#include "Canvas.h"



int main()
{
	Canvas c1(100, 100);//100/100?
	//c1.DrawRect(5, 5, 9, 9, 'a');
	//c1.FillRect(6, 6, 8, 8, 'b');
	c1.DrawCircle2(50, 50, 25, '*');
	//c1.DrawLine(0, 0, 49, 48, '*');
	c1.Print();
};