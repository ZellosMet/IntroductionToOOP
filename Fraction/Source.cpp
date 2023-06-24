#include<iostream>
using namespace std;

class Fraction
{
	int Int, Num, Den;

public:
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
};
//Перегрузка операторов
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_Den(left.get_Den() * right.get_Den());
	result.set_Num(left.get_Den() * right.get_Num() + right.get_Den() * left.get_Num());
	result.set_Int(left.get_Int() + right.get_Int() + result.get_Num() / result.get_Den());
	result.set_Num(result.get_Num() % result.get_Den());
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_Den(left.get_Den() * right.get_Den());
	result.set_Num((left.get_Den() * left.get_Int() + left.get_Num()) - (right.get_Den() * right.get_Int() + right.get_Num()));
	result.set_Int(left.get_Int() - right.get_Int() + result.get_Num() / result.get_Den());
	result.set_Num(result.get_Num() % result.get_Den());
	return result;
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_Den(left.get_Den() * right.get_Den());
	result.set_Num((left.get_Den() * left.get_Int() + left.get_Num()) * (right.get_Den() * right.get_Int() + right.get_Num()));
	result.set_Int(left.get_Int() + right.get_Int() + result.get_Num() / result.get_Den());
	result.set_Num(result.get_Num() % result.get_Den());
	return result;
}


ostream& operator<<(ostream& os, const Fraction& obj)
{
	return os << "  " << obj.get_Num() << endl << obj.get_Int() << " ---" << endl << "  " << obj.get_Den();
}
istream& operator>>(istream& is, Fraction& obj)
{
	int Int, Num, Den;
	cout << "Введите значения дроби(Целое, числитель, знаменатель)"; is >> Int >> Num >> Den;
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
	cin >> Fr1;
	cout << "Значение первой дроби" << endl << Fr1 << endl;
	cin >> Fr2;
	cout << "Значение второй дроби" << endl << Fr2 << endl;
	Fraction Fr3 = Fr1 + Fr2;
	cout << "Значение суммы дроби" << endl << Fr3 << endl;
	Fraction Fr4 = Fr1 - Fr2;
	cout << "Значение разности дроби" << endl << Fr4 << endl;
	Fraction Fr5 = Fr1 * Fr2;
	cout << "Значение умножения дроби" << endl << Fr5 << endl;

}