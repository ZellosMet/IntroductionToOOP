#include<iostream>

int** Allocate(const int rows, const int cols);
void FillMatrix(int** matrix, const int rows, const int cols);
void Clear(int** matrix, const int rows);

class Matrix
{
	int rows;
	int cols;
	int** matrix;
public:

	//Геттеры/Сеттеры
	int get_cols()const
	{
		return cols;
	}
	int get_rows()const
	{
		return rows;
	}
	int** get_matrix()const
	{
		return matrix;
	}
	void set_cols(int cols)
	{
		this->cols = cols;
	}
	void set_rows(int rows)
	{
		this->rows = rows;
	}


//Конструкторы
	Matrix()
	{
		rows = 3;
		cols = 3; 
		matrix = Allocate(rows, cols);
		FillMatrix(matrix, rows, cols);
		std::cout << "Конструктор поумолчанию\t\t" << this << std::endl;
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		matrix = Allocate(rows, cols); //Можно ли выделятьпамять через функцию
		FillMatrix(matrix, rows, cols);
		std::cout << "Конструктор с параметрами\t" << this << std::endl;

	}
	Matrix(const Matrix& matrix)
	{
		this->rows = matrix.get_rows();
		this->cols = matrix.get_cols();
		this->matrix = Allocate(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = matrix[i][j];
		std::cout << "Конструктор копирования\t\t" << this <<std::endl;
	}
	Matrix(Matrix&& matrix)noexcept
	{
		this->matrix = matrix.matrix;
		this->rows = matrix.rows;
		this->cols = matrix.cols;
		//for (int i = 0; i < rows; i++)  //Есть ли необходимость?
			//matrix.matrix[i] = nullptr;
		matrix.matrix = nullptr;
		matrix.rows = 0;
		matrix.cols = 0;
		std::cout << "Конструктор переноса\t\t" << this <<std::endl;
	}

//Перегрузка операторов
	Matrix& operator=(const Matrix& matrix)
	{
		if (this == &matrix) return *this;
		Clear(this->matrix, rows);
		rows = matrix.rows;
		cols = matrix.cols;
		this->matrix = Allocate(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = matrix[i][j];
		std::cout << "Оператор копирования" << std::endl;
		return *this;
	}
	Matrix& operator=(Matrix&& matrix)noexcept
	{
		if (this == &matrix) return *this;
		Clear(this->matrix, rows);
		this->matrix = matrix.matrix;
		rows = matrix.rows;
		cols = matrix.cols;
		//for (int i = 0; i < rows; i++) //Есть ли необходимость?
			//matrix.matrix[i] = nullptr;
		matrix.matrix = nullptr;
		matrix.rows = 0;
		matrix.cols = 0;
		std::cout << "Оператор перемещения\t\t" << std::endl;
		return *this;
	}
	int* operator[](const int i)
	{
		return matrix[i];
	}
	const int* operator[](const int i)const
	{
		return matrix[i];
	}
//Методы
	void negative()
	{	
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = -matrix[i][j];
	}
//Деструктор
	~Matrix() 
	{
		Clear(matrix, rows); //Моджно ли удалять через функцию??
		std::cout << "Деструктор\t\t\t" << this <<std::endl;
	}

};

//Перегрузка за классом
Matrix operator+(Matrix& lvalue, Matrix& rvalue)
{
	Matrix Sub(lvalue.get_rows(), lvalue.get_cols());
	for (int i = 0; i < lvalue.get_rows(); i++)
		for (int j = 0; j < lvalue.get_cols(); j++)
			Sub[i][j] = lvalue[i][j] + rvalue[i][j];
	return Sub;
}
Matrix operator-(Matrix& lvalue, Matrix& rvalue)
{
	Matrix negative = rvalue;// Двойное потребление памяти??
	negative.negative();
	return lvalue + negative;
}
std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix.get_rows(); i++)
	{
		for (int j = 0; j < matrix.get_rows(); j++)
		{
			os << matrix[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}

//Функции
int** Allocate(const int rows, const int cols)
{
	int** matrix = new int* [rows] {};
	for (int i = 0; i < rows; i++) matrix[i] = new int[cols] {};
	return matrix;
}
void FillMatrix(int** matrix, const int rows, const int cols)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 10;
	}
void Clear(int** matrix, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void main()
{
	setlocale(LC_ALL, "ru");

	Matrix M1;
	std::cout << "Первая матрица:" << std::endl << M1 << std::endl;
	Matrix M2(3, 3);
	std::cout << "Вторая матрица:" << std::endl << M2 << std::endl;
	Matrix M3 = M1 + M2;
	std::cout << "Третья матрица:" << std::endl << M3 << std::endl;
	Matrix M4;
	M4 = M1 - M2;
	std::cout << "Четвёртая матрица:" << std::endl << M4 << std::endl;
}