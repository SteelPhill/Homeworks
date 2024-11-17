#include <iostream>
#include <string>
using namespace std;


//			ВСТРЕЧА №1

/*Реализуйте класс Дробь. Необходимо хранить числитель 
и знаменатель в качестве переменных-членов. Реализуйте 
функции-члены для ввода данных в переменные-члены, 
для выполнения арифметических операций (сложение, 
вычитание, умножение, деление, и т.д.).*/

class Fraction
{
	int integer;
	int numerator;
	int denominator;

	int GreatestCommonDivisor(const int firstValue, const int secondValue)
	{
		if (secondValue == 0)
			return abs(firstValue);

		return GreatestCommonDivisor(secondValue, firstValue % secondValue);
	}

	int LeastCommonMultiple(const int firstValue, const int secondValue)
	{
		return firstValue * secondValue / GreatestCommonDivisor(firstValue, secondValue);
	}

	inline void ShowThatIncorrectFraction(Fraction& secondFraction)
	{
		cout << endl << "Введена некорректная дробь!";
	}

	string FractionToString()
	{
		string fractionToString = " ";

		if (integer > 0)
			fractionToString += to_string(integer);
		else if (integer < 0)
			fractionToString = to_string(integer);

		if (integer != 0 && numerator != 0)
			fractionToString += ":";

		if (numerator > 0 || numerator < 0 && integer != 0)
			fractionToString += to_string(numerator) + "/" + to_string(denominator);
		else if (numerator < 0)
			fractionToString = to_string(numerator) + "/" + to_string(denominator);

		return fractionToString;
	}

public:

	Fraction() : Fraction(0, 0, 0)
	{
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}

	inline int GetInteger() { return integer; }
	inline int GetNumerator() { return numerator; }
	inline int GetDenominator() { return denominator; }

	inline void SetInteger(const int value) { integer = value; }
	inline void SetNumerator(const int value) { numerator = value; }
	inline void SetDenominator(const int value) { denominator = value; }

	void ShowFraction()
	{
		Fraction tempFraction(integer, numerator, denominator);

		cout << tempFraction.FractionToString() << endl;
	}

	bool IsFractionNotCorrect()
	{
		if (denominator == 0 && numerator != 0 || numerator < 0 && integer != 0 || denominator < 0 || numerator == 0 && integer == 0)
		{
			Fraction tempFraction(integer, numerator, denominator);

			ShowThatIncorrectFraction(tempFraction);
			return true;
		}

		return false;
	}

	void ConvertCorrectFractionToWrong()
	{
		const int multiplierForNegativeNumbers = -1;

		bool isNegative = integer < 0;

		numerator += abs(integer) * denominator;
		integer = 0;

		if (isNegative)
			numerator *= multiplierForNegativeNumbers;
	}

	void FractionReduction()
	{
		const int reduceBy = GreatestCommonDivisor(numerator, denominator);

		numerator /= reduceBy;
		denominator /= reduceBy;
	}

	void ConvertWrongFractionToCorrect()
	{
		integer += numerator / denominator;
		numerator %= denominator;

		if (integer < 0 && numerator < 0)
			numerator = abs(numerator);

		denominator = abs(denominator);
	}

	Fraction Sum(const Fraction& secondFraction)
	{
		Fraction tempFirstFraction(integer, numerator, denominator);
		Fraction tempSecondFraction = secondFraction;
		Fraction sumResult;

		if (tempFirstFraction.IsFractionNotCorrect() || tempSecondFraction.IsFractionNotCorrect())
			return sumResult;

		tempFirstFraction.ConvertCorrectFractionToWrong();
		tempSecondFraction.ConvertCorrectFractionToWrong();

		const int commonDenominator = LeastCommonMultiple(tempFirstFraction.GetDenominator(), tempSecondFraction.GetDenominator());

		tempFirstFraction.SetNumerator(tempFirstFraction.GetNumerator() * commonDenominator / tempFirstFraction.GetDenominator()); 
		tempFirstFraction.SetDenominator(commonDenominator);

		tempSecondFraction.SetNumerator(tempSecondFraction.GetNumerator() * commonDenominator / tempSecondFraction.GetDenominator());
		tempSecondFraction.SetDenominator(commonDenominator);

		sumResult.SetNumerator(tempFirstFraction.GetNumerator() + tempSecondFraction.GetNumerator());
		sumResult.SetDenominator(commonDenominator);

		sumResult.FractionReduction();
		sumResult.ConvertWrongFractionToCorrect();

		return sumResult;
	}

	Fraction Diff(const Fraction& secondFraction)
	{
		Fraction tempFirstFraction(integer, numerator, denominator);
		Fraction tempSecondFraction = secondFraction;
		Fraction diffResult;

		if (tempFirstFraction.IsFractionNotCorrect() || tempSecondFraction.IsFractionNotCorrect())
			return diffResult;

		tempFirstFraction.ConvertCorrectFractionToWrong();
		tempSecondFraction.ConvertCorrectFractionToWrong();

		const int commonDenominator = LeastCommonMultiple(tempFirstFraction.GetDenominator(), tempSecondFraction.GetDenominator());

		tempFirstFraction.SetNumerator(tempFirstFraction.GetNumerator() * commonDenominator / tempFirstFraction.GetDenominator());
		tempFirstFraction.SetDenominator(commonDenominator);

		tempSecondFraction.SetNumerator(tempSecondFraction.GetNumerator() * commonDenominator / tempSecondFraction.GetDenominator());
		tempSecondFraction.SetDenominator(commonDenominator);

		diffResult.SetNumerator(tempFirstFraction.GetNumerator() - tempSecondFraction.GetNumerator());
		diffResult.SetDenominator(commonDenominator);

		diffResult.FractionReduction();
		diffResult.ConvertWrongFractionToCorrect();

		return diffResult;
	}

	Fraction Mult(const Fraction& secondFraction)
	{
		Fraction tempFirstFraction(integer, numerator, denominator);
		Fraction tempSecondFraction = secondFraction;
		Fraction multResult;

		if (tempFirstFraction.IsFractionNotCorrect() || tempSecondFraction.IsFractionNotCorrect())
			return multResult;

		tempFirstFraction.ConvertCorrectFractionToWrong();
		tempSecondFraction.ConvertCorrectFractionToWrong();

		multResult.SetNumerator(tempFirstFraction.GetNumerator() * tempSecondFraction.GetNumerator());
		multResult.SetDenominator(tempFirstFraction.GetDenominator() * tempSecondFraction.GetDenominator());

		multResult.FractionReduction();
		multResult.ConvertWrongFractionToCorrect();

		return multResult;
	}

	Fraction Div(const Fraction& secondFraction)
	{
		const int multiplierForNegativeNumbers = -1;

		Fraction tempFirstFraction(integer, numerator, denominator);
		Fraction tempSecondFraction = secondFraction;
		Fraction divResult;

		if (tempFirstFraction.IsFractionNotCorrect() || tempSecondFraction.IsFractionNotCorrect())
			return divResult;

		tempFirstFraction.ConvertCorrectFractionToWrong();
		tempSecondFraction.ConvertCorrectFractionToWrong();

		if (tempSecondFraction.GetNumerator() < 0)
			tempSecondFraction.SetDenominator(tempSecondFraction.GetDenominator() * multiplierForNegativeNumbers);

		divResult.SetNumerator(tempFirstFraction.GetNumerator() * tempSecondFraction.GetDenominator());
		divResult.SetDenominator(tempFirstFraction.GetDenominator() * abs(tempSecondFraction.GetNumerator()));

		divResult.FractionReduction();
		divResult.ConvertWrongFractionToCorrect();

		return divResult;
	}
};

void main()
{
	setlocale(LC_ALL, "ru");

	Fraction firstFraction(1, 2, 3);

	Fraction secondFraction;
	secondFraction.SetInteger(-2);
	secondFraction.SetNumerator(3);
	secondFraction.SetDenominator(5);

	cout << "Первая дробь:\t";
	firstFraction.ShowFraction();

	cout << "Вторая дробь:\t";
	secondFraction.ShowFraction();

	cout << endl;

	cout << "Сумма:  \t";
	Fraction SumResult = firstFraction.Sum(secondFraction);
	SumResult.ShowFraction();

	cout << "Разность:\t";
	Fraction DiffResult = firstFraction.Diff(secondFraction);
	DiffResult.ShowFraction();

	cout << "Умножение:\t";
	Fraction MultResult = firstFraction.Mult(secondFraction);
	MultResult.ShowFraction();

	cout << "Деление:\t";
	Fraction DivResult = firstFraction.Div(secondFraction);
	DivResult.ShowFraction();

	cout << endl;
	system("pause");
}