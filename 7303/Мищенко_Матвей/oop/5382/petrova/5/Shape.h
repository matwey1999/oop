
#include "string"
#include "math.h"
#include <cmath>
#include <iostream>
#include <ostream>
using namespace std; 
enum ProjectionType { X = 0, Y = 1 };
const double range = 5;
struct Point
{
	double x, y;

 Point(const double& x = 0, const double& y = 0): x(x), y(y)
	{
	}
};
double fRand(double f = -range)
{
	double l = (double)rand() / RAND_MAX;
	return l;
}
struct my_color
{
	double r, g, b;
	my_color(const double& r = 0, const double& g = 0, const double& b = 0) : r(r), g(g), b(b)
	{
	}
};


class Shape //������� �����
{
protected:
	Point center;	
	my_color color;
	int angle; // ������� �� ���� 

public:
	Shape() {} //����������� ������
	virtual void move(Point newCenter) = 0;
	virtual void changesize(double k) = 0;
	virtual void turn(double angle)=0; // ������������ �� ����
	my_color getColor()	//��������� �����
	{
		return this->color;
	}
	void set�olor(my_color color)	//��������� �����
	{
		this->color = color;
	}
	virtual ostream &operator << (ostream &output)	//�������� ������ � �����
	{
		return output;
	}
	bool equalProjection(const Shape& other, const ProjectionType projection) const
	{
		double left1 = this->leftx();
		double left2 = other.leftx();
		if (left1 == left2) return true;
		else return false;
	}
	virtual double const leftx() const = 0;
	virtual ~Shape();
};
class Ellips : public Shape //����� ����������
{
private:
	double R;
	double r;
	Point left;
public:
	Ellips() {};
	Ellips(Point center, int _R = 1, int _r = 2);//����������� ������
    void move(Point newCenter) ;
    void changesize(double k);
    void turn(double angle); // ������������ �� ����
	double const leftx() const;

	ostream &operator << (ostream &output)
	{
		my_color tmpColor = getColor();
		output << "Color: " << "red component = " << tmpColor.r << ", green component = " << tmpColor.g << ", blue component = " << tmpColor.b << " " << endl;
		output << "Center-point {" << this->center.x << " ; " << this->center.y << "}" << endl;
		output << "R" << R << " r " << r << endl;
		return output;
	}
	virtual ~Ellips() {}
};


class SegEl : public Shape //����� ��������
{
private:
	Point left;
	Point right;
public:
	SegEl() {};
	SegEl(Point center, Point left, Point right); //����������� ������
	void move(Point newCenter);
	void changesize(double k);
	void turn(double angle); // ����������� ����� ��� ������ ������ �� ����
	double const leftx() const;
	ostream &operator << (ostream &output)
	{
		my_color tmpColor = getColor();
		output << "Color: " << "red component = " << tmpColor.r << ", green component = " << tmpColor.g << ", blue component = " << tmpColor.b << " " << endl;
		output << "Center-point {" << this->center.x << " ; " << this->center.y << "}" << endl;
		output << "Left-point {" << this->left.x << " ; " << this->left.y << "}" << endl;
		output << "Right-point {" << this->right.x << " ; " << this->right.y << "}" << endl;
		return output;
	}
	virtual ~SegEl() {}
};

class Parallelogramm : public Shape //����� ��������
{
private:
	double l,L;
public:
	Parallelogramm() {};
	Parallelogramm(Point center, int _l = 9, int _L = 3);
	void move(Point newCenter);
	void changesize(double k);
	void turn(double angle);  // ����������� ����� ��� ������ ������ �� ����
	double const leftx() const;
	ostream &operator << (ostream &output)
	{
		my_color tmpColor = getColor();
		output << "Color: " << "red component = " << tmpColor.r << ", green component = " << tmpColor.g << ", blue component = " << tmpColor.b << " " ;
		output << "First-point {" << this->center.x << " ; " << this->center.y << "}" << endl;
		output << "L " << L << "l"<<l << endl;
		return output;
	}
	virtual ~Parallelogramm() {}
};
