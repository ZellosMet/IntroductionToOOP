#pragma once
#include<iostream>
class Fraction
{
	int Int, Num, Den;

public:
	// �������
	int get_Int()const;
	int get_Num()const;
	int get_Den()const;

	// �������
	void set_Int(int Int);
	void set_Num(int Num);
	void set_Den(int Den);

	// ������������
	Fraction(); // �� ���������
	Fraction(int Int);// � ����� ����������(�����)
	Fraction(int Num, int Den); //� ����� �����������(�����)
	Fraction(int Int, int Num, int Den); // ������ �����������(����� � �����)
	Fraction(double value); //����������� � ��������� �� ���������
	Fraction(const Fraction& other); // ����������� �����������
	operator double();

	// ������
	Fraction& ToProper(); //���������� �����	
	Fraction& ToImproper(); //������������ �����	
	Fraction& Reduce(); //���������� �����	
	Fraction Inverted()const;	
	double FractionToDecFraction();

	// ���������� ������������
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	//���������� ���������� ���������
	bool operator==(const Fraction& other)const;	
	bool operator<(const Fraction& other)const;	
	bool operator!=(const Fraction& other)const;	
	bool operator>(const Fraction& other)const;	
	bool operator<=(const Fraction& other)const;	
	bool operator>=(const Fraction& other)const;

	//���������� ����������/����������
	Fraction& operator++(); //���������� ���������
	Fraction operator++(int); //���������� ���������	
	Fraction& operator--(); //���������� ���������	
	Fraction operator--(int); //���������� ���������
};

//���������� �������������� ����������
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

// ���������� ������
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

// �������
Fraction Pow(Fraction& other, int deg);
int ToIntNumber(char* str);
char* Shrink(char* str);
