#pragma once
#include "stdafx.h"
#include "Shape.h"
class Pentagon : public Shape {
public:
	int  Side;
	int Id;
	Pentagon(int, int, int, double, int, string);
	Pentagon(int);
	int GetSide();
	void SetSide(int);
	friend ostream&operator<<(ostream&a, const Pentagon&b) {
		a << "ID ������: id=" << b.Id << "\n";
		a << "����� ������: x=" << b.X << "; y=" << b.Y << "\n";
		a << "����: " << b.Color << "\n";
		a << "���� �������� ������: fi=" << b.Angle << "\n";
		a << "�������: delta=" << b.Scale << "\n";
		a << "����� ������ � ������ �������: ������� �������������=" << b.Side*b.Scale << "\n";
		return a;
	}
	~Pentagon();
};