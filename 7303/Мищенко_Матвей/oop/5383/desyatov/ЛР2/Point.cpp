#include "Point.h"
#include <iostream>
using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}
	
Point::Point(double x0, double y0)
{
	x = x0;
	y = y0;
}

void Point::ShowPoint()
{
	cout << "���������� ����� x = " << x << endl;
	cout << "���������� ����� y = " << y << endl;
}