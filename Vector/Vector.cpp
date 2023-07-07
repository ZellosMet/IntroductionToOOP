#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Vector
{
	double x;
	double y;
	double z;
public:
	//Геттеры
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	double get_z()const
	{
		return z;
	}

	//Сеттеры
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_z(double z)
	{
		this->z = z;
	}

	//Конструторы
	Vector() //Конструктор поумолчанию
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	Vector(double x) //Конструктор с одним параметром
	{
		this->x = x;
		this->y = 0;
		this->z = 0;
	}
	Vector(double x, double y) //Конструктор с двумя параметрами
	{
		this->x = x;
		this->y = y;
		this->z = 0;
	}
	Vector(double x, double y, double z) //Конструктор с тремя параметрами
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

//Операторы класса
	Vector& operator=(const Vector& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};

//Перегрузка операторов
	std::ostream& operator<<(std::ostream& os, const Vector& obj)
	{
		return os << "(" << obj.get_x() << ", " << obj.get_y() << ", " << obj.get_z() << ")";
	}
	std::istream& operator>>(std::istream& is, Vector& obj)
	{
		const int SIZE = 10;
		char buffer[SIZE] = {};
		is.getline(buffer, SIZE);
		int number[3] = {};
		int i = 0;
		char delimiters[] = " ";
		for (char* pch = std::strtok(buffer, delimiters); pch; pch = std::strtok(NULL, delimiters)) number[i++] = std::atoi(pch);
		switch (i)
		{
		case 1: obj = Vector(number[0]); break;
		case 2: obj = Vector(number[0], number[1]); break;
		case 3: obj = Vector(number[0], number[1], number[2]); break;
		}
		return is;
	}

void main()
{
	setlocale(LC_ALL, "ru");

	Vector V1;
	Vector V2 = 5;
	std::cout << "Введите координаты ветора: "; std::cin >> V1;
	std::cout << V1 << std::endl;
	std::cout << V2 << std::endl;
}