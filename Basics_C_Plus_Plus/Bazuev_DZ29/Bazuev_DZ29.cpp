#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string rtrim(string& str)
{
	str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch)
		{
			return !isspace(ch);
		}).base(), str.end());

	return str;
}

bool IsAlphaRus(unsigned char ch)
{
	if (ch >= 192 && ch <= 255 || ch == 168 || ch == 184)
		return true;

	return false;
}

bool IsLowerRus(unsigned char ch)
{
	if (ch >= 224 && ch <= 255 || ch == 184)
		return true;

	return false;
}

bool IsUpperRus(unsigned char ch)
{
	if (ch >= 192 && ch <= 223 || ch == 168)
		return true;

	return false;
}


//			ЗАДАЧА №1

/*Дано два текстовых файла. Выяснить, совпадают ли их строки.
Если нет, то вывести несовпадающую строку из каждого файла.*/

//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	ifstream file1;
//	file1.open("ЗАДАЧА №1 - 1.txt");
//
//	if (!file1.is_open())
//		return;
//
//	ifstream file2;
//	file2.open("ЗАДАЧА №1 - 2.txt");
//
//	if (!file2.is_open())
//		return;
//
//	string str1;
//	string str2;
//
//	bool isStringsMatch = true;
//
//
////#define rTrim
//
//
//#ifdef rTrim												//ВАРИАНТ С ИСПОЛЬЗОВАНИЕМ rtrim
//	while (getline(file1, str1) && getline(file2, str2))
//	{
//		if (rtrim(str1).compare(rtrim(str2)) != 0)
//		{
//			isStringsMatch = false;
//			cout << "Строки не совпадают!" << endl;
//			cout << "Строка в первом файле: " << str1 << endl;
//			cout << "Строка во втором файле: " << str2 << endl << endl;
//		}
//	}
//#else														//ВАРИАНТ БЕЗ ИСПОЛЬЗОВАНИЯ rtrim
//	while (getline(file1, str1) && getline(file2, str2))
//	{
//		if (str1.compare(str2) != 0)
//		{
//			isStringsMatch = false;
//			cout << "Строки не совпадают!" << endl;
//			cout << "Строка в первом файле: " << str1 << endl;
//			cout << "Строка во втором файле: " << str2 << endl << endl;
//		}
//	}
//#endif
//
//	if (isStringsMatch)
//		cout << "Строки в файлах полностью совпадают." << endl << endl;
//
//	file1.close();
//	file2.close();
//
//	system("pause");
//}


//			ЗАДАЧА №2

/*Дан текстовый файл. Необходимо создать 
новый файл и записать в него следующую статистику по 
исходному файлу:
- Количество символов;
- Количество строк;
- Количество гласных букв;
- Количество согласных букв;
- Количество цифр.*/

//struct FileStatistics
//{
//	int charactersNumber = 0;
//	int rowsNumber = 0;
//	int vowelLettersNumber = 0;
//	int consonantLettersNumber = 0;
//	int digitsNumber = 0;
//};
//
//bool IsVowelLetter(unsigned char ch)
//{
//	const int engVowelLettersNumber = 12;
//	const int rusVowelLettersNumber = 20;
//
//	char engVowelLetters[engVowelLettersNumber] = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y' };
//	unsigned char rusVowelLetters[rusVowelLettersNumber] = { 'а', 'А', 'е', 'Е', 'ё', 'Ё', 'и', 'И', 'о', 'О', 'у', 'У', 'ы', 'Ы', 'э', 'Э', 'ю', 'Ю', 'я', 'Я'};
//
//	for (int i = 0; i < engVowelLettersNumber; i++)
//		if (ch == engVowelLetters[i])
//			return true;
//
//	for (int i = 0; i < rusVowelLettersNumber; i++)
//		if (ch == rusVowelLetters[i])
//			return true;
//
//	return false;
//}
//
//FileStatistics CalculateStatistics(ifstream& file)
//{
//	FileStatistics statistic;
//
//	string str;
//
//	while (getline(file, str))
//	{
//		statistic.charactersNumber += str.size();
//		statistic.rowsNumber += 1;
//
//		for (int i = 0; i < str.size(); i++)
//			if (IsVowelLetter(str[i]))
//				statistic.vowelLettersNumber++;
//
//			else if (isalpha((unsigned char)str[i]) || IsAlphaRus(str[i]))
//				statistic.consonantLettersNumber++;
//
//			else if (isdigit((unsigned char)str[i]))
//				statistic.digitsNumber++;
//	}
//
//	return statistic;
//}
//
//void WritingStatisticsFile(ofstream& destinationFile, FileStatistics& statistic)
//{
//	destinationFile << "Количество символов в файле: " << statistic.charactersNumber << endl;
//	destinationFile << "Количество строк в файле: " << statistic.rowsNumber << endl;
//	destinationFile << "Количество гласных букв в файле: " << statistic.vowelLettersNumber << endl;
//	destinationFile << "Количество согласных букв в файле: " << statistic.consonantLettersNumber << endl;
//	destinationFile << "Количество цифр в файле: " << statistic.digitsNumber;
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	ifstream sourceFile;
//	sourceFile.open("ЗАДАЧА №2 - исходный файл.txt");
//
//	if (sourceFile.is_open())
//		cout << "Исходный файл открыт." << endl;
//	else
//		return;
//
//	FileStatistics statistic = CalculateStatistics(sourceFile);
//
//	sourceFile.close();
//
//	ofstream destinationFile;
//	destinationFile.open("ЗАДАЧА №2 - статистический файл.txt");
//
//	if (destinationFile.is_open())
//		cout << "Файл для записи открыт (создан)." << endl;
//	else
//		return;
//
//	WritingStatisticsFile(destinationFile, statistic);
//
//	destinationFile.close();
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3 - 1-ый вариант (не очень хороший)

/*Шифр Цезаря — один из древнейших шифров. 
При шифровании каждый символ заменяется другим, 
отстоящим от него в алфавите на фиксированное число 
позиций.
Пример:
- Шифрование с использованием ключа: 3.
- Оригинальный текст: Съешь же ещё этих мягких 
французских булок, да выпей чаю.
- Шифрованный текст: Фэзыя йз зьи ахлш пвёнлш
чугрщцкфнлш дцосн, жг еютзм ъгб.
- Дан текстовый файл. Зашифровать его, используя
шифр Цезаря. Результат записать в другой файл.*/

//int SearchSymbolIndexInAlphabet(unsigned char* alphabet, const int alphabetSize, const unsigned char searchSymbol)
//{
//	int index = -1;
//
//	for (int i = 0; i < alphabetSize; i++)
//		if (searchSymbol == alphabet[i])
//			index = i;
//
//	return index;
//}
//
//void ShiftAlphabet(char* alphabet, const int alphabetSize, const int shiftsNumber)
//{
//	for (int i = 1; i <= shiftsNumber; i++)
//		for (int j = 1; j < alphabetSize; j++)
//			swap(alphabet[j], alphabet[j - 1]);
//}
//
//char ReplaceLetterByCiphered(char* alphabet, const int alphabetSize, char symbol, const int key)
//{
//	int indexLetter = SearchSymbolIndexInAlphabet((unsigned char*)alphabet, alphabetSize, symbol);
//
//	ShiftAlphabet(alphabet, alphabetSize, key);
//
//	symbol = alphabet[indexLetter];
//
//	return symbol;
//}
//
//void EncryptionWithCaesarCipher(ifstream& sourceFile, ofstream& destinationFile, const int key)
//{
//	const int rusAlphabetSize = 33;
//	const int engAlphabetSize = 26;
//
//	char uppercaseRusAlphabet[rusAlphabetSize] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М',
//		'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я' };
//
//	char lowercaseRusAlphabet[rusAlphabetSize] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м',
//		'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
//
//	char uppercaseEngAlphabet[engAlphabetSize] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
//		'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//
//	char lowercaseEngAlphabet[engAlphabetSize] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
//		'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
//
//	string str;
//
//	while (getline(sourceFile, str))
//	{
//		for (int i = 0; i < str.size(); i++)
//			if (IsAlphaRus(str[i]))
//			{
//				if (IsUpperRus(str[i]))
//					str[i] = ReplaceLetterByCiphered(uppercaseRusAlphabet, rusAlphabetSize, str[i], key);
//				else if (IsLowerRus(str[i]))
//					str[i] = ReplaceLetterByCiphered(lowercaseRusAlphabet, rusAlphabetSize, str[i], key);
//			}
//
//			else if (isalpha(str[i]))
//			{
//				if (isupper(str[i]))
//					str[i] = ReplaceLetterByCiphered(uppercaseEngAlphabet, engAlphabetSize, str[i], key);
//				else if (islower(str[i]))
//					str[i] = ReplaceLetterByCiphered(lowercaseEngAlphabet, engAlphabetSize, str[i], key);
//			}
//
//		destinationFile << str << endl;
//	}
//}
//
//void main()
//{
//	const int key = 3;
//
//	setlocale(LC_ALL, "ru");
//
//	ifstream sourceFile;
//	sourceFile.open("ЗАДАЧА №3 - исходный файл.txt");
//
//	if (sourceFile.is_open())
//		cout << "Исходный файл открыт." << endl;
//	else
//		return;
//
//	ofstream destinationFile;
//	destinationFile.open("ЗАДАЧА №3 - файл с шифром.txt");
//
//	if (destinationFile.is_open())
//		cout << "Файл для записи открыт (создан)." << endl;
//	else
//		return;
//
//	EncryptionWithCaesarCipher(sourceFile, destinationFile, key);
//
//	sourceFile.close();
//	destinationFile.close();
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАЧА №3 - 2-ой вариант (получше 1-ого)

/*Шифр Цезаря — один из древнейших шифров. 
При шифровании каждый символ заменяется другим, 
отстоящим от него в алфавите на фиксированное число 
позиций.
Пример:
- Шифрование с использованием ключа: 3.
- Оригинальный текст: Съешь же ещё этих мягких 
французских булок, да выпей чаю.
- Шифрованный текст: Фэзыя йз зьи ахлш пвёнлш
чугрщцкфнлш дцосн, жг еютзм ъгб.
- Дан текстовый файл. Зашифровать его, используя
шифр Цезаря. Результат записать в другой файл.*/

//int SearchSymbolIndexInAlphabet(unsigned char* alphabet, const int alphabetSize, const unsigned char searchSymbol)
//{
//	int index = -1;
//
//	for (int i = 0; i < alphabetSize; i++)
//		if (searchSymbol == alphabet[i])
//		{
//			index = i;
//			break;
//		}
//
//	return index;
//}
//
//char ReplaceRusLetterByCiphered(char* alphabet, const int alphabetSize, char symbol, const int key)
//{
//	int indexLetter = SearchSymbolIndexInAlphabet((unsigned char*)alphabet, alphabetSize, symbol);
//
//	if ((indexLetter + key) > alphabetSize - 1)
//		indexLetter = (indexLetter + key) - alphabetSize;
//	else
//		indexLetter += key;
//
//	symbol = alphabet[indexLetter];
//
//	return symbol;
//}
//
//char ReplaceEngLetterByCiphered(const int beginAlphabet, const int endAlphabet, char symbol, const int key)
//{
//	if ((symbol + key) > endAlphabet)
//		symbol = (beginAlphabet - 1) + (symbol + key - endAlphabet);
//	else
//		symbol += key;
//
//	return symbol;
//}
//
//void EncryptionWithCaesarCipher(ifstream& sourceFile, ofstream& destinationFile, const int key)
//{
//	const int rusAlphabetSize = 33;
//	const char ASymbolInUpper = 'A';
//	const char ZSymbolInUpper = 'Z';
//	const char ASymbolInLower = 'a';
//	const char ZSymbolInLower = 'z';
//
//	char uppercaseRusAlphabet[rusAlphabetSize] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М',
//		'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я' };
//
//	char lowercaseRusAlphabet[rusAlphabetSize] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м',
//		'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
//
//	string str;
//
//	while (getline(sourceFile, str))
//	{
//		for (int i = 0; i < str.size(); i++)
//			if (IsAlphaRus(str[i]))
//			{
//				if (IsUpperRus(str[i]))
//					str[i] = ReplaceRusLetterByCiphered(uppercaseRusAlphabet, rusAlphabetSize, str[i], key);
//				else if(IsLowerRus(str[i]))
//					str[i] = ReplaceRusLetterByCiphered(lowercaseRusAlphabet, rusAlphabetSize, str[i], key);
//			}
//			else if (isalpha(str[i]))
//			{
//				if (isupper(str[i]))
//					str[i] = ReplaceEngLetterByCiphered(ASymbolInUpper, ZSymbolInUpper, str[i], key);
//				else if (islower(str[i]))
//					str[i] = ReplaceEngLetterByCiphered(ASymbolInLower, ZSymbolInLower, str[i], key);
//			}
//
//		destinationFile << str << endl;
//	}
//}
//
//void main()
//{
//	const int key = 3;
//
//	setlocale(LC_ALL, "ru");
//
//	ifstream sourceFile;
//	sourceFile.open("ЗАДАЧА №3 - исходный файл.txt");
//
//	if (sourceFile.is_open())
//		cout << "Исходный файл открыт." << endl;
//	else
//		return;
//
//	ofstream destinationFile;
//	destinationFile.open("ЗАДАЧА №3 - файл с шифром.txt");
//
//	if (destinationFile.is_open())
//		cout << "Файл для записи открыт (создан)." << endl;
//	else
//		return;
//
//	EncryptionWithCaesarCipher(sourceFile, destinationFile, key);
//
//	sourceFile.close();
//	destinationFile.close();
//
//	cout << endl;
//	system("pause");
//}