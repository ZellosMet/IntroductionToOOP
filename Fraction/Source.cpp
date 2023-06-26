#include<iostream>
using namespace std;

class Fraction
{
	int Int, Num, Den;

public:
	//Конструкторы
	Fraction(int Int = 0, int Num = 0, int Den = 0) // Конструктор по умолчанию
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
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		Fraction tmp = other;
		tmp.Int--;
		tmp.Num = Den;
		Int -= tmp.Int;
		Num -= tmp.Num;
		if (Num < 0) Num = -Num;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		Fraction tmp = other;
		int t = 1;
		tmp.Num = tmp.Int;
		tmp.Den = 1;
		Num = Int * Den + Num;
		Num *= tmp.Num;
		Den *= tmp.Den;
		Int = Num / Den;
		Num = Num % Den;
		for (int i = 2; i <= 11; i++) if (Num % i == 0 && Den % i == 0) t = i;
		Num /= t;
		Den /= t;
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		Fraction tmp = other;
		int t = 1;
		tmp.Num = tmp.Int;
		tmp.Den = 1;
		Num = Int * Den + Num;
		Num *= tmp.Den;
		Den *= tmp.Num;
		Int = Num / Den;
		Num = Num % Den;
		for (int i = 2; i <= 11; i++) if (Num % i == 0 && Den % i == 0) t = i;
		Num /= t;
		Den /= t;
		return *this;
	}

	// Методы
	Fraction Pow(int deg)
	{
		Int == 0 ? Num = Num : Num = Int * Den + Num;
		int Num_tmp = Num, Den_tmp = Den;
		for (int i = 0; i < deg-1; i++)
		{
			Num *= Num_tmp;
			Den *= Den_tmp;
		}
		Int = Num / Den;
		Num = Num % Den;
		return *this;
	}
	int Сomparison(const Fraction& other)const
	{
		int Num_tmp, Den_tmp, ot_Num_tmp, ot_Den_tmp = other.Den;
		if (other.Num == 0)
		{
			ot_Num_tmp = other.Int; 
			ot_Den_tmp = 1;
		}
		else other.Int == 0 ? ot_Num_tmp = other.Num : ot_Num_tmp = other.Int * other.Den + other.Num;
		if (Num == 0)
		{
			Num_tmp = Int;
			Den_tmp = 1;
		}
		else Int == 0 ? Num_tmp = Num : Num_tmp = Int * Den + Num;
		Num_tmp = Num_tmp * ot_Den_tmp - ot_Num_tmp * Den;
		if (Num_tmp < 0) return -1;
		else if (Num_tmp > 0) return 1;
		if (Num_tmp == 0) 0; return 0;
	}
};

//Перегрузка арифметических операторов
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	int t = 1;
	if (left.get_Num() == 0 || right.get_Num() == 0)
	{
		result.set_Int(left.get_Int() + right.get_Int());
		result.set_Num(left.get_Num() + right.get_Num());
		result.set_Den(left.get_Den() + right.get_Den());
	}
	else
	{
		result.set_Den(left.get_Den() * right.get_Den());
		result.set_Num(left.get_Den() * right.get_Num() + right.get_Den() * left.get_Num());
		result.set_Int(left.get_Int() + right.get_Int() + result.get_Num() / result.get_Den());
		result.set_Num(result.get_Num() % result.get_Den());
		for (int i = 2; i <= 11; i++) if (result.get_Num() % i == 0 && result.get_Den() % i == 0) t = i;
		result.set_Num(result.get_Num() / t);
		result.set_Den(result.get_Den() / t);
	}
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right;
	int t = 1;
	if (left_tmp.get_Num() == 0 && left_tmp.get_Den() == 0)
	{
		left_tmp.set_Num(left_tmp.get_Int());
		left_tmp.set_Int(0);
		left_tmp.set_Den(1);
	}
	else
	{
		left_tmp.set_Num(left_tmp.get_Int() * left_tmp.get_Den() + left_tmp.get_Num());
	}
	if (right_tmp.get_Num() == 0 && right_tmp.get_Den() == 0)
	{
		right_tmp.set_Num(right_tmp.get_Int());
		right_tmp.set_Int(0);
		right_tmp.set_Den(1);
	}
	else
	{
		right_tmp.set_Num(right_tmp.get_Int() * right_tmp.get_Den() + right_tmp.get_Num());
	}
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Den());
	result.set_Num(left_tmp.get_Num() * right_tmp.get_Den() - left_tmp.get_Den() * right_tmp.get_Num());
	result.set_Int(result.get_Num() / result.get_Den());
	result.set_Num(result.get_Num() % result.get_Den());
	for (int i = 2; i <= 11; i++) if (result.get_Num() % i == 0 && result.get_Den() % i == 0) t = i;
	result.set_Num(result.get_Num() / t);
	result.set_Den(result.get_Den() / t);
		if (result.get_Int() < 0) result.set_Num(-result.get_Num()); //Костыль	
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right; 
	int t = 1;
	if (left_tmp.get_Num() == 0 && left_tmp.get_Den() == 0)
	{
		left_tmp.set_Num(left_tmp.get_Int());
		left_tmp.set_Int(0);
		left_tmp.set_Den(1);
	}
	else
	{
		left_tmp.set_Num(left_tmp.get_Int() * left_tmp.get_Den() + left_tmp.get_Num());
	}
	if (right_tmp.get_Num() == 0 && right_tmp.get_Den() == 0)
	{
		right_tmp.set_Num(right_tmp.get_Int());
		right_tmp.set_Int(0);
		right_tmp.set_Den(1);
	}
	else
	{
		right_tmp.set_Num(right_tmp.get_Int() * right_tmp.get_Den() + right_tmp.get_Num());
	}
	result.set_Num(left_tmp.get_Num() * right_tmp.get_Num());
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Den());
	result.set_Int(result.get_Num() / result.get_Den());
	result.set_Num(result.get_Num() % result.get_Den());
	for (int i = 2; i <= 11; i++) if (result.get_Num() % i == 0 && result.get_Den() % i == 0) t = i;
	result.set_Num(result.get_Num() / t);
	result.set_Den(result.get_Den() / t);
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result, left_tmp = left, right_tmp = right;
	int t = 1;
	if (left_tmp.get_Num() == 0 && left_tmp.get_Den() == 0)
	{
		left_tmp.set_Num(left_tmp.get_Int());
		left_tmp.set_Int(0);
		left_tmp.set_Den(1);
	}
	else
	{
		left_tmp.set_Num(left_tmp.get_Int() * left_tmp.get_Den() + left_tmp.get_Num());
	}
	if (right_tmp.get_Num() == 0 && right_tmp.get_Den() == 0)
	{
		right_tmp.set_Num(right_tmp.get_Int());
		right_tmp.set_Int(0);
		right_tmp.set_Den(1);
	}
	else
	{
		right_tmp.set_Num(right_tmp.get_Int() * right_tmp.get_Den() + right_tmp.get_Num());
	}
	result.set_Num(left_tmp.get_Num() * right_tmp.get_Den());
	result.set_Den(left_tmp.get_Den() * right_tmp.get_Num());
	result.set_Int(result.get_Num() / result.get_Den());
	result.set_Num(result.get_Num() % result.get_Den());
	for (int i = 2; i <= 11; i++) if (result.get_Num() % i == 0 && result.get_Den() % i == 0) t = i;
	result.set_Num(result.get_Num() / t);
	result.set_Den(result.get_Den() / t);
	return result;
}
//Перегрузка потока
ostream& operator<<(ostream& os, const Fraction& obj)
{
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

void main()
{
	setlocale(LC_ALL, "ru");
	Fraction Fr1;
	Fraction Fr2;

	cout << "Введите значения первой дроби(Целое, числитель, знаменатель)";
	cin >> Fr1;
	cout << "\nЗначение первой дроби" << endl << Fr1 << endl;

	cout << "Введите значения первой дроби(Целое, числитель, знаменатель)";
	cin >> Fr2;
	cout << "\nЗначение второй дроби" << endl << Fr2 << endl;

	Fraction Fr3 = Fr1 + Fr2;
	cout << "Значение суммы дроби" << endl << Fr3 << endl;
	Fraction Fr4 = Fr1 - Fr2;
	cout << "Значение разности дроби" << endl << Fr4 << endl;
	Fraction Fr5 = Fr1 * Fr2;
	cout << "Значение умножения дроби" << endl << Fr5 << endl;
	Fraction Fr6 = Fr1 / Fr2;
	cout << "Значение деления дроби" << endl << Fr6 << endl;
	Fr1.Pow(3);
	cout << "Возведение первой дроби в степень 3" << endl << Fr1 << endl;
	Fr2*=5;
	cout << "*= 5 для второй дроби" << endl << Fr2 << endl;
	Fr1.Сomparison(Fr2) == 0 ? cout << "Дроби равны" : Fr1.Сomparison(Fr2) < 0 ? cout << "Первая дробь меньше второй" : cout << "Первая дробь больше второй";	
}