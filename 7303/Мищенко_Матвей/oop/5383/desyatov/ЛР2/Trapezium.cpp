#include "Trapezium.h"
#include <iostream>
using namespace std;


	void Trapezium::ChangeColor(string c) //�������� ����
	{
		color = c;
		cout << "���� ��� ������� �� " << c;
	}

	Trapezium::Trapezium()
	{
		type = "��������";
		color = "�������";
		scale = 0;
	}

	Trapezium::Trapezium(double lenghtTop, double h, double lenghtBottom)
	{
		area = ((lenghtBottom + lenghtTop) * h) / 2;
	}

	void Trapezium::SetPoint(double x, double y, int num)
	{
		switch (num)
		{
		case 1:
			a1 = Point(x, y); // A
		case 2:
			a2 = Point(x, y); // B
		case 3:
			a3 = Point(x, y); // C
		case 4:
			a4 = Point(x, y); // D
		}
	}

	void Trapezium::check()
	{
		int tmp;
		if (a1.x > a2.x) //�������� A � B
		{
			tmp = a2.x;
			a2.x = a1.x;
			a1.x = tmp;
		}
		if (a3.y > a2.y) //�������� C � �
		{
			tmp = a2.y;
			a2.y = a3.y;
			a3.y = tmp;
		}
		if (a4.x > a3.x) //�������� C � D
		{
			tmp = a3.x;
			a3.x = a4.x;
			a4.x = tmp;
		}
		if (a4.y > a1.y) //�������� D � A
		{
			tmp = a1.y;
			a1.y = a4.y;
			a4.y = tmp;
		}
		double k1, k2;
		k1 = (a2.y - a1.y) / (a2.x - a1.x); //������� ���������� ������� AB
		k2 = (a4.y - a3.y) / (a4.x - a3.x); //������� ���������� ������� CD
		if (k1 != k2)
		{
			k1 = (a3.y - a2.y) / (a3.x - a2.x); //������� ���������� ������� CB
			k2 = (a4.y - a1.y) / (a4.x - a1.x); //������� ���������� ������� AD
			if (k1 != k2)
			{
				cout << "��������� ������ �� �������� ���������!" << endl;
				exit(1);
			}
		}
		else
		{
			cout << "��������� ������ �������� ���������." << endl;
			scale = 1;
			hight = a1.y - a4.y;
			lenghtBottom = a3.x = a4.x;
			lenghtTop = a2.x - a1.x;
			if (lenghtBottom > lenghtTop)
			{
				lenght = lenghtBottom;
			}
			else
				lenght = lenghtTop;

			center.x = lenght / 2;
			center.y = hight / 2;
			area = ((lenghtBottom + lenghtTop) *hight) / 2;
		}
	}

	void Trapezium::getArea()
	{
		area = ((lenghtBottom + lenghtTop) *hight) / 2; //�������
	}
    
	double Trapezium::compareAreas(Trapezium trap1, Trapezium trap2)
	{
			if (trap1.area> trap2.area)
			{
				return 1;
				cout << "������� ������ ������ ������ ������ " << endl;
			}
			if (trap1.area < trap2.area)
			{
				return 2;
				cout << "������� ������ ������ ������ ������ " << endl;
			}
			if (trap1.area == trap2.area)
			{
				return 3;
				cout << "������� �����" << endl;
			}
	}

	void Trapezium :: ShowPoints()
	{
		cout << "����� �: " << endl;
		a1.ShowPoint(); //1 - ����� �������
		cout << "����� B: " << endl;
		a2.ShowPoint(); //2 - ������ �������
		cout << "����� C: " << endl;
		a3.ShowPoint(); //3 - ������ ������
		cout << "����� D: " << endl;
		a4.ShowPoint(); //4 - ����� ������
		cout << "���������� ������: "  << endl;
		cout << "X = " << center.x << " " << "Y = " << center.y << endl;
	}

	void Trapezium::Move(double x, double y)
	{
		a1.x = a1.x + x;
		a2.x = a2.x + x;
		a3.x = a3.x + x;
		a4.x = a4.x + x;

		a1.y = a1.y + y;
		a2.y = a2.y + y;
		a3.y = a3.y + y;
		a4.y = a4.y + y;
		cout << "�������� ���� ��������� " << endl;
	}

	void Trapezium::ChangeScale(int n)
	{
		lenghtBottom = lenghtBottom * n;
		lenghtTop = lenghtTop * n;
		hight = hight * n;
		a1.x = center.x + lenghtTop/2;
		a1.y = center.y + hight/2;
		a2.x = center.x + lenghtTop/2;
		a2.y = center.y + hight/2;
		a3.x = center.x + lenghtBottom/2;
		a3.y = center.y + hight/2;
		a4.x = center.x + lenghtBottom/2;
		a4.y = center.y + hight/2;

		scale = n;
		cout << "������� ������ ��� ������� �� " << n << endl;
	}

	void Trapezium::ShowFigure()
	{
		cout << "��� ������ - " << type << endl;
		cout << "���� ������ - " << color << endl;
		ShowPoints();
		cout << "������� ������ = " << area << endl;
	}

	void Trapezium::ChangeAngle(double a)
	{
		int x0;

		x0 = a1.x;
		a1.x = a1.x * cos(a) - a1.y * sin(a);
		a1.y = x0 * sin(a) + a1.y * cos(a);

		x0 = a2.x;
		a2.x = a2.x * cos(a) - a2.y * sin(a);
		a2.y = x0 * sin(a) + a2.y * cos(a);

		x0 = a3.x;
		a3.x = a3.x * cos(a) - a3.y * sin(a);
		a3.y = x0 * sin(a) + a3.y * cos(a);

		x0 = a4.x;
		a4.x = a4.x * cos(a) - a4.y * sin(a);
		a4.y = x0 * sin(a) + a4.y * cos(a);
	}

	void Trapezium::print(ostream& output)
	{
		output << "��� ������ - " << type << endl;
		output << "���� ������ - " << color << endl;
		ShowPoints();
	}
	Trapezium::~Trapezium()
	{

	}