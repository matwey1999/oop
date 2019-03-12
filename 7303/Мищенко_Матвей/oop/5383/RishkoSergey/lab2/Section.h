#include "stdafx.h"
#include "Shape.h"
using namespace std;
class Section : public Shape {
private:
	double X1, X2, Y1, Y2;
	double Id=0;
	double CenterX=0, CenterY=0;
	double Per;
public:
	Section(double, double, double, double);
	void GetCenter();
	double Perimetr();
	void MoveFigure(double, double);
	void TurnFigure(double);
	void ScaleFigure(double);
	friend ostream&operator<<(ostream&a, const Section&b){
		a << "�������" << "\n";
		/*a << "ID ������: id=" << ID << "\n";
			a << "����� ������: x=" << b.CenterX << "; y=" << b.CenterY << "\n";
		a << "���� �������� ������ (� ��������)" << b.radAngle << "\n";
		a << "�������: ������=" << b.Scale << "\n";
		a << "�������� ������=" << b.Per << "\n";
		a << "���������� �����: " << b.X1 << ", " << b.Y1 << ", " << b.X2 << ", " << b.Y2 << ", /n";*/
		return a;
	}
	~Section();
};
