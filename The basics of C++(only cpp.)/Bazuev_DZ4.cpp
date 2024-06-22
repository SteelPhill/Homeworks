#include <iostream>
using namespace std;


			//Задание 1
/*Пользователь вводит с клавиатуры время в секундах. Необходимо написать программу, которая переведет введенные 
пользователем секунды в часы, минуты, секунды и выводит их на экран.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int secondsPerMinute = 60;
//	const int secondsPerHour = 3600;
//	cout << "Введите время в секундах => ";
//	int seconds;
//	cin >> seconds;
//	cout << "Время: " << seconds / secondsPerHour << " ч. " << seconds % secondsPerHour / 60
//		 << " м. " << seconds % secondsPerHour % 60  << " с. " << endl;
//	system("pause");
//}

			//Задание 2
/*Написать программу, которая преобразует введенное с 
клавиатуры дробное число в денежный формат. Например, 
число 12,5 должно быть преобразовано к виду — 12 долларов 
и 50 центов.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int kopecksInRubles = 100;
//	cout << "Введите количество рублей и копеек в формате дробного числа => ";
//	double money;
//	cin >> money;
//	int rubles = money;
//	int kopecks = (money - rubles) * kopecksInRubles;
//	cout << "Сумма: " << rubles << " руб. " << kopecks << " коп. " << endl;
//	system("pause");
//}

			//Задание 3
/*Написать программу, которая преобразует введенное 
пользователем количество дней в количество полных недель 
и оставшихся дней. Например, пользователь ввел 17 дней, 
программа должна вывести на экран 2 недели и 3 дня.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int daysPerWeek = 7;
//	cout << "Введите количество дней => ";
//	int daysEntered;
//	cin >> daysEntered;
//	int weeks = daysEntered / daysPerWeek;
//	int days = daysEntered % daysPerWeek;
//	cout << "Прошло: " << weeks << " нед. " << days << " дн. " << endl;
//	system("pause");
//}

			//Задание 4
/*Написать программу, вычисляющую, с какой скоростью 
бегун пробежал дистанцию.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int secondsPerMinute = 60;
//	const int secondsPerHour = 3600;
//	const int metersPerKilometer = 1000;
//	const int secondsMultiplier = 100;
//	cout << "Вычисление скорости бега" << endl;
//	cout << "Введите длину дистанции (метров) = ";
//	int distance;
//	cin >> distance;
//	cout << "Введите время (мин.сек) = ";
//	double timeInMinutes;
//	cin >> timeInMinutes;
//	cout << "Дистанция: " << distance << " м" << endl;
//	int minutes = timeInMinutes;
//	int seconds = (timeInMinutes - minutes) * secondsMultiplier;
//	int timeInSeconds = minutes * secondsPerMinute + seconds;
//	cout << "Время: " << minutes << " мин " << seconds << " сек = " 
//		 << timeInSeconds << " сек" << endl;
//	double velocity =  ((double) distance / metersPerKilometer) /
//		  ((double) timeInSeconds / secondsPerHour);
//	cout << "Вы бежали со скоростью " << velocity  << " км/ч" << endl;
//	system("pause");
//}

			//Задание 5
/*Написать программу, которая предлагает пользователю 
ввести сумму денежного вклада в евро, а также процент годовых, которые выплачивает банк. Определить сумму денег, 
выплачиваемых банком вкладчику каждый месяц.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//	const int monthsPerYear = 12;
//	const double OneHundredPercent = 100.0;
//	cout << "Введите сумму денежного вклада в евро => ";
//	double deposit;
//	cin >> deposit;
//	cout << "Введите процент годовых, которые выплачивает банк => ";
//	double percent;
//	cin >> percent;
//	for (int i = 1; i <= monthsPerYear; i++)
//	{
//		double depositNow = deposit + (deposit * (percent / OneHundredPercent));
//		deposit = depositNow;
//		cout << "Сумма вклада в " << i << " месяц = " << depositNow << endl;
//	}
//	system("pause");
//}