#pragma once
#include "stdafx.h"
#include "Shape.h"
class Ellips : public Shape {
public:
	int  SmallAxle, BigAxle;
	int Id;
	Ellips(int, int, int, int, double, int, string);
	Ellips(int, int);
	int GetSAxle();
	int GetBAxle();
	void SetAxles(int, int);
	friend ostream&operator<<(ostream&a, const Ellips&b) {

		a << "ID ������: id=" << b.Id << "\n";
		a << "����� ������: x=" << b.X << "; y=" << b.Y << "\n";
		a << "����: " << b.Color << "\n";
		a << "���� �������� ������: fi=" << b.Angle << "\n";
		a << "�������: delta=" << b.Scale << "\n";
		a << "������ ������� � ������ ���������������=" << b.BigAxle*b.Scale << "  ������ �������=" << b.SmallAxle*b.Scale << "\n";
		return a;
	}
	~Ellips();
};