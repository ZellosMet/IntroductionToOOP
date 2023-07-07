#include<iostream>

class Strings
{
	char* str;
	int size = 0;
public:
//Геттеры
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
//Конструкторы
	explicit Strings(int size = 80) //Конструктор с параметром размера строки
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
	}
	Strings(const Strings& str) //Конструктор копирования
	{
		this-> size = strlen(str.str);
		this->str = new char[size+1] {};
		for (int i = 0; i < size; i++) this->str[i] = str.str[i];
	}
	Strings(Strings&& str)noexcept //Конструктор переноса
	{
		this->str = str.str;
		this->size = str.size;
		str.str = nullptr;
		str.size = 0;
	}
//Операторы
	Strings& operator=(const char *str)
	{
		this->size = strlen(str);
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
	}
	char& operator[](char i)const
	{
		return str[i];
	}
//Деструктор
	~Strings()
	{
		delete[] str;
	}
};

//Перегрузка операторов
Strings operator+(const Strings& left, const Strings& right)
{
	Strings concate = Strings(left.get_size() + right.get_size() + 1);
	int i = 0;
	for (; i < left.get_size(); i++) concate[i] = left[i];
	for (int j = 0; j < right.get_size(); j++, i++) concate[i] = right[j];
	return concate;
}
std::ostream& operator<<(std::ostream& os, const Strings& str)
{
	return os << str.get_str();
}

void main()
{
	setlocale(LC_ALL, "ru");
	Strings str1;
	Strings str2 = (Strings)5;
	Strings str3 = "Hello";
	std::cout << "Первая строка: " << str3 << std::endl;
	Strings str4 = "World";
	std::cout << "Первая строка: " << str4 << std::endl;
	Strings str5 = str3 + str4;
	std::cout << "Конкатенация строк: " << str5 << std::endl;
}
