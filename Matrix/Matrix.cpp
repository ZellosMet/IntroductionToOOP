#include<iostream>

int** Allocate(const int rows, const int cols);
void FillMatrix(int** matrix, const int rows, const int cols);

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
		matrix = Allocate(rows, cols);
		FillMatrix(matrix, rows, cols);
		std::cout << "Конструктор с параметрами\t" << this << std::endl;

	}
	Matrix(Matrix& matrix)
	{
		this->rows = matrix.get_rows();
		this->cols = matrix.get_cols();
		this->matrix = Allocate(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = matrix[i][j];
		std::cout << "Конструктор копирования\t" <<  this <<std::endl;
	}
	Matrix(Matrix&& matrix)noexcept
	{
		this->matrix = matrix.matrix;
		this->rows = matrix.rows;
		this->cols = matrix.cols;
		for (int i = 0; i < rows; i++)
			matrix.matrix[i] = nullptr;
		matrix.matrix = nullptr;
		matrix.rows = 0;
		matrix.cols = 0;
		std::cout << "Конструктор перенома\t" << this <<std::endl;
	}

//Перегрузка операторов
	Matrix& operator=(const Matrix& matrix)
	{
		if (this == &matrix) return *this; //??
		for (int i = 0; i < rows; i++)
			delete[] this->matrix[i];
		delete[] this->matrix;
		rows = matrix.rows;
		cols = matrix.cols;
		this->matrix = Allocate(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = matrix[i][j];
		return *this;
	}
	Matrix& operator=(Matrix&& matrix)noexcept //Ругается на брейкпоинт
	{
		if (this == &matrix) return *this; //??
		for (int i = 0; i < rows; i++)
			delete[] this->matrix[i];
		delete[] this->matrix;
		this->matrix = matrix.matrix;
		rows = matrix.rows;
		cols = matrix.cols;
		for (int i = 0; i < rows; i++)
			matrix.matrix[i] = nullptr;
		matrix.matrix = nullptr;
		matrix.rows = 0;
		matrix.cols = 0;
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

//Деструктор
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		std::cout << "Деструктор\t\t\t" << this <<std::endl;
	}

};

//Перегрузка за классом
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
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = rand() % 10;
			}
		}
	}

void main()
{
	setlocale(LC_ALL, "ru");

	Matrix M1;
	std::cout << "Первая матрица:" << std::endl << M1 << std::endl;
	Matrix M2(3, 3);
	std::cout << "Вторая матрица:" << std::endl << M2 << std::endl;
	M2 = M1;
	std::cout << "Вторая матрица:" << std::endl << M2 << std::endl;
}