#include <iostream>
using namespace std;

void ShowResult(int result)
{
	cout << "Результат: " << result << endl;
}

void WritingNumberInArray(int value, int arr[], int size)
{
	arr[0] = value / 1000000000;
	arr[1] = value % 1000000000 / 100000000;
	arr[2] = value % 1000000000 % 100000000 / 10000000;
	arr[3] = value % 1000000000 % 100000000 % 10000000 / 1000000;
	arr[4] = value % 1000000000 % 100000000 % 10000000 % 1000000 / 100000;
	arr[5] = value % 1000000000 % 100000000 % 10000000 % 1000000 % 100000 / 10000;
	arr[6] = value % 1000000000 % 100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000;
	arr[7] = value % 1000000000 % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
	arr[8] = value % 1000000000 % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
	arr[9] = value % 1000000000 % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10;
}


//				ЗАДАЧА №1
/*Подсчитать количество целых чисел в диапазоне от 100
до 999, у которых есть две одинаковые цифры.*/

//bool CheckingForMatches(int firstDigit, int secondDigit, int thirthDigit)
//{
//	if(firstDigit == secondDigit || secondDigit == thirthDigit || firstDigit == thirthDigit)
//		return true;
//	return false;
//}
//
//int CountingIndenticalDigits(int beginValue, int endValue)
//{
//	int count = 0;
//	int firstDigit;
//	int secondDigit;
//	int thirthDigit;
//	for(int i = beginValue; i <= endValue; i++)
//	{
//		firstDigit = i / 100;
//		secondDigit = i % 100 / 10;
//		thirthDigit = i % 100 % 10;
//		if (CheckingForMatches(firstDigit, secondDigit, thirthDigit))
//			count++;
//	}
//	return count;
//}
//
//void main()
//{
//	const int BeginValue = 100;
//	const int EndValue = 999;
//	setlocale(LC_ALL, "ru");
//	cout << "Количество целых чисел в диапазоне от 100 до 999, у которых есть две одинаковые цифры:" << endl;
//	ShowResult(CountingIndenticalDigits(BeginValue, EndValue));
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №2
/*Подсчитать количество целых чисел в диапазоне от 100 до 
999, у которых все цифры разные.*/

//bool CheckingForMatches(int firstDigit, int secondDigit, int thirthDigit)
//{
//	if (firstDigit != secondDigit && secondDigit != thirthDigit && firstDigit != thirthDigit)
//		return true;
//	return false;
//}
//
//int CountingIndenticalDigits(int beginValue, int endValue)
//{
//	int count = 0;
//	int firstDigit;
//	int secondDigit;
//	int thirthDigit;
//	for (int i = beginValue; i <= endValue; i++)
//	{
//		firstDigit = i / 100;
//		secondDigit = i % 100 / 10;
//		thirthDigit = i % 100 % 10;
//		if (CheckingForMatches(firstDigit, secondDigit, thirthDigit))
//			count++;
//	}
//	return count;
//}
//
//void main()
//{
//	const int BeginValue = 100;
//	const int EndValue = 999;
//	setlocale(LC_ALL, "ru");
//	cout << "Количество целых чисел в диапазоне от 100 до 999, у которых все цифры разные:" << endl;
//	ShowResult(CountingIndenticalDigits(BeginValue, EndValue));
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №3
/*Пользователь вводит любое целое число. Необходимо из 
этого целого числа удалить все цифры 3 и 6 и вывести обратно 
на экран.*/

//bool CheckingNumber(int value)
//{
//	if (value == 3 || value == 6 || value == - 3 || value == - 6)
//		return false;
//	return true;
//}
//
//int SummationTheNumber(int arr[], int size, int multiplier)
//{
//	int result = 0;
//	for (int i = 0; i < size; i++)
//	{
//		result = result + arr[i] * multiplier;
//		multiplier /= 10;
//	}
//	return result;
//}
//
//int RemoveDigit3And6(int arr[], int size)
//{
//	int multiplier = 1000000000;
//	int finalSize = size;
//	int j = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (CheckingNumber(arr[i]))
//		{
//			arr[j] = arr[i];
//		}
//		else
//		{
//			j--;
//			finalSize--;
//			multiplier /= 10;
//		}
//		j++;
//	}
//	return SummationTheNumber(arr, finalSize, multiplier);
//}
//
//void main()
//{
//	const int BeginRange = -2000000000;
//	const int EndRange = 2000000000;
//	const int Size = 10;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите целое число от -2 000 000 000 до 2 000 000 000 => ";
//	int value;
//	cin >> value;
//	if (value < BeginRange || value > EndRange)
//	{
//		cout << "Число за пределами диапазона!";
//		cout << endl;
//		system("pause");
//		return;
//	}
//	int arr[Size];
//	WritingNumberInArray(value, arr, Size);
//	cout << "Введенное число без цифр 3 и 6:" << endl;
//	ShowResult(RemoveDigit3And6(arr, Size));
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №4
/*Пользователь вводит любое целое число А. Необходимо 
вывести все целые числа В, для которых А делиться без остатка 
на В*В и не делиться без остатка на В*В*В.*/

//bool divisionByCube(int A, int B)
//{
//	B = B * B * B;
//	if(A % B != 0)
//		return true;
//	return false;
//}
//
//bool DivisionBySquared(int A, int B)
//{
//	B = B * B;
//	if (A % B == 0)
//		return true;
//	return false;
//}
//
//void CheckingNumberA(int A)
//{
//	for (int i = 1; i <= A; i++)
//		if (divisionByCube(A, i) && DivisionBySquared(A, i))
//			ShowResult(i);
//}
//
//void main()
//{
//	const int BeginRange = 1;
//	const int EndRange = 2000000000;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите целое число A в диапазоне от 1 до 2 000 000 000 => ";
//	int A;
//	cin >> A;
//	if (A < BeginRange || A > EndRange)
//	{
//		cout << "Число за пределами диапазона!";
//		cout << endl;
//		system("pause");
//		return;
//	}
//	cout << "Целые числа В, для которых А делиться без остатка на В * В и не делиться без остатка на В * В * В:" << endl;
//	CheckingNumberA(A);
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №5
/*Пользователь вводит целое число А. Программа должна 
определить, что куб суммы цифр этого числа равен А*А.*/

//void EqualityCheck(int A, int sum)
//{
//	if(A * A == sum * sum * sum)
//		cout << "Куб суммы цифр числа А равен квадрату числа А.";
//	else
//		cout << "Куб суммы цифр числа А НЕравен квадрату числа А!!!";
//}
//
//int SummationDigitsInArray(int arr[], int size)
//{
//	int result = 0;
//	for(int i = 0; i < size; i++)
//	{
//		result += arr[i];
//		
//	}
//	cout << "Сумма цифр числа А: " << result << endl;
//	return result;
//}
//
//void main()
//{
//	const int BeginRange = 1;
//	const int EndRange = 2000000000;
//	const int Size = 10;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите целое число А в диапазоне от 1 до 2 000 000 000 => ";
//	int A;
//	cin >> A;
//	if (A < BeginRange || A > EndRange)
//	{
//		cout << "Число за пределами диапазона!";
//		cout << endl;
//		system("pause");
//		return;
//	}
//	int arr[Size];
//	WritingNumberInArray(A, arr, Size);
//	EqualityCheck(A, SummationDigitsInArray(arr, Size));
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №6
/*Пользователь вводит целое число. Необходимо вывести все 
целые числа, на которое заданное число делиться без остатка.*/

//void CheckingForDivisionWithoutRemainder(int value)
//{
//	for(int i = 1; i <= value; i++)
//	{
//		if (value % i == 0)
//			ShowResult(i);
//	}
//}
//
//void main()
//{
//	const int BeginRange = 1;
//	const int EndRange = 2000000000;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите целое число в диапазоне от 1 до 2 000 000 000 => ";
//	int value;
//	cin >> value;
//	if (value < BeginRange || value > EndRange)
//	{
//		cout << "Число за пределами диапазона!";
//		cout << endl;
//		system("pause");
//		return;
//	}
//	cout << "Целые числа, на которое заданное число делиться без остатка:" << endl;
//	CheckingForDivisionWithoutRemainder(value);
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №7
/*Пользователь вводит два целых числа. Необходимо вывести все целые числа, на которые оба введенных числа делятся 
без остатка.*/

//void CheckingForDivisionWithoutRemainder(int firstValue, int secondValue)
//{
//	int size;
//	if (firstValue < secondValue)
//		size = firstValue;
//	else
//		size = secondValue;
//	for (int i = 1; i <= size; i++)
//	{
//		if (firstValue % i == 0 && secondValue % i == 0)
//			ShowResult(i);
//	}
//}
//
//void main()
//{
//	const int BeginRange = 1;
//	const int EndRange = 2000000000;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите целое число №1 в диапазоне от 1 до 2 000 000 000 => ";
//	int firstValue;
//	cin >> firstValue;
//	cout << firstValue << endl;
//	if(firstValue < BeginRange || firstValue > EndRange)
//	{
//		cout << "Число за пределами диапазона!";
//		cout << endl;
//		system("pause");
//		return;
//	}
//	cout << "Введите целое число №2 в диапазоне от 1 до 2 147 483 647 => ";
//	int secondValue;
//	cin >> secondValue;
//	if (secondValue < BeginRange || secondValue > EndRange)
//	{
//		cout << "Число за пределами диапазона!";
//		cout << endl;
//		system("pause");
//		return;
//	}
//	cout << "Целые числа, на которые оба введенных числа делятся без остатка:" << endl;
//	CheckingForDivisionWithoutRemainder(firstValue, secondValue);
//	cout << endl;
//	system("pause");
//}
