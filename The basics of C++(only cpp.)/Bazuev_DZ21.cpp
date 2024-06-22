#include <iostream>
#include <windows.h>
using namespace std;

int GetStringLength(char* str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}

	return length;
}


//			ЗАДАЧА №1

/*Написать функцию, которая удаляет из
строки символ с заданным номером.*/

//void DeletingCharacterFromStringByIndex(char* str, int index)
//{
//	char* firstPointer = str + index;
//	char* secondPointer = str + index + 1;
//
//	while (*secondPointer != '\0')
//		*firstPointer++ = *secondPointer++;
//
//	*firstPointer = '\0';
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	int indexOfDeleteElement = 1;
//
//	char str[] = "Hello!";
//	cout << "Исходная строка: " << str << endl;
//	cout << endl;
//
//	DeletingCharacterFromStringByIndex(str, indexOfDeleteElement);
//	cout << "Строка после удаления элемента: " << str << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №2

/*Написать функцию, которая удаляет из строки 
все вхождения в нее заданного символа.*/

//void DeletingCharacterFromString(char* str, char characterBeingDeleted)
//{
//	char* firstPointer = str;
//	char* secondPointer = str;
//
//	while (*secondPointer != '\0')
//		if (*secondPointer != characterBeingDeleted)
//			*firstPointer++ = *secondPointer++;
//		else
//			secondPointer++;
//
//	*firstPointer = '\0';
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	char characterBeingDeleted = 'l';
//
//	char str[] = "Hello!";
//	cout << "Исходная строка: " << str << endl;
//	cout << endl;
//
//	DeletingCharacterFromString(str, characterBeingDeleted);
//	cout << "Строка после удаления элемента(ов): " << str << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3 

/*Написать функцию, которая вставляет в строку 
в указанную позицию заданный символ.*/

//void InsertingCharacterByIndex(char* str, const char insertedCharacter, const int insertionIndex)
//{
//	int originalStrSize = GetStringLength(str);
//
//	char* firstPointer = str + originalStrSize;
//	char* secondPointer = str + originalStrSize - 1;
//
//	while (firstPointer >= str + insertionIndex)
//		*firstPointer-- = *secondPointer--;
//
//	*(str + insertionIndex) = insertedCharacter;
//	*(str + originalStrSize + 1) = '\0';
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	char insertedCharacter = '#';
//	int insertionIndex = 3;
//
//	char str[128] = "Hello!";
//	cout << "Исходная строка: " << str << endl;
//	cout << endl;
//
//	InsertingCharacterByIndex(str, insertedCharacter, insertionIndex);
//	cout << "Строка после добавления элемента: " << str << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №4
/*Написать программу, которая заменяет все 
символы точки «.» в строке, введенной пользователем, 
на символы восклицательного знака «!».*/

//void ReplacingPointsToExclamationMarksInString(char* str)
//{
//	while (*str != '\0')
//		if (*str == '.')
//			*str++ = '!';
//		else
//			str++;
//}
//
//void main()
//{
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//	char str[128];
//	cout << "Введите строку, содержащую точки => ";
//	gets_s(str);
//	cout << endl;
//
//	ReplacingPointsToExclamationMarksInString(str);
//	cout << "Строка после замены точек на восклицательные знаки: " << str << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №5

/*Пользователь вводит строку символов и искомый 
символ, посчитать сколько раз он встречается
в строке.*/

//int CountingCharactersInString(char* str, const char symbol)
//{
//	int counterOfSpecifiedSymbol = 0;
//
//	while (*str != '\0')
//		if (*str == symbol)
//		{
//			counterOfSpecifiedSymbol++;
//			str++;
//		}
//		else
//			str++;
//
//	return counterOfSpecifiedSymbol;
//}
//
//void main()
//{
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//	char str[128];
//	cout << "Введите строку => ";
//	gets_s(str);
//	cout << endl;
//
//	char symbol;
//	cout << "Введите символ => ";
//	cin >> symbol;
//	cout << endl;
//
//	cout << "Количество симколов '" << symbol << "' в строке \"" << str << "\": " << CountingCharactersInString(str, symbol) << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №6

/*Пользователь вводит строку. Определить количество
букв, количество цифр и количество остальных символов,
присутствующих в строке.*/

//void CountingLettersAndNumbersAndOtherCharactersInString(char* str, int* numberOfLetters, int* numberOfDigits, int* numberOfOtherCharacters)
//{
//	while (*str != '\0')
//		if (*str >= 65 && *str <= 90 || *str >= 97 && *str <= 122)
//		{
//			(*numberOfLetters)++;
//			str++;
//		}
//
//		else if (*str >= 48 && *str <= 57)
//		{
//			(*numberOfDigits)++;
//			str++;
//		}
//
//		else
//		{
//			(*numberOfOtherCharacters)++;
//			str++;
//		}
//}
//
//void main()
//{
//	char str[128];
//
//	cout << "Input string => ";
//	gets_s(str);
//	cout << endl;
//
//	int numberOfLettersInString = 0;
//	int numberOfDigitsInString = 0;
//	int numberOfOtherCharactersInString = 0;
//
//	CountingLettersAndNumbersAndOtherCharactersInString(str, &numberOfLettersInString, &numberOfDigitsInString, &numberOfOtherCharactersInString);
//
//	cout << "Number of letters in string: " << numberOfLettersInString << endl;
//	cout << "Number of digits in string: " << numberOfDigitsInString << endl;
//	cout << "Number of other characters in string: " << numberOfOtherCharactersInString << endl;
//
//	cout << endl;
//	system("pause");
//}