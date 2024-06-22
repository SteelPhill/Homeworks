#include <iostream>
using namespace std;


			//Задание 1
/*Пользователь вводит с клавиатуры время в секундах, прошедшее с начала дня. Вывести на экран текущее время в часах, 
минутах и секундах. Посчитать, сколько часов, минут и секунд 
осталось до полуночи.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int secondPerMinute = 60;
//	const int secondPerHour = 3600;
//	const int secondPerDay = 86400;
//	int pastTime;
//	cout << "Введите время в секундах, прошедшее с начала дня => ";
//	cin >> pastTime;
//	while (pastTime < 0 || pastTime > secondPerDay)
//	{
//		cout << "Введенное значение невозможно! " << endl;
//		cout << "Ещё раз введите время в секундах, прошедшее с начала дня => ";
//		cin >> pastTime;
//	}
//	int pastTimeInHours = pastTime / secondPerHour;
//	int pastTimeInMinutes = pastTime % secondPerHour / secondPerMinute;
//	int pastTimeInSeconds = pastTime % secondPerHour % secondPerMinute;
//	cout << "С начала дня прошло: " << pastTimeInHours << " ч. " << pastTimeInMinutes << " м. " << pastTimeInSeconds << " с." << endl;
//	int timeLeftInHours = (secondPerDay - pastTime) / secondPerHour;
//	int timeLeftInMinutes = (secondPerDay - pastTime) % secondPerHour / secondPerMinute;
//	int timeLeftInSeconds = (secondPerDay - pastTime) % secondPerHour % secondPerMinute;
//	cout << "До конца дня осталось: " << timeLeftInHours << " ч. " << timeLeftInMinutes << " м. " << timeLeftInSeconds << " с." << endl;
//	system("pause");
//}


			//Задание 2
/*Пользователь вводит с клавиатуры время в секундах, прошедшее с начала рабочего дня. Посчитать, сколько целых часов 
ему осталось работать если рабочий день — 8 часов.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int secondPerHour = 3600;
//	const int workingDayInSeconds = 28800;
//	int pastTime;
//	cout << "Введите время в секундах, прошедшее с начала рабочего дня => ";
//	cin >> pastTime;
//	while (pastTime < 0 || pastTime > workingDayInSeconds)
//	{
//		cout << "Введенное значение невозможно! " << endl;
//		cout << "Ещё раз введите время в секундах, прошедшее с начала рабочего дня => ";
//		cin >> pastTime;
//	}
//	int timeLeftInHours = (workingDayInSeconds - pastTime) / secondPerHour;
//	cout << "Целых часов до конца дня осталось: " << timeLeftInHours << endl;
//	system("pause");
//}