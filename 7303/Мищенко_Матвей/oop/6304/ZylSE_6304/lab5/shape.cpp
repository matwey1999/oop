#include "stdafx.h"
#include "shape.h"

	void Shape::setColor(string color) {// ��������� �����
		this->color = color;
	}

	void Shape:: reLocate(double x, double y) {// ����������� � ������ ���������� (�� ������)+

		for (auto& i : points) {
			i.x += x - center.x;
			i.y += y - center.y;
		}
		center.x = x;
		center.y = y;
	}
	void Shape::prepare_for_zoom(double& n) {// ��������������� ������ �����
		if (n<0) {
			n = abs(n);
		}
		center.x *= n;
		center.y *= n;
		for (auto& i : points) {
			i.x *= n;
			i.y *= n;
		}
	}

	void Shape::turn(int angl) {// ������� �� ����
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


/////////////////////////////////////////////////////////
	void Square:: zoom(double n) {
		prepare_for_zoom(n);
		side *= n;
	}

	void Square:: printOUT(ostream& out) {
		out << "������ �������!" << endl;
		out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
		out << "����� ������� ��������: " << side << endl;
		out << "����� ��������:" << endl;
		for (const auto& i : points) {
			out << "(" << i.x << ", " << i.y << ")\n";
		}
		out << "����: " << color << endl;
		out << "����: " << angle << endl;

	}
//////////////////////////////////////////

	void Rhomb::zoom(double n) {
		prepare_for_zoom(n);
		side *= n;
	}

	void Rhomb:: printOUT(ostream& out) {
		out << "������ ����!" << endl;
		out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
		out << "����� ������� �����: " << side << endl;
		out << "����� �����:" << endl;
		for (const auto& i : points) {
			out << "(" << i.x << ", " << i.y << ")\n";
		}
		out << "����: " << color << endl;
		out << "����: " << angle << endl;

	}
///////////////////////////////////////////////////

	void Trapezium::zoom(double n) {
		prepare_for_zoom(n);
		side_1 *= n;
		side_2 *= n;
		h *= n;
	}

	void Trapezium:: printOUT(ostream& out) {
		out << "������� ��������!" << endl;
		out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
		out << "����� ��������� ��������: " << side_1 << " " << side_2 << endl;
		out << "����� ������: " << h << endl;
		out << "����� ��������:" << endl;
		for (const auto& i : points) {
			out << "(" << i.x << ", " << i.y << ")\n";
		}
		out << "����: " << color << endl;
		out << "����: " << angle << endl;

	}


