#include<iostream>
#include<math.h>

using namespace std;


class Point //создание структуры
{
	double x;
	double y;

public: // реализация сетторов и геттеров
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
		this->x = x; // this указывает на член класса для которого вызывается сетер
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance()const
	{
		return sqrt(x * x + y * y);
	}
};

double Distance(Point a, Point b);

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef STRUCT_POINT
	Point A; //Создание объекта

	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl; //Обращение к полю по имени

	Point *pA = &A;

	cout << pA->x << "\t" << pA->y << endl; //Обращение к полю по адресу
#endif 
	//Использование гетеров и сетеров
	double dot;
	Point A;
	Point B;
	cout << "Введите координаты точки 'А': "; 
	cin >> dot;
	A.set_x(dot); 
	cin >> dot;
	A.set_y(dot);
	cout << "Введите координаты точки 'В': ";
	cin >> dot;
	B.set_x(dot); 
	cin >> dot;
	B.set_y(dot);	
	cout << "Координаты точки 'А': (" << A.get_x() << ", " << A.get_y() << ")" << endl;
	cout << "Координаты точки 'B': (" << B.get_x() << ", " << B.get_y() << ")" << endl;
	cout << "Расстояние до точки 'А': " << A.distance() << endl;
	cout << "Расстояние до точки 'В': " << B.distance() << endl;
	cout << "Расстояние между точками: " << Distance(A, B) << endl;
}

double Distance(Point a, Point b)
{
	return b.distance() - a.distance();
}