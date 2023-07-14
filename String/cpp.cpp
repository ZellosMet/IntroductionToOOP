#include "String.h"

int Strings::get_size()const
{
	return size;
}
const char* Strings::get_str()const
{
	return str;
}
char* Strings::get_str()
{
	return str;
}
Strings::Strings(int size) :size(size), str(new char[size] {}) //Универсальный конструктор для выделения памяти
{
	//std::cout << "конструктор\t" << this << std::endl;
}
Strings::Strings(const char* str) :Strings(strlen(str) + 1)//Конструктор для ввода строки
{
	for (int i = 0; str[i]; i++) this->str[i] = str[i];
	//std::cout << "конструктор\t" << this << std::endl;
}
Strings::Strings(const Strings& str) :Strings(str.str)//Конструктор копирования
{
	//std::cout << "конструктор\t" << this << std::endl;
}
Strings::Strings(Strings&& str) :size(str.size), str(str.str) //Конструктор переноса
{
	str.str = nullptr;
	str.size = 0;
	//std::cout << "конструктор\t" << this << std::endl;
}
Strings& Strings::operator=(const Strings& str)
{
	if (this == &str) return *this;
	delete[] this->str;
	this->size = strlen(str.str);
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = str.str[i];
	//std::cout << "Присваивание\t" << this << std::endl;
	return *this;
}
Strings& Strings::operator=(Strings&& str)
{
	if (this == &str) return *this;
	delete[] this->str;
	this->str = str.str;
	size = str.size;
	str.str = nullptr;
	str.size = 0;
	//std::cout << "Присваивание\t" << this << std::endl;
	return *this;
}
char Strings::operator[](int i)const
{
	return str[i];
}
char& Strings::operator[](int i)
{
	return str[i];
}
Strings::~Strings()
{
	delete[] str;
	//std::cout << "Деструктор\t" << this <<std::endl;
}
Strings operator+(const Strings& left, const Strings& right)
{
	Strings concate(left.get_size() + right.get_size() - 1);
	int i = 0;
	for (; i < left.get_size(); i++) concate[i] = left[i];
	i--;
	for (int j = 0; j < right.get_size(); j++, i++) concate[i] = right[j];
	return concate;
}
Strings operator-(const Strings& left, const Strings& right)
{
	const int n = 256;
	char buff[n] = {};
	int k = 0;
	for (int i = 0; left[i]; i++)
	{
		for (int j = 0; right[j]; j++)
		{
			if (left[i] != right[j])
			{
				buff[k] = left[i];
				continue;
			}
			else
			{
				buff[k] = 0;
				k--;
				break;
			}
		}
		k++;
	}
	Strings diff(k + 1);
	for (int i = 0; buff[i]; i++)
	{
		diff[i] = buff[i];
	}
	return diff;
}
std::ostream& operator<<(std::ostream& os, const Strings& str)
{
	return os << str.get_str();
}
std::istream& operator>>(std::istream& is, Strings& str)
{
	return is.getline(str.get_str(), str.get_size());
}