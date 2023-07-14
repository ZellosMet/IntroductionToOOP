#pragma once
#include<iostream>
#include<Windows.h>

class Strings
{
	int size;
	char* str;
public:
	//Геттеры
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//Конструкторы
	explicit Strings(int size = 80);
	Strings(const char* str);
	Strings(const Strings& str);
	Strings(Strings&& str);
	//Перегрузка операторов в классе
	Strings& operator=(const Strings& str);
	Strings& operator=(Strings&& str);
	char& operator[](int i);
	char operator[](int i)const;
	//Деструктор
	~Strings();
};

Strings operator+(const Strings& left, const Strings& right);
Strings operator-(const Strings& left, const Strings& right);
std::ostream& operator<<(std::ostream& os, const Strings& str);
std::istream& operator>>(std::istream& is, Strings& str);