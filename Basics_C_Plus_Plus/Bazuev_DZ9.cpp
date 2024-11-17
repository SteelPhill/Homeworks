#include <iostream>;
using namespace std;


			//Задача 1
/*Пользователь вводит с клавиатуры символ. Определить, 
какой это символ: Буква, цифра, знак препинания или другое.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	cout << "Введите символ с клавиатуры => ";
//	char symbol;
//	cin >> symbol;
//	cout << endl;
//	if(symbol >= 48 && symbol <= 57)
//		cout << "Это цифра" << endl;
//	else if(symbol >= 65 && symbol <= 90)
//		cout << "Это прописная буква" << endl;
//	else if(symbol >= 97 && symbol <= 122)
//		cout << "Это строчная буква" << endl;
//	else if (symbol == 33 || symbol == 34 || symbol == 40 || symbol == 41 || symbol == 44 ||
//			 symbol == 45 || symbol == 46 || symbol == 58 || symbol == 59 || symbol == 63)
//	{
//		cout << "Это знак препинания";
//		if(symbol == 45)
//			cout << " и знак арифметического действия";
//		cout << endl;
//	}
//	else if(symbol == 37 || symbol == 42 || symbol == 43 || symbol == 47 || symbol == 61)
//		cout << "Это знак арифметического действия" << endl;
//	else
//		cout << "Это специальный символ" << endl;
//	cout  << endl;
//	system("pause");
//}


			//Задача 2
/*Написать программу подсчета стоимости разговора для 
разных мобильных операторов. Пользователь вводит длительность разговора и выбирает с какого на какой оператор 
он звонит. Вывести стоимость на экран.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const double MinutePriceMTS = 3;
//	const double MinutePriceTELE2 = 3.5;
//	const double MinutePriceBEELINE = 4;
//	const int SecondsPerMinute = 60;
//	cout << "Список доступных операторов:" << endl;
//	cout << "\t1.МТС" << endl;
//	cout << "\t2.ТЕЛЕ2" << endl;
//	cout << "\t3.Билайн" << endl;
//	cout << endl;
//	cout << "Выберите оператора ИСХОДЯЩЕГО звонка (пункт меню) => ";
//	int outcomingCallOperator;
//	cin >> outcomingCallOperator;
//	while (outcomingCallOperator < 1 || outcomingCallOperator > 3)
//	{
//		cout << "Неверный код! Выберите оператора ИСХОДЯЩЕГО звонка (пункт меню) => ";
//		cin >> outcomingCallOperator;
//	}
//	cout << "Выберите оператора ВХОДЯЩЕГО звонка (пункт меню) => ";
//	int incomingCallOperator;
//	cin >> incomingCallOperator;
//	while (incomingCallOperator < 1 || incomingCallOperator > 3)
//	{
//		cout << "Неверный код! Выберите оператора ВХОДЯЩЕГО звонка (пункт меню) => ";
//		cin >> incomingCallOperator;
//	}
//	cout << "Введите продолжительность звонка в секундах => ";
//	double timeCall;
//	cin >> timeCall;
//	cout << endl;
//	if(outcomingCallOperator == incomingCallOperator)
//		cout << "Звонок - бесплатный." << endl;
//	else if(outcomingCallOperator == 1)
//		cout << "Стоймость звонка: " << MinutePriceMTS * (timeCall / SecondsPerMinute) << endl;
//	else if (outcomingCallOperator == 2)
//		cout << "Стоймость звонка: " << MinutePriceTELE2 * (timeCall / SecondsPerMinute) << endl;
//	else if (outcomingCallOperator == 3)
//		cout << "Стоймость звонка: " << MinutePriceBEELINE * (timeCall / SecondsPerMinute) << endl;
//	cout  << endl;
//	system("pause");
//}


			//Задача 3
/*Вася работает программистом и получает 50$ за каждые 
штрафуют на 20$. Реализовать меню:
- пользователь вводит желаемый доход Васи и количество 
опозданий, посчитать, сколько строк кода емунадонаписать;
- пользователь вводит количество строк кода, написанное 
Васей и желаемый объем зарплаты. Посчитать, сколько 
раз Вася может опоздать;
- пользователь вводит количество строк кода и количество
опозданий, определить, сколько денег заплатят Васе и
заплатят ли вообще.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int Cost100Strng = 50;
//	const double Cost1String = Cost100Strng / 100.0;
//	const int CostEvery3Delay = 20;
//	cout << " \tМеню:" << endl;
//	cout << " 1. Введите желаемый доход и количество опозданий, чтобы узнать, сколько строк нужно написать." << endl;
//	cout << " 2. Введите количество строк и желаемый уровень зарплаты, чтобы узнать, сколько раз можно опоздать." << endl;
//	cout << " 3. Введите количество строк и количество опозданий, чтобы узнать зарплату." << endl;
//	cout << " 0. Закончить выполнение программы." << endl;
//	cout << endl;
//	cout << " Выберите пункт меню => ";
//	int choice;
//	cin >> choice;
//
//	while (choice < 0 || choice > 3)
//	{
//		cout << "Такого пункта меню не существует!" << endl;
//		cout << "Выберите пункт меню => ";
//		cin >> choice;
//	}
//
//	if(choice == 0)
//		system("pause");
//
//	cout << endl;
//	double income;
//	int numberDelays;
//	int numberStringsOfCode;
//	double penalty = 0;
//	double result = 0;
//
//	switch (choice)
//	{
//	case 1:
//		cout << "Введите желаемый доход => ";
//		cin >> income;
//		cout << "Введите количество опозданий => ";
//		cin >> numberDelays;
//		if (numberDelays >= 3)
//			penalty = numberDelays / 3 * CostEvery3Delay;
//		result = (income + penalty) / Cost1String;
//		cout << "Необходимо написать строк кода: " << result << endl;
//		break;
//	case 2:
//		cout << "Введите количество написанных строк кода => ";
//		cin >> numberStringsOfCode;
//		cout << "Введите желаемый доход => ";
//		cin >> income;
//		penalty = numberStringsOfCode * Cost1String - income;
//		cout << "Остаток от дохода, который можно потратиь на опоздания: " << penalty << endl;
//		if (penalty / CostEvery3Delay >= 1)
//		{
//			for (int i = penalty; i >= CostEvery3Delay; i -= CostEvery3Delay)
//				result += 3;
//		}
//		result += 2;
//		cout << "Можно опоздать раз: " << result << endl;
//		break;
//	case 3:
//		cout << "Введите количество написанных строк кода => ";
//		cin >> numberStringsOfCode;
//		cout << "Введите количество опозданий => ";
//		cin >> numberDelays;
//		if (numberDelays / 3 >= 1)
//			penalty = numberDelays / 3 * CostEvery3Delay;
//		result = numberStringsOfCode * Cost1String - penalty;
//		if(result > 0)
//			cout << "Зарплата: " << result << endl;
//		else
//			cout << "Зарплаты не будет!" << endl;
//		break;
//	}
//
//	cout << endl;
//	system("pause");
//}