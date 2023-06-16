#include<iostream>
using namespace std;

class Point //�������� ���������
{
	double x;
	double y;

public: // ���������� �������� � ��������
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x; // this ��������� �� ���� ������ ��� �������� ���������� �����
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef STRUCT_POINT
	Point A; //�������� �������

	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl; //��������� � ���� �� �����

	Point *pA = &A;

	cout << pA->x << "\t" << pA->y << endl; //��������� � ���� �� ������
#endif 

	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

}