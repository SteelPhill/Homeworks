#include <iostream>
#include <span>
using namespace std;

template<typename TValue> 
void ShowOneDimensionalArray(TValue* arr, int size)
{
	for (int i : span(arr, size))
		cout << i << " ";
	cout << endl;
}

template<typename TValue>
void FillingOneDimensionalArrayInOrderOfOne(TValue* arr, int size, int beginOfRange, int endOfRange)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (endOfRange - beginOfRange + 1) + beginOfRange;
}

void ShowResultOfSearh(int index)
{
	if (index != -1)
		cout << "Ключ расположен по индексу: " << index << endl;
	else
		cout << "Ключ в массиве отсутствует." << endl;
	cout << endl;
}


//			ЗАДАНИЕ№ 1
/*Написать функцию, реализующую алгоритм 
линейного поиска заданного ключа в одномерном массиве.*/

//bool EqualityCheck(int arrayElement, int key)
//{
//	return arrayElement == key;
//}
//
//void LinearSearch(int* arr, int size, int key)
//{
//	bool keyIsMissing = true;
//
//	for (int i = 0; i < size; i++)
//		if (EqualityCheck(arr[i], key))
//		{
//			ShowResultOfSearh(i);
//			keyIsMissing = false;
//		}
//
//	if (keyIsMissing)
//		ShowResultOfSearh(-1);
//}
//
//void main()
//{
//	const int Size = 10;
//	const int BeginOfRange = 1;
//	const int EndOfRange = 20;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int arr[Size];
//	FillOneDimensionalArray(arr, Size, BeginOfRange, EndOfRange);
//	ShowOneDimensionalArray(arr, Size);
//	cout << endl;
//
//	int key;
//	cout << "Введите ключ (число) для проверки его наличия в массиве => ";
//	cin >> key;
//	cout << endl;
//
//	LinearSearch(arr, Size, key);
//
//	system("pause");
//}


//			ЗАДАНИЕ№ 2
/*Написать функцию, реализующую алгоритм 
бинарного поиска заданного ключа в одномерном массиве.*/

//void QuickSort(int* arr, int begin, int end)
//{
//	if (begin > end)
//		return;
//	
//	int i = begin;
//	int j = end;
//	int k = arr[(begin + end) / 2];
//
//	do
//	{
//		while (arr[i] < k)
//			i++;
//		while (arr[j] > k)
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
//	QuickSort(arr, begin, j);
//	QuickSort(arr, i, end);
//}
//
//int BinarySearchUsingRecursion(int* arr, int leftRange, int rightRange, int key)
//{
//	int mid = (leftRange + rightRange) / 2;
//
//	if (key == arr[mid])
//		return mid;
//
//	if (leftRange >= rightRange)
//		return -1;
//	
//	if (key < arr[mid])
//		return BinarySearchUsingRecursion(arr, leftRange, mid - 1, key);
//	if (key > arr[mid])
//		return BinarySearchUsingRecursion(arr, mid + 1, rightRange, key);
//}
//
//int BinarySearchUsingIteration(int* arr, int leftRange, int rightRange, int key)
//{
//	int mid;
//
//	while (leftRange <= rightRange)
//	{
//		mid = (leftRange + rightRange) / 2;
//
//		if (key < arr[mid])
//			rightRange = mid - 1;
//
//		if (key > arr[mid])
//			leftRange = mid + 1;
//
//		if (key == arr[mid])
//			return mid;
//	}
//
//	return - 1;
//}
//
//void main()
//{
//	const int Size = 10;
//	const int BeginOfRange = 1;
//	const int EndOfRange = 20;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int arr[Size];
//	FillOneDimensionalArray(arr, Size, BeginOfRange, EndOfRange);
//
//	cout << "Массив до сортировки:" << endl;
//	ShowOneDimensionalArray(arr, Size);
//	cout << endl;
//
//	QuickSort(arr, 0, Size - 1);
//
//	cout << "Массив после сортировки:" << endl;
//	ShowOneDimensionalArray(arr, Size);
//	cout << endl;
//
//	int key;
//	cout << "Введите ключ (число) для проверки его наличия в массиве => ";
//	cin >> key;
//	cout << endl;
//
//	cout << "Результат бинарного поиска с использованием рекурсивного метода:" << endl;
//	ShowResultOfSearh(BinarySearchUsingRecursion(arr, 0, Size, key));
//
//	cout << "Результат бинарного поиска с использованием итеративного метода:" << endl;
//	ShowResultOfSearh(BinarySearchUsingIteration(arr, 0, Size, key));
//
//	system("pause");
//}


//			ЗАДАНИЕ№ 3
/*Написать функцию для перевода числа, записанного в двоичном виде, в десятичное представление*/

//bool CheckingLengthOfNumber(long long binaryNumber)
//{
//	const long long divisorToCheckIfThisNumberFitsIntoLongLong = 10000000000000000000;
//
//	return binaryNumber / divisorToCheckIfThisNumberFitsIntoLongLong == 0;
//}
//
//bool CheckingWhetherNumberIsBinary(long long binaryNumber)
//{
//	bool numberIsBinary = true;
//
//	while (binaryNumber != 0)
//	{
//		if (binaryNumber % 10 > 1)
//		{
//			numberIsBinary = false;
//			break;
//		}
//		binaryNumber /= 10;
//	}
//
//	return numberIsBinary;
//}
//
//bool CheckingForPresenceOfSign(long long binaryNumber)
//{
//	return binaryNumber >= 0;
//}
//
//bool CheckingBinaryNumber(long long binaryNumber)
//{
//	return CheckingLengthOfNumber(binaryNumber) && CheckingWhetherNumberIsBinary(binaryNumber) && CheckingForPresenceOfSign(binaryNumber);
//}
//
//
//int ConvertingBinaryNumberToDecimalNumber(long long binaryNumber)
//{
//	int result = 0;
//	int count = 1;
//
//	while (binaryNumber)
//	{
//		if (binaryNumber % 10 == 1)
//			result += count;
//
//		binaryNumber /= 10;
//		count *= 2;
//	}
//
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	long long binaryNumber;
//
//	cout << "Введите число в двоичном виде. Количество символов должно быть не более 19-ти => ";
//	cin >> binaryNumber;
//	cout << endl;
//
//	if (!CheckingBinaryNumber(binaryNumber))
//	{
//		cout << "Введенное число не соответствует требованиям!" << endl;
//		cout << endl;
//		cout << "Завершение работы программы..." << endl;
//		cout << endl;
//		system("pause");
//		return;
//	}
//
//	cout << "Введенное число в десятичной системе счисления: " << ConvertingBinaryNumberToDecimalNumber(binaryNumber) << endl;
//
//	cout << endl;
//	system("pause");
//}