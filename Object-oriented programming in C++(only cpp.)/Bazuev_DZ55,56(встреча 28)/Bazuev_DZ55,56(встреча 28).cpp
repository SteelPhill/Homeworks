#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;


//			ВСТРЕЧА №28

/*Написать программу формирования частотного словаря
появления отдельных слов в некотором тексте. Обеспечить:
1. Чтение исходного текста из файла;
2. Вывод информации обо всех словах;
3. Вывод информации о наиболее часто встречающемся
слове;
4. Запись результата в файл.
При разработке программы использовать словарь типа map.*/

string to_string(const pair<string, int> pair)
{
	return pair.first + ": " + to_string(pair.second);
}

class FrequencyDictionaryFileHandler
{
	string dictionaryFileName;
	map<string, int> wordCount;

	void CleanWord(string& word)
	{
		const int size = word.size();

		int startIndex = 0;
		while (startIndex < size && !isalpha(word[startIndex]))
			startIndex++;

		int endIndex = size - 1;
		while (endIndex >= 0 && !isalpha(word[endIndex]))
			endIndex--;

		if ((startIndex != 0 || endIndex != size - 1) && startIndex <= endIndex)
			word = word.substr(startIndex, endIndex - startIndex + 1);

		if (startIndex > endIndex)
			word = "";
	}

	string MapToString() const
	{
		if (wordCount.empty())
			return "";

		string result;

		for (auto i : wordCount)
			result += i.first + ": " + to_string(i.second) + "\n";

		return result;
	}

public:
	FrequencyDictionaryFileHandler(const string& dictionaryFileName)
	{
		SetDictionaryFileName(dictionaryFileName);
	}

	void SetDictionaryFileName(const string& dictionaryFileName)
	{
		this->dictionaryFileName = dictionaryFileName;

		wordCount.clear();

		ifstream file(dictionaryFileName);
		if (!file.is_open())
			throw string("file is not open!");

		string word;
		while (file >> word)
		{
			CleanWord(word);

			if (word.empty())
				continue;

			auto insertResult = wordCount.insert(make_pair(word, 1));
			if (!insertResult.second)
				insertResult.first->second++;
		}

		file.close();
	}

	string GetDictionaryFileName() const
	{
		return dictionaryFileName;
	}

	void ShowInfoAboutAllWords() const
	{
		cout << MapToString() << endl;
	}

	string SearchMostCommonWord() const
	{
		if (wordCount.empty())
			throw string("map is empty!");

		auto max = wordCount.begin();

		for (auto i = wordCount.begin(); i != wordCount.end(); i++)
		{
			if (i->second > max->second)
				max = i;
		}

		return to_string(pair<string, int>(max->first, max->second));
	}

	void WriteResultsToFile(const string& resultFileName) const
	{
		ofstream file(resultFileName);
		if (!file.is_open())
			throw string("file is not open!");

		file << "Frequency dictionary content:" << endl;
		file << MapToString() << endl;
		file << "Most common word:" << endl;
		file << SearchMostCommonWord();

		file.close();
	}
};

void FrequencyDictionaryTest(const string& dictionaryFileName, const string& resultFileName)
{
	FrequencyDictionaryFileHandler dictionary(dictionaryFileName);

	cout << "\tFrequency dictionary content:" << endl;
	dictionary.ShowInfoAboutAllWords();

	cout << "\tMost common word:" << endl << dictionary.SearchMostCommonWord() << endl;

	dictionary.WriteResultsToFile(resultFileName);
}

void main()
{
	const char* DictionaryFileName = "frequency dictionary.txt";
	const char* ResultFileName = "result.txt";

	try
	{
		FrequencyDictionaryTest(DictionaryFileName, ResultFileName);
	}
	catch (const string& error)
	{
		cout << "Error: " << error << endl;
	}

	//remove(ResultFileName);

	cout << endl;
	system("pause");
}