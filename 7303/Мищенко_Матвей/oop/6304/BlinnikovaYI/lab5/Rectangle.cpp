#pragma once
#include "Rectangle.h"

void Rectangle::zoom(double n) {
	prepare_for_zoom(n);
	sideA *= n;
	sideB *= n;
}

void Rectangle::printOUT(ostream& out) {
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