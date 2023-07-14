#include<iostream>
#include<Windows.h>
#include"String.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Strings str1;
	Strings str2 = (Strings)5;
	Strings str3 = "Hello";
	std::cout << "Первая строка: " << str3 << std::endl;
	Strings str4 = "World";
	std::cout << "Первая строка: " << str4 << std::endl;
	Strings str5 = str3 + str4;
	std::cout << "Конкатенация строк: " << str5 << std::endl;
	//std::cout << "Введите строку: " << std::endl;
	//Strings str6;
	//std::cin >> str6;
	//std::cout << "Вы ввели строку: " << str6;
	Strings str6 = str3 - str4;
	std::cout << "Результат разности строк: " << str6 << std::endl;
}
