#include "stdafx.h"
#include "Shape.h"

Point Shape::getCenter() {
	return center;
}

void Shape::setColor(string color) {// ��������� �����
	this->color = color;
}

void Shape::reLocate(double x, double y) {// ����������� � ������ ���������� (�� ������)
	for (auto& i : points) {
		i.x += x - center.x;
		i.y += y - center.y;
	}
	center.x = x;
	center.y = y;
}

void Shape::prepare_for_zoom(double& n) {// ��������������� ������ �����
	for (auto& center : points) {
		center.x = center.x * n;
		center.y = center.y * n;
	}

}

void Shape::turn(int angl) {// ������� �� ����
	angle += angl % 360;
	double radian = angl * PI / 180;
	for (auto& i : points) {
		double newX = (i.x - center.x)*cos(radian) - (i.y - center.y)*sin(radian);
		double newY = (i.x - center.x)*sin(radian) + (i.y - center.y)*cos(radian);
		i.x = center.x + newX;
		i.y = center.y - newY;
	}
}

string Shape::getColor() {
	return color;
}