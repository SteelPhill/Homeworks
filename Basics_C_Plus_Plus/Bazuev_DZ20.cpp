#include <iostream>
#include <iomanip>
using namespace std;

template<typename TValue>
void FillingOneDimensionalArray(TValue* arr, const int size, const int beginRange, const int endRange)
{
	for (TValue* ptr = arr; ptr < &arr[size]; ptr++)
		*ptr = rand() % (endRange - beginRange + 1) + beginRange;
}

void FillingOneDimensionalArray(double* arr, const int size, int beginRange, int endRange)
{
	beginRange *= 10;
	endRange *= 10;

	for (double* ptr = arr; ptr < &arr[size]; ptr++)
		*ptr = (rand() % (endRange - beginRange + 1) + beginRange) / 10.0;
}

template<typename TValue>
void ShowOneDimensionalArray(TValue* arr, const int size)
{
	for (TValue* ptr = arr; ptr < &arr[size]; ptr++)
		cout << *ptr << " ";
	cout << endl;
	cout << endl;
}

void ShowOneDimensionalArray(double* arr, const int size)
{
	for (double* ptr = arr; ptr < &arr[size]; ptr++)
		cout << fixed << setprecision(1) << *ptr << "  ";
	cout << endl;
	cout << endl;
}


//			ЗАДАЧА №1

/*Написать следующие функции для работы
с динамическим массивом:
- Функция распределения динамической памяти.
- Функция инициализации динамического массива.
- Функция печати динамического массива.
- Функция удаления динамического массива.
- Функция добавления элемента в конец массива.
- Функция вставки элемента по указанному индексу.
- Функция удаления элемента по указанному индексу.*/

//template<typename TValue>
//TValue* AllocatingMemoryForArray(const int size)
//{
//	TValue* arr = new TValue[size];
//	return arr;
//}
//
//template<typename TValue>
//void DeletingDynamicArray(TValue* arr)
//{
//	delete[] arr;
//}
//
//template<typename TValue>
//void AddingElementToEndOfArray(TValue* arr, const int size, const TValue addedElement)
//{
//	*(arr + (size - 1)) = addedElement;
//}
//
//template<typename TValue>
//void AddingElementByIndex(TValue* arr, const int size, const int index, const TValue addedElement)
//{
//	*(arr + index) = addedElement;
//}
//
//template<typename TValue>
//void DeletingElementByIndex(TValue** originalArray, int *size, const int index)
//{
//	TValue* newArray = new TValue[--*size];
//
//	TValue* OriginalArrayPointer = *originalArray;
//	TValue* newArrayPointer = newArray;
//
//	while (OriginalArrayPointer < *originalArray + index)
//		*newArrayPointer++ = *OriginalArrayPointer++;
//
//	OriginalArrayPointer++;
//
//	while (OriginalArrayPointer < *originalArray + (*size + 1))
//		*newArrayPointer++ = *OriginalArrayPointer++;
//
//	DeletingDynamicArray(*originalArray);
//
//	*originalArray = newArray;
//}
//
//void main()
//{
//	const int BeginRange = 65;
//	const int EndRange = 90;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int size = 10;
//
//	int* arr = AllocatingMemoryForArray<int>(size);
//	int newValueOfElement1 = 11;
//	int newValueOfElement2 = 99;
//	
//	/*char* arr = AllocatingMemoryForArray<char>(size);
//	char newValueOfElement1 = 35;
//	char newValueOfElement2 = 64;*/
//
//	/*double* arr = AllocatingMemoryForArray<double>(size);
//	double newValueOfElement1 = 11.1;
//	double newValueOfElement2 = 99.9;*/
//
//	int indexOfReplacedElement1 = 1;
//
//	int indexOfDeletedElement2 = 2;
//
//	cout << "Исходный массив:" << endl;
//	FillingOneDimensionalArray(arr, size, BeginRange, EndRange);
//	ShowOneDimensionalArray(arr, size);
//
//	cout << "Массив после замены последнего элемента:" << endl;
//	AddingElementToEndOfArray(arr, size, newValueOfElement1);
//	ShowOneDimensionalArray(arr, size);
//
//	cout << "Массив после замены элемента по индексу:" << endl;
//	AddingElementByIndex(arr, size, indexOfReplacedElement1, newValueOfElement2);
//	ShowOneDimensionalArray(arr, size);
//
//	cout << "Массив после удаления элемента по индексу:" << endl;
//	DeletingElementByIndex(&arr, &size, indexOfDeletedElement2);
//	ShowOneDimensionalArray(arr, size); 
//
//	DeletingDynamicArray(arr);
//
//	system("pause");
//}


//			ЗАДАЧА №2 (Простые числа: 2, 3, 5, 7, 11, 13, 17, 19...)

/*Написать функцию, которая получает указатель на 
динамический массив и его размер. Функция 
должна удалить из массива все простые числа и 
вернуть указатель на новый динамический массив.*/

//bool CheckSimpleNumber(const int number)
//{
//	if (number == 2)
//		return true;
//
//	if (number == 1)
//		return false;
//
//	for (int i = 2; i < number; i++)
//		if (number % i == 0)
//			return false;
//
//	return true;
//}
//
//void ShiftingSimpleNumbers(int* arr, const int size)
//{
//	int* firstPointer = arr;
//	int* secondPointer = arr + 1;
//
//	while (secondPointer < arr + size)
//		if (!CheckSimpleNumber(*firstPointer))
//			secondPointer = ++firstPointer + 1;
//		else
//			swap(*firstPointer, *secondPointer++);
//}
//
//int CountingNonSimpleNumbers(int* arr, const int size)
//{
//	int nonSimpleNumbers = 0;
//
//	for (int i = 0; !CheckSimpleNumber(*arr++) && i < size; i++)
//		nonSimpleNumbers++;
//
//	return nonSimpleNumbers;
//}
//
//int* CreateArrayWithoutSimpleNumbers(int** originalArray, const int sizeOfOriginalArray)
//{
//	ShiftingSimpleNumbers(*originalArray, sizeOfOriginalArray);
//
//	int sizeOfNewArray = CountingNonSimpleNumbers(*originalArray, sizeOfOriginalArray);
//
//	if (sizeOfNewArray == 0)
//		return nullptr;
//
//	int* newArray = new int[sizeOfNewArray];
//
//	int* originalArrayPointer = *originalArray;
//	int* newArrayPointer = newArray;
//
//	while (newArrayPointer < newArray + sizeOfNewArray)
//		*newArrayPointer++ = *originalArrayPointer++;
//
//	return newArray;
//}
//
//void main()
//{
//	const int BeginRange = 1;
//	const int EndRange = 20;
//	const int sizeOfOriginalArray = 10;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//	
//	int* originalArray = new int[sizeOfOriginalArray];
//
//	FillingOneDimensionalArray(originalArray, sizeOfOriginalArray, BeginRange, EndRange);
//	cout << "Исходный массив:" << endl;
//	ShowOneDimensionalArray(originalArray, sizeOfOriginalArray);
//
//	int* newArray = CreateArrayWithoutSimpleNumbers(&originalArray, sizeOfOriginalArray);
//	int sizeOfNewArray = CountingNonSimpleNumbers(originalArray, sizeOfOriginalArray);
//
//	if (newArray == nullptr)
//	{
//		cout << "В исходном массиве все числа простые!" << endl;
//		cout << endl;
//		delete[] originalArray;
//		system("pause");
//		return;
//	}
//
//	cout << "Новый массив без простых чисел:" << endl;
//	ShowOneDimensionalArray(newArray, sizeOfNewArray);
//
//	delete[] originalArray;
//	delete[] newArray;
//
//	system("pause");
//}


//			ЗАДАЧА №3 (В задании написано: "Написать функцию, которая получает указатель на статический массив и его размер".
//                     Я понял, что кроме массива и его размера в функцию большего ничего передавать нельзя.
//                     Поэтому динамические массивы создал, использовал и удалил в этой же функции, а как их передать в main(), я не придумал)
//					   В голове мелькал вариант с return-ом двумерного массива, но не уверен, что это правильный вариант)
//					   И в принципе не уверен, нужно ли это по заданию))

/*Написать функцию, которая получает указатель 
на статический массив и его размер. Функция распределяет
положительные, отрицательные и нулевые элементы 
в отдельные динамические массивы.*/

//int CountingNumberNegativeElementsInArray(int* const originalArray, const int size)
//{
//	int count = 0;
//
//	for (int* ptr = originalArray; ptr < originalArray + size; ptr++)
//		if (*ptr < 0)
//			count++;
//
//	return count;
//}
//
//int CountingNumberZerosInArray(int* const originalArray, const int size)
//{
//	int count = 0;
//
//	for (int* ptr = originalArray; ptr < originalArray + size; ptr++)
//		if (*ptr == 0)
//			count++;
//
//	return count;
//}
//
//int CountingNumberPositiveElementsInArray(int* const originalArray, const int size)
//{
//	int count = 0;
//
//	for (int* ptr = originalArray; ptr < originalArray + size; ptr++)
//		if (*ptr > 0)
//			count++;
//
//	return count;
//}
//
//void FillingArrayWithNegativeElements(int* originalArray, int* arrayWithNegativeElements, const int sizeOfOriginalArray, const int sizeArrayWithNegativeElements)
//{
//	int* originalArrayPointer = originalArray;
//	int* arrayWithNegativeElementsPointer = arrayWithNegativeElements;
//
//	while (originalArrayPointer < originalArray + sizeOfOriginalArray)
//		if (*originalArrayPointer < 0)
//			*arrayWithNegativeElementsPointer++ = *originalArrayPointer++;
//		else
//			originalArrayPointer++;
//}
//
//void FillingZeroArray(int* originalArray, int* arrayWithZero, const int sizeOfOriginalArray, const int sizeArrayWithZero)
//{
//	int* originalArrayPointer = originalArray;
//	int* arrayWithNegativeElementsPointer = arrayWithZero;
//
//	while (originalArrayPointer < originalArray + sizeOfOriginalArray)
//		if (*originalArrayPointer == 0)
//			*arrayWithNegativeElementsPointer++ = *originalArrayPointer++;
//		else
//			originalArrayPointer++;
//}
//
//void FillingArrayWithPositiveElements(int* originalArray, int* arrayWithPositiveElements, const int sizeOfOriginalArray, const int sizeArrayWithPositiveElements)
//{
//	int* originalArrayPointer = originalArray;
//	int* arrayWithNegativeElementsPointer = arrayWithPositiveElements;
//
//	while (originalArrayPointer < originalArray + sizeOfOriginalArray)
//		if (*originalArrayPointer > 0)
//			*arrayWithNegativeElementsPointer++ = *originalArrayPointer++;
//		else
//			originalArrayPointer++;
//}
//
//void DistributionOfArrayElementsOverSpecifiedArrays(int (*originalArray)[10], const int sizeOfOriginalArray)
//{
//	int sizeArrayWithNegativeElements = CountingNumberNegativeElementsInArray(*originalArray, sizeOfOriginalArray);
//	int sizeArrayWithZero = CountingNumberZerosInArray(*originalArray, sizeOfOriginalArray);
//	int sizeArrayWithPositiveElements = CountingNumberPositiveElementsInArray(*originalArray, sizeOfOriginalArray);
//
//	if (sizeArrayWithNegativeElements != 0)
//	{
//		int* arrayWithNegativeElements = new int[sizeArrayWithNegativeElements];
//		FillingArrayWithNegativeElements(*originalArray, arrayWithNegativeElements, sizeOfOriginalArray, sizeArrayWithNegativeElements);
//		cout << "Массив, заполненный отрицательными значениями, содержащимися в исходном массиве:" << endl;
//		ShowOneDimensionalArray(arrayWithNegativeElements, sizeArrayWithNegativeElements);
//		delete[] arrayWithNegativeElements;
//	}
//	else
//		cout << "Отрицательных значений в массиве нет!" << endl << endl;
//
//
//	if (sizeArrayWithZero != 0)
//	{
//		int* arrayWithZero = new int[sizeArrayWithZero];
//		FillingZeroArray(*originalArray, arrayWithZero, sizeOfOriginalArray, sizeArrayWithZero);
//		cout << "Массив, заполненный нулевыми значениями, содержащимися в исходном массиве:" << endl;
//		ShowOneDimensionalArray(arrayWithZero, sizeArrayWithZero);
//		delete[] arrayWithZero;
//	}
//	else
//		cout << "Нулевых значений в массиве нет!" << endl << endl;
//
//
//	if (sizeArrayWithPositiveElements != 0)
//	{
//		int* arrayWithPositiveElements = new int[sizeArrayWithPositiveElements];
//		FillingArrayWithPositiveElements(*originalArray, arrayWithPositiveElements, sizeOfOriginalArray, sizeArrayWithPositiveElements);
//		cout << "Массив, заполненный положительными значениями, содержащимися в исходном массиве:" << endl;
//		ShowOneDimensionalArray(arrayWithPositiveElements, sizeArrayWithPositiveElements);
//		delete[] arrayWithPositiveElements;
//	}
//	else
//		cout << "Положительных значений в массиве нет!" << endl << endl;
//}
//
//void main()
//{
//	const int BeginRange = -3;
//	const int EndRange = 3;
//	const int SizeOfOriginalArray = 10;
//
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	int originalArray[SizeOfOriginalArray];
//
//	cout << "Исходный массив:" << endl;
//	FillingOneDimensionalArray(originalArray, SizeOfOriginalArray, BeginRange, EndRange);
//	ShowOneDimensionalArray(originalArray, SizeOfOriginalArray);
//
//	DistributionOfArrayElementsOverSpecifiedArrays(&originalArray, SizeOfOriginalArray);
//
//	system("pause");
//}