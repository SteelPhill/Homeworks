#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;


//			ЗАДАЧА №1

/*Создайте структуру, описывающую комплексное число.
Реализуйте арифметические операции с комплексными числами:
сумму, разность, умножение, деление.*/

//struct ComplexNumber
//{
//	double a;
//	double b;
//	char i;
//};
//
//void ShowComplexNumber(ComplexNumber& value)
//{
//	printf("%0.3f + %0.3f%c\n\r", value.a, value.b, value.i);
//}
//
//void ShowComplexNumber(ComplexNumber (*MathOperation)(ComplexNumber&, ComplexNumber&), ComplexNumber& value1, ComplexNumber& value2)
//{
//	ComplexNumber result = MathOperation(value1, value2);
//	printf("%0.3f + %0.3f%c\n\r", result.a, result.b, result.i);
//}
//
//ComplexNumber Sum(ComplexNumber& value1, ComplexNumber& value2)
//{
//	ComplexNumber result;
//
//	result.a = value1.a + value2.a;
//	result.b = value1.b + value2.b;
//	result.i = value1.i;
//
//	return result;
//}
//
//ComplexNumber Diff(ComplexNumber& value1, ComplexNumber& value2)
//{
//	ComplexNumber result;
//
//	result.a = value1.a - value2.a;
//	result.b = value1.b - value2.b;
//	result.i = value1.i;
//
//	return result;
//}
//
//ComplexNumber Mul(ComplexNumber& value1, ComplexNumber& value2)
//{
//	ComplexNumber result;
//
//	result.a = (value1.a * value2.a) - (value1.b * value2.b);
//	result.b = (value1.b * value2.a) + (value1.a * value2.b);
//	result.i = value1.i;
//
//	return result;
//}
//
//ComplexNumber Div(ComplexNumber& value1, ComplexNumber& value2)
//{
//	ComplexNumber result;
//
//	result.a = ((value1.a * value2.a) + (value1.b * value2.b)) / (pow(value2.a, 2) + pow(value2.b, 2));
//	result.b = ((value1.b * value2.a) - (value1.a * value2.b)) / (pow(value2.a, 2) + pow(value2.b, 2));
//	result.i = value1.i;
//
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	ComplexNumber value1;
//	ComplexNumber value2;
//
//	value1 = { 2.5, 4, 'i' };
//	value2 = { 3.5, 3, 'i' };
//
//	cout << "Первое комплексное число: ";
//	ShowComplexNumber(value1);
//
//	cout << "Второе комплексное число: ";
//	ShowComplexNumber(value2);
//
//	cout << endl;
//
//	cout << "Sum: ";
//	ShowComplexNumber(Sum, value1, value2);
//
//	cout << "Diff: ";
//	ShowComplexNumber(Diff, value1, value2);
//
//	cout << "Mul: ";
//	ShowComplexNumber(Mul, value1, value2);
//
//	cout << "Div: ";
//	ShowComplexNumber(Div, value1, value2);
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №2
 
/*Реализовать структуру «Автомобиль» (длина, 
клиренс (высота посадки), объем двигателя, мощность 
двигателя, диаметр колес, цвет, тип коробки передач). 
Создайте функции для задания значений, отображения 
значений, поиска значений.*/

//struct Car
//{
//	int Length;
//	int Clearance;
//	double EngineCapacity;
//	int EnginePower;
//	int WheelDiameter;
//	string Colour;
//	string Transmission;
//};
//
//void CarCharacteristicFill(Car& car)
//{
//	cout << "Длина => ";
//	cin >> car.Length;
//	cout << "Клиренс => ";
//	cin >> car.Clearance;
//	cout << "Объём двигателя => ";
//	cin >> car.EngineCapacity;
//	cout << "Мощность двигателя => ";
//	cin >> car.EnginePower;
//	cout << "Диаметр колёс => ";
//	cin >> car.WheelDiameter;
//	cout << "Цвет => ";
//	cin >> car.Colour;
//	cout << "Тип коробки передач => ";
//	cin >> car.Transmission;
//	cout << endl;
//}
//
//void FillAllCarsCharacteristic(vector <Car>& cars)
//{
//	Car temp;
//
//	int key = 1;
//	for (int i = 1; key != 0; i++)
//	{
//		cout << "Заполнение данных об автомобилях." << endl << endl;
//
//		cout << "\tАВТОМОБИЛЬ №" << i << ":" << endl;
//		CarCharacteristicFill(temp);
//		cars.push_back(temp);
//
//		cout << "Добавить автомобиль - введите 1." << endl;
//		cout << "Завершить добавление - введите 0." << endl;
//		do
//		{
//			cout << "Ввод => ";
//			cin >> key;
//			cout << endl;
//
//			if (key < 0 || key > 1)
//				cout << "Ошибка! Повторите ввод!" << endl;
//
//		} while (key < 0 || key > 1);
//
//		system("pause");
//		system("cls");
//	}
//}
//
//void CarCharacteristicShow(Car& car)
//{
//	cout << "Длина: " << car.Length << endl;
//	cout << "Клиренс: " << car.Clearance << endl;
//	cout << "Объём двигателя: " << car.EngineCapacity << endl;
//	cout << "Мощность двигателя: " << car.EnginePower << endl;
//	cout << "Диаметр колёс: " << car.WheelDiameter << endl;
//	cout << "Цвет: " << car.Colour << endl;
//	cout << "Тип коробки передач: " << car.Transmission << endl;
//	cout << endl;
//}
//
//void ShowAllCarsCharacteristic(vector <Car>& cars)
//{
//	cout << "Список характеристик всех автомобилей." << endl << endl;
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		CarCharacteristicShow(cars.at(i));
//	}
//
//	system("pause");
//	system("cls");
//}
//
//void ShowCarLength(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Длина: " << cars.at(i).Length << endl;
//		cout << endl;
//	}
//}
//
//void ShowCarClearance(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Клиренс: " << cars.at(i).Clearance << endl;
//		cout << endl;
//	}
//}
//
//void ShowCarEngineCapacity(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Объём двигателя: " << cars.at(i).EngineCapacity << endl;
//		cout << endl;
//	}
//}
//
//void ShowCarEnginePower(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Мощность двигателя: " << cars.at(i).EnginePower << endl;
//		cout << endl;
//	}
//}
//
//void ShowCarWheelDiameter(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Диаметр колес: " << cars.at(i).WheelDiameter << endl;
//		cout << endl;
//	}
//}
//
//void ShowCarColour(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Цвет: " << cars.at(i).Colour << endl;
//		cout << endl;
//	}
//}
//
//void ShowCarTransmission(vector <Car>& cars)
//{
//	for (int i = 0; i < cars.size(); i++)
//	{
//		cout << "\tАВТОМОБИЛЬ №" << i + 1 << ":" << endl;
//		cout << "Тип коробки передач: " << cars.at(i).Transmission << endl;
//		cout << endl;
//	}
//}
//
//int SelectingCharacteristicsNumber()
//{
//	const int firstPoint = 1;
//	const int lastPoint = 8;
//
//	cout << "Введите номер характеристики для поиска:" << endl;
//	cout << "1.Длина;" << endl;
//	cout << "2.Клиренс;" << endl;
//	cout << "3.Объём двигателя;" << endl;
//	cout << "4.Мощность двигателя;" << endl;
//	cout << "5.Диаметр колёс;" << endl;
//	cout << "6.Цвет;" << endl;
//	cout << "7.Тип коробки передач;" << endl;
//	cout << "8.Отмена поиска." << endl;
//	cout << endl;
//
//	int selectedCharacteristic;
//
//	do
//	{
//		cout << "Ввод => ";
//		cin >> selectedCharacteristic;
//		cout << endl;
//
//		if (selectedCharacteristic < firstPoint || selectedCharacteristic > lastPoint)
//			cout << "Пункта под таким номером нет! Повторите выбор." << endl;
//
//	} while (selectedCharacteristic < firstPoint || selectedCharacteristic > lastPoint);
//
//	return selectedCharacteristic;
//}
//
//void (*ChoiceSearchedCharacteristic())(vector <Car>&)
//{
//	const int characteristicsNumber = 7;
//	const int conditionEndSearch = 8;
//
//	void (*Parameters[characteristicsNumber])(vector <Car>&) = { ShowCarLength,
//											ShowCarClearance,
//											ShowCarEngineCapacity,
//											ShowCarEnginePower,
//											ShowCarWheelDiameter,
//											ShowCarColour,
//											ShowCarTransmission };
//
//	int numberSearchedCharacteristic = SelectingCharacteristicsNumber();
//
//	if (numberSearchedCharacteristic == conditionEndSearch)
//		return nullptr;
//
//	return Parameters[numberSearchedCharacteristic - 1];
//}
//
//void CharacteristicSearch(vector <Car>& cars)
//{
//	void (*Parameters)(vector <Car>&);
//	do
//	{
//		cout << "Поиск характеристик." << endl << endl;
//
//		Parameters = ChoiceSearchedCharacteristic();
//
//		if (Parameters != nullptr)
//		{
//			Parameters(cars);
//			system("pause");
//			system("cls");
//		}
//
//		else
//			cout << "Поиск окончен." << endl << endl;
//
//	} while (Parameters != nullptr);
//}
//
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	vector <Car> cars;
//
//	FillAllCarsCharacteristic(cars);
//
//	ShowAllCarsCharacteristic(cars);
//
//	CharacteristicSearch(cars);
//
//	cout << "Завершение работы программы." << endl << endl;
//	system("pause");
//}