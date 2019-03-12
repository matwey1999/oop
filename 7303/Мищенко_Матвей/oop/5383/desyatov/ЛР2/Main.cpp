#include <iostream>
#include <cmath>
#include <string>
#include "EqualTrapezium.h"
#include "Ellipse.h"
using namespace std;
/*
class Point
{
public:
	int x;
	int y;
	
	Point() //��������� ����������
	{
		x = 0;
		y = 0;
	}
	
	Point(int x0, int y0) //���������� ����� ������������
	{
		x = x0;
		y = y0;
	}

	void show_Point() // �������� �����
	{
		cout << "���������� ����� x = " << x << endl;
		cout << "���������� ����� y = " << y << endl;
	}
};

class Shape
{
public:

	virtual void ShowFigure()= 0; //��������
	virtual void Move(int x, int y) = 0;
	virtual void ChangeScale(int n) = 0;
	virtual void ChangeColor(string color) = 0;
};

class Trapezium : public Shape
{
public:
	
	Point a1;
	Point a2;
	Point a3;
	Point a4;
	string color = "�������";
	string type = "��������";

	void ChangeColor(string c) //�������� ����
	{
		color = c;
		cout << "���� ��� ������� �� " << c;
	}

	void SetPoint(int x, int y, int num)
	{
		switch (num)
		{
		case 1:
		a1 = Point(x,y); // A
		case 2:
		a2 = Point(x, y); // B
		case 3:
		a3 = Point(x, y); // C
		case 4:
		a4 = Point(x, y); // D
		}
	}

	void check()
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
		k1 = (a2.y - a1.y)/(a2.x - a1.x); //������� ���������� ������� AB
		k2 = (a4.y - a3.y)/(a4.x - a3.x); //������� ���������� ������� CD
		if (k1 != k2)
		{
			k1 = (a3.y - a2.y)/(a3.x - a2.x); //������� ���������� ������� CB
			k2 = (a4.y - a1.y)/(a4.x - a1.x); //������� ���������� ������� AD
			if (k1 != k2)
			{
				cout << "��������� ������ �� �������� ���������!" << endl;
			}
		}
		else
		cout << "��������� ������ �������� ���������." << endl;
	}

	void ShowPoints()
	{
		cout << "����� �: " << endl;
		a1.show_Point(); //1 - ����� �������
		cout << "����� B: " << endl;
		a2.show_Point(); //2 - ������ �������
		cout << "����� C: " << endl;
	    a3.show_Point(); //3 - ������ ������
		cout << "����� D: " << endl;
		a4.show_Point(); //4 - ����� ������
	}

	void Move(int x, int y)
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

	void ChangeScale(int n)
	{
		a1.x = a1.x * n;
		a2.x = a2.x * n;
		a3.x = a3.x * n;
		a4.x = a4.x * n;

		a1.y = a1.y * n;
		a2.y = a2.y * n;
		a3.y = a3.y * n;
		a4.y = a4.y * n;
		cout << "������� ������ ��� ������� � " << n << " ��� " << endl;
	}

	void ShowFigure()
	{
		cout << "��� ������ - " << type << endl;
		cout << "���� ������ - " << color << endl;
		ShowPoints();
	}
};

class EqualTrapezium : public Trapezium //�������������� ��������
{
public:
	string type = "�������������� ��������";
	void check()
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
		double k1, k2, l1, l2;
		k1 = (a2.y - a1.y) / (a2.x - a1.x); //������� ���������� ������� AB
		k2 = (a4.y - a3.y) / (a4.x - a3.x); //������� ���������� ������� CD
		if (k1 != k2)
		{
			k1 = (a3.y - a2.y) / (a3.x - a2.x); //������� ���������� ������� CB
			k2 = (a4.y - a1.y) / (a4.x - a1.x); //������� ���������� ������� AD
			if (k1 != k2)
			{
				cout << "��������� ������ �� �������� �������������� ���������!" << endl;
				exit(1);
			}
			else //���� AB � CD �����������, ��������� ������ ��� ������� �� ���������
			{
				l1 = sqrt(((a2.x - a1.x)*(a2.x - a1.x)) + ((a2.y - a1.y)*(a2.y - a1.y)));
				l2 = sqrt(((a3.x - a4.x)*(a3.x - a4.x)) + ((a3.y - a4.y)*(a3.y - a4.y)));
				if (l1 != l2)
				{
					cout << " ������� ������ �� �������� �������������� ���������!" << endl;
					exit(1);
				}
			}
		}
		l1 = sqrt(((a4.x - a1.x)*(a4.x - a1.x)) + ((a4.y - a1.y)*(a4.y - a1.y)));
		l2 = sqrt(((a3.x - a2.x)*(a3.x - a2.x)) + ((a3.y - a2.y)*(a3.y - a2.y)));
		if (l1 != l2)
		{
			cout << "�������� ������ �� �������� �������������� ���������! " << endl;
			exit(1);
		}

	};
};
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, n;
	string colornew;
	int num = 1;
	int var = 0;
	char par[5] = "ABCD";
	cout << "������� ��� ����������� ������ (1 - ��������, 2 - �������������� ��������, 3 - ������. " << endl;
	cin >> var;
	if (var == 1)
	{
		Trapezium trap;
		while (num != 5)
		{
			cout << "������� ����������  ����� " << par[num - 1] << endl;
			cout << "(A - ����� �������, B - ������ �������, C - ������ ������ , D - ����� ������)" << endl;
			cout << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			//��������
			trap.SetPoint(x, y, num);
			num++;
		}
		trap.check();
		trap.ShowPoints();
		while (var != 0)
		{
			cout << endl << "�������� ��������:" << endl << "1.��������� ������ �� x ��� y" << endl;
			cout << "2.�������� ������� " << endl << "3.�������� ���� " << endl << "4.�������� ��������� " << endl << "0. ��� ������ " << endl;
			cin >> var;
			switch (var)
			{
			case 1:
				cout << "������� � � � �� ������� ����� ��������� " << endl;
				cout << "X = ";
				cin >> x;
				cout << endl << "Y = ";
				cin >> y;
				trap.Move(x, y);
				trap.ShowPoints();
				break;
			case 2:
				cout << "������� �� ������� ����� ��������� " << endl;
				cin >> n;
				trap.ChangeScale(n);
				break;
			case 3:
//				cout << "������� ���� (������ ���� " << trap.color << " )" << endl;
				cin >> colornew;
				trap.ChangeColor(colornew);
				break;
			case 4:
				trap.ShowFigure();
				break;
			case 0:
				exit(1);
			}
		}
	}
	if (var == 2)
	{
		EqualTrapezium Etrap;
		while (num != 5)
		{
			cout << "������� ����������  ����� " << par[num - 1] << endl;
			cout << "(A - ����� �������, B - ������ �������, C - ������ ������ , D - ����� ������)" << endl;
			cout << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			//��������
			Etrap.SetPoint(x, y, num);
			num++;
		}
		Etrap.check();
		Etrap.ShowPoints();
		while (var != 0)
		{
			cout << endl << "�������� ��������:" << endl << "1.��������� ������ �� x ��� y" << endl;
			cout << "2.�������� ������� " << endl << "3.�������� ���� " << endl << "4.�������� ��������� " << endl << "0. ��� ������ " << endl;
			cin >> var;

			switch (var)
			{
			case 1:
				cout << "������� � � � �� ������� ����� ��������� " << endl;
				cout << "X = ";
				cin >> x;
				cout << endl << "Y = ";
				cin >> y;
				Etrap.Move(x, y);
				Etrap.ShowPoints();
				break;
			case 2:
				cout << "������� �� ������� ����� ��������� " << endl;
				cin >> n;
				Etrap.ChangeScale(n);
				break;
			case 3:
//				cout << "������� ���� (������ ���� " << Etrap.color << " )" << endl;
				cin >> colornew;
				Etrap.ChangeColor(colornew);
				break;
			case 4:
				Etrap.ShowFigure();
				break;
			case 0:
				exit(1);
			}
		}
	}

	if (var == 3)
	{
		Ellipse trap;

		cout << "������� ���������� ����� " << endl;
	}
}