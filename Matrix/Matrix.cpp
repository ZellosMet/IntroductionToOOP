#include<iostream>

double** Allocate(const int rows, const int cols);
void Clear(double** matrix, const int rows);

class Matrix
{
	int rows;
	int cols;
	double** matrix;
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
	double** get_matrix()const
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
		//std::cout << "Конструктор поумолчанию\t\t" << this << std::endl;
	}
	Matrix(int size)
	{
		rows = cols = size;
		matrix = Allocate(rows, cols); 
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		matrix = Allocate(rows, cols); 
		//std::cout << "Конструктор с параметрами\t" << this << std::endl;

	}
	Matrix(const Matrix& matrix)
	{
		this->rows = matrix.get_rows();
		this->cols = matrix.get_cols();
		this->matrix = Allocate(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = matrix[i][j];
		//std::cout << "Конструктор копирования\t\t" << this <<std::endl;
	}
	Matrix(Matrix&& matrix)noexcept
	{
		this->matrix = matrix.matrix;
		this->rows = matrix.rows;
		this->cols = matrix.cols;
		matrix.matrix = nullptr;
		matrix.rows = 0;
		matrix.cols = 0;
		//std::cout << "Конструктор переноса\t\t" << this <<std::endl;
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
		//std::cout << "Оператор копирования" << std::endl;
		return *this;
	}
	Matrix& operator=(Matrix&& matrix)noexcept
	{
		if (this == &matrix) return *this;
		Clear(this->matrix, rows);
		this->matrix = matrix.matrix;
		rows = matrix.rows;
		cols = matrix.cols;
		matrix.matrix = nullptr;
		matrix.rows = 0;
		matrix.cols = 0;
		//std::cout << "Оператор перемещения\t\t" << std::endl;
		return *this;
	}
	Matrix& operator*=(int value)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				matrix[i][j] *= value;
		}
		return *this;
	}
	double* operator[](const int i)
	{
		return matrix[i];
	}
	const double* operator[](const int i)const
	{
		return matrix[i];
	}
//Методы
	void Negative()
	{	
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = -matrix[i][j];
	}
	void FillMatrix()
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 10;	
	}
	void InverseMatrix()
	{
		Matrix t_matrix(rows);
		double RE;
		for (int i = 0; i < t_matrix.rows; i++)
			for (int j = 0; j < t_matrix.rows; j++)
				if (i==j)
					t_matrix[i][j] = 1;

		for (int k = 0; k < rows; k++)
		{
			RE = matrix[k][k];
			for (int j = 0; j < rows; j++)
			{
				matrix[k][j] /= RE;
				t_matrix[k][j] /= RE;
			}
			for (int i = k+1; i < rows; i++)
			{
				RE = matrix[i][k];
				for (int j = 0; j < rows; j++)
				{
					matrix[i][j] -= matrix[k][j] * RE;
					t_matrix[i][j] -= t_matrix[k][j] * RE;
				}
			}
		}
		for (int k = rows-1; k > 0; k--)
		{
			for (int i = k - 1; i >= 0; i--)
			{
				RE = matrix[i][k];
				for (int j = 0; j < rows; j++)
				{
					matrix[i][j] -= matrix[k][j] * RE;
					t_matrix[i][j] -= t_matrix[k][j] * RE;
				}
			}
		}

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < rows; j++)
				matrix[i][j] = t_matrix[i][j];
	}
//Деструктор
	~Matrix() 
	{
		Clear(matrix, rows); //Моджно ли удалять через функцию??
		//std::cout << "Деструктор\t\t\t" << this <<std::endl;
	}

};

//Перегрузка за классом
Matrix operator+(Matrix& lvalue, Matrix& rvalue)
{
	Matrix Sub(lvalue.get_rows(), lvalue.get_cols());
	if (lvalue.get_rows() == rvalue.get_rows() && lvalue.get_cols() == rvalue.get_cols())
	{
		for (int i = 0; i < lvalue.get_rows(); i++)
			for (int j = 0; j < lvalue.get_cols(); j++)
				Sub[i][j] = lvalue[i][j] + rvalue[i][j];
		return Sub;
	}
	std::cout << "Невозможно расчитать матрицу" << std::endl;
	return Sub;
}
Matrix operator-(Matrix& lvalue, Matrix rvalue)
{
	rvalue.Negative();
	return lvalue + rvalue;
}
Matrix operator*(Matrix& lvalue, Matrix& rvalue)
{
	Matrix Mul(lvalue.get_rows(), rvalue.get_cols());
	if (lvalue.get_cols()==rvalue.get_rows())
	{
		for (int i = 0; i < lvalue.get_rows(); i++)
			for (int j = 0; j < rvalue.get_cols(); j++)
				for (int k =0; k < lvalue.get_cols(); k++)
					Mul[i][j] += lvalue[i][k] * rvalue[k][j];
		return Mul;
	}
	std::cout << "Невозможно расчитать матрицу" << std::endl;
	return Mul;
}
Matrix operator/(Matrix& lvalue, Matrix rvalue)
{
	if (rvalue.get_rows() == rvalue.get_cols())
	{
		rvalue.InverseMatrix();
		return lvalue * rvalue;
	}
	Matrix Div;
	std::cout << "Невозможно расчитать матрицу" << std::endl;
	return Div;
}
std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix.get_rows(); i++)
	{
		for (int j = 0; j < matrix.get_cols(); j++)
		{
			os << matrix[i][j] << " \t";
		}
		os << std::endl;
	}
	return os;
}

//Функции
double** Allocate(const int rows, const int cols)
{
	double** matrix = new double* [rows] {};
	for (int i = 0; i < rows; i++) 
		matrix[i] = new double[cols] {};
	return matrix;
}
void Clear(double** matrix, const int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void main()
{
	setlocale(LC_ALL, "ru");

	Matrix M1(3);
	M1.FillMatrix();
	std::cout << "Первая матрица:" << std::endl << M1 << std::endl;
	Matrix M2(3, 3);
	M2.FillMatrix();
	std::cout << "Вторая матрица:" << std::endl << M2 << std::endl;
	Matrix M3 = M1 + M2;
	std::cout << "Сумма матриц:" << std::endl << M3 << std::endl;
	Matrix M4;
	M4 = M1 - M2;
	std::cout << "Разность матрица:" << std::endl << M4 << std::endl;
	Matrix M5 = M1 * M2;
	std::cout << "Произведение матриц:" << std::endl << M5 << std::endl;
	Matrix M6;
	M6 = M1 / M2;
	std::cout << "Деление матриц:" << std::endl << M6 << std::endl;
}