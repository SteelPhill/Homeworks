#include <iostream>
using namespace std;

void ShowResult(double result)
{
	cout << "Результат: " << result << endl;
}


//			ЗАДАЧА №1
/*Пользователь вводит число. Определить количество цифр 
в этом числе, посчитать их сумму и среднее арифметическое. 
Определить количество нулей в этом числе. Общение с пользователем организовать через меню.*/

//int NumberOfDigits(int value)
//{
//	int count = 0;
//	while (value > 0)
//	{
//		value /= 10;
//		count++;
//	}
//	return count;
//}
//
//int SumOfDigits(int value)
//{
//	int sum = 0;
//	while (value > 0)
//	{
//		sum += value % 10;
//		value /= 10;
//	}
//	return sum;
//}
//
//double ArithmeticMean(int value)
//{
//	int count = 0;
//	double sum = 0;
//	while (value > 0)
//	{
//		sum += value % 10;
//		value /= 10;
//		count++;
//	}
//	return sum / count;
//}
//
//int NumberOfZeros(int value)
//{
//	int count = 0;
//	while (value > 0)
//	{
//		if (value % 10 == 0)
//			count++;
//		value /= 10;
//	}
//	return count;
//}
//
//double MenuSelection(int option, int value)
//{
//	double result;
//	switch (option)
//	{
//	case 1:
//		result = NumberOfDigits(value);
//		break;
//	case 2:
//		result = SumOfDigits(value);
//		break;
//	case 3:
//		result = ArithmeticMean(value);
//		break;
//	case 4:
//		result = NumberOfZeros(value);
//		break;
//	}
//	return result;
//}
//
//int Menu()
//{
//	cout << "\tМеню." << endl;
//	cout << "1.Определить количество цифр в этом числе;" << endl;
//	cout << "2.Посчитать сумму цифр в этом числе;" << endl;
//	cout << "3.Посчитать среднее арифметическое суммы цифр в этом числе;" << endl;
//	cout << "4.Определить количество нулей в этом числе;" << endl;
//	cout << "0.Завершить работу программы." << endl;
//	cout << endl;
//	cout << "Выберите пункт меню => ";
//	int option;
//	cin >> option;
//	while (option < 0 || option > 4)
//	{
//		cout << "Некорректный ввод! Выберите пункт меню => ";
//		cin >> option;
//	}
//	cout << endl;
//	return option;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите число в диапазоне от 1 до 2 000 000 000 => ";
//	int value;
//	cin >> value;
//	cout << endl;
//	cout << "Введенное число: " << value << endl;
//	while (value < 1 || value > 2000000000)
//	{
//		cout << "Некорректный ввод! Введите число в диапазоне от 1 до 2 000 000 000 => ";
//		cin >> value;
//	}
//	cout << endl;
//	int option = Menu();
//	while (option != 0)
//	{
//		ShowResult(MenuSelection(option, value));
//		cout << endl;
//		system("pause");
//		system("cls");
//		cout << "Введенное число: " << value << endl;
//		cout << endl;
//		option = Menu();
//	}
//	cout << "Завершение работы программы..." << endl;
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №2
/*Написать программу, которая выводит на экран шахматную 
доску с заданным размером клеточки.
Например,
***---***---***---***---
***---***---***---***---
***---***---***---***---
---***---***---***---***
---***---***---***---***
---***---***---***---***
*/

//void OddRow(int cellSize, int NumberColumns)
//{
//	for (int i = 1; i <= cellSize; i++)
//	{
//		for (int j = 1; j <= NumberColumns; j++)
//		{
//			int k = 1;
//			while (k <= cellSize)
//			{
//				cout << "-";
//				k++;
//			}
//			k = 1;
//			while (k <= cellSize)
//			{
//				cout << "+";
//				k++;
//			}
//		}
//		cout << endl;
//	}
//}
//
//void EvenRow(int cellSize, int NumberColumns)
//{
//	for (int i = 1; i <= cellSize; i++)
//	{
//		for (int j = 1; j <= NumberColumns; j++)
//		{
//			int k = 1;
//			while (k <= cellSize)
//			{
//				cout << "+";
//				k++;
//			}
//			k = 1;
//			while (k <= cellSize)
//			{
//				cout << "-";
//				k++;
//			}
//		}
//		cout << endl;
//	}
//}
//
//void creatingBoard(int cellSize)
//{
//	const int NumberRows = 8;
//	const int NumberColumns = 8;
//	const int UnityTwoDifferentCells = NumberColumns / 2;
//	for (int i = 1; i <= NumberRows; i++)
//	{
//		if (i % 2 == 0)
//			EvenRow(cellSize, UnityTwoDifferentCells);
//		else
//			OddRow(cellSize, UnityTwoDifferentCells);
//	}
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите размер ячейки шахматной доски => ";
//	int cellSize;
//	cin >> cellSize;
//	while (cellSize < 1)
//	{
//		cout << "Некорректный ввод! Введите размер ячейки шахматной доски => ";
//		cin >> cellSize;
//	}
//	cout << endl;
//	cout << "Размер ячейки: " << cellSize << " x " << cellSize << endl;
//	cout << endl;
//	creatingBoard(cellSize);
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3
/*Реализовать программу расчета заказа в кафетерии 
при условии, что заказ может быть на несколько человек и 
каждый клиент формирует свою часть заказа. Необходимо 
спросить у пользователя на сколько человек заказ. Далее 
каждому человеку выводиться меню (названия напитков, 
кондитерских изделий и их цена) и он выбирает. Предусмотреть возможность выбора нескольких элементов меню для 
клиента, если он желает добавить еще что-то в свой заказ. 
Результат работы программы — итоговая сумма общего 
заказа всей компании.*/

//int SelectingMenuPosition(int position)
//{
//	int cost;
//	switch (position)
//	{
//	case 1:
//		cost = 100;
//		break;
//	case 2:
//		cost = 125;
//		break;
//	case 3:
//		cost = 150;
//		break;
//	case 4:
//		cost = 50;
//		break;
//	case 5:
//		cost = 75;
//		break;
//	case 6:
//		cost = 100;
//		break;
//	}
//	return cost;
//}
//
//void Menu()
//{
//	cout << endl;
//	cout << "\tМеню." << endl;
//	cout << endl;
//	cout << "\tДесерты:" << endl;
//	cout << "1.Кекс      \t100р." << endl;
//	cout << "2.Мороженное\t125р." << endl;
//	cout << "3.Пироженное\t150р." << endl;
//	cout << endl;
//	cout << "\tНапитки:" << endl;
//	cout << "4.Чай       \t50р." << endl;
//	cout << "5.Кофе      \t75р." << endl;
//	cout << "6.Сок       \t100р." << endl;
//	cout << endl;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "На сколько человек заказ => ";
//	int numberPersons;
//	cin >> numberPersons;
//	while (numberPersons < 1)
//	{
//		cout << "Некорректный ввод!" << endl;
//		cout << "На сколько человек заказ => ";
//		cin >> numberPersons;
//	}
//	cout << endl;
//	int positionSelection;
//	int orderCounter = 1;
//	int orderSum = 0;
//	while (orderCounter <= numberPersons)
//	{
//		cout << "Промежуточная сумма заказа: " << orderSum << "р." << endl;
//		Menu();
//		cout << "Выберите позицию меню для " << orderCounter << "-ого клиента." << endl;
//		cout << "Нажмите 0 для завершения заказа " << orderCounter << "-ого клиента." << endl;
//		cout << "=> ";
//		cin >> positionSelection;
//		if (positionSelection != 0)
//		{
//			orderSum += SelectingMenuPosition(positionSelection);
//			system("cls");
//		}
//		else
//		{
//			orderCounter++;
//			system("cls");
//			continue;
//		}
//
//		
//	}
//	cout << "Окончательная сумма заказа: " << orderSum << "р." << endl;
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №4
/*Есть пустое поле игры «Морской бой».
Вывести в консоль номера полей игры:
A0 B0 C0 D0 E0 F0 G0 H0 I0 J0
A1 B1 C1 D1 E1 F1 G1 H1 I1 J1
…..
A9 B9 C9 D9 E9 F9 G9 H9 I9 J9
*/

//void FillingInField()
//{
//	const int NumberRows = 10;
//	const int NumberColumns = 10;
//	const int CodeOfSymbolA = 65;
//	for (int i = 0; i < NumberRows; i++)
//	{
//		for (char j = CodeOfSymbolA; j < NumberColumns + CodeOfSymbolA; j++)
//			cout << j << i << " ";
//		cout << endl;
//	}
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << endl;
//	FillingInField();
//	cout << endl;
//	system("pause");
//}