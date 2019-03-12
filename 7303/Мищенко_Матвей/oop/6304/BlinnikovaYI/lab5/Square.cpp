
#include "Square.h"

void Square::zoom(double n) {
	prepare_for_zoom(n);
	side *= n;
}

void Square::printOUT(ostream& out) {
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