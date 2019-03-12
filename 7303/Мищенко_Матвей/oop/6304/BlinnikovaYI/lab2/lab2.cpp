// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <locale.h>
using namespace std;
#define PI            3.14159265358979323846
class Point {
public:
	double x;
	double y;
	Point(double x, double y) : x(x), y(y) {}
};

class Shape {
public:
	Shape(double x, double y) :color("black"), center(x, y), angle(0) {}

	void setColor(string color) {// ��������� �����
		this->color = color;
	}

	void reLocate(double x, double y) {// ����������� � ������ ���������� (�� ������)

		for (auto& i : points) {
			i.x += x - center.x;
			i.y += y - center.y;
		}
		center.x = x;
		center.y = y;
	}
	virtual void zoom(double n)=0;
	void prepare_for_zoom(double& n) {// ��������������� ������ �����
		if (n<0) {
			n = abs(n);
		}
		for (auto& i : points) {
			i.x *= n;
			i.y *= n;
		}
	}

	void turn(int angl) {// ������� �� ����
		angl = angl % 360;
		angle += angl;
		double radian = angl*PI / 180;
		for (auto& i : points) {
			double x_ = i.x*cos(radian) - i.y*sin(radian);
			double y_ = i.y*cos(radian) + i.x*sin(radian);
			i.x = x_;
			i.y = y_;
		}
	}

	virtual void printOUT(ostream& out) = 0; // ������ ���������� � ������
	friend std::ostream& operator<<(std::ostream& outStream, Shape& shape) {
		shape.printOUT(outStream);
		return outStream;
	}


protected:
	string color;
	Point center;
	int angle;
	vector<Point> points;
};

class Square : public Shape {
public:
	Square(Point center, double side) : Shape(center.x, center.y), side(side) {
		points.push_back({ center.x - side / 2, center.y + side / 2 });
		points.push_back({ center.x + side / 2, center.y + side / 2 });
		points.push_back({ center.x + side / 2, center.y - side / 2 });
		points.push_back({ center.x - side / 2, center.y - side / 2 });
	}

	void zoom(double n) {
		prepare_for_zoom(n);
		side *= n;
	}

	void printOUT(ostream& out) {
		out << "������ �������" << endl;
		out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
		out << "����� ������� ��������: " << side << endl;
		out << "����� ��������:" << endl;
		for (const auto& i : points) {
			out << "(" << i.x << ", " << i.y << ")\n";
		}
		out << "����: " << color << endl;
		out << "����: " << angle << endl;

	}

private:
	double side;
};

class Ellipse : public Shape
{
	int radiusX, radiusY;

public:
	Ellipse(Point center, int radiusX, int radiusY) : Shape(center.x, center.y), radiusX(radiusX), radiusY(radiusY){
		
		points.push_back(Point((center.x - radiusX), center.y));
		points.push_back(Point(center.x, (center.y + radiusY)));
		points.push_back(Point((center.x + radiusX), center.y));
		points.push_back(Point(center.x, (center.y - radiusY)));
	}

	void zoom(double n) {
		prepare_for_zoom(n);
		radiusX *= n;
		radiusY *= n;
	}

	void printOUT(ostream& out) {
		out << "������ ������" << endl;
		out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
		out << "����� ��������: " << radiusX << " , "<< radiusY<< endl;
		out << "����� �������:" << endl;
		for (const auto& i : points) {
			out << "(" << i.x << ", " << i.y << ")\n";
		}
		out << "����: " << color << endl;
		out << "����: " << angle << endl;

	}
};
class Rectangle : public Shape
{
	int sideA;
	int sideB;

public:
	Rectangle(Point center, int sideA, int sideB) : Shape(center.x, center.y), sideA(sideA),sideB(sideB)
	{
		points.push_back(Point((center.x - sideB / 2), (center.y + sideA / 2)));
		points.push_back(Point((center.x + sideB / 2), (center.y + sideA / 2)));
		points.push_back(Point((center.x + sideB / 2), (center.y - sideA / 2)));
		points.push_back(Point((center.x - sideB / 2), (center.y - sideA / 2)));
	}

	void zoom(double n) {
		prepare_for_zoom(n);
		sideA *= n;
		sideB *= n;
	}

	void printOUT(ostream& out) {
		out << "������ �������������" << endl;
		out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
		out << "����� ������: " << sideA << " , " << sideB << endl;
		out << "����� ��������������:" << endl;
		for (const auto& i : points) {
			out << "(" << i.x << ", " << i.y << ")\n";
		}
		out << "����: " << color << endl;
		out << "����: " << angle << endl;
	}

};





int main()
{
	setlocale(LC_ALL, "Russian");
	Square sq({ 0,0 }, 2);
	cout << sq << endl;
	cout << "" << endl;
	cout << "after zooming +color" << endl;
	sq.zoom(2);
	sq.setColor("Green");
	cout << sq << endl;
	sq.turn(90);
	cout << "" << endl;

	cout << "after turning" << endl;
	cout << sq << endl;
	cout << "" << endl;

	cout << "after moving" << endl;
	sq.reLocate(3,3);
	cout << sq << endl;
	cout << "/----------------------------------/" << endl;

	
	
	Ellipse el({ 0,0 }, 4, 2);
	cout << el;
	cout << "" << endl;
	cout << "after zooming +color" << endl;
	el.setColor("Red");
	el.zoom(2);
	cout << el;
	cout << "" << endl;

	cout << "after turning" << endl;
	el.turn(90);
	cout << el << endl;
	cout << "" << endl;

	cout << "after moving" << endl;
	el.reLocate(-2,-2);
	cout << el << endl;
	cout << "-------------------------------------" << endl;

	Rectangle rec({ 0,0 }, 4, 2);
	cout << rec;
	cout << "" << endl;
	cout << "after zooming +color" << endl;
	rec.zoom(2);
	rec.setColor("White");
	cout << "" << endl;

	cout << "after turning" << endl;	
	rec.turn(90);
	cout << rec << endl;
	cout << "" << endl;

	cout << "after moving" << endl;
	rec.reLocate(1,1);
	cout << rec;
	cout << "----------------------------------" << endl;
	cout << "/***********************************************/" << "\n\n";

	system("pause");

	return 0;
}



