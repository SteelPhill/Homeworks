#include <iostream>
using namespace std;


//				ЗАДАЧА №1
/*Написать функцию, которая принимает два 
параметра: основание степени и показатель степени, и 
вычисляет степень числа на основе полученных данных.*/

//double Exponentiation(double foundation, int degree)
//{
//	double result = 1;
//
//	if (degree >= 0)
//		for (int i = 1; i <= degree; i++)
//			result *= foundation;
//
//	else
//		for (int i = degree; i < 0; i++)
//			result /= foundation;
//
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	double foundation;
//	cout << "Введите основание степени => ";
//	cin >> foundation;
//
//	int degree;
//	cout << "Введите показатель степени => ";
//	cin >> degree;
//
//	cout << endl;
//	cout << "Число " << foundation << " в степени " << degree << " равно: " << Exponentiation(foundation, degree) << endl;
//
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №2
/*. Написать функцию, которая получает в качестве параметров
2 целых числа и возвращает сумму чисел из диапазона между ними.*/

//int SumOfNumbersInRange(int firstValue, int secondValue)
//{
//	int result = 0;
//
//	if(firstValue < secondValue)
//		for (int i = firstValue + 1; i < secondValue; i++)
//			result += i;
//
//	else
//		for (int i = secondValue + 1; i < firstValue; i++)
//			result += i;
//
//	return result;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	int firstValue;
//	cout << "Введите первое число => ";
//	cin >> firstValue;
//
//	int secondValue;
//	cout << "Введите второе число => ";
//	cin >> secondValue;
//
//	cout << endl;
//	cout << "Сумма целых чисел в диапазоне между числом " << firstValue << " и числом " << secondValue << " равна: " << SumOfNumbersInRange(firstValue, secondValue) << endl;
//
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №3
/*Число называется совершенным, если сумма 
всех его делителей равна ему самому. Напишите функцию 
поиска таких чисел во введенном интервале.*/

//bool EqualityCheck(int value, int sum)
//{
//	if (value == sum && sum != 0)
//		return true;
//	return false;
//}
//
//void ShowPerfectNumber(int value)
//{
//	cout << value << " - совершенное число." << endl;
//}
//
//void SearchForPerfectNumbersInRange(int beginRange, int endRange)
//{
//	while (beginRange < 2 && beginRange % 2 != 0)
//		beginRange++;
//
//	int sum;
//
//	for (int i = beginRange; i <= endRange; i = i + 2)
//	{
//		sum = 0;
//
//		for (int j = 1; j <= i / 2; j++)
//		{
//			if (i % j == 0)
//				sum += j;
//		}
//
//		if (EqualityCheck(i, sum))
//			ShowPerfectNumber(i);
//	}
//}
//
//void main()
//{
//	const int MaximumPossibleValueOfRange = 9000;
//
//	setlocale(LC_ALL, "ru");
//	int beginRange;
//	int endRange;
//
//	do
//	{
//		cout << "Введите значение начала диапазона поиска совершенных чисел => ";
//		cin >> beginRange;
//
//		cout << "Введите значение конца диапазона поиска совершенных чисел => ";
//		cin >> endRange;
//
//		if (endRange < beginRange || beginRange < 0 || endRange > MaximumPossibleValueOfRange)
//		{
//			cout << endl;
//			cout << "Значение начала диапазона не может быть больше значения конца диапазона!" << endl;
//			cout << "Совершенные числа не могут быть отрицательными!" << endl;
//			cout << "Максимальное возможное значение конца диапазона - 9000!" << endl;
//			cout << endl;
//			cout << "Введите значения заново!" << endl;
//			cout << endl;
//			system("pause");
//			system("cls");
//		}
//		
//	} while (endRange < beginRange || beginRange < 0 || endRange > MaximumPossibleValueOfRange);
//
//	cout << endl;
//	SearchForPerfectNumbersInRange(beginRange, endRange);
//
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №4
/*Написать функцию, выводящую на экран 
переданную ей игральную карту.*/

//enum CardSuit {
//	Spades = 1,
//	Hearts = 2,
//	Diamonds = 3,
//	Clubs = 4
//};
//
//enum ValueOfCard {
//	Six = 1,
//	Seven = 2,
//	Eight = 3,
//	Nine = 4,
//	Ten = 5,
//	Jack = 6,
//	Queen = 7,
//	King = 8,
//	Ace = 9
//};
//
//int ChoosingSuitOfCard()
//{
//	int cardSuit;
//	cout << "Варианты карточной масти:" << endl;
//	cout << "1. Пики;" << endl;
//	cout << "2. Червы;" << endl;
//	cout << "3. Бубны;" << endl;
//	cout << "4. Трефы." << endl;
//
//	do
//	{
//		cout << "Выберите пункт из списка => ";
//		cin >> cardSuit;
//
//		if (cardSuit < 1 || cardSuit > 4)
//		{
//			cout << "Пункта под номером " << cardSuit << " нет в списке!" << endl;
//			cout << "Выберите пункт из списка!" << endl;
//		}
//
//		cout << endl;
//	} while (cardSuit < 1 || cardSuit > 4);
//
//	return cardSuit;
//}
//
//int ChoosingValueOfCard()
//{
//	int valueOfCard;
//	cout << "Варианты достоинства карты:" << endl;
//	cout << "1. Шестёрка;" << endl;
//	cout << "2. Семёрка;" << endl;
//	cout << "3. Восьмёрка;" << endl;
//	cout << "4. Девятка;" << endl;
//	cout << "5. Десятка;" << endl;
//	cout << "6. Валет;" << endl;
//	cout << "7. Дама;" << endl;
//	cout << "8. Король;" << endl;
//	cout << "9. Туз." << endl;
//
//	do
//	{
//		cout << "Выберите пункт из списка => ";
//		cin >> valueOfCard;
//
//		if (valueOfCard < 1 || valueOfCard > 9)
//		{
//			cout << "Пункта под номером " << valueOfCard << " нет в списке!" << endl;
//			cout << "Выберите пункт из списка!" << endl;
//		}
//
//		cout << endl;
//	} while (valueOfCard < 1 || valueOfCard > 9);
//
//	return valueOfCard;
//}
//
//void PrintingOutCardSuit(int cardSuit)
//{
//	switch (cardSuit)
//	{
//	case CardSuit::Spades:
//		cout << "|    /\\    |" << endl;
//		cout << "|   /  \\   |" << endl;
//		cout << "|  (_/\\_)  |" << endl;
//		cout << "|   /__\\   |" << endl;
//		break;
//	case CardSuit::Hearts:
//		cout << "|   _  _   |" << endl;
//		cout << "|  ( \\/ )  |" << endl;
//		cout << "|   \\  /   |" << endl;
//		cout << "|    \\/    |" << endl;
//		break;
//	case CardSuit::Diamonds:
//		cout << "|          |" << endl;
//		cout << "|    /\\    |" << endl;
//		cout << "|   /  \\   |" << endl;
//		cout << "|   \\  /   |" << endl;
//		cout << "|    \\/    |" << endl;
//		break;
//	case CardSuit::Clubs:
//		cout << "|    __    |" << endl;
//		cout << "|  _(  )_  |" << endl;
//		cout << "| (__  __) |" << endl;
//		cout << "|   /__\\   |" << endl;
//		break;
//	default:
//		return;
//	}
//}
//
//void PrintingOutValueOfCard(int valueOfCard)
//{
//	switch (valueOfCard)
//	{
//	case ValueOfCard::Six:
//		cout << "6 ";
//		break;
//	case ValueOfCard::Seven:
//		cout << "7 ";
//		break;
//	case ValueOfCard::Eight:
//		cout << "8 ";
//		break;
//	case ValueOfCard::Nine:
//		cout << "9 ";
//		break;
//	case ValueOfCard::Ten:
//		cout << "10";
//		break;
//	case ValueOfCard::Jack:
//		cout << "В ";
//		break;
//	case ValueOfCard::Queen:
//		cout << "Д ";
//		break;
//	case ValueOfCard::King:
//		cout << "К ";
//		break;
//	case ValueOfCard::Ace:
//		cout << "Т ";
//		break;
//	default:
//		return;
//	}
//}
//
//void PrintingOutPlayingCard()
//{
//	int cardSuit = ChoosingSuitOfCard();
//	int valueOfCard = ChoosingValueOfCard(); 
//	system("pause");
//	system("cls");
//
//	cout << "Ваша карта:" << endl;
//
//	cout << " __________" << endl;
//	cout << "|";
//	PrintingOutValueOfCard(valueOfCard);
//	cout << "        |" << endl;
//	cout << "|          |" << endl;
//	PrintingOutCardSuit(cardSuit);
//	cout << "|          |" << endl;
//	cout << "|          |" << endl;
//	cout << "|__________|";
//	cout << endl;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	
//	PrintingOutPlayingCard();
//
//	cout << endl;
//	system("pause");
//}


//				ЗАДАЧА №5
/*Написать функцию, которая определяет, является ли «счастливым» шестизначное число.*/

//int SummingDigitsInTransmittedHalf(int value)
//{
//		if (value == 0)
//			return 0;
//
//		return value % 10 + SummingDigitsInTransmittedHalf(value / 10);
//}
//
//bool CheckingForLuckyNumber(int value)
//{
//	int firstThreeDigitsOfNumber = value / 1000;
//	int lastThreeDigitsOfNumber = value % 1000;
//
//	if (SummingDigitsInTransmittedHalf(firstThreeDigitsOfNumber) == SummingDigitsInTransmittedHalf(lastThreeDigitsOfNumber))
//		return true;
//	return false;
//}
//
//void main()
//{
//	const int beginRange = 100000;
//	const int endRange = 999999;
//
//	setlocale(LC_ALL, "ru");
//
//	int value;
//	do
//	{
//		cout << "Введите шестизначное число => ";
//		cin >> value;
//		if (value < beginRange || value > endRange)
//		{
//			cout << "Число должно быть в диапазоне от " << beginRange << " до " << endRange << "!" << endl;
//		}
//	} while (value < beginRange || value > endRange);
//	system("cls");
//	cout << "Введенное число: " << value << endl;
//	cout << endl;
//
//	if (CheckingForLuckyNumber(value))
//		cout << "Число является счастливым!" << endl;
//
//	else
//		cout << "Число НЕ является счастливым." << endl;
//
//	cout << endl;
//	system("pause");
//}