#include "stdafx.h"
#include "Shape.h"
using namespace std;
class Ellipse : public Shape {
private:
	double X1, X2, X3, Y1, Y2, Y3;
	double Id=0;
	double CenterX = 0, CenterY = 0;
	double Length, Per;
public:
	Ellipse(double, double, double, double, double, double);
	void GetCenter();
	double Perimetr();
	void MoveFigure(double, double);
	void TurnFigure(double);
	void ScaleFigure(double);
	friend ostream&operator<<(ostream&a, const Ellipse&b){
		a << "������" << "\n";
		/*a << "ID ������: id=" << ID << "\n";
			a << "����� ������: x=" << b.CenterX << "; y=" << b.CenterY << "\n";
		a << "���� �������� ������ (� ��������)" << b.radAngle << "\n";
		a << "�������: ������=" << b.Scale << "\n";
		a << "�������� ������=" << b.Per << "\n";
		a << "���������� �����: " << b.X1 << ", " << b.Y1 << ", " << b.X2 << ", " << b.Y2 << ", /n";*/
		return a;
	}
	~Ellipse();
};
