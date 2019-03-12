#pragma once
#include "stdafx.h"
#include "string"
#include "math.h"
using namespace std;
class Shape {
public:
    Shape();
	virtual ~Shape();
	friend ostream&operator<<(ostream&, const Shape&); //����� ������
protected: 
	static  int ID;
	int X = 0, Y = 0;//����� ������
	int Angle = 0; //���� ��������
	double Scale = 1; // ����������� �������
	string Color = "�����";//���� ������
	virtual void MoveFigure(int, int) = 0; //����������
	virtual void TurnFigure(int) = 0; //�������
	virtual void ScaleFigure(double) = 0; //�������
	virtual string GetColorFigure() = 0; //�������� ����
	virtual void SetColorFigure(string) = 0; //������ ����
};