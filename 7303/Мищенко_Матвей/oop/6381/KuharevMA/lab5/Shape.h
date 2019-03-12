#include <string>
#include <cmath>
#include <iostream>

using namespace std;

namespace custom
{
    class Shape
    {
    public:
        virtual ~Shape();
        virtual void MoveFigure(int, int) = 0; //����������
        virtual void TurnFigure(int) = 0; //�������
        virtual void ScaleFigure(double) = 0; //�������
        virtual string GetColorFigure() = 0; //�������� ����
        virtual void SetColorFigure(string) = 0; //������ ����
        friend ostream&operator<<(ostream&, const Shape&); //����� ������

        int X = 0, Y = 0;//����� ������
        int Angle = 0; //���� ��������
    protected:
        static  int ID;
        double Scale = 1; // ����������� �������
        string Color = "�����";//���� ������
    };

    class Pentagon : public Shape
    {
    public:
        int  Side;
        int Id;
        Pentagon(int, int, int, double, int, string);
        Pentagon(int);
        void MoveFigure(int, int); //����������
        void TurnFigure(int); //�������
        void ScaleFigure(double); //�������
        string GetColorFigure(); //�������� ����
        void SetColorFigure(string); //������ ����
        int GetSide();
        void SetSide(int);
        friend ostream& operator<<(ostream&a, const Pentagon&b)
        {
            a << "ID ������: id=" << b.Id << "\n";
            a << "����� ������: x=" << b.X << "; y=" << b.Y << "\n";
            a << "����: " << b.Color << "\n";
            a << "���� �������� ������: fi=" << b.Angle << "\n";
            a << "�������: delta=" << b.Scale << "\n";
            a << "����� ������ � ������ �������: ������� �������������=" << b.Side*b.Scale << "\n";
            return a;
        }
        ~Pentagon();
    };

    class Segment : public Shape
    {
    private:
        double Length;
        int Id;
    public:
        Segment(int, int, int, double, int, string);
        Segment(int Length);
        void MoveFigure(int, int); //����������
        void TurnFigure(int); //�������
        void ScaleFigure(double); //�������
        string GetColorFigure(); //�������� ����
        void SetColorFigure(string); //������ ����
        void SetLength(int);
        int GetLength();
        friend ostream&operator<<(ostream&a, const Segment&b) {
            a << "ID ������: id=" << b.Id << "\n";
            a << "����� ������: x=" << b.X << "; y=" << b.Y << "\n";
            a << "����: " << b.Color << "\n";
            a << "���� �������� ������: fi=" << b.Angle << "\n";
            a << "�������: delta=" << b.Scale << "\n";
            a << "����� � ������ �������: �������������� �������=" << b.Length*b.Scale << "\n";
            return a;
        }
        ~Segment();
    };

    class Ellipse : public custom::Shape
    {
    public:
        int SmallAxle, BigAxle;
        int Id;
        Ellipse(int, int, int, int, double, int, string);
        Ellipse(int, int);
        void MoveFigure(int, int); //�����������
        void TurnFigure(int); //�������
        void ScaleFigure(double); //�������
        string GetColorFigure(); //�������� ����
        void SetColorFigure(string); //������ ����
        int GetSAxle();
        int GetBAxle();
        void SetAxles(int, int);
        friend ostream&operator<<(ostream& a, const Ellipse& b) {

            a << "ID ������: id=" << b.Id << "\n";
            a << "����� ������: x=" << b.X << "; y=" << b.Y << "\n";
            a << "����: " << b.Color << "\n";
            a << "���� �������� ������: fi=" << b.Angle << "\n";
            a << "�������: delta=" << b.Scale << "\n";
            a << "������ ������� � ������ ���������������=" << b.BigAxle*b.Scale << "  ������ �������=" << b.SmallAxle*b.Scale << "\n";
            return a;
        }
        ~Ellipse();
    };
}


