#include <iostream>
#include <span>
#include <iomanip>
using namespace std;

template <typename TValue>
void FillOneDimensionalArray(TValue* arr, const int size, const int beginRange, const int endRange)
{
	for (int i = 0; i < size; i++)
		*(arr + i) = rand() % (endRange - beginRange + 1) + beginRange;
}

void FillOneDimensionalArray(double* arr, const int size, int beginRange, int endRange)
{
	beginRange *= 10;
	endRange *= 10;

	for (int i = 0; i < size; i++)
		*(arr + i) = (rand() % (endRange - beginRange + 1) + beginRange) / 10.0;
}

template <typename TValue>
void FillMatrix(TValue** arr, const int rows, const int columns, const int beginRange, const int endRange)
{
	for (int i = 0; i < rows; i++)
		FillOneDimensionalArray(*(arr + i), columns, beginRange, endRange);	
}

template <typename TValue>
void ShowOneDimensionalArray(TValue* arr, const int size)
{
	for (TValue i : span(arr, size))
		cout << i << " ";
	cout << endl;
}

void ShowOneDimensionalArray(double* arr, const int size)
{
	for (double i : span(arr, size))
		cout << fixed << setprecision(1) << i << " ";
	cout << endl;
}

template <typename TValue>
void ShowMatrix(TValue** arr, const int rows, const int columns)
{
	for (TValue* i : span(arr, rows))
		ShowOneDimensionalArray(i, columns);
	cout << endl;
}


//			ЗАДАЧА №1

/*Написать функцию, добавляющую столбец 
двухмерному массиву в указанную позицию.*/

//template <typename TValue>
//TValue** AddColumn(TValue **sourceArr, int& rows, int& columns, int& position)
//{
//	TValue** newArr = new TValue * [rows];
//	for (int i = 0; i < rows; i++)
//		*(newArr + i) = new TValue[columns + 1];
//	
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < position; j++)
//			newArr[i][j] = sourceArr[i][j];
//
//		newArr[i][position] = 0;
//
//		for (int j = position; j < columns; j++)
//			newArr[i][j + 1] = sourceArr[i][j];
//	}
//
//	columns++;
//
//	for (int i = 0; i < rows; i++)
//		delete[] * (sourceArr + i);
//	delete[] sourceArr;
//
//	sourceArr = newArr;
//
//	return newArr;
//}
//
//void main()
//{
//	const int BeginRange = 10;
//	const int EndRange = 99;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int rows = 4;
//	int columns = 4;
//
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//		*(arr + i) = new int[columns];
//
//	FillMatrix(arr, rows, columns, BeginRange, EndRange);
//	cout << "Исходный двумерный массив: " << endl;
//	ShowMatrix(arr, rows, columns);
//
//	int position;
//	do
//	{
//		cout << "Введите индекс нового столбца => ";
//		cin >> position;
//		cout << endl;
// 
//		if (position < 0 || position > rows)
//			cout << "Введенный индекс остуствует в массиве. Повторите ввод. " << endl;
//
//	} while (position < 0 || position > rows);
//
//	arr = AddColumn(arr, rows, columns, position);
//
//	cout << "Двумерный массив после добавления столбца: " << endl;
//	ShowMatrix(arr, rows, columns);
//
//	for (int i = 0; i < rows; i++)
//		delete[] * (arr + i);
//	delete[] arr;
//
//	system("pause");
//}


//			ЗАДАЧА №2

/*Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.*/

//template <typename TValue>
//TValue** RemoveColumn(TValue** sourceArr, int& rows, int& columns, int& position)
//{
//	TValue** newArr = new TValue * [rows];
//	for (int i = 0; i < rows; i++)
//		*(newArr + i) = new TValue[columns - 1];
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < position; j++)
//			newArr[i][j] = sourceArr[i][j];
//
//		for (int j = position; j < columns; j++)
//			newArr[i][j] = sourceArr[i][j + 1];
//	}
//
//	columns--;
//
//	for (int i = 0; i < rows; i++)
//		delete[] * (sourceArr + i);
//	delete[] sourceArr;
//
//	sourceArr = newArr;
//
//	return newArr;
//}
//
//void main()
//{
//	const int BeginRange = 10;
//	const int EndRange = 99;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int rows = 4;
//	int columns = 4;
//
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//		*(arr + i) = new int[columns];
//
//	FillMatrix(arr, rows, columns, BeginRange, EndRange);
//	cout << "Исходный двумерный массив: " << endl;
//	ShowMatrix(arr, rows, columns);
//
//	int position;
//	do
//	{
//		cout << "Введите индекс столбца, для его удаления => ";
//		cin >> position;
//		cout << endl;
//
//		if (position < 0 || position > (rows - 1))
//			cout << "Введенный индекс остуствует в массиве. Повторите ввод. " << endl;
//
//	} while (position < 0 || position > (rows - 1));
//
//	arr = RemoveColumn(arr, rows, columns, position);
//
//	cout << "Двумерный массив после удаления столбца: " << endl;
//	ShowMatrix(arr, rows, columns);
//
//	for (int i = 0; i < rows; i++)
//		delete[] * (arr + i);
//	delete[] arr;
//
//	system("pause");
//}


//			ЗАДАЧА №3

/*Дана матрица порядка MхN (M строк, N столбцов).
Необходимо заполнить ее значениями и написать 
функцию, осуществляющую циклический сдвиг строк 
и/или столбцов массива указанное количество раз и
в указанную сторону.*/

//struct Shift
//{
//	int Quantity;
//	int Direction;
//};
//
//struct Matrix
//{
//	int** arr;
//	int Rows;
//	int Columns;
//	Shift ShiftRows;
//	Shift ShiftColumns;
//};
//
//bool IsRowsNotShift(Matrix& matrix)
//{
//	return matrix.ShiftRows.Direction == 0 || matrix.ShiftRows.Quantity == 0;
//}
//
//bool IsColumnsNotShift(Matrix& matrix)
//{
//	return matrix.ShiftColumns.Direction == 0 || matrix.ShiftColumns.Quantity == 0;
//}
//
//void ShowMatrixAndShiftParameters(Matrix& matrix)
//{
//	cout << "Количество строк в матрице: " << matrix.Rows << endl;
//	cout << "Количество столбцов в матрице: " << matrix.Columns << endl;
//	cout << endl;
//
//	if (IsRowsNotShift(matrix))
//		cout << "Сдвиг строк отсутствует." << endl;
//
//	else if (matrix.ShiftRows.Direction == 1)
//	{
//		cout << "Направление сдвига строк: вниз" << endl;
//		cout << "Количество сдвигов строк: " << matrix.ShiftRows.Quantity << endl;
//	}
//	else if (matrix.ShiftRows.Direction == 2)
//	{
//		cout << "Направление сдвига строк: вверх" << endl;
//		cout << "Количество сдвигов строк: " << matrix.ShiftRows.Quantity << endl;
//	}
//
//	cout << endl;
//
//	if (IsColumnsNotShift(matrix))
//		cout << "Сдвиг столбцов отсутствует." << endl;
//
//	else if (matrix.ShiftColumns.Direction == 1)
//	{
//		cout << "Направление сдвига столбцов: влево" << endl;
//		cout << "Количество сдвигов столбцов: " << matrix.ShiftColumns.Quantity << endl;
//	}
//	else if (matrix.ShiftColumns.Direction == 2)
//	{
//		cout << "Направление сдвига столбцов: вправо" << endl;
//		cout << "Количество сдвигов столбцов: " << matrix.ShiftColumns.Quantity << endl;
//	}
//
//	cout << endl;
//}
//
//void EnterSizeMatrix(Matrix& matrix)
//{
//	do
//	{
//		cout << "Введите количество строк в матрице => ";
//		cin >> matrix.Rows;
//		if (matrix.Rows < 1)
//			cout << "Количество строк не может быть меньше 1! Повторите выбор." << endl;
//	} while (matrix.Rows < 1);
//
//	do
//	{
//		cout << "Введите количество столбцов в матрице => ";
//		cin >> matrix.Columns;
//		if (matrix.Columns < 1)
//			cout << "Количество столбцов не может быть меньше 1! Повторите выбор." << endl;
//	} while (matrix.Columns < 1);
//
//	cout << endl;
//}
//
//void EnterShiftParameters(Matrix& matrix)
//{
//	do
//	{
//		cout << "Варианты сдвига строк:" << endl;
//		cout << "1. Сдвиг вниз;" << endl;
//		cout << "2. Сдвиг вверх;" << endl;
//		cout << "0. Без сдвига строк." << endl;
//		cout << "Выберите код сдвига строк => ";
//		cin >> matrix.ShiftRows.Direction;
//		if (matrix.ShiftRows.Direction < 0 || matrix.ShiftRows.Direction > 2)
//			cout << endl << "Неверный код! Повторите выбор." << endl;
//
//	} while (matrix.ShiftRows.Direction < 0 || matrix.ShiftRows.Direction > 2);
//
//	cout << endl;
//
//	do
//	{
//		cout << "Введите количество сдвигов строк => ";
//		cin >> matrix.ShiftRows.Quantity;
//
//		if (matrix.ShiftRows.Quantity < 0)
//			cout << endl << "Число сдвигов не может быть отрицательным! Повторите выбор." << endl;
//
//	} while (matrix.ShiftRows.Quantity < 0);
//
//	cout << endl;
//
//	do
//	{
//		cout << "Варианты сдвига столбцов:" << endl;
//		cout << "1. Сдвиг влево;" << endl;
//		cout << "2. Сдвиг вправо;" << endl;
//		cout << "0. Без сдвига столбцов." << endl;
//		cout << "Выберите код сдвига столбцов => ";
//		cin >> matrix.ShiftColumns.Direction;
//
//		if (matrix.ShiftColumns.Direction < 0 || matrix.ShiftColumns.Direction > 2)
//			cout << endl << "Неверный код! Повторите выбор." << endl;
//
//	} while (matrix.ShiftColumns.Direction < 0 || matrix.ShiftColumns.Direction > 2);
//
//	cout << endl;
//
//	do
//	{
//		cout << "Введите количество сдвигов столбцов => ";
//		cin >> matrix.ShiftColumns.Quantity;
//
//		if (matrix.ShiftColumns.Quantity < 0)
//			cout << endl << "Число сдвигов не может быть отрицательным! Повторите выбор." << endl;
//
//	} while (matrix.ShiftColumns.Quantity < 0);
//
//	cout << endl;;
//	system("pause");
//	system("cls");
//}
//
//void ShiftMatrixDown(Matrix& matrix)
//{
//	for (int i = 0; i < matrix.ShiftRows.Quantity; i++)
//		for (int j = matrix.Rows - 1; j > 0; j--)
//			for (int k = 0; k < matrix.Columns; k++)
//				swap(matrix.arr[j - 1][k], matrix.arr[j][k]);
//}
//
//void ShiftMatrixUp(Matrix& matrix)
//{
//	for (int i = 0; i < matrix.ShiftRows.Quantity; i++)
//		for (int j = 1; j < matrix.Rows; j++)
//			for (int k = 0; k < matrix.Columns; k++)
//				swap(matrix.arr[j - 1][k], matrix.arr[j][k]);
//}
//
//void ShiftMatrixLeft(Matrix& matrix)
//{
//	for (int i = 0; i < matrix.ShiftColumns.Quantity; i++)
//		for (int j = 0; j < matrix.Rows; j++)
//			for (int k = 1; k < matrix.Columns; k++)
//				swap(matrix.arr[j][k - 1], matrix.arr[j][k]);
//}
//
//void ShiftMatrixRight(Matrix& matrix)
//{
//	for (int i = 0; i < matrix.ShiftColumns.Quantity; i++)
//		for (int j = 0; j < matrix.Rows; j++)
//			for (int k = matrix.Columns - 1; k > 0; k--)
//				swap(matrix.arr[j][k - 1], matrix.arr[j][k]);
//}
//
//void ShiftingMatrix(Matrix& matrix)
//{
//	if (matrix.ShiftRows.Direction == 1)
//		ShiftMatrixDown(matrix);
//	else if (matrix.ShiftRows.Direction == 2)
//		ShiftMatrixUp(matrix);
//
//	if (matrix.ShiftColumns.Direction == 1)
//		ShiftMatrixLeft(matrix);
//	else if (matrix.ShiftColumns.Direction == 2)
//		ShiftMatrixRight(matrix);
//}
//
//void main()
//{
//	const int BeginRange = 10;
//	const int EndRange = 99;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	Matrix matrix;
//
//	EnterSizeMatrix(matrix);
//
//	matrix.arr = new int* [matrix.Rows];
//	for (int i = 0; i < matrix.Rows; i++)
//		*(matrix.arr + i) = new int[matrix.Columns];
//
//	FillMatrix(matrix.arr, matrix.Rows, matrix.Columns, BeginRange, EndRange);
//	cout << "Исходная матрица: " << endl;
//	ShowMatrix(matrix.arr, matrix.Rows, matrix.Columns);
//
//	EnterShiftParameters(matrix);
//
//	ShowMatrixAndShiftParameters(matrix);
//
//	cout << "Исходная матрица: " << endl;
//	ShowMatrix(matrix.arr, matrix.Rows, matrix.Columns);
//
//	if (IsRowsNotShift(matrix) && IsColumnsNotShift(matrix))
//		cout << "Сдвига матрицы не произошло." << endl << endl;
//	else
//	{
//		ShiftingMatrix(matrix);
//
//		cout << "Матрица после сдвига: " << endl;
//		ShowMatrix(matrix.arr, matrix.Rows, matrix.Columns);
//	}
//
//	for (int i = 0; i < matrix.Rows; i++)
//		delete[] * (matrix.arr + i);
//	delete[] matrix.arr;
//
//	system("pause");
//}