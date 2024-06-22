#include <iostream>
#include <span>
#include <iomanip>
using namespace std;

template<typename TValue>
void ShowOneDimensionalArray(TValue* arr, int size)
{
	for (int i : span(arr, size))
		cout << (TValue)i << " ";
	cout << endl;
}

void ShowTwoDimensionalArray(int arr[][4], int rows, int columns)
{
	for (int* i : span(arr, rows))
		ShowOneDimensionalArray(i, columns);
	cout << endl;
}

void ShowTwoDimensionalArray(char arr[][4], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		ShowOneDimensionalArray(arr[i], columns);
	cout << endl;
}

void ShowTwoDimensionalArray(double arr[][4], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << fixed << setprecision(1) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}

void FillingTwoDimensionalArray(double arr[][4], int rows, int columns, int beginValue, int endValue)
{
	beginValue *= 10;
	endValue *= 10;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			arr[i][j] = (rand() % (endValue - beginValue + 1) + beginValue) / 10.0;
}

template<typename TValue>
void FillingTwoDimensionalArray(TValue arr[][4], int rows, int columns, int beginValue, int endValue)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			arr[i][j] = rand() % (endValue - beginValue + 1) + beginValue;
}


//			ЗАДАЧА №1
/*Написать перегруженные функции (int, double, 
char) для выполнения следующих задач:
- Инициализация квадратной матрицы;
- Вывод матрицы на экран;
- Определениемаксимального иминимального элемента 
на главной диагонали матрицы;
- Сортировка элементов по возрастанию отдельно для 
каждой строки матрицы.*/

//template<typename TValue>
//void MinAndMaxElementsOnMainDiagonal(TValue arr[][4], int rows, int columns)
//{
//	TValue min = arr[0][0];
//	TValue max = arr[0][0];
//
//	for (int i = 1, j = 1; (i < rows && j < columns); i++, j++)
//	{
//		if (arr[i][j] < min)
//			min = arr[i][j];
//		if (arr[i][j] > max)
//			max = arr[i][j];
//	}
//
//	cout << "Минимальный элемент на главной диагонали матрицы: " << min << endl;
//	cout << "Максимальный элемент на главной диагонали матрицы: " << max << endl;
//	cout << endl;
//}
//
//template<typename TValue>
//void QuickSortingOfEachRowOfMatrix(TValue* arr, int begin, int end)
//{
//	if (begin > end)
//		return;
//
//	int i = begin;
//	int j = end;
//	TValue key = arr[(begin + end) / 2];
//
//	do
//	{
//		while (arr[i] < key)
//			i++;
//		while (arr[j] > key)
//			j--;
//
//		if (i <= j)
//		{
//			swap(arr[i], arr[j]);
//			i++;
//			j--;
//		}
//
//	} while (i <= j);
//
//	QuickSortingOfEachRowOfMatrix(arr, begin, j);
//	QuickSortingOfEachRowOfMatrix(arr, i, end);
//}
//
//template<typename TValue>
//void SortingMatrix(TValue arr[][4], int rows, int columns)
//{
//	for (int i = 0; i < rows; i++)
//		QuickSortingOfEachRowOfMatrix(arr[i], 0, columns - 1);
//}
//
//void main()
//{
//	const int beginValue = 65;
//	const int endValue = 90;
//	const int rows = 4;
//	const int columns = 4;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	cout << "Матрица типа int:" << endl;
//	int arr[rows][columns];
//
//	/*cout << "Матрица типа char:" << endl;
//	char arr[rows][columns];*/
//
//	/*cout << "Матрица типа double:" << endl;
//	double arr[rows][columns];*/
//
//	FillingTwoDimensionalArray(arr, rows, columns, beginValue, endValue);
//
//	ShowTwoDimensionalArray(arr, rows, columns);
//
//	MinAndMaxElementsOnMainDiagonal(arr, rows, columns);
//
//	cout << "Матрица после сортировки:" << endl;
//	SortingMatrix(arr, rows, columns);
//	ShowTwoDimensionalArray(arr, rows, columns);
//
//	system("pause");
//}


//			ЗАДАЧА №2
/*Написать рекурсивную функцию нахождения 
наибольшего общего делителя двух целых чисел.*/

//bool CheckingWhetherDividerIsCommon(int firstValue, int secondValue, int commonDivisor)
//{
//	return firstValue % commonDivisor == 0 && secondValue % commonDivisor == 0;
//}
//
//int FindingLargestCommonDivisorOfTwoNumbers(int firstValue, int secondValue, int commonDivisor)
//{
//	if (CheckingWhetherDividerIsCommon(firstValue, secondValue, commonDivisor))
//		return commonDivisor;
//
//	return FindingLargestCommonDivisorOfTwoNumbers(firstValue, secondValue, --commonDivisor);
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	cout << "\tНахождение наибольшего общего делителя двух целых чисел." << endl;
//	cout << endl;
//
//	int firstValue;
//	cout << "Введите первое число => ";
//	cin >> firstValue;
//
//	int secondValue;
//	cout << "Введите второе число => ";
//	cin >> secondValue;
//	cout << endl;
//
//	cout << "Наибольший общий делитель введенных чисел: " << FindingLargestCommonDivisorOfTwoNumbers(firstValue, secondValue, min(abs(firstValue), abs(secondValue))) << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3
/*Написать игру «Быки и коровы». Программа 
«загадывает» четырёхзначное число и играющий должен 
угадать его. После ввода пользователем числа программа 
сообщает, сколько цифр числа угадано (быки) и сколько 
цифр угадано и стоит на нужном месте (коровы). После 
отгадывания числа на экран необходимо вывести количество 
сделанных пользователем попыток. В программе 
необходимо использовать рекурсию.*/

//int CreatingRandomFourDigitNumber()
//{
//	const int minValue = 1000;
//	const int maxValue = 9999;
//
//	return rand() % (maxValue - minValue + 1) + minValue;
//}
//
//void RulesOfGame()
//{
//	cout << "\t\tИгра \"Быки и коровы\"." << endl;
//	cout << endl;
//	cout << "Правила игры:" << endl;
//	cout << endl;
//	cout << "1) Отгадайте четырехзначное, положительное число, загаданное игрой, за наименьшее количество попыток." << endl;
//	cout << "2) После каждой попытки игра даёт подсказку, сколько цифр угадано (быки) и " << endl;
//	cout << "   сколько цифр угадано и стоит на нужном месте (коровы)." << endl;
//	cout << endl;
//}
//
//void ChekingCows(int hiddenNumber, int value, int cows)
//{
//	if (hiddenNumber == 0 || value == 0)
//	{
//		cout << "Коров: " << cows << endl;
//		return;
//	}
//
//	if (hiddenNumber % 10 == value % 10)
//		cows++;
//
//	return ChekingCows(hiddenNumber / 10, value / 10, cows);
//}
//
//void ChekingBulls(int hiddenNumber, int value, int bulls)
//{
//	if (hiddenNumber == 0)
//	{
//		cout << "Быков: " << bulls << endl;
//		return;
//	}
//
//	for (int i = value; i > 0; i /= 10)
//		if (hiddenNumber % 10 == i % 10)
//		{
//			bulls++;
//			break;
//		}
//
//	return ChekingBulls(hiddenNumber / 10, value, bulls);
//}
//
//bool CheckingEnteredValue(int value)
//{
//	const int minValue = 1000;
//	const int maxValue = 9999;
//
//	return value < minValue || value > maxValue || value < 0;
//}
//
//int GuessingTheNumber(int hiddenNumber, int numberOfAttempts)
//{
//	int bulls = 0;
//	int cows = 0;
//
//	//cout << "Загаданное число: " << hiddenNumber << endl << endl;
//
//	RulesOfGame();
//
//	cout << "Попытка №" << numberOfAttempts << ":" << endl;
//	cout << endl;
//
//	int value;
//
//	do
//	{
//		cout << "Введите четырехзначное число => ";
//		cin >> value;
//
//		if (CheckingEnteredValue(value))
//		{
//			cout << "Введенное число не соответствует требованиям!" << endl;
//			cout << endl;
//		}
//
//	} while (CheckingEnteredValue(value));
//
//	cout << endl;
//
//	if (hiddenNumber == value)
//	{
//		cout << "Число угадано!" << endl;
//		cout << endl;
//		system("pause");
//		system("cls");
//
//		cout << "Игра окончена." << endl;
//		cout << endl;
//
//		cout << "Загаданное число: " << value << endl;
//		cout << endl;
//
//		return numberOfAttempts;
//	}
//	else
//	{
//		ChekingBulls(hiddenNumber, value, bulls);
//		ChekingCows(hiddenNumber, value, cows);
//
//		cout << endl;
//	}
//
//	system("pause");
//	system("cls");
//
//	return GuessingTheNumber(hiddenNumber, ++numberOfAttempts);
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int numberOfAttempts = GuessingTheNumber(CreatingRandomFourDigitNumber() , 1);
//
//	cout << "Количество попыток: " << numberOfAttempts << endl;
//
//	cout << endl;
//	system("pause");
//}