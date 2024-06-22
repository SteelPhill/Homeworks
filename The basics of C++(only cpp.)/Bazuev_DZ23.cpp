#include <iostream>
#include <span>
using namespace std;


template <typename TValue>
void ShowArrayStartingFromSpecifiedCharacter(TValue* arr, const int &size, char startSymbol)
{
	for (int i : span(arr, size))
		cout << startSymbol++ << ": " << i << endl;
}

//				ЗАДАНИЕ №1

/*Есть некоторый текст. Используя стандартные 
строковые функции из библиотеки языка C:
- Найдите и замените вхождение некоторого слова на 
заданное пользователем слово.
- Изменить текст таким образом, чтобы каждое предложение начиналось с большой буквы.
- Посчитайте сколько раз каждая буква встречается в тексте.
- Посчитайте сколько раз цифры встречаются в тексте.*/

//			Найдите и замените вхождение некоторого слова на заданное пользователем слово.

bool IsWordsEnteredSame(const char* replacedWord, const char* newWord)
{
	bool enteredWordsAreSame = false;

	int sizeReplacedWord = strlen(replacedWord);
	char* replacedWordInUppercase = new char[sizeReplacedWord + 3];

	*replacedWordInUppercase = ' ';
	for (int i = 1; i <= sizeReplacedWord; i++)
		*(replacedWordInUppercase + i) = toupper(*(replacedWord + (i - 1)));
	*(replacedWordInUppercase + sizeReplacedWord + 1) = ' ';
	*(replacedWordInUppercase + sizeReplacedWord + 2) = '\0';


	int sizeNewWord = strlen(newWord);
	char* NewWordInUppercase = new char[sizeNewWord + 3];

	*NewWordInUppercase = ' ';
	for (int i = 1; i <= sizeNewWord; i++)
		*(NewWordInUppercase + i) = toupper(*(newWord + (i - 1)));
	*(NewWordInUppercase + sizeNewWord + 1) = ' ';
	*(NewWordInUppercase + sizeNewWord + 2) = '\0';

	if (_stricmp(replacedWord, newWord) == 0)
		enteredWordsAreSame = true;

	delete[] replacedWordInUppercase;
	delete[] NewWordInUppercase;

	return enteredWordsAreSame;

}

bool IsCharacterSetNotWord(const char* word)
{
	while (*word != '\0')
		if (isalpha(*word))
			word++;
		else
			return true;

	return false;
}

bool IsThatWholeWord(const char* ptrToReplacedWord, const int& sizeReplacedWord)
{
	return ((isspace(*(ptrToReplacedWord - 1)) || ispunct(*(ptrToReplacedWord - 1)))
		&& (isspace(*(ptrToReplacedWord + sizeReplacedWord)) || ispunct(*(ptrToReplacedWord + sizeReplacedWord))));
}

int SearchingWordInText(const char* sourceText, const char* replacedWord, const int &sizeSourceText, const int &sizeReplacedWord)
{
	char* sourceTextInUppercase = new char[sizeSourceText + 3];

	*sourceTextInUppercase = ' ';
	for (int i = 1; i <= sizeSourceText; i++)
		*(sourceTextInUppercase + i) = toupper(*(sourceText + (i - 1)));
	*(sourceTextInUppercase + sizeSourceText + 1) = ' ';
	*(sourceTextInUppercase + sizeSourceText + 2) = '\0';

	char* replacedWordInUppercase = new char[sizeReplacedWord + 1];

	for (int i = 0; i < sizeReplacedWord; i++)
		*(replacedWordInUppercase + i) = toupper(*(replacedWord + i));
	*(replacedWordInUppercase + sizeReplacedWord) = '\0';

	char* ptrToReplacedWord = strstr(sourceTextInUppercase, replacedWordInUppercase);

	while (ptrToReplacedWord != nullptr && !(IsThatWholeWord(ptrToReplacedWord, sizeReplacedWord)))
		ptrToReplacedWord = strstr(++ptrToReplacedWord, replacedWordInUppercase);

	int indexOfSearchingWord;

	if (ptrToReplacedWord == nullptr)
		indexOfSearchingWord = -1;
	else
		indexOfSearchingWord = strlen(sourceTextInUppercase) - strlen(ptrToReplacedWord) - 1;

	delete[] replacedWordInUppercase;
	delete[] sourceTextInUppercase;

	return indexOfSearchingWord;
}

int CalculatingSizeOfNewText(const int &sizeDiffBetweenWordsBeingReplaced, const int &sizeOfSourceText)
{
	if (sizeDiffBetweenWordsBeingReplaced < 0)
		return (sizeOfSourceText + abs(sizeDiffBetweenWordsBeingReplaced));
	else
		return (sizeOfSourceText - abs(sizeDiffBetweenWordsBeingReplaced));
}

char* ReplacingWord(const char* sourceText, const char* replacedWord, const char* newWord)
{
	int sizeSourceText = strlen(sourceText);
	int sizeReplacedWord = strlen(replacedWord);

	int indexBeginningReplacedWord = SearchingWordInText(sourceText, replacedWord, sizeSourceText, sizeReplacedWord);

	if (indexBeginningReplacedWord == -1)
		return nullptr;

	int sizeNewWord = strlen(newWord);
	int differenceSizeReplacedWords = sizeReplacedWord - sizeNewWord;
	int sizeNewText = CalculatingSizeOfNewText(differenceSizeReplacedWords, sizeSourceText);

	char* newText = new char[sizeNewText + 1];

	strncpy_s(newText, (indexBeginningReplacedWord + 1), sourceText, indexBeginningReplacedWord);

	strcat_s(newText, (indexBeginningReplacedWord + sizeNewWord + 1), newWord);

	char* ptrOnTextAfterReplacedWord = (char*)sourceText + indexBeginningReplacedWord + sizeReplacedWord;

	strcat_s(newText, (sizeNewText + 1), ptrOnTextAfterReplacedWord);

	return newText;
}

char* ReplacingGivenWordAndItsRepetitions(const char* sourceText, const char* replacedWord, const char* newWord) // Пытался придумать более адекватную логику
																												 // на проверку повторений слова в тексте,
																												 // чтобы не копировать код. Пробовал использовать
																												 // do...while, но получилось ещё страшнее) Больше не
																												 // путного ничего в голову не пришло)
{
	if (IsCharacterSetNotWord(replacedWord) || IsCharacterSetNotWord(newWord) || IsWordsEnteredSame(replacedWord, newWord))
		return nullptr;

	char* newText = ReplacingWord(sourceText, replacedWord, newWord);

	if(newText == nullptr)
		return nullptr;

	char temporaryArrayForDataTransfer[256];

	int i = 0;
	for (; *(newText + i) != '\0'; i++)
		*(temporaryArrayForDataTransfer + i) = *(newText + i);
	*(temporaryArrayForDataTransfer + i) = '\0';

	while (ReplacingWord(temporaryArrayForDataTransfer, replacedWord, newWord) != nullptr) 
	{
		delete[] newText;

		newText = ReplacingWord(temporaryArrayForDataTransfer, replacedWord, newWord);

		int j = 0;

		for (; *(newText + j) != '\0'; j++)
			*(temporaryArrayForDataTransfer + j) = *(newText + j);
		*(temporaryArrayForDataTransfer + j) = '\0';
	}

	return newText;
}



//			Изменить текст таким образом, чтобы каждое предложение начиналось с большой буквы.

bool IsThisEndOfSentence(const char &symbol)
{
	return symbol == '.' || symbol == '!' || symbol == '?';
}

char* TranslatingBeginningOfSentenceInUppercase(const char* sourceText)
{
	int sizeNewText = strlen(sourceText);
	char* newText = new char[sizeNewText + 1];

	char* ptrNewText = newText;

	bool IsThisBeginningOfNewSentence = true;

	for (; *sourceText != '\0'; sourceText++, ptrNewText++)
	{
		if (IsThisEndOfSentence(*(sourceText)))
		{
			*ptrNewText = *sourceText;
			IsThisBeginningOfNewSentence = true;
		}
		
		else if (IsThisBeginningOfNewSentence && isdigit(*(sourceText)))
		{
			*ptrNewText = *sourceText;
			IsThisBeginningOfNewSentence = false;
		}

		else if (IsThisBeginningOfNewSentence && isalpha(*sourceText))
		{
			*ptrNewText = toupper(*sourceText);
			IsThisBeginningOfNewSentence = false;
		}

		else
			*ptrNewText = *sourceText;
	}

	*ptrNewText = '\0';

	return newText;
}



//			Посчитайте сколько раз каждая буква встречается в тексте.

void CountingEachLetterInText(const char* sourceText, const int &size, int* arrayForCountingNumberOfEachLetter)
{
	const int CodeOfACharacterInUppercase = 65;
	const int CodeOfACharacterInLowercase = 97;

	for (int i = 0; i < size; i++)
	{
		*(arrayForCountingNumberOfEachLetter + i) = 0;

		for (int j = 0; *(sourceText + j) != '\0'; j++)
			if (*(sourceText + j) == CodeOfACharacterInUppercase + i || *(sourceText + j) == CodeOfACharacterInLowercase + i)
				(*(arrayForCountingNumberOfEachLetter + i))++;
	}
}



//			Посчитайте сколько раз цифры встречаются в тексте (для каждой цифры)

void CountingEachDigitInText(const char* sourceText, const int &size, int* arrayForCountingNumberOfEachDigit)
{
	const int codeOfZeroCharacter = 48;

	for (int i = 0; i < size; i++)
	{
		*(arrayForCountingNumberOfEachDigit + i) = 0;

		for (int j = 0; *(sourceText + j) != '\0'; j++)
			if (*(sourceText + j) == codeOfZeroCharacter + i )
				(*(arrayForCountingNumberOfEachDigit + i))++;
	}
}



//			Посчитайте сколько раз цифры встречаются в тексте

int CountingDigitInText(const char* sourceText)
{
	int digitCounter = 0;

	for (int i = 0; *(sourceText + i) != '\0'; i++)
		if (isdigit(*(sourceText + i)))
			digitCounter++;

	return digitCounter;
}




void main()
{
	setlocale(LC_ALL, "ru");

	const int SizeOfEngAlphabet = 26;
	const int NumberOfDigits = 10;
	const char ACharacterInLowercase = 'a';
	const char codeOfZeroCharacter = '0';

	const char* sourceText = "hello! my name is Bob. i am a student. 1991.01.01 - my date of birth. my phone number: 12345432.";


	//Найдите и замените вхождение некоторого слова на заданное пользователем слово.
	{
		cout << "Исходный текст: " << sourceText << endl;
		cout << endl;

		char replacedWord[128];
		cout << "Введите слово, которое будет заменено => ";
		gets_s(replacedWord);

		char newWord[128];
		cout << "Введите новое слово => ";
		gets_s(newWord);
		cout << endl;

		char* textAfterReplacingWord = ReplacingGivenWordAndItsRepetitions(sourceText, replacedWord, newWord);
		if (textAfterReplacingWord != nullptr)
			cout << "Текст после замены слова: " << textAfterReplacingWord << endl;
		else
			cout << "Ошибка ввода! Варианты ошибки:\nЗаменяемое слово отсутствует в тексте;\nВеденые символы не являются буквами английского алфавита;\nВведены одинаковые слова." << endl;
		delete[] textAfterReplacingWord;

		cout << endl;
		system("pause");
		system("cls");
	}

	//Изменить текст таким образом, чтобы каждое предложение начиналось с большой буквы.
	{
		cout << "Исходный текст: " << sourceText << endl;
		cout << endl;
		char* textAfterIncreasingFirstLettersOfSentence = TranslatingBeginningOfSentenceInUppercase(sourceText);
		cout << "Предложения начинаются с заглавной буквы: " << textAfterIncreasingFirstLettersOfSentence << endl;
		delete[] textAfterIncreasingFirstLettersOfSentence;

		cout << endl;
		system("pause");
		system("cls");
	}

	//Посчитайте сколько раз каждая буква встречается в тексте.
	{
		cout << "Сколько раз каждая буква повторяется в тексте: " << sourceText << endl;
		int numberOfEachLetterInText[SizeOfEngAlphabet];
		CountingEachLetterInText(sourceText, SizeOfEngAlphabet, numberOfEachLetterInText);
		ShowArrayStartingFromSpecifiedCharacter(numberOfEachLetterInText, SizeOfEngAlphabet, ACharacterInLowercase);

		cout << endl;
		system("pause");
		system("cls");
	}

	//Посчитайте сколько раз цифры встречаются в тексте (для каждой цифры)
	{
		cout << "Сколько раз каждая цифра повторяется в тексте: " << sourceText << endl;
		int numberOfEachDigitInText[NumberOfDigits];
		CountingEachDigitInText(sourceText, NumberOfDigits, numberOfEachDigitInText);
		ShowArrayStartingFromSpecifiedCharacter(numberOfEachDigitInText, NumberOfDigits, codeOfZeroCharacter);

		cout << endl;
		system("pause");
		system("cls");
	}

	//Посчитайте сколько раз цифры встречаются в тексте
	{
		cout << "Исходный текст: " << sourceText << endl;
		cout << endl;
		cout << "Сколько раз цифры повторяются в тексте: " << CountingDigitInText(sourceText) << endl;
	}


	cout << endl;
	system("pause");
}