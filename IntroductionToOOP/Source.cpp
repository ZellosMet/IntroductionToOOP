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
		//cout << "Конструктор с двумя параметрами:\t" << this << endl;
	}
	Point(const Point &other) // Конструктор копирования
	{
		x = other.x;
		y = other.y;
		//cout << "Конструктор копирования:\t\t" << this << endl;
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
		//cout << "Деконструктор:\t\t\t\t" << this << endl;
	}

	//					Унарные поераторы перегружаются внутри класса
	Point& operator=(const Point& other) //возвращаем по ссылки
	{	
		this-> x = other.x;
		this-> y = other.y;
		//cout << "Оператор копирования:\t\t\t" << this << endl;
		return *this; // возвращаем разъименованное значение
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point& operator-=(const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Point& operator*=(const Point& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	Point& operator/=(const Point& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}
	Point& operator++() //Префексный инкримент
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int) //Посфиксный инкримент
	{
		Point old(*this); // Сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}
	Point& operator--() //Префексный декримент
	{
		x--;
		y--;
		return *this;
	}
	Point operator--(int) //Посфиксный декримент
	{
		Point old(*this); 
		x--;
		y--;
		return old;
	}
};
					//Арифметические операторы перегружаются за классом

Point operator+(const Point& left, const Point& right)
{
	/*Point result;																			//1. Способ описания реализации перегрузки
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());*/

	//Point result(left.get_x() + right.get_x(), left.get_y() + right.get_y());				//2. Способ описания реализации перегрузки

	return Point (left.get_x() + right.get_x(), left.get_y() + right.get_y());				//3. Способ описания реализации перегрузки
}
Point operator-(const Point& left, const Point& right)
{
	return Point(left.get_x() - right.get_x(), left.get_y() - right.get_y());
}
Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}
Point operator/(const Point& left, const Point& right)
{
	return Point(left.get_x() / right.get_x(), left.get_y() / right.get_y());
}
					//Операторы потока перегружаются за классом
ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();	
}
istream& operator>>(istream& is, Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}


double Distance(Point& a, Point& b)
{
	return sqrt(pow((b.get_x() - a.get_x()), 2) + pow((b.get_y() - a.get_y()), 2));
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define INCREMENT_CHECK
//#define THREAD_OPERATORS

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
#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	A.print();
	B.print();
	C.print();
	A = B = C = Point(2, 3);
#endif 
#ifdef INCREMENT_CHECK
	Point A(2, 3);
	cout << "Точка А\t\t";
	A.print();
	Point B(7, 8);
	cout << "Точка B\t\t";
	B.print();
	Point C = A + B;
	cout << "С = А + В\t";
	C.print();
	C = A - B;
	cout << "С = А - В\t";
	C.print();
	C = A * B;
	cout << "С = А * В\t";
	C.print();
	C = A / B;
	cout << "С = А / В\t";
	C.print();
	++A;
	cout << "++А\t\t";
	A.print();
	Point D = A++;
	cout << "D = А++\t\t";
	D.print();
	cout << "Точка А\t\t";
	A.print();

	Point E(3, 3);
	cout << "Точка E\t\t";
	E.print();
	E = E++ + ++E;
	cout << "E = E++ + ++E\t";
	E.print();
#endif 
#ifdef THREAD_OPERATORS
	Point A(2, 3);
	cout << "Точка А\t\t";
	A.print();
	Point B(7, 8);
	cout << "Точка B\t\t";
	B.print();
	A += B;
	cout << "A+=B\t\t";
	A.print();
	A -= B;
	cout << "A-=B\t\t";
	A.print();
	A *= B;
	cout << "A*=B\t\t";
	A.print();
	A /= B;
	cout << "A/=B\t\t";
	A.print();
	cout << A << endl << "Введите координаты точки\n";
	cin >> A;
	cout << A << endl;
#endif 

}