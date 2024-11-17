#include <iostream>
using namespace std;

template<typename TValue>
void FillingOneDimensionalArrayInOrderOfOne(TValue* arr, int size)
{
	for (int i = 0; i < size; i++)
		*(arr + i) = i + 1;
}

template<typename TValue>
void ShowOneDimensionalArray(TValue* arr, int size)
{
	int* firstElement = arr;

	while(arr <= (firstElement + (size - 1)))
		cout << *arr++ << " ";

	cout << endl;
}


//			ЗАДАЧА №1
/*Используя два указателя на массив целых 
чисел, скопировать один массив в другой. Использовать 
в программе арифметику указателей для продвижения
по массиву, а также оператор разыменования.*/

//template<typename TValue>
//void CopyingAnArray(TValue* originalArray, TValue* arrayToCopy, int size)
//{
//	for (int i = 0; i < size; i++)
//		*(arrayToCopy + i) = *(originalArray + i);
//}
//
//void main()
//{
//	const int Size = 10;
//
//	setlocale(LC_ALL, "ru");
//
//	cout << "Исходный массив:" << endl;
//	int originalArray[Size];
//	FillingOneDimensionalArrayInOrderOfOne(originalArray, Size);
//	ShowOneDimensionalArray(originalArray, Size);
//
//	cout << endl;
//
//	cout << "Копия исходного массива:" << endl;
//	int copyOfOriginalArray[Size];
//	CopyingAnArray(originalArray, copyOfOriginalArray, Size);
//	ShowOneDimensionalArray(copyOfOriginalArray, Size);
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №2
/*Используя указатель на массив целых чисел, 
изменить порядок следования элементов массива на 
противоположный. 
Использовать в программе арифметику указателей 
для продвижения по массиву, а также оператор разыменования.*/

//template<typename TValue>
//void FlippingAnArray(TValue* arr, int size)
//{
//	int leftIndex = 0;
//	int rightIndex = size - 1;
//
//	while (leftIndex < rightIndex)
//		swap(*(arr + leftIndex++), *(arr + rightIndex--));
//}
//
//void main()
//{
//	const int Size = 10;
//
//	setlocale(LC_ALL, "ru");
//
//	cout << "Исходный массив:" << endl;
//	int arr[Size];
//	FillingOneDimensionalArrayInOrderOfOne(arr, Size);
//	ShowOneDimensionalArray(arr, Size);
//
//	cout << endl;
//
//	cout << "Перевернутый исходный массив:" << endl;
//	FlippingAnArray(arr, Size);
//	ShowOneDimensionalArray(arr, Size);
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3
/*Используя два указателя на массивы целых 
чисел, скопировать один массив в другой так, чтобы во 
втором массиве элементы находились в обратном порядке. 
Использовать в программе арифметику указателей 
для продвижения по массиву, а также оператор разыменования.*/

//template<typename TValue>
//void CopyingAnFlippingArray(TValue* originalArray, TValue* arrayToCopy, int size)
//{
//	for (int i = 0; i < size; i++)
//		*(arrayToCopy + i) = *(originalArray + ((size - 1) - i));
//}
//
//void main()
//{
//	const int Size = 10;
//
//	setlocale(LC_ALL, "ru");
//
//	cout << "Исходный массив:" << endl;
//	int originalArray[Size];
//	FillingOneDimensionalArrayInOrderOfOne(originalArray, Size);
//	ShowOneDimensionalArray(originalArray, Size);
//
//	cout << endl;
//
//	cout << "Копия перевернутого исходного массива:" << endl;
//	int copyOfOriginalArray[Size];
//	CopyingAnFlippingArray(originalArray, copyOfOriginalArray, Size);
//	ShowOneDimensionalArray(copyOfOriginalArray, Size);
//
//	cout << endl;
//	system("pause");
//}




////			Решение 3-х задач с помощью массива указателей и указателя на функцию, как аргумента.
//
//
//void ShowResult(void(*taskNumber)(int*, int*, int), int count, int* originalArray, int* copyOfOriginalArray, int size)
//{
//	taskNumber(originalArray, copyOfOriginalArray, size);
//	cout << "Результат задачи №" << count << endl;
//	ShowOneDimensionalArray(copyOfOriginalArray, size);
//	cout << endl;
//
//}
//
//void TaskNumberOne(int* originalArray, int* arrayToCopy, int size)
//{
//	for (int i = 0; i < size; i++)
//		*(arrayToCopy + i) = *(originalArray + i);
//}
//
//void TaskNumberTwo(int* originalArray, int* arrayToCopy, int size)	// Решение 2-ой задачи, относительно оригинала, 
//																	// изменено для корректного подсчета и вывода результатов. 
//{
//	int leftIndex = 0;
//	int rightIndex = size - 1;
//
//	while (leftIndex < rightIndex)
//		swap(*(originalArray + leftIndex++), *(originalArray + rightIndex--));
//
//	for (int i = 0; i < size; i++)
//		*(arrayToCopy + i) = *(originalArray + i);
//
//	FillingOneDimensionalArrayInOrderOfOne(originalArray, size);
//}
//
//void TaskNumberThree(int* originalArray, int* arrayToCopy, int size)
//{
//	for (int i = 0; i < size; i++)
//		*(arrayToCopy + i) = *(originalArray + ((size - 1) - i));
//}
//
//void main()
//{
//	const int Size = 10;
//	const int NumberOfTasks = 3;
//
//	setlocale(LC_ALL, "ru");
//
//	void (*taskOptions[NumberOfTasks])(int*, int*, int) = 
//	{
//		TaskNumberOne,
//		TaskNumberTwo,
//		TaskNumberThree
//	};
//
//	cout << "Исходный массив:" << endl;
//	int originalArray[Size];
//	FillingOneDimensionalArrayInOrderOfOne(originalArray, Size);
//	ShowOneDimensionalArray(originalArray, Size);
//
//	cout << endl;
//
//	int copyOfOriginalArray[Size];
//
//	for (int i = 0; i < NumberOfTasks; i++)
//		ShowResult(taskOptions[i], i + 1, originalArray, copyOfOriginalArray, Size);
//
//	system("pause");
//}