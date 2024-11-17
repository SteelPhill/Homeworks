#include <iostream>
#include <algorithm>
#include <span>
using namespace std;


//			ВСТРЕЧА №11

/*Реализуйте шаблонные функции для поиска максимума, минимума,
сортировки массива (любым алгоритмом сортировки),
двоичного поиска в массиве, замены элемента 
массива на переданное значение. */

template <typename TValue>
TValue MinArray(const TValue* arr, const int size)
{
	TValue result = arr[0];

	for (int i = 1; i < size; i++)
		result = min(arr[i], result);

	return result;
}

template <typename TValue>
TValue MaxArray(const TValue* arr, const int size)
{
	TValue result = arr[0];

	for (int i = 1; i < size; i++)
		result = max(arr[i], result);

	return result;
}

template <typename TValue>
void SortArray(TValue* arr, const int size, bool desc = false)
{
	if (desc)
		sort(arr, arr + size, [](const TValue& left, const TValue& right) { return left > right; });
	else
		sort(arr, arr + size, [](const TValue& left, const TValue& right) { return left < right; });
}

template <typename TValue>
int BinarySearchArray(const TValue* arr, const int size, const TValue key)
{
	int mid;
	int leftRange = 0;
	int rightRange = size;

	while (leftRange <= rightRange)
	{
		mid = (leftRange + rightRange) / 2;

		if (key < arr[mid])
			rightRange = mid - 1;

		if (key > arr[mid])
			leftRange = mid + 1;

		if (key == arr[mid])
			return mid;
	}

	return -1;
}

template <typename TValue>
void ReplaceElementByIndexInArray(TValue* arr, const int size, const int index, const TValue newValue)
{
	if (index >= 0 && index < size)
		arr[index] = newValue;
}

template <typename TValue>
void ShowArray(const TValue* arr, const int size)
{
	for (TValue i : span(arr, arr + size))
		cout << i << "  ";
	cout << endl;
}

void main()
{
	const int size = 5;

	cout << "\tint array test:" << endl << endl;

	int arr1[size] = { 1, 8, 3, 2, 5 };
	cout << "Original arr1: ";
	ShowArray(arr1, size);
	cout << endl;
	cout << "Min arr1: " << MinArray(arr1, size) << endl;
	cout << "Max arr1: " << MaxArray(arr1, size) << endl;
	cout << endl;
	ReplaceElementByIndexInArray(arr1, size, 1, 4);
	cout << "Replace element in arr1: ";
	ShowArray(arr1, size);
	cout << endl;
	SortArray(arr1, size);
	cout << "Sort arr1: ";
	ShowArray(arr1, size);
	cout << endl;
	cout << "Number 4 in arr1 located by index: [" << BinarySearchArray(arr1, size, 4) << "]" << endl;

	cout << endl << endl << "\tdouble array test:" << endl << endl;

	double arr2[size] = { 2.2, 1.1, 4.4, 3.3, 7.7 };
	cout << "Original arr2: ";
	ShowArray(arr2, size);
	cout << endl;
	cout << "Min arr2: " << MinArray(arr2, size) << endl;
	cout << "Max arr2: " << MaxArray(arr2, size) << endl;
	cout << endl;
	ReplaceElementByIndexInArray(arr2, size, 4, 5.5);
	cout << "Replace element in arr2: ";
	ShowArray(arr2, size);
	cout << endl;
	SortArray(arr2, size);
	cout << "Sort arr2: ";
	ShowArray(arr2, size);
	cout << endl;
	cout << "Number 1.1 in arr2 located by index: [" << BinarySearchArray(arr2, size, 1.1) << "]" << endl;

	cout << endl << endl << "\tchar array test:" << endl << endl;

	char arr3[size] = { 'b', 'c', 'x', 'a', 'e'};
	cout << "Original arr3: ";
	ShowArray(arr3, size);
	cout << endl;
	cout << "Min arr3: " << MinArray(arr3, size) << endl;
	cout << "Max arr3: " << MaxArray(arr3, size) << endl;
	cout << endl;
	ReplaceElementByIndexInArray(arr3, size, 2, 'd');
	cout << "Replace element in arr3: ";
	ShowArray(arr3, size);
	cout << endl;
	SortArray(arr3, size);
	cout << "Sort arr3: ";
	ShowArray(arr3, size);
	cout << endl;
	cout << "Symbol 'c' in arr3 located by index: [" << BinarySearchArray(arr3, size, 'c') << "]" << endl;

	cout << endl;
	system("pause");
}