#include<iostream>
#include<ctime>
using namespace std;

class Point //создание класса
{
	double x;
	double y;

public: // реализация сетторов и геттеров
	/*
	Point() //Конструктор без параметров
	{
		x = y = double(); //type() - то значение по умолчанию для заданного типа. таким образом мы якобы вызываем конструктор по умолчанию для заданного типа
		cout << "Конструктор по умолчанию\t\t" << this << endl;
	}
	Point(double x)
	{	
		this->x = x;
		this->y = 0;
		cout << "Конструктор с одним параметром:\t\t" << this << endl;
	}
	*/
	Point(double x = 0, double y = 0) //Универсальный Конструктор с параметрами
	{
		this->x = x;
		this->y = y;
		cout << "Конструктор с двумя параметрами:\t" << this << endl;
	}
	Point(const Point &other) // Конструктор копирования
	{
		x = other.x;
		y = other.y;
		cout << "Конструктор копирования:\t\t" << this << endl;
	}
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
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance()const
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	double distancePointToPoint(const Point &b)const
	{
		return sqrt(pow(b.x - x, 2) + pow(b.y - y, 2));
	}
	void print()
	{	
		cout << "X = " << x << " Y = " << y << endl;
	}
	~Point() // Деконструктор
	{
		cout << "Деконструктор:\t\t\t\t" << this << endl;
	}
	// оператор:
	Point &operator=(const Point& other) //возвращаем по ссылки
	{	
		this-> x = other.x;
		this-> y = other.y;
		cout << "Оператор копирования:\t\t\t" << this << endl;
		return *this; // возвращаем разъименованное значение
	}
};

double Distance(Point &a, Point &b);

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTUCTORS_CHECK

#define delim "\n-----------------------------------------------\n"

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
#ifdef DISTANCE_CHECK
	Point A(2, 3); // Создание объекта конструктором с параметрами
	Point B; //Создание объекта конструктором без параметров
	cout << "Сгенерированные координаты точки 'А': (" << A.get_x() << ", " << A.get_y() << ")" << endl;
	cout << "Сгенерированные координаты точки 'B': (" << B.get_x() << ", " << B.get_y() << ")" << endl;
	cout << "Расстояние до точки 'А': " << A.distance() << endl;
	cout << "Расстояние до точки 'В': " << B.distance() << endl;
	cout << delim << endl;
	cout << "Расчёт расстояние между точками через функцию: " << Distance(A, B) << endl;
	cout << delim << endl;
	cout << "Расстояние между точками методом класса: " << A.distancePointToPoint(B) << endl;
#endif
#ifdef CONSTUCTORS_CHECK
	//Методы создания объектов перегрузкой конструктора
	Point A;
	A.print();
	Point B = 5;
	B.print();
	Point C(2, 3);
	C.print();
	Point D = C; //конструктор копирования
	D.print();
	Point E;
	E = D; //оператор присваивания
	E.print();
#endif 
	Point A, B, C;
	A.print();
	B.print();
	C.print();
	A = B = C = Point(2, 3);
}

double Distance(Point &a, Point &b)
{
	return sqrt(pow((b.get_x() - a.get_x()), 2) + pow((b.get_y() - a.get_y()), 2));
}