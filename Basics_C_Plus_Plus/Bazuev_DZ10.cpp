#include <iostream>
using namespace std;

void ShowResult(long long result)
{
	cout << "Результат: " << result << endl;
}


			//Задача №1
/*Напишите программу, которая вычисляет сумму целых 
чисел от а до 500 (значение a вводится с клавиатуры).*/

//int SumNumbers(int startNumber)
//{
//	int result = 0;
//	for (int i = startNumber; i <= 500; i++)
//		result += i;
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите число от 0 до 500 => ";
//	int number;
//	cin >> number;
//	while (number < 0 || number > 500)
//	{
//		cout << "Неверное число! Введите число от 0 до 500 => ";
//		cin >> number;
//	}
//	int result = SumNumbers(number);
//	ShowResult(result);
//	system("pause");
//}


			//Задача №2
/*Напишите программу, которая запрашивает два целых числа 
x и y, после чего вычисляет и выводит значение x в степени y.*/

//int Exponentiation(int number, int degree)
//{
//	int result = 1;
//	for (int i = 1; i <= degree; i++)
//		result *= number;
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите число (x) => ";
//	int number;
//	cin >> number;
//	cout << "Введите степень числа (y) => ";
//	int degree;
//	cin >> degree;
//	int result = Exponentiation(number, degree);
//	ShowResult(result);
//	system("pause");
//}


			//Задача №3
/*Найти среднее арифметическое всех целых чисел от 1 до 1000.*/

//void main()
//{
//	const int BeginValue = 1;
//	const int EndValue = 1000;
//	setlocale(LC_ALL, "ru");
//	double result = 0;
//	result = (EndValue + BeginValue) * EndValue / 2;
//	cout << "Среднее арифметическое суммы чисел от " << BeginValue << " до " << EndValue << ": " << result / EndValue;
//	cout << endl;
//	system("pause");
//}


			//Задача №4
/*Найти произведение всех целых чисел от a до 20 (значение 
a вводится с клавиатуры: 1 <=a <= 20).*/

//long long ProductOfNumbers(int beginValue)
//{
//	const int EndValue = 20;
//	long long result = 1;
//	for (int i = beginValue; i <= EndValue; i++)
//		result *= i;
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите число a => ";
//	int numberA;
//	cin >> numberA;
//	while (numberA < 1 || numberA > 20)
//	{
//		cout << "Неверное число! Введите число a = > ";
//		cin >> numberA;
//	}
//	long long result = ProductOfNumbers(numberA);
//	ShowResult(result);
//	system("pause");
//}


			//Задача №5 (1 вариант)
/*Написать программу, которая выводит на экран таблицу 
умножения на k, где k — номер варианта. Например, для 7-го 
варианта:
7 x 2 = 14;
7 x 3 = 21.
*/

//void MultiplicationTable(int number)
//{
//	for (int i = 1; i <= 10; i++)
//		cout << number << " x " << i << " = " << number * i << endl;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите число => ";
//	int number;
//	cin >> number;
//	MultiplicationTable(number);
//	system("pause");
//}


			//Задача №5 (2 вариант)
/*Написать программу, которая выводит на экран таблицу 
умножения на k, где k — номер варианта. Например, для 7-го 
варианта:
7 x 2 = 14;
7 x 3 = 21.
*/

//void MultiplicationTable(int option)
//{
//	cout << "Таблица умножения на " << option << ": " << endl;
//	switch (option)
//	{
//	case 1:
//		for (int i = 1; i <= 10; i++)
//			cout << 1 << " x " << i << " = " << 1 * i << endl;
//		break;
//	case 2:
//		for (int i = 1; i <= 10; i++)
//			cout << 2 << " x " << i << " = " << 2 * i << endl;
//		break;
//	case 3:
//		for (int i = 1; i <= 10; i++)
//			cout << 3 << " x " << i << " = " << 3 * i << endl;
//		break;
//	case 4:
//		for (int i = 1; i <= 10; i++)
//			cout << 4 << " x " << i << " = " << 4 * i << endl;
//		break;
//	case 5:
//		for (int i = 1; i <= 10; i++)
//			cout << 5 << " x " << i << " = " << 5 * i << endl;
//		break;
//	case 6:
//		for (int i = 1; i <= 10; i++)
//			cout << 6 << " x " << i << " = " << 6 * i << endl;
//		break;
//	case 7:
//		for (int i = 1; i <= 10; i++)
//			cout << 7 << " x " << i << " = " << 7 * i << endl;
//		break;
//	case 8:
//		for (int i = 1; i <= 10; i++)
//			cout << 8 << " x " << i << " = " << 8 * i << endl;
//		break;
//	case 9:
//		for (int i = 1; i <= 10; i++)
//			cout << 9 << " x " << i << " = " << 9 * i << endl;
//		break;
//	}
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "\tМеню" << endl;
//	cout << "1. Таблица умножения на 1;" << endl;
//	cout << "2. Таблица умножения на 2;" << endl;
//	cout << "3. Таблица умножения на 3;" << endl;
//	cout << "4. Таблица умножения на 4;" << endl;
//	cout << "5. Таблица умножения на 5;" << endl;
//	cout << "6. Таблица умножения на 6;" << endl;
//	cout << "7. Таблица умножения на 7;" << endl;
//	cout << "8. Таблица умножения на 8;" << endl;
//	cout << "9. Таблица умножения на 9;" << endl;
//	cout << endl;
//	cout << "Выберите вариант меню => ";
//	int option;
//	cin >> option;
//	cout << endl;
//	while (option < 1 || option > 9)
//	{
//		cout << "Такого варианта не существует! Выберите существующий вариант меню => ";
//		cin >> option;
//	}
//	MultiplicationTable(option);
//	system("pause");
//}