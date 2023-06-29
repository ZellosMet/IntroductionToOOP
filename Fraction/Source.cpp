#include<iostream>
using namespace std;

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int Int, Num, Den;

public:
	// Геттеры
	int get_Int()const
	{
		return Int;
	}
	int get_Num()const
	{
		return Num;
	}
	int get_Den()const
	{
		return Den;
	}
	// Сеттеры
	void set_Int(int Int)
	{
		this-> Int = Int;
	}
	void set_Num(int Num)
	{
		this-> Num = Num;
	}
	void set_Den(int Den)
	{
		Den == 0 ? this->Den = 1 : this->Den = Den;
	}

	// Конструкторы
	Fraction() // По умолчанию
	{
		this->Int = 0;
		this->Num = 0;
		this->Den = 1;
	}
	Fraction(int Int) // С одним параметром(целое)
	{
		this->Int = Int;
		this->Num = 0;
		this->Den = 1;
	
	}
	Fraction(int Num, int Den) //С двумя параметрами(дробь)
	{
		this->Int = 0;
		this->Num = Num;
		this->Den = Den;	
	}
	Fraction(int Int, int Num, int Den) // Стремя параметрами(целое и дробь)
	{
		this->Int = Int;
		this->Num = Num;
		this->Den = Den;	
	}
	Fraction(const Fraction& other) // Конструктор копирования
	{
		Int = other.Int;
		Num = other.Num;
		Den = other.Den;
	}

	// Методы
	Fraction& ToProper() //Правильная дробь
	{
	
		Int += Num / Den;
		Num %= Den;
		return *this;
	}
	Fraction& ToImproper() //Неправильная дробь
	{
		Num += Int * Den;
		Int = 0;
		return *this;
	}
	Fraction& Reduce() //Сокращение дроби
	{
		int t = 1;
		for (int i = 100; i >= 2; i--)
		{
			if (Num % i == 0 && Den % i == 0)
			{
				t = i;
				break;
			}
		}
		Num = Num / t;
		Den = Den / t;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.ToImproper();
		std::swap(inverted.Num, inverted.Den);
		return inverted;	
	}

	// Перегрузка присваивания
	Fraction& operator=(const Fraction& other)
	{
		Int = other.Int;
		Num = other.Num;
		Den = other.Den;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//Перегрузка операторов сравнения
	bool operator==(const Fraction& other)const
	{
		Fraction ot = other, th = *this;
		th.ToImproper();
		ot.ToImproper();
		return th.Num * ot.get_Den() == ot.get_Num() * th.Den;
	}
	bool operator!=(const Fraction& other)const
	{
		return !(*this == other);
	}
	bool operator<(const Fraction& other)const
	{
		Fraction ot = other, th = *this;
		th.ToImproper();
		ot.ToImproper();
		return th.Num * ot.get_Den() < ot.get_Num() * th.Den;
	}
	bool operator>(const Fraction& other)const
	{
		return !(*this < other);
	}
	bool operator<=(const Fraction& other)const
	{
		Fraction ot = other, th = *this;
		th.ToImproper();
		ot.ToImproper();
		return th.Num * ot.get_Den() <= ot.get_Num() * th.Den;
	}
	bool operator>=(const Fraction& other)const
	{
		return !(*this <= other);
	}

	//Перегрузка инкримента/декримента
	Fraction& operator++() //Префексный инкримент
	{
		Int++;
		return *this;
	}
	Fraction operator++(int) //Посфиксный инкримент
	{
		Fraction old(*this);
		Int++;
		return old;
	}
	Fraction& operator--() //Префексный декримент
	{
		Int--;
		return *this;
	}
	Fraction operator--(int) //Посфиксный декримент
	{
		Fraction old(*this);
		Int--;
		return old;
	}
};

//Перегрузка арифметических операторов
Fraction operator+(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	return Fraction(left.get_Num() * right.get_Den() + right.get_Num() * left.get_Den(), left.get_Den() * right.get_Den()).ToProper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	right.set_Num(-right.get_Num());
	return left + right;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();	
	return Fraction(left.get_Num() * right.get_Num(), left.get_Den() * right.get_Den()).ToProper();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	return left * right.inverted();
}

// Перегрузка потока
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_Int() == 0 && obj.get_Num() == 0) return os << 0;
	if (obj.get_Int() == 0) return os << " " << obj.get_Num() << endl << "---" << endl << " " << obj.get_Den();
	if (obj.get_Num() == 0) return os << obj.get_Int();
	return os << "  " << obj.get_Num() << endl << obj.get_Int() << "---" << endl << "  " << obj.get_Den();
}
istream& operator>>(istream& is, Fraction& obj)
{
	int Int, Num, Den;
	is >> Int >> Num >> Den;
	obj.set_Int(Int);
	obj.set_Num(Num);
	obj.set_Den(Den);
	return is;
}

// Функции
Fraction Pow(Fraction& other, int deg)
{
	Fraction tmp;
	other.ToImproper();
	tmp = other;
	for (int i = 0; i < deg - 1; i++) other *= tmp;
	other.ToProper();
	other.Reduce();
	return other;
}


void main()
{
	setlocale(LC_ALL, "ru");
	bool b;
	Fraction Fr1(3, 4, 5);
	Fraction Fr2(2, 3, 4);
	//cout << "Введите значения первой дроби(Целое, числитель, знаменатель)\n";
	//cin >> Fr1;
	cout << "Значение первой дроби" << endl << Fr1 << endl;
	//cout << "Введите значения первой дроби(Целое, числитель, знаменатель)\n";
	//cin >> Fr2;
	cout << "Значение второй дроби" << endl << Fr2 << endl;
	Fraction Fr3 = Fr1 + Fr2;
	cout << "Значение суммы дроби" << endl << Fr3 << endl;
	Fraction Fr4 = Fr1 - Fr2;
	cout << "Значение разности дроби" << endl << Fr4 << endl;
	Fraction Fr5 = Fr1 * Fr2;
	cout << "Значение умножения дроби" << endl << Fr5 << endl;
	Fraction Fr6 = Fr1 / Fr2;
	cout << "Значение деления дроби" << endl << Fr6 << endl;
	Pow(Fr1, 3);
	cout << "Возведение первой дроби в степень 3" << endl << Fr1 << endl;
	Fr1++;
	cout << "Инкримент первой дроби" << endl << Fr1 << endl;
	Fr2*=5;
	cout << "*= 5 для второй дроби" << endl << Fr2 << endl;
	Fr1 == Fr2 ? cout << "Дроби равны" : (Fr1 > Fr2 ? cout << "Первая дробь больше второй" : cout << "Первая дробь меньше второй");
}