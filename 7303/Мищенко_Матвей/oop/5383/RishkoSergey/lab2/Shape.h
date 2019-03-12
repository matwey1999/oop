#pragma once
#include "stdafx.h"
#include "string"
#include "math.h"
using namespace std;
class Shape{
public:
	static  int ID;
	double CenterX, CenterY;

	virtual void GetCenter() = 0;
	virtual ~Shape();
	virtual void MoveFigure(double, double) = 0; //�����������
	virtual void TurnFigure(double) = 0; //�������
	virtual void ScaleFigure(double) = 0; //�������
	//virtual void Perimetr() = 0;
	/*virtual string GetColorFigure() = 0; //�������� ����
	virtual void SetColorFigure(string) = 0; //������ ����*/
	friend ostream&operator<<(ostream&, const Shape&); //����� ������

};

