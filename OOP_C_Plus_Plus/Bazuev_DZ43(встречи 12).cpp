#include <iostream>
#include <string>
#include <span>
#include <iomanip>
#include <functional>
using namespace std;


//			ВСТРЕЧА №12 (Решил не писать перегрузки арифметических операторов для short, long long, float и т.п., так как код в них не поменяется)

/*Создайте шаблонный класс матрица. Необходимо реализовать динамическое выделение памяти,
очистку памяти, заполнение матрицы с клавиатуры, заполнение случайными значениями,
отображение матрицы, арифметические операции с помощью перегруженных операторов
(+, –, *, /), поиск максимального и минимального элемента. */

template <typename TValue>
class Matrix
{
	TValue** matrix;
	int rows;
	int columns;

	bool IsEmpty() const
	{
		return matrix == nullptr;
	}

	TValue FindDeterminant() const
	{
		if (IsEmpty())
			return 0;

		if (!IsSquareMatrix())
			return 0;

		TValue mainDiagonalSum = 0;
		TValue sideDiagonalSum = 0;

		TValue temp;

		for (int k = 0; k < rows; k++)
		{
			temp = 1;

			for (int i = 0, j = k; i < rows; i++, j++)
				temp *= matrix[i][j % columns];

			mainDiagonalSum += temp;
		}

		for (int k = 0; k < rows; k++)
		{
			temp = 1;

			for (int i = rows - 1, j = k; i >= 0; i--, j++)
				temp *= matrix[i][j % columns];

			sideDiagonalSum += temp;
		}

		return mainDiagonalSum - sideDiagonalSum;
	}

	Matrix Inverse() const
	{
		if (IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!IsSquareMatrix())
			return Matrix(nullptr, 0, 0);

		TValue determinant = FindDeterminant();

		if (determinant == 0)
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, columns);

		TValue temp;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
			{
				temp = 0;

				result.matrix[i][j] = matrix[(j + 1) % rows][(i + 1) % columns] *
					matrix[(j + 2) % rows][(i + 2) % columns];

				temp = matrix[(j + 1) % rows][(i + 2) % columns] *
					matrix[(j + 2) % rows][(i + 1) % columns];

				result.matrix[i][j] = (result.matrix[i][j] - temp) / determinant;
			}

		return result;
	}

	int LargestSizeElementInStringArray(const string* arr, const int size) const
	{
		int result = 0;

		for (int i = 0; i < size; i++)
			if (result < arr[i].size())
				result = arr[i].size();

		return result;
	}

	string* ToStringArray(string* arr) const
	{
		if (IsEmpty())
			return nullptr;

		int k = 0;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				arr[k++] = to_string(matrix[i][j]);

		return arr;
	}

public:
	Matrix<TValue>() : Matrix(nullptr, 0, 0)
	{
	}

	Matrix<TValue>(const int rows, const int columns) : Matrix(rows, columns, 0)
	{
	}

	Matrix(const int rows, const int columns, const TValue value)
	{
		this->rows = rows;
		this->columns = columns;

		matrix = new TValue * [rows];

		for (int i = 0; i < rows; i++)
			matrix[i] = new TValue[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] = value;
	}

	Matrix(TValue* pointerToMatrix[], const int rows, const int columns)
	{
		if (pointerToMatrix == nullptr)
		{
			matrix = nullptr;
			this->rows = 0;
			this->columns = 0;
			return;
		}

		matrix = new TValue * [rows];

		for (int i = 0; i < rows; i++)
			matrix[i] = new TValue[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] = pointerToMatrix[i][j];

		this->rows = rows;
		this->columns = columns;
	}

	Matrix(const Matrix& other)
	{
		if (other.IsEmpty())
		{
			matrix = nullptr;
			rows = 0;
			columns = 0;
			return;
		}

		rows = other.rows;
		columns = other.columns;

		matrix = new TValue * [rows];

		for (int i = 0; i < rows; i++)
			matrix[i] = new TValue[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] = other.matrix[i][j];
	}

	Matrix(Matrix&& other)
	{
		if (this == &other)
			return;

		if (other.IsEmpty())
		{
			matrix = nullptr;
			rows = 0;
			columns = 0;
			return;
		}

		matrix = other.matrix;
		rows = other.rows;
		columns = other.columns;

		other.matrix = nullptr;
	}

	~Matrix()
	{
		if (!IsEmpty())
		{
			for (int i = 0; i < rows; i++)
				delete[] matrix[i];

			delete[] matrix;
		}
	}

	TValue** GetMatrix() const { return matrix; }
	int GetRows() const { return rows; }
	int GetColumns() const { return columns; }

	bool IsSquareMatrix() const
	{
		return rows == columns;
	}

	bool IsMatrixesSizesEqual(const Matrix& other) const
	{
		return rows == other.rows && columns == other.columns;
	}

	void AddElementByIndexes(const int rowIndex, const int columnIndex, const TValue newValue) const
	{
		if (rowIndex < 0 || rowIndex >= rows || columnIndex < 0 || columnIndex >= columns)
			return;

		matrix[rowIndex][columnIndex] = newValue;
	}

	Matrix& operator=(const Matrix& other)
	{
		if (other.IsEmpty())
		{
			matrix = nullptr;
			rows = 0;
			columns = 0;
			return *this;
		}

		rows = other.rows;
		columns = other.columns;

		matrix = new TValue * [rows];

		for (int i = 0; i < rows; i++)
			matrix[i] = new TValue[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] = other.matrix[i][j];

		return *this;
	}

	Matrix& operator=(Matrix&& other)
	{
		if (this == &other)
			return *this;

		if (other.IsEmpty())
		{
			matrix = nullptr;
			rows = 0;
			columns = 0;
			return *this;
		}

		matrix = other.matrix;
		rows = other.rows;
		columns = other.columns;

		other.matrix = nullptr;

		return *this;
	}

	Matrix operator+(const Matrix<int>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!IsMatrixesSizesEqual(right))
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, columns);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];

		return result;
	}

	Matrix operator+(const Matrix<double>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!IsMatrixesSizesEqual(right))
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, columns);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result.matrix[i][j] = matrix[i][j] + right.matrix[i][j];

		return result;
	}

	Matrix operator-(const Matrix<int>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!IsMatrixesSizesEqual(right))
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, columns);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result.matrix[i][j] = matrix[i][j] - right.matrix[i][j];

		return result;
	}

	Matrix operator-(const Matrix<double>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!IsMatrixesSizesEqual(right))
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, columns);

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result.matrix[i][j] = matrix[i][j] - right.matrix[i][j];

		return result;
	}

	Matrix operator*(const Matrix<int>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (columns != right.rows)
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, right.columns);

		for (int i = 0; i < result.rows; i++)
			for (int j = 0; j < result.columns; j++)
				for (int k = 0; k < columns; k++)
					result.matrix[i][j] += matrix[i][k] * right.matrix[k][j];

		return result;
	}

	Matrix operator*(const Matrix<double>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (columns != right.rows)
			return Matrix(nullptr, 0, 0);

		Matrix<TValue> result(rows, right.columns);

		for (int i = 0; i < result.rows; i++)
			for (int j = 0; j < result.columns; j++)
				for (int k = 0; k < columns; k++)
					result.matrix[i][j] += matrix[i][k] * right.matrix[k][j];

		return result;
	}

	Matrix operator/(const Matrix<int>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!right.IsSquareMatrix())
			return Matrix(nullptr, 0, 0);

		Matrix invertedRight = right.Inverse();

		return *this * invertedRight;
	}

	Matrix operator/(const Matrix<double>& right) const
	{
		if (IsEmpty() || right.IsEmpty())
			return Matrix(nullptr, 0, 0);

		if (!right.IsSquareMatrix())
			return Matrix(nullptr, 0, 0);

		Matrix invertedRight = right.Inverse();

		return *this * invertedRight;
	}

	TValue Min(const function<TValue(const TValue, const TValue)> action) const
	{
		if (IsEmpty())
			return 0;

		TValue result = matrix[0][0];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result = action(matrix[i][j], result);

		return result;
	}

	TValue Max(const function<TValue(const TValue, const TValue)> action) const
	{
		if (IsEmpty())
			return 0;

		TValue result = matrix[0][0];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result = action(matrix[i][j], result);

		return result;
	}

	void Random(const function<TValue()> action)
	{
		if (IsEmpty())
			return;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				matrix[i][j] = action();
	}

	void Show(const function<TValue(TValue**, const int, const int)> action) const
	{
		if (IsEmpty())
			return;

		const int charactersNumberAfterDot = 2;

		string* matrixToStringArray = new string[rows * columns];
		ToStringArray(matrixToStringArray);
		int largestSizeElement = LargestSizeElementInStringArray(matrixToStringArray, rows * columns);
		delete[] matrixToStringArray;
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				cout << "|" << left << setw(largestSizeElement) << fixed << setprecision(charactersNumberAfterDot) << action(matrix, i, j);
			cout << endl;
		}
	}

	void Input(const function<void(TValue**, int, int)> action)
	{
		if (IsEmpty())
			return;

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				action(matrix, i, j);
	}

	friend ostream& operator<<(ostream& output, const Matrix& matrix)
	{
		if (matrix.IsEmpty())
			return output;

		const int charactersNumberAfterDot = 2;

		string* matrixToStringArray = new string[matrix.GetRows() * matrix.GetColumns()];
		matrix.ToStringArray(matrixToStringArray);
		int largestSizeElement = matrix.LargestSizeElementInStringArray(matrixToStringArray, matrix.GetRows() * matrix.GetColumns());
		delete[] matrixToStringArray;

		for (int i = 0; i < matrix.GetRows(); i++)
		{
			for (const TValue& j : span(matrix.GetMatrix()[i], matrix.GetMatrix()[i] + matrix.GetColumns()))
				output << "|"  << left << setw(largestSizeElement) << fixed << setprecision(charactersNumberAfterDot)  << j;
			output << endl;
		}

		return output;
	}

	friend istream& operator>>(istream& input, Matrix& matrix)
	{
		if (matrix.GetMatrix() == nullptr)
			return input;

		TValue temp;

		for (int i = 0; i < matrix.GetRows(); i++)
			for (int j = 0; j < matrix.GetColumns(); j++)
			{
				input >> temp;
				matrix.AddElementByIndexes(i, j, temp);
			}

		return input;
	}
};

void main()
{
	//system("color 0A");
	srand(time(0));

	const int rows1 = 3;
	const int columns1 = 3;
	const int rows2 = 3;
	const int columns2 = 3;

	double twoDimensionalArray1[rows1][columns1] = { {100.4,1.1,3.3}, {4.4,5.5,6.6}, {7.7,8.8,9.9} };
	double* pointerToMatrix1[rows1];
	for (int i = 0; i < rows1; i++)
		pointerToMatrix1[i] = twoDimensionalArray1[i];
	Matrix matrix1(pointerToMatrix1, rows1, columns1);

	cout << "Matrix 1:" << endl << matrix1 << endl;

	Matrix<double> matrix2(rows2, columns2);;
	matrix2.Random([]() { return (rand() % 100) / 10.0; });

	cout << "Matrix 2:" << endl;
	matrix2.Show([](double** matrix, int row, int column) { return matrix[row][column]; });
	cout << endl;

	/*cout << "Input new matrix 1:" << endl;
	matrix1.Input([](double** matrix, int row, int column) -> void { cin >> matrix[row][column]; });
	cout << endl << "New matrix 1:" << endl << matrix1 << endl;*/

	/*cout << "Input new matrix 1:" << endl;
	cin >> matrix1;
	cout << endl << "New matrix 1:" << endl << matrix1 << endl;*/

	matrix1.AddElementByIndexes(0, 0, 99.99);
	cout << "Matrix 1 After add:" << endl << matrix1 << endl;

	cout << "Min in matrix 1: " << matrix1.Min([](double a, double b) { return min(a, b); }) << endl;
	cout << "Max in matrix 1: " << matrix1.Max([](double a, double b) { return max(a, b); }) << endl;

	cout << endl;

	if (matrix1.IsMatrixesSizesEqual(matrix2))
		cout << "Size matrix 1 == size matrix 2" << endl;
	else
		cout << "Size matrix 1 != size matrix 2" << endl;

	cout << endl;

	if (matrix1.IsSquareMatrix())
		cout << "matrix 1 - square" << endl;
	else
		cout << "matrix 1 - !square" << endl;

	if (matrix2.IsSquareMatrix())
		cout << "matrix 2 - square" << endl;
	else
		cout << "matrix 2 - !square" << endl;

	cout << endl;

	Matrix <double>result = matrix1 + matrix2;
	cout << "Operator+ test:" << endl << result << endl;

	result = matrix1 - matrix2;
	cout << "Operator- test:" << endl << result << endl;

	result = matrix1 * matrix2;
	cout << "Operator* test:" << endl << result << endl;

	result = matrix1 / matrix2;
	cout << "Operator/ test:" << endl << result << endl;

	system("pause");
}