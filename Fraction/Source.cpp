#include<iostream>
using namespace std;

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
		this-> Den = Den;
		if (Den == 0) this -> Den = 1;
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
		if (Num > Den)
		{
			Int = Num / Den;
			Num = Num % Den;
		}
		return *this;
	}
	Fraction& ToImproper() //Неправильная дробь
	{
		Int == 0 ? Num = Num : Num = Int * Den + Num;
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

		Int += other.Int;
		Num = Num * other.Den + Den * other.Num;
		Den *= other.Den;
		ToProper();
		Reduce();
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		Fraction tmp = other;
		ToImproper();
		tmp.ToImproper();
		Num = Num * tmp.Den - Den * tmp.Num;
		Den *= other.Den;
		ToProper();
		Reduce();
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		Fraction tmp = other;
		ToImproper();
		tmp.ToImproper();
		Num *= tmp.Num;
		Den *= tmp.Den;
		ToProper();
		Reduce();
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		Fraction tmp = other;
		ToImproper();
		tmp.ToImproper();
		Num *= tmp.Den;
		Den *= tmp.Num;
		ToProper();
		Reduce();
		return *this;
	}

	//Перегрузка операторов сравнения
	bool operator==(const Fraction& other)
	{
		Fraction tmp = other;
		tmp.ToImproper();
		return Num*tmp.get_Den() == tmp.get_Num()*Den;
	}
	bool operator!=(const Fraction& other)
	{
		Fraction tmp = other;
		tmp.ToImproper();
		return Num * tmp.get_Den() != tmp.get_Num() * Den;
	}
	bool operator<(const Fraction& other)
	{
		Fraction tmp = other;
		tmp.ToImproper();
		return Num * tmp.get_Den() < tmp.get_Num() * Den;
	}
	bool operator>(const Fraction& other)
	{
		Fraction tmp = other;
		tmp.ToImproper();
		return Num * tmp.get_Den() > tmp.get_Num() * Den;
	}
};

//Перегрузка арифметических операторов
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right;
	left_tmp.ToImproper();
	right_tmp.ToImproper();
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Den());
	result.set_Num(left_tmp.get_Den() * right_tmp.get_Num() + right_tmp.get_Den() * left_tmp.get_Num());
	result.ToProper();
	result.Reduce();
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right;
	left_tmp.ToImproper();
	right_tmp.ToImproper();
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Den());
	result.set_Num(left_tmp.get_Num() * right_tmp.get_Den() - right_tmp.get_Num() * left_tmp.get_Den());
	result.ToProper();
	result.Reduce();
	if (result.get_Int() < 0) result.set_Num(-result.get_Num()); //Костыль	
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right;
	left_tmp.ToImproper();
	right_tmp.ToImproper();
	result.set_Num(left_tmp.get_Num() * right_tmp.get_Num());
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Den());
	result.ToProper();
	result.Reduce();
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right;
	left_tmp.ToImproper();
	right_tmp.ToImproper();
	result.set_Num(left_tmp.get_Num() * right_tmp.get_Den());
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Num());
	result.ToProper();
	result.Reduce();
	return result;
}

//Перегрузка потока
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

// Функции для дробей
int Сomparison(const Fraction& left, const Fraction& right)
{
	Fraction result = left - right;
	if (result.get_Num() < 0) return -1;
	else if (result.get_Num() > 0) return 1;
	if (result.get_Num() == 0) 0; return 0;
}
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
	Fraction Fr1(1, 1, 15);
	Fraction Fr2(1, 4, 16);	
	//cout << "Введите значения первой дроби(Целое, числитель, знаменатель)";
	//cin >> Fr1;
	cout << "Значение первой дроби" << endl << Fr1 << endl;
	//cout << "Введите значения первой дроби(Целое, числитель, знаменатель)";
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
	Fr2*=5;
	cout << "*= 5 для второй дроби" << endl << Fr2 << endl;
	Сomparison(Fr1, Fr2) == 0 ? cout << "Дроби равны" : Сomparison(Fr1, Fr2) < 0 ? cout << "Первая дробь меньше второй" : cout << "Первая дробь больше второй";	
	cout << "\nПервая дробь > Вторая дробь? " << (Fr1 > Fr2);
}