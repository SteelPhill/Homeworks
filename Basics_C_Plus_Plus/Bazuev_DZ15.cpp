#include <iostream>
using namespace std;

template <typename TValue>
void ShowArray(TValue** arr, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
}

void FillTwoDimensionalArray(int** arr, int rows, int columns, int beginValue,int endValue)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			arr[i][j] = rand() % (endValue - beginValue + 1) + beginValue;
}


//				ЗАДАЧА №1
/*Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: 
пользователь вводит число (например, 3) первый элемент массива принимает значение
этого числа, последующий элемент массива принимает значение этого числа 
умноженного на 2 (т.е. 6 для нашего примера), третий 
элемент массива предыдущий элемент умноженный на 
2 (т.е. 6*2=12 для нашего примера). Созданный массив 
вывести на экран.*/

//void FillArray(int** arr, int rows, int columns, int value)
//{
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < columns; j++)
//		{
//			arr[i][j] = value;
//			value *= 2;
//		}
//}
//
//void main()
//{ 
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int rows;
//	cout << "Введите количество строк в массиве => ";
//	cin >> rows;
//	while (rows < 1)
//	{
//		cout << "Количество строк в массиве не может быть меньше 1 !" << endl;
//		cout << "Введите количество строк в массиве => ";
//		cin >> rows;
//	}
//	system("cls");
//	cout << "Количество строк в массиве: " << rows << endl;
//
//	int columns;
//	cout << "Введите количество столбцов в массиве => ";
//	cin >> columns;
//	while (columns < 1)
//	{
//		cout << "Количество столбцов в массиве не может быть меньше 1 !" << endl;
//		cout << "Введите количество столбцов в массиве => ";
//		cin >> columns;
//	}
//	system("cls");
//	cout << "Количество строк в массиве: " << rows << endl;
//	cout << "Количество столбцов в массиве: " << columns << endl;
//	cout << "Количество элементов в массиве: " << rows * columns << endl;
//
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//		arr[i] = new int[columns];
//
//	int startValue;
//	cout << "Введите значение для первого элемента в массиве => ";
//	cin >> startValue;
//	cout << endl;
//
//	FillArray(arr, rows, columns, startValue);
//	cout << "Заполненный двухмерный массив:" << endl;
//	ShowArray(arr, rows, columns);
//
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №2
/*Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: 
пользователь вводит число (например, 3) первый элемент 
массива принимает значение этого числа, последующий 
элемент массива принимает значение этого числа + 1 (т.е. 
4 для нашего примера), третий элемент массива предыдущий элемент + 1
(т.е. 5 для нашего примера). Созданный массив вывести на экран.*/

//void FillArray(int** arr, int rows, int columns, int value)
//{
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < columns; j++)
//		{
//			arr[i][j] = value;
//			value++;
//		}
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int rows;
//	cout << "Введите количество строк в массиве => ";
//	cin >> rows;
//	while (rows < 1)
//	{
//		cout << "Количество строк в массиве не может быть меньше 1 !" << endl;
//		cout << "Введите количество строк в массиве => ";
//		cin >> rows;
//	}
//	system("cls");
//	cout << "Количество строк в массиве: " << rows << endl;
//
//	int columns;
//	cout << "Введите количество столбцов в массиве => ";
//	cin >> columns;
//	while (columns < 1)
//	{
//		cout << "Количество столбцов в массиве не может быть меньше 1 !" << endl;
//		cout << "Введите количество столбцов в массиве => ";
//		cin >> columns;
//	}
//	system("cls");
//	cout << "Количество строк в массиве: " << rows << endl;
//	cout << "Количество столбцов в массиве: " << columns << endl;
//	cout << "Количество элементов в массиве: " << rows * columns << endl;
//
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//		arr[i] = new int[columns];
//
//	int startValue;
//	cout << "Введите значение для первого элемента в массиве => ";
//	cin >> startValue;
//	cout << endl;
//
//	FillArray(arr, rows, columns, startValue);
//	cout << "Заполненный двухмерный массив:" << endl;
//	ShowArray(arr, rows, columns);
//
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №3 
/*Создайте двухмерный массив. Заполните его 
случайными числами и покажите на экран. Пользователь 
выбирает количество сдвигов и положение (влево,
вправо, вверх, вниз). Выполнить сдвиг массива и показать на 
экран полученный результат. Сдвиг циклический. 
Например, если мы имеем следующий массив:
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы 
получим:
5 3 1 2 0 4
0 1 4 5 3 9.*/

//enum Direction {
//	Left = 1,
//	Right = 2,
//	Up = 3, 
//	Down = 4
//};
//
//void ShowMatrix(int** arr, int rows, int columns)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//			cout << arr[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
//}
//
//int ChoosingDirectionOfShifts()
//{
//	cout << "Выберите напрвление сдвига:" << endl;
//	cout << "\t1.Налево;" << endl;
//	cout << "\t2.Направо;" << endl;
//	cout << "\t3.Вверх;" << endl;
//	cout << "\t4.Вниз;" << endl;
//	int direction;
//	cout << "Введите номер пункта из списка => ";
//	cin >> direction;
//	while (direction < 1 || direction > 4)
//	{
//		cout << "Такого пункта в списке нет!" << endl;
//		cout << "Введите номер пункта из списка => ";
//		cin >> direction;
//	}
//	return direction;
//}
//
//int ChoosingNumberOfShifts()
//{
//	cout << "Введите количество сдвигов => ";
//	int quantity;
//	cin >> quantity;
//	while (quantity < 0)
//	{
//		cout << "Значение количества сдвигов не может быть отрицательным числом!" << endl;
//		cout << "Введите количество сдвигов => ";
//		cin >> quantity;
//	}
//	return quantity;
//}
//
//void ShiftToTheLeft(int** arr, int rows, int columns, int numberOfShifts)
//{
//	for (int i = 0; i < numberOfShifts; i++)
//		for (int j = 0; j < rows; j++)
//			for (int k = 0; k < columns - 1; k++)
//					swap(arr[j][k], arr[j][k + 1]);
//}
//
//void ShiftToTheRight(int** arr, int rows, int columns, int numberOfShifts)
//{
//	for (int i = 0; i < numberOfShifts; i++)
//		for (int j = 0; j < rows; j++)
//			for (int k = columns - 1; k > 0; k--)
//				swap(arr[j][k], arr[j][k - 1]);
//}
//
//void UpwardShift(int** arr, int rows, int columns, int numberOfShifts)
//{
//	for (int i = 0; i < numberOfShifts; i++)
//		for (int j = 0; j < columns; j++)
//			for (int k = 0; k < rows - 1; k++)
//				swap(arr[k][j], arr[k + 1][j]);
//}
//
//void DownwardShift(int** arr, int rows, int columns, int numberOfShifts)
//{
//	for (int i = 0; i < numberOfShifts; i++)
//		for (int j = 0; j < columns; j++)
//			for (int k = rows - 1; k > 0; k--)
//				swap(arr[k][j], arr[k - 1][j]);
//}
//
//void ShiftingArray(int** arr, int rows, int columns)
//{
//	int direction = ChoosingDirectionOfShifts();
//	int quantity = ChoosingNumberOfShifts();
//	system("cls");
//	cout << "Изначальный двухмерный массив:" << endl;
//	ShowMatrix(arr, rows, columns);
//	cout << "Количество сдвигов: " << quantity << endl;
//	cout << "Напрвление сдвига: ";
//	switch (direction)
//	{
//	case Direction::Left:
//	{
//		cout << "налево." << endl;
//		ShiftToTheLeft(arr, rows, columns, quantity);
//		break;
//	}
//	case Direction::Right:
//	{
//		cout << "направо." << endl;
//		ShiftToTheRight(arr, rows, columns, quantity);
//		break;
//	}
//	case Direction::Up:
//	{
//		cout << "вверх." << endl;
//		UpwardShift(arr, rows, columns, quantity);
//		break;
//	}
//	case Direction::Down:
//	{
//		cout << "вниз." << endl;
//		DownwardShift(arr, rows, columns, quantity);
//		break;
//	}
//	default:
//		return;
//	}
//	cout << endl;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int rows;
//	cout << "Введите количество строк в массиве => ";
//	cin >> rows;
//	while (rows < 1)
//	{
//		cout << "Количество строк в массиве не может быть меньше 1 !" << endl;
//		cout << "Введите количество строк в массиве => ";
//		cin >> rows;
//	}
//	system("cls");
//	cout << "Количество строк в массиве: " << rows << endl;
//
//	int columns;
//	cout << "Введите количество столбцов в массиве => ";
//	cin >> columns;
//	while (columns < 1)
//	{
//		cout << "Количество столбцов в массиве не может быть меньше 1 !" << endl;
//		cout << "Введите количество столбцов в массиве => ";
//		cin >> columns;
//	}
//	system("cls");
//	cout << "Количество строк в массиве: " << rows << endl;
//	cout << "Количество столбцов в массиве: " << columns << endl;
//	cout << endl;
//
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; i++)
//		arr[i] = new int[columns];
//
//	FillTwoDimensionalArray(arr, rows, columns, 10, 99);
//	cout << "Изначальный двухмерный массив:" << endl;
//	ShowMatrix(arr, rows, columns);
//
//	ShiftingArray(arr, rows, columns);
//
//	cout << "Двухмерный массив после сдвига:" << endl;
//	ShowMatrix(arr, rows, columns);
//
//	cout << endl;
//	system("pause");
//}