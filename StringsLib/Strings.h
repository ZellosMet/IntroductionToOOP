#pragma once
#include<iostream>
#include<Windows.h>
namespace Strings
{
	class Strings
	{
		int size;
		char* str;
	public:
		//�������
		int get_size()const;
		const char* get_str()const;
		char* get_str();
		//������������
		explicit Strings(int size = 80);
		Strings(const char* str);
		Strings(const Strings& str);
		Strings(Strings&& str);
		//���������� ���������� � ������
		Strings& operator=(const Strings& str);
		Strings& operator=(Strings&& str);
		char& operator[](int i);
		char operator[](int i)const;
		//����������
		~Strings();
	};

	Strings operator+(const Strings& left, const Strings& right);
	Strings operator-(const Strings& left, const Strings& right);
	std::ostream& operator<<(std::ostream& os, const Strings& str);
	std::istream& operator>>(std::istream& is, Strings& str);
}