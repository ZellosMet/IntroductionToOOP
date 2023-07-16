#include"Fraction.h"

Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
int ToIntNumber(char* str);
char* Shrink(char* str);

	// Геттеры
	int Fraction::get_Int()const
	{
		return Int;
	}
	int Fraction::get_Num()const
	{
		return Num;
	}
	int Fraction::get_Den()const
	{
		return Den;
	}

	// Сеттеры
	void Fraction::set_Int(int Int)
	{
		this->Int = Int;
	}
	void Fraction::set_Num(int Num)
	{
		this->Num = Num;
	}
	void Fraction::set_Den(int Den)
	{
		Den == 0 ? this->Den = 1 : this->Den = Den;
	}

	// Конструкторы
	Fraction::Fraction(): Int(0), Num(0), Den(1) // По умолчанию
	{
	}
	Fraction::Fraction(int Int) : Int(Int), Num(0), Den(1) // С одним параметром(целое)
	{
	}
	Fraction::Fraction(int Num, int Den) : Int(0), Num(Num), Den(Den) //С двумя параметрами(дробь)
	{
	}
	Fraction::Fraction(int Int, int Num, int Den) : Int(Int), Num(Num), Den(Den) // Стремя параметрами(целое и дробь)
	{
	}
	Fraction::Fraction(double value)//Конструктор с точностью по умолчанию
	{
		int precision = 5;
		Int = value;
		Num = (value - Int) * pow(10, precision);
		Den = pow(10, precision);
		Reduce();
	}
	Fraction::Fraction(const Fraction& other) : Int(other.Int), Num(other.Num), Den(other.Den)// Конструктор копирования
	{
	}
	Fraction::operator double()
	{
		return (double)Num / Den + Int;
	}

	// Методы
	Fraction& Fraction::ToProper() //Правильная дробь
	{
		Int += Num / Den;
		Num %= Den;
		return *this;
	}
	Fraction& Fraction::ToImproper() //Неправильная дробь
	{
		Num += Int * Den;
		Int = 0;
		return *this;
	}
	Fraction& Fraction::Reduce() //Сокращение дроби
	{
		int i;
		for (i = Num; i >= 2; i--) if (Num % i == 0 && Den % i == 0) break;
		Num /= i;
		Den /= i;
		return *this;
	}
	Fraction Fraction::Inverted()const
	{
		Fraction inverted = *this;
		inverted.ToImproper();
		std::swap(inverted.Num, inverted.Den);
		return inverted;
	}
	double Fraction::FractionToDecFraction()
	{
		double dexfraction;
		return dexfraction = (double)Num / (double)Den + Int;
	}

	// Перегрузка присваивания
	Fraction& Fraction::operator=(const Fraction& other)
	{
		Int = other.Int;
		Num = other.Num;
		Den = other.Den;
		return *this;
	}
	Fraction& Fraction::operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& Fraction::operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& Fraction::operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& Fraction::operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//Перегрузка операторов сравнения
	bool Fraction::operator==(const Fraction& other)const
	{
		Fraction ot = other, th = *this;
		th.ToImproper();
		ot.ToImproper();
		return th.Num * ot.get_Den() == ot.get_Num() * th.Den;
	}
	bool Fraction::operator<(const Fraction& other)const
	{
		Fraction ot = other, th = *this;
		th.ToImproper();
		ot.ToImproper();
		return th.Num * ot.get_Den() < ot.get_Num() * th.Den;
	}
	bool Fraction::operator!=(const Fraction& other)const
	{
		return !(*this == other);
	}
	bool Fraction::operator>(const Fraction& other)const
	{
		Fraction ot = other, th = *this;
		th.ToImproper();
		ot.ToImproper();
		return th.Num * ot.get_Den() > ot.get_Num() * th.Den;
	}
	bool Fraction::operator<=(const Fraction& other)const
	{
		return !(*this > other);
	}
	bool Fraction::operator>=(const Fraction& other)const
	{
		return !(*this < other);
	}

	//Перегрузка инкримента/декримента
	Fraction& Fraction::operator++() //Префексный инкримент
	{
		Int++;
		return *this;
	}
	Fraction Fraction::operator++(int) //Посфиксный инкримент
	{
		Fraction old(*this);
		Int++;
		return old;
	}
	Fraction& Fraction::operator--() //Префексный декримент
	{
		Int--;
		return *this;
	}
	Fraction Fraction::operator--(int) //Посфиксный декримент
	{
		Fraction old(*this);
		Int--;
		return old;
	}

//Перегрузка арифметических операторов
Fraction operator+(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	return Fraction(left.get_Num() * right.get_Den() + right.get_Num() * left.get_Den(), left.get_Den() * right.get_Den()).ToProper().Reduce();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	right.set_Num(-right.get_Num());
	return left + right;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	return Fraction(left.get_Num() * right.get_Num(), left.get_Den() * right.get_Den()).ToProper().Reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();
	return left * right.Inverted();
}

// Перегрузка потока
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_Int() == 0 && obj.get_Num() == 0) return os << 0;
	if (obj.get_Int() == 0) return os << " " << obj.get_Num() << std::endl << "---" << std::endl << " " << obj.get_Den();
	if (obj.get_Num() == 0) return os << obj.get_Int();
	return os << "  " << obj.get_Num() << std::endl << obj.get_Int() << "---" << std::endl << "  " << obj.get_Den();
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	bool chk_doub = false;
	const int SIZE = 10;
	char fraction[SIZE];
	is.getline(fraction, SIZE);
	for (int i = 0; fraction[i]; i++) //Проверка числа на double
		if (fraction[i] == '.')
		{
			chk_doub = true; break;
		}
	if (chk_doub)
	{
		int i;
		obj.set_Int(ToIntNumber(fraction));
		for (i = 0; fraction[i]; i++) {}; //Определение точности
		obj.set_Num(ToIntNumber(fraction));
		obj.set_Den(pow(10, i));
		obj.Reduce();
	}
	else
	{
		int space = 0;
		for (int i = 0; i < fraction[i]; i++) //Проверка числа на корректность и подсчёт входных параметров
		{
			if (fraction[i] == ' ') space++;
			else if (fraction[i] < '0' || fraction[i] > '9')
			{
				std::cout << "Введены некорректные данные\n";
				return is;
			}
		}
		if (space == 2)
		{
			obj.set_Int(ToIntNumber(fraction));
			obj.set_Num(ToIntNumber(fraction));
			obj.set_Den(ToIntNumber(fraction));
		}
		else if (space == 1)
		{
			obj.set_Num(ToIntNumber(fraction));
			obj.set_Den(ToIntNumber(fraction));
		}
		else if (space == 0)
		{
			obj.set_Int(ToIntNumber(fraction));
		}
		else
		{
			std::cout << "Введено слишком много переменных\n";
		}
	}
	return is;
}

// Функции
Fraction Pow(Fraction& other, int deg)
{
	Fraction tmp;
	other.ToImproper();
	tmp = other;
	for (int i = 0; i < deg - 1; i++) other *= tmp;
	other.ToProper().Reduce();
	return other;
}
int ToIntNumber(char* str)
{
	int num = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' || str[i] == '.') break;
		num *= 10;
		num += str[i] - '0';
	}
	if (str[1] != 0)Shrink(str);
	return num;
}
char* Shrink(char* str)
{
	while ((str[0] != ' ' && str[0] != '.') && str[1] != 0)
		for (int j = 0; str[j]; j++)
			str[j] = str[j + 1];
	for (int i = 0; str[i]; i++) str[i] = str[i + 1];
	return str;
}