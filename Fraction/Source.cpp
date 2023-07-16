#include<iostream>
#include"Fraction.h"

void main()
{
	setlocale(LC_ALL, "ru");
	
	Fraction Fr1;
	Fraction Fr2;
	std::cout << "Введите значения первой дроби(Целое, числитель, знаменатель)\n";
	std::cin >> Fr1;
	std::cout << "Значение первой дроби" << std::endl << Fr1 << std::endl;
	std::cout << "Введите значения первой дроби(Целое, числитель, знаменатель)\n";
	std::cin >> Fr2;
	std::cout << "Значение второй дроби" << std::endl << Fr2 << std::endl;
	Fraction Fr3 = Fr1 + Fr2;
	std::cout << "Значение суммы дроби" << std::endl << Fr3 << std::endl;
	Fraction Fr4 = Fr1 - Fr2;
	std::cout << "Значение разности дроби" << std::endl << Fr4 << std::endl;
	Fraction Fr5 = Fr1 * Fr2;
	std::cout << "Значение умножения дроби" << std::endl << Fr5 << std::endl;
	Fraction Fr6 = Fr1 / Fr2;
	std::cout << "Значение деления дроби" << std::endl << Fr6 << std::endl;
	Pow(Fr1, 3);
	std::cout << "Возведение первой дроби в степень 3" << std::endl << Fr1 << std::endl;
	Fr1++;
	std::cout << "Инкримент первой дроби" << std::endl << Fr1 << std::endl;
	Fr1 == Fr2 ? std::cout << "Дроби равны" : (Fr1 > Fr2 ? std::cout << "Первая дробь больше второй" : std::cout << "Первая дробь меньше второй");
	std::cout << std::endl;
	double a;
	std::cout << (a = Fr1.FractionToDecFraction());
}