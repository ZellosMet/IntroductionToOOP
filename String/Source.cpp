#include<iostream>

class Strings
{
	char* str;
	int size = 0;
public:
//Конструкторы
	Strings() //Конструктор поумолчанию
	{
		char* str = new char[80]{};
		this->str = str;
	}
	Strings(int size) //Конструктор с параметром размера строки
	{
		this->size = size;
		char* str = new char[size] {};
		this->str = str;
	}
	Strings(const char *str) //Конструктор для с пораметром строки
	{
		this->size = strlen(str);
		this->str = new char[size+1] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		this->str[size] = '\0';
	}
	Strings(const Strings& str) //Конструктор копирования
	{
		this-> size = strlen(str.str);
		this->str = new char[size+1] {};
		for (int i = 0; i < size; i++) this->str[i] = str.str[i];
		this->str[size] = '\0';
	}
	Strings(Strings&& str)noexcept //Конструктор переноса
	{
		this->str = str.str;
		this->size = str.size;
		str.str = nullptr;
		str.size = 0;
	}
//Геттры
	int get_size()const
	{
		return size;
	}
//Операторы
	Strings& operator=(const int size)
	{
		char* str = new char[size]{};
		return *this;
	}
	Strings& operator=(const char *str)
	{
		this->size = strlen(str);
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		this->str[size] = '\0';
	}
	char& operator[](char i)const
	{
		return str[i];
	}
//Деструктор
	~Strings()
	{
		delete this->str;
	}
};

//Перегрузка операторов
std::ostream& operator<<(std::ostream& os, const Strings& str)
{
	for (int i = 0; i < str.get_size(); i++) std::cout << str[i];
	return os;
}
Strings operator+(const Strings& left, const Strings& right)
{
	Strings concate = left.get_size() + right.get_size() + 1;
	int i = 0;
	for (; i < left.get_size(); i++) concate[i] = left[i];
	for (int j = 0; j < right.get_size(); j++, i++) concate[i] = right[j];
	concate[left.get_size() + right.get_size()] = '\0';
	return concate;
}

void main()
{
	setlocale(LC_ALL, "ru");
	Strings str1;
	Strings str2 = 5;
	Strings str3 = "Hello";
	std::cout << "Первая строка: " << str3 << std::endl;
	Strings str4 = "World";
	std::cout << "Первая строка: " << str4 << std::endl;
	Strings str5 = str3 + str4;
	std::cout << "Конкатенация строк: " << str5 << std::endl;
}
