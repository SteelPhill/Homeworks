#include <iostream>
using namespace std;

template<typename TValue>
void ShowArray(TValue arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << "arr[" << i << "] = " << arr[i] << endl;
}

void FillArray(int arr[], int size, int beginValue, int endValue)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (endValue - beginValue + 1) + beginValue;
}

void FillArray(double arr[], int size, int beginValue, int endValue)
{
	beginValue *= 10;
	endValue *= 10;
	for (int i = 0; i < size; i++)
		arr[i] = (rand() % (endValue - beginValue + 1) + beginValue) / 10.0;
}


//			ЗАДАЧА №1
/*В одномерном массиве, заполненном случайными числами, 
определить минимальный и максимальный элементы.*/

//int SearchMinElement(int arr[], int size)
//{
//	int min = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (min > arr[i])
//			min = arr[i];
//	}
//	return min;
//}
//
//int SearchMaxElement(int arr[], int size)
//{
//	int max = arr[0];
//	for (int i = 0; i < size; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//	}
//	return max;
//}
//
//void main()
//{ 
//	const int Size = 10;
//	const int BeginRange = 1;
//	const int EndRange = 30;
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	int arr[Size];
//	FillArray(arr, Size, BeginRange, EndRange);
//	cout << "Массив:" << endl;
//	ShowArray(arr, Size);
//	cout << "Минимальный элемент массива: " << SearchMinElement(arr, Size) << endl;
//	cout << "Максимальный элемент массива: " << SearchMaxElement(arr, Size) << endl;
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №2
/*В одномерном массиве, заполненном случайными числами 
в заданном пользователем диапазоне, найти сумму элементов, 
значения которых меньше указанного пользователем.*/

//int SumOfArrayElementsThatLessValue(int arr[], int size, int value)
//{
//	int sum = 0;
//	for (int i = 0; i < size; i++)
//		if (arr[i] < value)
//			sum += arr[i];
//	return sum;
//}
//
//void main()
//{
//	const int Size = 10;
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	cout << "Введите наименьшее значение элементов массива => ";
//	int beginningOfRange;
//	cin >> beginningOfRange;
//	cout << "Введите наибольшее значение элементов массива => ";
//	int endOfRange;
//	cin >> endOfRange;
//	while (beginningOfRange > endOfRange)
//	{
//		cout << "Ошибка! \"Наименьшее\" значение не может быть больше \"наибольшего\"!" << endl;
//		cout << "Введите значения заново!" << endl;
//		cout << endl;
//		system("pause");
//		system("cls");
//		cout << "Введите наименьшее значение элементов массива => ";
//		cin >> beginningOfRange;
//		cout << "Введите наибольшее значение элементов массива => ";
//		cin >> endOfRange;
//	}
//	int arr[Size];
//	FillArray(arr, Size, beginningOfRange, endOfRange);
//	cout << "Массив:" << endl;
//	ShowArray(arr, Size);
//	cout << "Введите число => ";
//	int value;
//	cin >> value;
//	cout << "Сумма элементов массива, значение которых меньше " << value << ": " << SumOfArrayElementsThatLessValue(arr, Size, value) << endl;
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3 (поиск включает в себя заданные месяца (края диапазона))
/*Пользователь вводит прибыль фирмы за год (12 месяцев). 
Затем пользователь вводит диапазон (например, 3 и 6 — поиск 
между 3-м и 6-м месяцем). Необходимо определить месяц, 
в котором прибыль была максимальна и месяц, в котором 
прибыль была минимальна с учетом выбранного диапазона.*/

//void ShowProfitForYear(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//		cout << i + 1 << " месяц: " << arr[i] << endl;
//}
//
//int EnteringStartSearchRange()
//{
//	cout << "Укажите месяц (номер) - начало диапазона поиска мин. и макс. прибыли => ";
//	int beginningSearchRange;
//	cin >> beginningSearchRange;
//	while (beginningSearchRange < 1 || beginningSearchRange > 12)
//	{
//		cout << "Такого месяца не существует!" << endl;
//		cout << "Укажите месяц (номер) - начало диапазона поиска мин. и макс. прибыли => ";
//		cin >> beginningSearchRange;
//	}
//	cout << endl;
//	return beginningSearchRange;
//}
//
//int EnteringEndSearchRange()
//{
//	cout << "Укажите месяц (номер) - конец диапазона поиска мин. и макс. прибыли => ";
//	int endingSearchRange;
//	cin >> endingSearchRange;
//	while (endingSearchRange < 1 || endingSearchRange > 12)
//	{
//		cout << "Такого месяца не существует!" << endl;
//		cout << "Укажите месяц (номер) - конец диапазона поиска мин. и макс. прибыли => ";
//		cin >> endingSearchRange;
//	}
//	cout << endl;
//	return endingSearchRange;
//}
//
//int SearchAMonthWithMinProfit(int arr[], int startRange, int endRange)
//{
//	int result = startRange - 1;
//	int min = arr[startRange - 1];
//	for (int i = startRange - 1; i < endRange; i++)
//		if (arr[i] < min)
//		{
//			result = i;
//			min = arr[i];
//		}
//	return result + 1;
//}
//
//int SearchAMonthWithMaxProfit(int arr[], int startRange, int endRange)
//{
//	int result = startRange - 1;
//	int max = arr[startRange - 1];
//	for (int i = startRange - 1; i < endRange; i++)
//		if (arr[i] > max)
//		{
//			result = i;
//			max = arr[i];
//		}
//	return result + 1;
//}
//
//void main()
//{
//	const int NumberOfMonthsInYear = 12;
//	const int MinProfitForYear = 10000;
//	const int MaxProfitForYear = 20000;
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	int arr[NumberOfMonthsInYear];
//	FillArray(arr, NumberOfMonthsInYear, MinProfitForYear, MaxProfitForYear);
//	cout << "Прибыль фирмы за год (12 месяцев):" << endl;
//	ShowProfitForYear(arr, NumberOfMonthsInYear);
//	cout << endl;
//	int beginningSearchRange = EnteringStartSearchRange();
//	int endingSearchRange = EnteringEndSearchRange();
//	while (endingSearchRange < beginningSearchRange)
//	{
//		cout << "Значение верхней границы диапазона не может быть меньше нижней границы!" << endl;
//		cout << "Введите границы диапазона заново!" << endl;
//		cout << endl;
//		system("pause");
//		system("cls");
//		cout << "Прибыль фирмы за год (12 месяцев):" << endl;
//		ShowProfitForYear(arr, NumberOfMonthsInYear);
//		cout << endl;
//		beginningSearchRange = EnteringStartSearchRange();
//		endingSearchRange = EnteringEndSearchRange();
//		cout << endl;
//	}
//	system("cls");
//	cout << "Прибыль фирмы за год (12 месяцев):" << endl;
//	ShowProfitForYear(arr, NumberOfMonthsInYear);
//	cout << endl;
//	cout << "Начало диапазона поиска (номер месяца): " << beginningSearchRange << endl;
//	cout << "Конец диапазона поиска (номер месяца): " << endingSearchRange << endl;
//	int monthWithMinProfit = SearchAMonthWithMinProfit(arr, beginningSearchRange, endingSearchRange);
//	int monthWithMaxProfit = SearchAMonthWithMaxProfit(arr, beginningSearchRange, endingSearchRange);
//	cout << endl;
//	cout << "Месяц с минимальной прибылью в заданном диапазоне: " << monthWithMinProfit << ". Прибыль: " << arr[monthWithMinProfit - 1] << endl;
//	cout << "Месяц с максимальной прибылью в заданном диапазоне: " << monthWithMaxProfit << ". Прибыль: " << arr[monthWithMaxProfit - 1] << endl;
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №4 
/*В одномерном массиве, состоящем из N вещественных 
чисел вычислить:
- Сумму отрицательных элементов.
- Произведение элементов, находящихся между min и max
элементами.
- Произведение элементов с четными номерами.
- Сумму элементов, находящихся между первым и последним отрицательными элементами.*/

//double SumOfnegativeElements(double arr[], int size)
//{
//	double sum = 0;
//	for (int i = 0; i < size; i++)
//		if (arr[i] < 0)
//			sum += arr[i];
//	return sum;
//}
//
//int EnteringStartSearchRange()
//{
//	cout << "Укажите начало диапазона (min), для вычисления произведения элементов в указанном диапазоне => ";
//	int min;
//	cin >> min;
//	return min;
//}
//
//int EnteringEndSearchRange()
//{
//	cout << "Укажите конец диапазона (max), для вычисления произведения элементов в указанном диапазоне => ";
//	int max;
//	cin >> max;
//	return max;
//}
//
//double MultiplierOfElementsInRange(double arr[], int size, int startRange, int endRange)
//{
//	double multiplier = 1;
//	for (int i = startRange; i < endRange - 1; i++)
//		multiplier *= arr[i];
//	return multiplier;
//}
//
//double MultiplierOfElementsWithEvenNumbers(double arr[], int size)
//{
//	double multiplier = 1;
//	for (int i = 0; i < size; i++)
//		if(i % 2 != 0)
//			multiplier *= arr[i];
//	return multiplier;
//}
//
//int SearchFirstNegativeElement(double arr[], int size)
//{
//	int firstNegativ = 0;
//	for (int i = 0; i < size; i++)
//		if (arr[i] < 0)
//		{
//			firstNegativ = i;
//			break;
//		}
//	return firstNegativ;
//}
//
//int SearchLastNegativeElement(double arr[], int size)
//{
//	int lastNegativ = size - 1;
//	for (int i = size - 1; i >= 0; i--)
//		if (arr[i] < 0)
//		{
//			lastNegativ = i;
//			break;
//		}
//	return lastNegativ;
//}
//
//double SumOfElementsBetweenfirstAndLastNegativeElements(double arr[], int size)
//{
//	double sum = 0;
//	int firstNegativ = SearchFirstNegativeElement(arr, size);
//	int lastNegativ = SearchLastNegativeElement(arr, size);
//	for (int i = firstNegativ + 1; i < lastNegativ; i++)
//		sum += arr[i];
//	return sum;
//}
//
//void main()
//{
//	const int SizeN = 20;
//	const int BeginRange = -10;
//	const int EndRange = 10;
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	double arr[SizeN];
//	FillArray(arr, SizeN, BeginRange, EndRange);
//	cout << "Массив:" << endl;
//	ShowArray(arr, SizeN);
//	cout << endl;
//	int min = EnteringStartSearchRange();
//	while (min < 1 || min > SizeN)
//	{
//		cout << "Введенное значение за пределами диапазона!" << endl;
//		min = EnteringStartSearchRange();
//	}
//	int max = EnteringEndSearchRange();
//	while (max < 1 || max > SizeN)
//	{
//		cout << "Введенное значение за пределами диапазона!" << endl;
//		max = EnteringEndSearchRange();
//	}
//	while (min > max)
//	{
//		cout << "Значение начала диапазона не может быть больше значения конца диапазона!" << endl;
//		cout << "Введите границы диапазона заново!" << endl;
//		cout << endl;
//		min = EnteringStartSearchRange();
//		while (min < 1 || min > SizeN)
//		{
//			cout << "Введенное значение за пределами диапазона!" << endl;
//			min = EnteringStartSearchRange();
//		}
//		max = EnteringEndSearchRange();
//		while (max < 1 || max > SizeN)
//		{
//			cout << "Введенное значение за пределами диапазона!" << endl;
//			max = EnteringEndSearchRange();
//		}
//	}
//	cout << endl;
//	system("pause");
//	system("cls");
//	cout << "Массив:" << endl;
//	ShowArray(arr, SizeN);
//	cout << endl;
//	cout << "1) Сумма отрицательных элементов массива равна: " << SumOfnegativeElements(arr, SizeN) << endl;
//	cout << endl;
//	cout << "2) Произведение элементов массива, находящихся между " << min << " элементом и " << max << " элементом равно: " << MultiplierOfElementsInRange(arr, SizeN, min, max) << endl;
//	cout << endl;
//	cout << "3) Произведение четных элементов массива равно: " << MultiplierOfElementsWithEvenNumbers(arr, SizeN) << endl;
//	cout << endl;
//	cout << "4) Сумма элементов, находящихся между первым и последним отрицательными элементами равна: " << SumOfElementsBetweenfirstAndLastNegativeElements(arr, SizeN) << endl;
//	cout << endl;
//	system("pause");
//}