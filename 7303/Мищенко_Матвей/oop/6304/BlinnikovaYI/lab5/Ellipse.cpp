#include "Ellipse.h"

void Ellipse::zoom(double n) {
	prepare_for_zoom(n);
	radiusX *= n;
	radiusY *= n;
}

void Ellipse::printOUT(ostream& out) {
	out << "������ ������" << endl;
	out << "���������� ������: (" << center.x << ", " << center.y << ")" << endl;
	out << "����� ��������: " << radiusX << " , " << radiusY << endl;
	out << "����� �������:" << endl;
	for (const auto& i : points) {
		out << "(" << i.x << ", " << i.y << ")\n";
	}
	out << "����: " << color << endl;
	out << "����: " << angle << endl;

}