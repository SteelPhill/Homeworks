#include <iostream>
using namespace std;


			//Задача 1
/*Написать программу, реализующую процедуры заказа и 
расчета его суммы в мини — пиццерии. В меню пиццерии 
предусмотрено 4 вида пиццы и три вида напитков. 
Пользователю выводится меню (вначале пиццы, потом 
напитки), содержащее код и название. Пользователь вводит 
код желаемого продукта, после чего вводит количество единиц 
данного продукта. 
В пиццерии предусмотрены два вида скидок: 
- если общая сумма заказа более 50$, то размер скидки составляет 20% от суммы заказа;
- каждая пятая пицца — в подарок;
- для напитков с ценой более 2$, если количество в заказе более трех, то скидка 15% (только на напитки, а не на 
весь заказ).
Вывести пользователю "чек" для оплаты в виде: название -
количество — цена. Итого к оплате.*/

//void main()
//{
//	const double CostBarbecue = 8.0;
//	const double CostHawaiian = 8.5;
//	const double CostMargarita = 9.0;
//	const double CostPepperoni = 9.5;
//	const double CostCocaCola = 2.0;
//	const double CostPepsi = 2.5;
//	const double CostFanta = 3.0;
//	const double DiscountOnDrinks15Percent = 0.85;
//	const double DiscountOnAll20Percent = 0.8;
//	setlocale(LC_ALL, "ru");
//	cout << "\tМеню." << endl;
//	cout << " Пиццы: " << endl;
//	cout << "\t 1.Барбекю\t" << CostBarbecue << "   $" << endl;
//	cout << "\t 2.Гавайская\t" << CostHawaiian << " $" << endl;
//	cout << "\t 3.Маргарита\t" << CostMargarita << "   $" << endl;
//	cout << "\t 4.Пеперони\t" << CostPepperoni << " $" << endl;
//	cout << " Напитки: " << endl;
//	cout << "\t 1.Кока-кола\t" << CostCocaCola << "   $" << endl;
//	cout << "\t 2.Пепси\t" << CostPepsi << " $" << endl;
//	cout << "\t 3.Фанта\t" << CostFanta << "   $" << endl;
//	cout << " Акции:" << endl;
//	cout << " - Каждая пятая пицца — в подарок." << endl;
//	cout << " - При заказе от 4-х напитков стоймостью более 2$, получите скидку на напитки - 15%." << endl;
//	cout << " - Если общая сумма заказа более 50$, получите скидку 20% от суммы заказа." << endl;
//	cout << endl;
//	cout << "Выберете пиццу и введите её код (номер позиции) => ";
//	int codePizza;
//	cin >> codePizza;
//	while (codePizza < 1 || codePizza > 4)
//	{
//		cout << "Несуществующий код! Ещё раз введите код (номер позиции) пиццы => ";
//		cin >> codePizza;
//	}
//	cout << "Введите количество пицц => ";
//	int numberOfPizzas;
//	cin >> numberOfPizzas;
//	cout << "Выберете напиток и введите его код (номер позиции) => ";
//	int codeDrink;
//	cin >> codeDrink;
//	while (codeDrink < 1 || codeDrink > 3)
//	{
//		cout << "Несуществующий код! Ещё раз введите код (номер позиции) напитка => ";
//		cin >> codeDrink;
//	}
//	cout << "Введите количество напитков => ";
//	int numberOfDrinks;
//	cin >> numberOfDrinks;
//
//	int finalNumberOfPizzas;
//	double finalCostPizzas;
//	double finalCostDrinks;
//	string NamePizza;
//	string NameDrink;
//
//	switch (codePizza)
//	{
//	case 1:
//		if (numberOfPizzas / 5 >= 1)
//			finalCostPizzas = (numberOfPizzas - (numberOfPizzas / 5)) * CostBarbecue;
//		else
//			finalCostPizzas = numberOfPizzas * CostBarbecue;
//		NamePizza = "Барбекю  ";
//		break;
//	case 2:
//		if (numberOfPizzas / 5 >= 1)
//			finalCostPizzas = (numberOfPizzas - (numberOfPizzas / 5)) * CostHawaiian;
//		else
//			finalCostPizzas = numberOfPizzas * CostHawaiian;
//		NamePizza = "Гавайская";
//		break;
//	case 3:
//		if (numberOfPizzas / 5 >= 1)
//			finalCostPizzas = (numberOfPizzas - (numberOfPizzas / 5)) * CostMargarita;
//		else
//			finalCostPizzas = numberOfPizzas * CostMargarita;
//		NamePizza = "Маргарита";
//		break;
//	case 4:
//		if (numberOfPizzas / 5 >= 1)
//			finalCostPizzas = (numberOfPizzas - (numberOfPizzas / 5)) * CostPepperoni;
//		else
//			finalCostPizzas = numberOfPizzas * CostPepperoni;
//		NamePizza = "Пеперони ";
//		break;
//	}
//
//	switch (codeDrink)
//	{
//	case 1:
//		finalCostDrinks = numberOfDrinks * CostCocaCola;
//		if (CostCocaCola > 2 && numberOfDrinks > 3)
//			finalCostDrinks = numberOfDrinks * CostCocaCola * DiscountOnDrinks15Percent;
//		NameDrink = "Кока-кола";
//		break;
//	case 2:
//		finalCostDrinks = numberOfDrinks * CostPepsi;
//		if (CostPepsi > 2 && numberOfDrinks > 3)
//			finalCostDrinks = numberOfDrinks * CostPepsi * DiscountOnDrinks15Percent;
//		NameDrink = "Пепси    ";
//		break;
//	case 3:
//		finalCostDrinks = numberOfDrinks * CostFanta;
//		if (CostFanta > 2 && numberOfDrinks > 3)
//			finalCostDrinks = numberOfDrinks * CostFanta * DiscountOnDrinks15Percent;
//		NameDrink = "Фанта    ";
//		break;
//	}
//
//	double allCost;
//	allCost = finalCostPizzas + finalCostDrinks;
//	if (allCost > 50)
//		allCost = allCost * DiscountOnAll20Percent;
//
//	cout << endl;
//	cout << "\t\t\tЧек. " << endl;
//	cout << endl;
//	cout << "Вид:    \t" << "Название:" << "\t" << "Количество:" << "\t" << "Стоймость:" << endl;
//	cout << "Пицца   \t" << NamePizza << "\t" << numberOfPizzas << " шт.\t\t" << finalCostPizzas << " $" << endl;
//	cout << "Напитки \t" << NameDrink << "\t" << numberOfDrinks << " шт.\t\t" << finalCostDrinks << " $" << endl;
//	cout << endl;
//	cout << "Итого к оплате: " << allCost << " $" << endl;
//	cout << endl;
//	system("pause");
//}

			//Задача 2
/*Зарплатаменеджера составляет 200$ + процент от продаж, 
продажи до 500$ — 3%, от 500 до 1000 — 5%, свыше 
8%. Пользователь вводит с клавиатуры уровень продаж 
для трех менеджеров. Определить их зарплату, определить 
лучшего менеджера, начислить ему премию 200$, вывести 
итоги на экран.
Примечание: уровень продаж у всех трех менеджеров 
разный.*/

//double percentOfSales(double s)
//{
//	const double PercentOfSales0_500 = 0.03;
//	const double PercentOfSales500_1000 = 0.05;
//	const double PercentOfSales1000_ = 0.08;
// 
//	if (s >= 0 && s < 500)
//		return s * PercentOfSales0_500;
//	else if (s >= 500 && s < 1000)
//		return s * PercentOfSales500_1000;
//	else
//		return s * PercentOfSales1000_;
//}
// 
//void main()
//{
//	const int ManagersSalary = 200;
//	const int Bonus = 200;
//	setlocale(LC_ALL, "ru");
//	cout << "Введите сумму продаж первого менеджера => ";
//	double sumOfSales1Manager;
//	cin >> sumOfSales1Manager;
//	cout << "Введите сумму продаж второго менеджера => ";
//	double sumOfSales2Manager;
//	cin >> sumOfSales2Manager;
//	cout << "Введите сумму продаж третьего менеджера => ";
//	double sumOfSales3Manager;
//	cin >> sumOfSales3Manager;
//	double percentOfSales1 = percentOfSales(sumOfSales1Manager);
//	double percentOfSales2 = percentOfSales(sumOfSales2Manager);
//	double percentOfSales3 = percentOfSales(sumOfSales3Manager);
//	cout << endl;
//
//	if (percentOfSales1 > percentOfSales2 && percentOfSales1 > percentOfSales3)
//	{
//		cout << "Лучший менеджер: Первый." << endl;
//		cout << endl;
//		cout << "Зарплата первого менеджера: " << ManagersSalary + percentOfSales1 + Bonus << endl;
//		cout << "Зарплата второго менеджера: " << ManagersSalary + percentOfSales2 << endl;
//		cout << "Зарплата третьего менеджера: " << ManagersSalary + percentOfSales3 << endl;
//	}
//	else if (percentOfSales2 > percentOfSales1 && percentOfSales2 > percentOfSales3)
//	{
//		cout << "Лучший менеджер: Второй." << endl;
//		cout << endl;
//		cout << "Зарплата первого менеджера: " << ManagersSalary + percentOfSales1 << endl;
//		cout << "Зарплата второго менеджера: " << ManagersSalary + percentOfSales2 + Bonus << endl;
//		cout << "Зарплата третьего менеджера: " << ManagersSalary + percentOfSales3 << endl;
//	}
//	else if (percentOfSales3 > percentOfSales1 && percentOfSales3 > percentOfSales2)
//	{
//		cout << "Лучший менеджер: Третий." << endl;
//		cout << endl;
//		cout << "Зарплата первого менеджера: " << ManagersSalary + percentOfSales1 << endl;
//		cout << "Зарплата второго менеджера: " << ManagersSalary + percentOfSales2 << endl;
//		cout << "Зарплата третьего менеджера: " << ManagersSalary + percentOfSales3 + Bonus << endl;
//	}
//
//	cout << endl;
//	system("pause");
//}
