#define INTEGER
//#define DOUBLE
//#define CHAR

#include <iostream>
#include "function.h"
using namespace std;


//				ЗАДАНИЕ №1

/*Создать проект в котором:
1. Cоздать три файла: function.h, function.cpp, prog.cpp.
2. В файле function.cpp необходимо написать следующие 
функции для работы с массивом данных:
a) функцию для заполнения массива случайными значениями;
b) функцию для вывода значений массива на консоль;
c) функцию для поиска минимального элемента;
d) функцию для поиска максимального элемента;
e) функцию для сортировки;
f) функцию для редактирования значения массива.
Данные функции необходимо написать для работы 
с массивом целых, действительных и символьных 
значений. (Для каждого типа написать отдельную 
функцию).
3. В файле function.h нужно:
a) описать прототипы всех функций;
b) сделать проверку определена ли константа, указывающая на тип данных (#ifdef INTEGER);
c) создать обобщающие имена функции, которым будет определена функция соответствующего типа в
зависимости от константы, указанной в файле prog.cpp (#define show ShowInt).
cpp .
4. В файле prog.cpp нужно:
a) в функции main вызвать все функции через переозначеные (обобщенные) имена из файла function.h
(show());
b) определить константу, которая указывает какой тип
данных будет использоваться.Например INTEGER - целые данные,
CHAR — символьные, DOUBLE — настоящие (#define INTEGER).
Имя функциям нужно давать так, чтобы они отвечали своей сути.
Например функция для вывода значений массива целых чисел на консоль — ShowArrayInt().
А, когда переопределяем функцию с помощью #define то нужно давать общее имя.
Например #define ShowArray ShowArrayInt.*/

template <typename TValue>
bool TryReadValue(
	TValue* result,
	istream& input,
	const streamsize ignoreCountOnError = 1,
	const int ignoreDelimiterOnError = EOF)
{
	while (true)
	{
		input >> *result;

		if (!input.fail())
			return true;

		if (input.eof())
			return false;

		input.clear();
		input.ignore(ignoreCountOnError, ignoreDelimiterOnError);
	}
}

template <typename TValue>
bool TryReadValue(
	TValue* result,
	istream& input,
	ostream& output,
	const string& inputMessage,
	const string& errorMessage,
	const streamsize ignoreCountOnError = 1,
	const int ignoreDelimiterOnError = EOF)
{
	while (true)
	{
		if (!inputMessage.empty())
			output << inputMessage;

		input >> *result;

		if (!input.fail())
			return true;

		if (input.eof())
			return false;

		input.clear();
		input.ignore(ignoreCountOnError, ignoreDelimiterOnError);

		if (!errorMessage.empty())
			output << errorMessage;
	}
}

template <typename TValue>
TValue CinValue(
	const string& inputMessage = " => ",
	const string& errorMessage = "Ошибка!\r\n",
	const streamsize ignoreCountOnError = numeric_limits<streamsize>::max(),
	const int ignoreDelimiterOnError = '\n')
{
	TValue value;
	TryReadValue<TValue>(
		&value,
		cin,
		cout,
		inputMessage,
		errorMessage,
		ignoreCountOnError,
		ignoreDelimiterOnError);

	return value;
}

template <typename TValue>
bool TryReadValueInRange(
	TValue* result,
	istream& input,
	const TValue startRange,
	const TValue endRange,
	const streamsize ignoreCountOnError = 1,
	const int ignoreDelimiterOnError = EOF)
{
	while (true)
	{
		bool inputResult =
			TryReadValue<TValue>(
				result,
				input,
				ignoreCountOnError,
				ignoreDelimiterOnError);

		if (inputResult && *result >= startRange && *result <= endRange)
			return true;
	}
}

template <typename TValue>
bool TryReadValueInRange(
	TValue* result,
	istream& input,
	ostream& output,
	const TValue startRange,
	const TValue endRange,
	const string& inputMessage,
	const string& errorMessage,
	const streamsize ignoreCountOnError = 1,
	const int ignoreDelimiterOnError = EOF)
{
	while (true)
	{
		bool inputResult =
			TryReadValue<TValue>(
				result,
				input,
				output,
				inputMessage,
				errorMessage,
				ignoreCountOnError,
				ignoreDelimiterOnError);

		if (inputResult && *result >= startRange && *result <= endRange)
			return true;

		if (!errorMessage.empty())
			output << errorMessage;
	}
}

template <typename TValue>
TValue CinValueInRange(
	const TValue startRange,
	const TValue endRange,
	const string& inputMessage = " => ",
	const string& errorMessage = "Ошибка!\r\n",
	const streamsize ignoreCountOnError = numeric_limits<streamsize>::max(),
	const int ignoreDelimiterOnError = '\n')
{
	TValue value;
	TryReadValueInRange<TValue>(
		&value,
		cin,
		cout,
		startRange,
		endRange,
		inputMessage,
		errorMessage,
		ignoreCountOnError,
		ignoreDelimiterOnError);

	return value;
}


//			ЗАДАЧА №1


void main()
{
	const int Size = 10;
	const int BeginValue = 65;
	const int EndValue = 90;
	const int firstIndex = 0;
	const int lastIndex = 9;

	setlocale(LC_ALL, "ru");
	srand(time(0));

#ifdef INTEGER
	int arr[Size];

	FillArray(arr, Size, BeginValue, EndValue);

	cout << "Изначальный массив int:" << endl;
	ShowArray(arr, Size);
	cout << endl;

	cout << "Индекс минимального элемента массива int: " << SearchMin(arr, Size) << endl << endl;
	cout << "Индекс максимального элемента массива int: " << SearchMax(arr, Size) << endl << endl;

	AscSortArray(arr, Size);

	cout << "Массив int после сортировки:" << endl;
	ShowArray(arr, Size);
	cout << endl;

	cout << "Редактирование элемента массива int по индексу:" << endl;
	int newValueInt;
	cout << "Введите новое значение";
	newValueInt = CinValue<int>();
	int replacedIntIndex;
	cout << "Введите индекс заменяемого элемента";
	replacedIntIndex = CinValueInRange(firstIndex, lastIndex);
	EditArray(arr, replacedIntIndex, newValueInt);
	cout << endl;

	cout << "Массив int после смены значения элемента:" << endl;
	ShowArray(arr, Size);
	cout << endl;
#endif

#ifdef DOUBLE
	double arr[Size];

	FillArray(arr, Size, BeginValue, EndValue);

	cout << "Изначальный массив double:" << endl;
	ShowArray(arr, Size);
	cout << endl;

	cout << "Индекс минимального элемента массива double: " << SearchMin(arr, Size) << endl << endl;
	cout << "Индекс максимального элемента массива double: " << SearchMax(arr, Size) << endl << endl;

	AscSortArray(arr, Size);

	cout << "Массив double после сортировки:" << endl;
	ShowArray(arr, Size);
	cout << endl;

	cout << "Редактирование элемента массива double по индексу:" << endl;
	double newValueDouble;
	cout << "Введите новое значение";
	newValueDouble = CinValue<double>();
	int replacedDoubleIndex;
	cout << "Введите индекс заменяемого элемента";
	replacedDoubleIndex = CinValueInRange(firstIndex, lastIndex);
	EditArray(arr, replacedDoubleIndex, newValueDouble);
	cout << endl;

	cout << "Массив double после смены значения элемента:" << endl;
	ShowArray(arr, Size);
	cout << endl;
#endif

#ifdef CHAR
	char arr[Size];

	FillArray(arr, Size, BeginValue, EndValue);

	cout << "Изначальный массив char:" << endl;
	ShowArray(arr, Size);
	cout << endl;

	cout << "Индекс минимального элемента массива char: " << SearchMin(arr, Size) << endl << endl;
	cout << "Индекс максимального элемента массива char: " << SearchMax(arr, Size) << endl << endl;

	AscSortArray(arr, Size);

	cout << "Массив char после сортировки:" << endl;
	ShowArray(arr, Size);
	cout << endl;

	cout << "Редактирование элемента массива char по индексу:" << endl;
	char newValueChar;
	cout << "Введите новое значение";
	newValueChar = CinValue<char>();
	int replacedCharIndex;
	cout << "Введите индекс заменяемого элемента";
	replacedCharIndex = CinValueInRange(firstIndex, lastIndex);
	EditArray(arr, replacedCharIndex, newValueChar);
	cout << endl;

	cout << "Массив char после смены значения элемента:" << endl;
	ShowArray(arr, Size);
	cout << endl;
#endif

	system("pause");
}