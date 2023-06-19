#include<iostream>
#include<ctime>
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
	void PointRand()
	{
		x = rand() % 10;
		y = rand() % 10;	
	}
	double distance()const
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	double distancePointToPoint(Point b)const
	{
		return sqrt(pow((b.x - x), 2) + pow((b.y - y), 2));
	}
};

double Distance(Point a, Point b);

//#define STRUCT_POINT
#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

#ifdef STRUCT_POINT
	Point A; //Создание объекта
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl; //Обращение к полю по имени
	Point *pA = &A;
	cout << pA->x << "\t" << pA->y << endl; //Обращение к полю по адресу
#endif 

#ifdef HOME_WORK
	Point A;
	Point B;
	A.PointRand();
	B.PointRand();
	cout << "Сгенерированные координаты точки 'А': (" << A.get_x() << ", " << A.get_y() << ")" << endl;
	cout << "Сгенерированные координаты точки 'B': (" << B.get_x() << ", " << B.get_y() << ")" << endl;
	cout << "Расстояние до точки 'А': " << A.distance() << endl;
	cout << "Расстояние до точки 'В': " << B.distance() << endl;
	cout << "Расчёт расстояние между точками через функцию: " << Distance(A, B) << endl;
	cout << "Расстояние между точками методом класса: " << A.distancePointToPoint(B) << endl;
#endif
}

double Distance(Point a, Point b)
{
	return sqrt(pow((b.get_x() - a.get_x()), 2) + pow((b.get_y() - a.get_y()), 2));
}