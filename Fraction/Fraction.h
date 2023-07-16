#pragma once
#include<iostream>
class Fraction
{
	int Int, Num, Den;

public:
	// Геттеры
	int get_Int()const;
	int get_Num()const;
	int get_Den()const;

	// Сеттеры
	void set_Int(int Int);
	void set_Num(int Num);
	void set_Den(int Den);

	// Конструкторы
	Fraction(); // По умолчанию
	Fraction(int Int);// С одним параметром(целое)
	Fraction(int Num, int Den); //С двумя параметрами(дробь)
	Fraction(int Int, int Num, int Den); // Стремя параметрами(целое и дробь)
	Fraction(double value); //Конструктор с точностью по умолчанию
	Fraction(const Fraction& other); // Конструктор копирования
	operator double();

	// Методы
	Fraction& ToProper(); //Правильная дробь	
	Fraction& ToImproper(); //Неправильная дробь	
	Fraction& Reduce(); //Сокращение дроби	
	Fraction Inverted()const;	
	double FractionToDecFraction();

	// Перегрузка присваивания
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	//Перегрузка операторов сравнения
	bool operator==(const Fraction& other)const;	
	bool operator<(const Fraction& other)const;	
	bool operator!=(const Fraction& other)const;	
	bool operator>(const Fraction& other)const;	
	bool operator<=(const Fraction& other)const;	
	bool operator>=(const Fraction& other)const;

	//Перегрузка инкримента/декримента
	Fraction& operator++(); //Префексный инкримент
	Fraction operator++(int); //Посфиксный инкримент	
	Fraction& operator--(); //Префексный декримент	
	Fraction operator--(int); //Посфиксный декримент
};

//Перегрузка арифметических операторов
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

// Перегрузка потока
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

// Функции
Fraction Pow(Fraction& other, int deg);
int ToIntNumber(char* str);
char* Shrink(char* str);
