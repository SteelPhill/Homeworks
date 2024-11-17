#include <iostream>
using namespace std;


			//Задание 1
/*Пользователь вводит с клавиатуры расстояние до аэропорта и время, за которое нужно доехать. Вычислить скорость, с 
которой ему нужно ехать.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int minutesPerHour = 60;
//	cout << "Введите расстояние до аэропорта в километрах => ";
//	double distance;
//	cin >> distance;
//	double timeInMinutes;
//	cout << "Введите время, за которое необходимо доехать в минутах => ";
//	cin >> timeInMinutes;
//	while(timeInMinutes == 0 && distance != 0)
//	{
//		cout << "Некорректное время! Введите значение повторно => ";
//		cin >> timeInMinutes;
//	}
//	double timeInHours = timeInMinutes / minutesPerHour;
//	double velocity = distance / timeInHours;
//	cout << "Скорость, с которой нужно ехать равна " << velocity << " км/ч" << endl;
//	system("pause");
//}


			// Задание 2
/*Пользователь вводит с клавиатуры время начала и время 
завершения использования скутера (часы, минутыи секунды).
Посчитать стоимость поездки, если стоимость минуты - 2 рубля.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int rublesPerMinute = 2;
//	const int secondsPerHour = 3600;
//	const int secondsPerMinutes = 60;
//	const int secondsPerDay = 86400;
//	cout << "Введите время начала использования скутера:" << endl;
//	int startHours;
//	int startMinutes;
//	int startSeconds;
//	cout << "Часы => ";
//	cin >> startHours;
//	cout << "Минуты => ";
//	cin >> startMinutes;
//	cout << "Секунды => ";
//	cin >> startSeconds;
//	cout << endl <<"Введите время окончания использования скутера:" << endl;
//	int endHours;
//	int endMinutes;
//	int endSeconds;
//	cout << "Часы => ";
//	cin >> endHours;
//	cout << "Минуты => ";
//	cin >> endMinutes;
//	cout << "Секунды => ";
//	cin >> endSeconds;
//	double totalStart;
//	double totalEnd;
//	double usageTime;
//	if(startHours > endHours)  //Если начало поездки в один день, а конец на следующий день
//	{
//		totalStart = secondsPerDay - (startHours * secondsPerHour + startMinutes * secondsPerMinutes + startSeconds);
//		totalEnd = endHours * secondsPerHour + endMinutes * secondsPerMinutes + endSeconds;
//		usageTime = totalEnd + totalStart;
//	}
//	else
//	{
//		totalStart = startHours * secondsPerHour + startMinutes * secondsPerMinutes + startSeconds;
//		totalEnd = endHours * secondsPerHour + endMinutes * secondsPerMinutes + endSeconds;
//		usageTime = totalEnd - totalStart;
//	}
//	int costOfTravel;
//	if(usageTime / secondsPerMinutes - (int) usageTime / secondsPerMinutes == 0)
//		costOfTravel = (usageTime / secondsPerMinutes) * rublesPerMinute;
//	else
//		costOfTravel = ((int) usageTime / secondsPerMinutes + 1) * rublesPerMinute;  //Округление стоимости в большую сторону
//	cout << endl << "Стоимость поездки: " << costOfTravel << " руб." << endl << endl;
//	system("pause");
//}


			//Задание 3
/*Пользователь вводит с клавиатуры расстояние, расход 
бензина на 100 км и стоимость трех видов бензина. Вывести 
на экран сравнительную таблицу со стоимостью поездки на 
разных видах бензина.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int probeg100km = 100;
//	cout << "Введите расстояние в километрах, которое необходимо проехать => ";
//	double distance;
//	cin >> distance;
//	cout << "Введите расход бензина на 100 км. в литрах => ";
//	double fuelConsumption;
//	cin >> fuelConsumption;
//	cout << "Введите стоймость трёх видов бензина:" << endl;
//	cout << "АИ-92 => ";
//	double ai92;
//	cin >> ai92;
//	cout << "АИ-95 => ";
//	double ai95;
//	cin >> ai95;
//	cout << "АИ-98 => ";
//	double ai98;
//	cin >> ai98;
//	cout << endl << "Стоймость поездки на расстояние " << distance << " км. при использовании бензина:" << endl;
//	cout << endl << "\tАИ-92\t  =\t" << fuelConsumption / probeg100km * distance * ai92 << endl;
//	cout << "\tАИ-95\t  =\t" << fuelConsumption / probeg100km * distance * ai95 << endl;
//	cout << "\tАИ-98\t  =\t" << fuelConsumption / probeg100km * distance * ai98 << endl << endl;
//	system("pause");
//}