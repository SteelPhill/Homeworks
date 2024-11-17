#include <iostream>
#include <string>
#include <format>
using namespace std;


//			ВСТРЕЧА №6


//			ЗАДАЧА №1

/*Создайте класс Дробь (или используйте уже ранее созданный вами).
Используя перегрузку операторов реализуйте для него арифметические
операции для работы с дробями (операции +, -, *, /).*/

//class Fraction
//{
//	int integer;
//	int numerator;
//	int denominator;
//
//	int GreatestCommonDivisor(const int firstValue, const int secondValue)
//	{
//		if (secondValue == 0)
//			return abs(firstValue);
//
//		return GreatestCommonDivisor(secondValue, firstValue % secondValue);
//	}
//
//	int LeastCommonMultiple(const int firstValue, const int secondValue)
//	{
//		return firstValue * secondValue / GreatestCommonDivisor(firstValue, secondValue);
//	}
//
//	bool IsCalculationBeenImpossible() const { return integer == -1 && numerator == -1 && denominator == -1; }
//
//public:
//
//	Fraction() : Fraction(0, 0, 0)
//	{
//	}
//
//	explicit Fraction(const int integer) : Fraction(integer, 0, 0)
//	{
//	}
//
//	Fraction(const int numerator, const int denominator) : Fraction(0, numerator, denominator)
//	{
//	}
//
//	Fraction(const int integer, const int numerator, const int denominator)
//	{
//		this->integer = integer;
//		this->numerator = numerator;
//		this->denominator = denominator;
//	}
//
//	Fraction(const Fraction& other)
//	{
//		integer = other.integer;
//		numerator = other.numerator;
//		denominator = other.denominator;
//	}
//
//	int GetInteger() const { return integer; }
//	int GetNumerator() const { return numerator; }
//	int GetDenominator() const { return denominator; }
//
//	void SetInteger(const int integer) { this->integer = integer; }
//	void SetNumerator(const int numerator) { this->numerator = numerator; }
//	void SetDenominator(const int denominator) { this->denominator = denominator; }
//
//	bool IsEqualZero() const { return integer == 0 && numerator == 0 && denominator == 0; }
//
//	bool IsNotCorrect() const
//	{
//		return denominator < 0
//			|| integer != 0 && numerator < 0
//			|| numerator == 0 && denominator != 0
//			|| integer == 0 && numerator == 0 && denominator != 0
//			|| integer == 0 && numerator != 0 && denominator == 0;
//	}
//
//	void ConvertCorrectFractionToWrong()
//	{
//		const int multiplierForNegativeNumbers = -1;
//
//		bool isNegative = integer < 0;
//
//		if (numerator != 0 && denominator != 0)
//			numerator += abs(integer) * denominator;
//		else
//		{
//			numerator = 1 * abs(integer);
//			denominator = 1;
//		}
//
//		integer = 0;
//
//		if (isNegative)
//			numerator *= multiplierForNegativeNumbers;
//	}
//
//	void FractionReduction()
//	{
//		const int reduceBy = GreatestCommonDivisor(numerator, denominator);
//
//		numerator /= reduceBy;
//		denominator /= reduceBy;
//	}
//
//	void ConvertWrongFractionToCorrect()
//	{
//		integer += numerator / denominator;
//		numerator %= denominator;
//
//		if (integer < 0 && numerator < 0)
//			numerator = abs(numerator);
//
//		denominator = abs(denominator);
//	}
// 
//	Fraction Sum(const Fraction& secondFraction) { return *this + secondFraction; }
//
//	Fraction Diff(const Fraction& secondFraction) { return *this - secondFraction; }
//
//	Fraction Mult(const Fraction& secondFraction) { return *this * secondFraction; }
//
//	Fraction Div(const Fraction& secondFraction) { return *this / secondFraction; }
//
//	Fraction operator+(const Fraction& secondFraction)
//	{
//		Fraction tempFirstFraction = *this;
//		Fraction tempSecondFraction = secondFraction;
//		Fraction result;
//
//		if (tempFirstFraction.IsNotCorrect() || tempSecondFraction.IsNotCorrect())
//		{
//			result.SetInteger(-1);
//			result.SetNumerator(-1);
//			result.SetDenominator(-1);
//			return result;
//		}
//
//		if (tempFirstFraction.IsEqualZero())
//			return tempSecondFraction;
//
//		if (tempSecondFraction.IsEqualZero())
//			return tempFirstFraction;
//
//		tempFirstFraction.ConvertCorrectFractionToWrong();
//		tempSecondFraction.ConvertCorrectFractionToWrong();
//
//		const int commonDenominator = LeastCommonMultiple(tempFirstFraction.GetDenominator(), tempSecondFraction.GetDenominator());
//
//		tempFirstFraction.SetNumerator(tempFirstFraction.GetNumerator() * commonDenominator / tempFirstFraction.GetDenominator());
//		tempFirstFraction.SetDenominator(commonDenominator);
//
//		tempSecondFraction.SetNumerator(tempSecondFraction.GetNumerator() * commonDenominator / tempSecondFraction.GetDenominator());
//		tempSecondFraction.SetDenominator(commonDenominator);
//
//		result.SetNumerator(tempFirstFraction.GetNumerator() + tempSecondFraction.GetNumerator());
//		result.SetDenominator(commonDenominator);
//
//		result.FractionReduction();
//		result.ConvertWrongFractionToCorrect();
//
//		return result;
//	}
//
//	Fraction operator-(const Fraction& secondFraction)
//	{
//		Fraction tempFirstFraction = *this;
//		Fraction tempSecondFraction = secondFraction;
//		Fraction result;
//
//		if (tempFirstFraction.IsNotCorrect() || tempSecondFraction.IsNotCorrect())
//		{
//			result.SetInteger(-1);
//			result.SetNumerator(-1);
//			result.SetDenominator(-1);
//			return result;
//		}
//
//		if (tempFirstFraction.IsEqualZero())
//			return tempSecondFraction;
//
//		if (tempSecondFraction.IsEqualZero())
//			return tempFirstFraction;
//
//		tempFirstFraction.ConvertCorrectFractionToWrong();
//		tempSecondFraction.ConvertCorrectFractionToWrong();
//
//		const int commonDenominator = LeastCommonMultiple(tempFirstFraction.GetDenominator(), tempSecondFraction.GetDenominator());
//
//		tempFirstFraction.SetNumerator(tempFirstFraction.GetNumerator() * commonDenominator / tempFirstFraction.GetDenominator());
//		tempFirstFraction.SetDenominator(commonDenominator);
//
//		tempSecondFraction.SetNumerator(tempSecondFraction.GetNumerator() * commonDenominator / tempSecondFraction.GetDenominator());
//		tempSecondFraction.SetDenominator(commonDenominator);
//
//		result.SetNumerator(tempFirstFraction.GetNumerator() - tempSecondFraction.GetNumerator());
//		result.SetDenominator(commonDenominator);
//
//		result.FractionReduction();
//		result.ConvertWrongFractionToCorrect();
//
//		return result;
//	}
//
//	Fraction operator*(const Fraction& secondFraction)
//	{
//		Fraction tempFirstFraction = *this;
//		Fraction tempSecondFraction = secondFraction;
//		Fraction result;
//
//		if (tempFirstFraction.IsNotCorrect() || tempSecondFraction.IsNotCorrect())
//		{
//			result.SetInteger(-1);
//			result.SetNumerator(-1);
//			result.SetDenominator(-1);
//			return result;
//		}
//
//		if (tempFirstFraction.IsEqualZero() || tempSecondFraction.IsEqualZero())
//			return result;
//
//		tempFirstFraction.ConvertCorrectFractionToWrong();
//		tempSecondFraction.ConvertCorrectFractionToWrong();
//
//		result.SetNumerator(tempFirstFraction.GetNumerator() * tempSecondFraction.GetNumerator());
//		result.SetDenominator(tempFirstFraction.GetDenominator() * tempSecondFraction.GetDenominator());
//
//		result.FractionReduction();
//		result.ConvertWrongFractionToCorrect();
//
//		return result;
//	}
//
//	Fraction operator/(const Fraction& secondFraction)
//	{
//		const int multiplierForNegativeNumbers = -1;
//
//		Fraction tempFirstFraction = *this;
//		Fraction tempSecondFraction = secondFraction;
//		Fraction result;
//
//		if (tempFirstFraction.IsNotCorrect() || tempSecondFraction.IsNotCorrect())
//		{
//			result.SetInteger(-1);
//			result.SetNumerator(-1);
//			result.SetDenominator(-1);
//			return result;
//		}
//
//		if (tempFirstFraction.IsEqualZero())
//			return result;
//
//		if (tempSecondFraction.IsEqualZero())
//		{
//			result.SetInteger(-1);
//			result.SetNumerator(-1);
//			result.SetDenominator(-1);
//			return result;
//		}
//
//		tempFirstFraction.ConvertCorrectFractionToWrong();
//		tempSecondFraction.ConvertCorrectFractionToWrong();
//
//		if (tempSecondFraction.GetNumerator() < 0)
//			tempSecondFraction.SetDenominator(tempSecondFraction.GetDenominator() * multiplierForNegativeNumbers);
//
//		result.SetNumerator(tempFirstFraction.GetNumerator() * tempSecondFraction.GetDenominator());
//		result.SetDenominator(tempFirstFraction.GetDenominator() * abs(tempSecondFraction.GetNumerator()));
//
//		result.FractionReduction();
//		result.ConvertWrongFractionToCorrect();
//
//		return result;
//	}
//
//	string ToString() const
//	{
//		string result = "";
//
//		if (IsCalculationBeenImpossible())
//			return result;
//
//		if (IsEqualZero())
//			return result += "0";
//
//		if (integer > 0)
//			result += to_string(integer);
//		else if (integer < 0)
//			result = to_string(integer);
//
//		if (integer != 0 && numerator != 0)
//			result += ":";
//
//		if (numerator > 0 || numerator < 0 && integer != 0)
//			result += to_string(numerator) + "/" + to_string(denominator);
//		else if (numerator < 0)
//			result = to_string(numerator) + "/" + to_string(denominator);
//
//		return result;
//	}
//
//	void ShowFraction() const { cout << ToString() << endl; }
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Fraction firstFraction(-2, 3);
//
//	if (firstFraction.IsNotCorrect())
//		cout << "Первая дробь введена некорректно!" << endl;
//	else
//	{
//		cout << "Первая дробь:\t";
//		firstFraction.ShowFraction();
//	}
//
//	cout << endl;
//
//	Fraction secondFraction(3, 1, 5);
//
//	if (secondFraction.IsNotCorrect())
//		cout << "Вторая дробь введена некорректно!" << endl;
//	else
//	{
//		cout << "Вторая дробь:\t";
//		secondFraction.ShowFraction();
//	}
//
//	cout << endl;
//
//	if (firstFraction.IsNotCorrect() || secondFraction.IsNotCorrect())
//	{
//		cout << "Вычисления невозможны!" << endl << endl;
//		system("pause");
//		return;
//	}
//
//	Fraction result;
//
//	result = firstFraction + secondFraction;
//	cout << "Сумма:  \t";
//	result.ShowFraction();
//
//	result = firstFraction - secondFraction;
//	cout << "Разность:\t";
//	result.ShowFraction();
//
//	result = firstFraction * secondFraction;
//	cout << "Умножение:\t";
//	result.ShowFraction();
//
//	result = firstFraction / secondFraction;
//	cout << "Деление:\t";
//	result.ShowFraction();
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №2

/*Создайте класс Complex (комплексное число) или используйте 
уже созданный вами класс. Создайте перегруженные 
операторы для реализации арифметических операций для 
по работе с комплексными числами (операции +, -, *, /).*/

//class Complex
//{
//	double a;
//	double b;
//	char i;
//
//	static const char imaginaryUnitStandardDesignation = 'i';
//	static const char imaginaryPartIsZero = ' ';
//
//public:
//
//	Complex() : Complex(0, 0, ' ')
//	{
//	}
//
//	explicit Complex(const char i) : Complex(0, 1, i)
//	{
//	}
//
//	explicit Complex(const int a) : Complex(a, 0, ' ')
//	{
//	}
//
//	explicit Complex(const double a) : Complex(a, 0, ' ')
//	{
//	}
//
//	Complex(const double b, const char i) : Complex(0, b, i)
//	{
//	}
//
//	Complex(const double a, const double b, const char i)
//	{
//		this->a = a;
//		this->b = b;
//		this->i = i;
//	}
//
//	Complex(const Complex& other)
//	{
//		a = other.a;
//		b = other.b;
//		i = other.i;
//	}
//
//	double GetA() const { return a; }
//	double GetB() const { return b; }
//	char GetI() const { return i; }
//
//	void SetA(const double a) { this->a = a; }
//	void SetB(const double b) { this->b = b; }
//	void SetI(const char i) { this->i = i; }
//
//	bool IsEqualZero() const { return a == 0 && b == 0; }
//
//	bool IsCorrect() const { return i == imaginaryUnitStandardDesignation || (i == imaginaryPartIsZero && b == 0); }
//
//	Complex Sum(const Complex& right) { return *this + right; }
//
//	Complex Diff(const Complex& right) { return *this - right; }
//
//	Complex Mul(const Complex& right) { return *this * right; }
//
//	Complex Div(const Complex& right) { return *this / right; }
//
//	Complex operator+(const Complex& right)
//	{
//		Complex result;
//
//		if (!IsCorrect() || !right.IsCorrect())
//			return result;
//
//		Complex tempLeft = *this;
//
//		result.a = tempLeft.a + right.a;
//		result.b = tempLeft.b + right.b;
//
//		if (result.a == 0 && result.b == 0)
//			result.i = imaginaryPartIsZero;
//		else
//			result.i = imaginaryUnitStandardDesignation;
//
//		return result;
//	}
//
//	Complex operator-(const Complex& right)
//	{
//		Complex result;
//
//		if (!IsCorrect() || !right.IsCorrect())
//			return result;
//
//		Complex tempLeft = *this;
//
//		result.a = tempLeft.a - right.a;
//		result.b = tempLeft.b - right.b;
//
//		if (result.a == 0 && result.b == 0)
//			result.i = imaginaryPartIsZero;
//		else
//			result.i = imaginaryUnitStandardDesignation;
//
//		return result;
//	}
//
//	Complex operator*(const Complex& right)
//	{
//		Complex result;
//
//		if (!IsCorrect() || !right.IsCorrect())
//			return result;
//
//		Complex tempLeft = *this;
//
//		result.a = (tempLeft.a * right.a) - (tempLeft.b * right.b);
//		result.b = (tempLeft.b * right.a) + (tempLeft.a * right.b);
//		
//		if (result.a == 0 && result.b == 0)
//			result.i = imaginaryPartIsZero;
//		else
//			result.i = imaginaryUnitStandardDesignation;
//
//		return result;
//	}
//
//	Complex operator/(const Complex& right)
//	{
//		Complex result;
//
//		if (!IsCorrect() || !right.IsCorrect() || right.IsEqualZero())
//		{
//			result.i = '_';
//			return result;
//		}
//
//		Complex tempLeft = *this;
//
//		result.a = ((tempLeft.a * right.a) + (tempLeft.b * right.b)) / (pow(right.a, 2) + pow(right.b, 2));
//		result.b = ((tempLeft.b * right.a) - (tempLeft.a * right.b)) / (pow(right.a, 2) + pow(right.b, 2));
//		
//		if (result.a == 0 && result.b == 0)
//			result.i = imaginaryPartIsZero;
//		else
//			result.i = imaginaryUnitStandardDesignation;
//
//		return result;
//	}
//
//	string ToString() const
//	{
//		string result = "";
//
//		if (!IsCorrect())
//			return result;
//
//		if (IsEqualZero())
//			return result += "0";
//
//		if (a != 0)
//			result += format("{:.3}", a);
//		
//		if (b == 0 && i == imaginaryPartIsZero)
//			return result;
//
//		if (b < 0)
//			result += "-";
//		else if (a != 0 && b !=0)
//			result += "+";
//
//		if (b != 1 && b != -1 && b != 0)
//			result += format("{:.3}", abs(b));
//
//		if (b != 0)
//			result += i;
//		
//		return result;
//	}
//
//	void ShowComplexNumber() const { cout << ToString() << endl; }
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Complex value1(2.5, 2, 'i');
//	
//	if (value1.IsCorrect())
//	{
//		cout << "Первое комплексное число: ";
//		value1.ShowComplexNumber();
//	}
//	else
//		cout << "Первое комплексное число введено некорректно!" << endl;
//
//	cout << endl;
//
//	Complex value2(2.7, 1, 'i');
//
//	if (value2.IsCorrect())
//	{
//		cout << "Второе комплексное число: ";
//		value2.ShowComplexNumber();
//	}
//	else
//		cout << "Второе комплексное число введено некорректно!" << endl;
//
//	cout << endl;
//
//	if (!value1.IsCorrect() || !value2.IsCorrect())
//	{
//		cout << "Вычисления невозможны!" << endl << endl;
//		system("pause");
//		return;
//	}
//
//	Complex result;
//
//	result = value1 + value2;
//	cout << "Сумма:  \t";
//	result.ShowComplexNumber();
//
//	result = value1 - value2;
//	cout << "Разность:\t";
//	result.ShowComplexNumber();
//
//	result = value1 * value2;
//	cout << "Умножение:\t";
//	result.ShowComplexNumber();
//
//	result = value1 / value2;
//	cout << "Деление:\t";
//	result.ShowComplexNumber();
//
//	cout << endl;
//	system("pause");
//}