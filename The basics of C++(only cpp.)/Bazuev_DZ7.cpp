#include <iostream>
using namespace std;


			//Задача 1
/*Пользователь вводит с клавиатуры целое шестизначное 
число. Написать программу, которая определяет, является ли 
введенное число — счастливым (Счастливым считается шестизначное число, у которого сумма первых 3 цифр равна сумме 
вторых трех цифр). Если пользователь ввел не шестизначное 
число — сообщение об ошибке.*/

//void main()
//{
//	const int size = 6;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите шестизначное число => ";
//	int number;
//	cin >> number;
//	if (number < 100000 || number > 999999)
//	{
//		cout << "Ошибка! Введенное число не шестизначное!";
//		cout << endl;
//		system("pause");
//	}
//	int arr[size];
//	int divider = 1;
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = number / divider % 10;
//		divider *= 10;
//	}
//	if (arr[0] + arr[1] + arr[2] == arr[3] + arr[4] + arr[5])
//		cout << "Это счастливое число!";
//	cout << endl;
//	system("pause");
//}


			//Задача 2
/*Пользователь вводит четырехзначное число. Необходимо 
поменять в этом числе 1 и 2 цифры, а также 3 и 4 цифры. Если 
пользователь вводит не четырехзначное число — вывести 
сообщение об ошибке.*/

//void main()
//{
//	const int size = 4;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите четырехзначное число => ";
//	int number;
//	cin >> number;
//	if (number < 1000 || number > 9999)
//	{
//		cout << "Ошибка! Введенное число не четырехзначное!";
//		cout << endl;
//		system("pause");
//	}
//	int arr[size];
//	int divider = 1;
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = number / divider % 10;
//		divider *= 10;
//	}
//	swap(arr[0], arr[1]);
//	swap(arr[2], arr[3]);
//	int result = 0;
//	int multiplier = 1;
//	for (int i = 0; i < size; i++)
//	{
//		result = result + arr[i] * multiplier;
//		multiplier *= 10;
//	}
//	cout << "Результат: " << result << endl;
//	system("pause");
//}


			//Задача 3
/*Пользователь вводит с клавиатуры 7 целых чисел. Напишите 
программу, которая определяет максимальное из этих 7 чисел.*/

//void main()
//{
//	const int size = 7;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите семь целых чисел:" << endl;
//	int arr[size];
//	for (int i = 0; i < size; i++)
//		cin >> arr[i];
//	int max = arr[0];
//	for (int i = 0; i < size; i++)
//		if (arr[i] > max)
//			max = arr[i];
//	cout << "Максимальное число: " << max << endl;
//	system("pause");
//}


			//Задача 4
/*Грузовой самолет должен пролететь с грузом из пункта А 
в пункт С через пункт В. Емкость бака для топлива у самолеот веса груза у самолета следующее:
- до 500 кг — 1 литров/км;
- до 1000 кг — 4 литров/км;
- до 1500 кг — 7 литров/км;
- до 2000 кг — 9 литров/км;
- более 2000 кг — самолет не поднимает.
Пользователь вводит расстояние между пунктами А и В, 
и расстояние между пунктами В и С, а также вес груза. Программа должна рассчитать какое минимальное количество 
топлива необходимо для дозаправки самолету в пункте В, 
чтобы долететь из пункта А в пункт С. В случае невозможности преодолеть любое из расстояний — программа должна 
вывести сообщение о невозможности полета по введенному маршруту.*/

//void main()
//{
//	const int TankCapacity = 300;
//	const int FuelUpTo500Kg = 1;
//	const int FuelUpTo1000Kg = 4;
//	const int FuelUpTo1500Kg = 7;
//	const int FuelUpTo2000Kg = 9;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите расстояние между пунктами А и В в километрах => ";
//	double distanceAB;
//	cin >> distanceAB;
//	cout << "Введите расстояние между пунктами B и C в километрах => ";
//	double distanceBC;
//	cin >> distanceBC;
//	cout << "Введите вес груза в килограммах => ";
//	double weight;
//	cin >> weight;
//	double needfulFuelAB;
//	double needfulFuelBC;
//
//	if (weight >= 0 && weight < 500)
//	{
//		needfulFuelAB = FuelUpTo500Kg * distanceAB;
//		needfulFuelBC = FuelUpTo500Kg * distanceBC;
//	}
//	else if (weight >= 500 && weight < 1000)
//	{
//		needfulFuelAB = FuelUpTo1000Kg * distanceAB;
//		needfulFuelBC = FuelUpTo1000Kg * distanceBC;
//	}
//	else if (weight >= 1000 && weight < 1500)
//	{
//		needfulFuelAB = FuelUpTo1500Kg * distanceAB;
//		needfulFuelBC = FuelUpTo1500Kg * distanceBC;
//	}
//	else if (weight >= 1500 && weight <= 2000)
//	{
//		needfulFuelAB = FuelUpTo2000Kg * distanceAB;
//		needfulFuelBC = FuelUpTo2000Kg * distanceBC;
//	}
//	else
//	{
//		cout << "Самолет не поднимет такой груз!" << endl;
//		system("pause");
//	}
//
//
//	if (TankCapacity < needfulFuelAB && TankCapacity < needfulFuelBC)
//	{
//		cout << "Самолет не сможет пролететь расстояние между пунктами А и В и пунктами В и С!" << endl;
//		system("pause");
//	}
//	else if (TankCapacity < needfulFuelAB)
//	{
//		cout << "Самолет не сможет пролететь расстояние между пунктами А и В!" << endl;
//		system("pause");
//	}
//	else if (TankCapacity < needfulFuelBC)
//	{
//		cout << "Самолет не сможет пролететь расстояние между пунктами B и C!" << endl;
//		system("pause");
//	}
//
//	cout << "Для перелета из пункта А в пункт В необходимо " << needfulFuelAB << " л. топлива" << endl;
//	cout << "Для перелета из пункта В в пункт С необходимо " << needfulFuelBC << " л. топлива" << endl;
//
//	double remainingFuel = TankCapacity - needfulFuelAB;
//	double refuelTheFuel;
//
//	if(remainingFuel >= needfulFuelBC)
//		cout << "Дозаправка в пункте B не требуется." << endl;
//	else
//	{
//		refuelTheFuel = needfulFuelBC - remainingFuel;
//		cout << "В пункте В необходимо дозаправить " << refuelTheFuel << " л. топлива." << endl;
//	}
//
//	system("pause");
//}