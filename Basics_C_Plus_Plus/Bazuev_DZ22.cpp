#include <iostream>
using namespace std;


//			ЗАДАЧА №1

/*Дополните свою библиотеку функций реализациями нижеследующих функций:
- int mystrcmp (const char * str1, const char * str2); — 
функция сравнивает две строки, и, если строки равны 
возвращает 0, если первая строка больше второй, то 
возвращает 1, иначе –1.
- int StringToNumber(char * str); — функция конвертирует строку в число и возвращает это число.
- char * NumberToString (int number); — функция конвертирует число в строку и возвращает указатель на 
эту строку.
- char * Uppercase (char * str1); — функция преобразует 
строку в верхний регистр.
- char * Lowercase (char * str1); — функция преобразует 
строку в нижний регистр.
- char * mystrrev (char * str); — функция реверсирует 
строку и возвращает указатель на новую строку.*/

int MyStrCmp(const char* str1, const char* str2)
{
	for (; *str1 != '\0' || *str2 != '\0'; str1++, str2++)
		if (*str1 < *str2)
			return -1;

		else if (*str1 > *str2)
			return 1;

	return 0;
}

int StringToNumber(char* str)
{
	const int decimalMinusCode = 45;
	const int decimalZeroCode = 48;
	const int bitDepthMultiplier = 10;
	const int multiplierForNegativeNumber = -1;

	char* firstSymbol = str;
	int result = 0;

	for (; *str != '\0'; str++)
		if (isdigit(*str))
		{
			result += (*str - decimalZeroCode);
			result *= bitDepthMultiplier;
		}

	if (*firstSymbol == decimalMinusCode)
		return result / bitDepthMultiplier * multiplierForNegativeNumber;

	return result / bitDepthMultiplier;
}

char* NumberToString(int number)
{
	const int decimalZeroCode = 48;
	const int bitDivider = 10;

	int lengthNumber = 0;
	int copyOfNumber = number;

	while (copyOfNumber != 0)
	{
		copyOfNumber /= bitDivider;
		lengthNumber++;
	}

	char* str;
	char* pointerStr;

	if (number > 0)
	{
		str = new char[lengthNumber + 1];
		pointerStr = str + lengthNumber - 1;
		*(str + lengthNumber) = '\0';
	}

	else if (number < 0)
	{
		str = new char[lengthNumber + 2];
		pointerStr = str + lengthNumber;
		*str = '-';
		*(str + lengthNumber + 1) = '\0';
	}

	else
	{
		str = new char[2];
		pointerStr = str + lengthNumber;
		*str = '0';
		*(str + 1) = '\0';
	}

	number = abs(number);

	for (; number != 0; pointerStr--)
	{
		*pointerStr = decimalZeroCode + (number % bitDivider);
		number /= bitDivider;
	}

	return str;
}

char* UpperCase(char* str1)
{
	const int differenceBetweenLowercaseAndUppercaseletters = 32;

	int lengthStr1 = strlen(str1);

	char* str2 = new char[lengthStr1 + 1];
	char* pointerStr2 = str2;

	for (; *str1 != '\0'; str1++, pointerStr2++)
		if (islower(*str1))
			*pointerStr2 = *str1 - differenceBetweenLowercaseAndUppercaseletters;
		else
			*pointerStr2 = *str1;

	*pointerStr2 = '\0';

	return str2;
}

char* LowerCase(char* str1)
{
	const int differenceBetweenLowercaseAndUppercaseletters = 32;

	int lengthStr1 = strlen(str1);

	char* str2 = new char[lengthStr1 + 1];
	char* pointerStr2 = str2;

	for (; *str1 != '\0'; str1++, pointerStr2++)
		if (isupper(*str1))
			*pointerStr2 = *str1 + differenceBetweenLowercaseAndUppercaseletters;
		else
			*pointerStr2 = *str1;

	*pointerStr2 = '\0';

	return str2;
}

char* MyStrRev(char* str)
{
	int lengthStr = strlen(str);

	char* newStr = new char[lengthStr + 1];
	newStr += lengthStr;

	*newStr-- = '\0';

	while (*str != '\0')
		*newStr-- = *str++;

	return ++newStr;
}

void main()
{
	setlocale(LC_ALL, "ru");


	//MyStrCmp
	const char* strCmp1 = "qwerty";
	const char* strCmp2 = "qwerty";

	int resultMyStrCmp = MyStrCmp(strCmp1, strCmp2);

	cout << "Результат вызова функции MyStrCmp(): ";
	if (resultMyStrCmp > 0)
		cout << "Первая строка больше" << endl;
	else if (resultMyStrCmp < 0)
		cout << "Вторая строка больше" << endl;
	else
		cout << "Строки равны" << endl;
	cout << endl;


	//StringToNumber
	char strIsNum[10] = "-12345678";
	int resultStrToNum = StringToNumber(strIsNum);
	cout << "Результат вызова функции StringToNumber(): " << resultStrToNum << endl;
	cout << endl;


	//NumberToString 
	char* numIsStr = NumberToString(-12345678);
	cout << "Результат вызова функции NumberToString(): " << numIsStr << endl;
	cout << endl;
	delete[] numIsStr;


	char strForUpperAndLowerCasesAndMyStrRev[14] = "HELLO, world!";


	//UpperCase
	char* upperCaseStr = UpperCase(strForUpperAndLowerCasesAndMyStrRev);
	cout << "Результат вызова функции UpperCase(): " << upperCaseStr << endl;
	cout << endl;
	delete[] upperCaseStr;


	//LowerCase
	char* lowerCaseStr = LowerCase(strForUpperAndLowerCasesAndMyStrRev);
	cout << "Результат вызова функции LowerCase(): " << lowerCaseStr << endl;
	cout << endl;
	delete[] lowerCaseStr;


	//MyStrRev
	char* reverseStr = MyStrRev(strForUpperAndLowerCasesAndMyStrRev);
	cout << "Результат вызова функции MyStrRev(): " << reverseStr << endl;
	cout << endl;
	delete[] reverseStr;

	system("pause");
}