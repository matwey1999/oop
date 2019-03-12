#pragma once
#include "stdafx.h"
#include "Shape.h"
using namespace std;

class Segment : public Shape
{
private:
	double Length;
	int Id;
public:
	Segment(int, int, int, double, int, string);
	Segment(int Length);
	void SetLength(int);
	int GetLength();
	friend ostream&operator<<(ostream&a, const Segment&b) {
		a << "ID ������: id=" << b.Id << "\n";
		a << "����� ������: x=" << b.X << "; y=" << b.Y << "\n";
		a << "����: " << b.Color << "\n";
		a << "���� �������� ������: fi=" << b.Angle << "\n";
		a << "�������: delta=" << b.Scale << "\n";
		a << "����� � ������ �������: �������������� �������=" << b.Length*b.Scale << "\n";
		return a;
	}
	~Segment();
};