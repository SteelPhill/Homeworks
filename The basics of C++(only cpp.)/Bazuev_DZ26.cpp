#define NOMINMAX
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <Windows.h>
using namespace std;

template <typename TValue>
bool TryReadValue(
	TValue* result,
	istream& input,
	ostream& output,
	const string& inputMessage,
	const string& errorMessage,
	const streamsize ignoreCountOnError = 1,
	const int ignoreDelimiterOnError = EOF)
{
	while (true)
	{
		if (!inputMessage.empty())
			output << inputMessage;

		input >> *result;

		if (!input.fail())
			return true;

		if (input.eof())
			return false;

		input.clear();
		input.ignore(ignoreCountOnError, ignoreDelimiterOnError);

		if (!errorMessage.empty())
			output << errorMessage;
	}
}

template <typename TValue>
bool TryReadValueInRange(
	TValue* result,
	istream& input,
	ostream& output,
	const TValue startRange,
	const TValue endRange,
	const string& inputMessage,
	const string& errorMessage,
	const streamsize ignoreCountOnError = 1,
	const int ignoreDelimiterOnError = EOF)
{
	while (true)
	{
		bool inputResult =
			TryReadValue<TValue>(
				result,
				input,
				output,
				inputMessage,
				errorMessage,
				ignoreCountOnError,
				ignoreDelimiterOnError);

		if (inputResult && *result >= startRange && *result <= endRange)
			return true;

		if (!errorMessage.empty())
			output << errorMessage;
	}
}

template <typename TValue>
TValue CinValueInRange(
	const TValue startRange,
	const TValue endRange,
	const string& inputMessage = " => ",
	const string& errorMessage = "Ошибка!\r\n",
	const streamsize ignoreCountOnError = numeric_limits<streamsize>::max(),
	const int ignoreDelimiterOnError = '\n')
{
	TValue value;
	TryReadValueInRange<TValue>(
		&value,
		cin,
		cout,
		startRange,
		endRange,
		inputMessage,
		errorMessage,
		ignoreCountOnError,
		ignoreDelimiterOnError);

	return value;
}


//			ЗАДАЧА №1

/*Разработайте программу «Библиотека». Создайте структуру «Книга»
(название, автор, издательство, жанр). Создайте массив из 10 книг.
Реализуйте для него следующие возможности:
- Редактировать книгу;
- Печать всех книг;
- Поиск книг по автору;
- Поиск книги по названию;
- Сортировка массива по названию книг;
- Сортировка массива по автору;
- Сортировка массива по издательству.*/

enum class MenuItems
{
	EditBook = 1,
	PrintAllBooks = 2,
	SearchByWriter = 3,
	SearchByName = 4,
	SortByName = 5,
	SortByWriter = 6,
	SortByPublisher = 7,
	ExitProgram = 8
};

struct Book
{
	string Name;
	string Writer;
	string Publisher;
	string Genre;
};

void FillLibrary(Book* library)
{
	library[0].Name = "Возвышение Хоруса";
	library[0].Writer = "Дэн Абнетт";
	library[0].Publisher = "Black Library";
	library[0].Genre = "Фантастика";

	library[1].Name = "Мастер и Маргарита";
	library[1].Writer = "Михаил Булгаков";
	library[1].Publisher = "Neoclassic";
	library[1].Genre = "Роман";

	library[2].Name = "Чистый код";
	library[2].Writer = "Роберт Мартин";
	library[2].Publisher = "Питер";
	library[2].Genre = "Технологии программирования";

	library[3].Name = "Ведьмак. Последнее желание";
	library[3].Writer = "Анджей Сапковский";
	library[3].Publisher = "Neoclassic";
	library[3].Genre = "Фантастика";

	library[4].Name = "Убийство в \"Восточном экспрессе\"";
	library[4].Writer = "Агата Кристи";
	library[4].Publisher = "Эксмо";
	library[4].Genre = "Детектив";

	library[5].Name = "Ангелы и демоны";
	library[5].Writer = "Дэн Браун";
	library[5].Publisher = "Neoclassic";
	library[5].Genre = "Детектив";

	library[6].Name = "Властелин колец";
	library[6].Writer = "Джон Рональд Руэл Толкин";
	library[6].Publisher = "Neoclassic";
	library[6].Genre = "Фэнтези";

	library[7].Name = "Бэтмен. Убийственная шутка";
	library[7].Writer = "Алан Мур";
	library[7].Publisher = "Азбука";
	library[7].Genre = "Комикс";

	library[8].Name = "Хранители";
	library[8].Writer = "Алан Мур";
	library[8].Publisher = "Азбука";
	library[8].Genre = "Комикс";

	library[9].Name = "Вокруг света за 80 дней";
	library[9].Writer = "Жюль Верн";
	library[9].Publisher = "Эксмо";
	library[9].Genre = "Приключения";
}

int Menu()
{
	const int FirstPoint = 1;
	const int LastPoint = 8;

	cout << "Меню программы \"Библиотека\"." << endl;
	cout << endl;
	cout << "\tСписок опций:" << endl;
	cout << "1.Редактировать книгу;" << endl;
	cout << "2.Печать всех книг;" << endl;
	cout << "3.Поиск книг по автору;" << endl;
	cout << "4.Поиск книг по названию;" << endl;
	cout << "5.Сортировка книг по названиям;" << endl;
	cout << "6.Сортировка книг по авторам;" << endl;
	cout << "7.Сортировка книг по издательствам." << endl;
	cout << "8.Завершить работу программы." << endl;
	cout << endl;

	cout << "Выберите номер опции из списка" << endl;
	int choice = CinValueInRange<int>(FirstPoint, LastPoint);
	cout << endl;

	return choice;
}

void ShowLibrary(Book* library, const int LibrarySize)
{
	cout << "Содержимое библиотеки:" << endl << endl;

	for (int i = 0; i < LibrarySize; i++)
	{
		cout << "Книга №" << i + 1 << endl;
		cout << "\tНазвание: " << library[i].Name << endl;
		cout << "\tАвтор: " << library[i].Writer << endl;
		cout << "\tИздательство: " << library[i].Publisher << endl;
		cout << "\tЖанр: " << library[i].Genre << endl;
		cout << endl;
	}
}

void ShowOneBook(Book& book, const int selectedBook)
{
	cout << "Книга №" << selectedBook << endl;
	cout << "\tНазвание: " << book.Name << endl;
	cout << "\tАвтор: " << book.Writer << endl;
	cout << "\tИздательство: " << book.Publisher << endl;
	cout << "\tЖанр: " << book.Genre << endl;
	cout << endl;
}

void ShowAllBooksName(Book* library, const int LibrarySize)
{
	cout << "Содержимое библиотеки:" << endl;

	for (int i = 0; i < LibrarySize; i++)
		cout << "\tКнига №" << i + 1 << ": " << library[i].Name << endl;
	cout << endl;
}

void EditName(Book& book)
{
	const int CapitalLetter = 0;

	cout << "Новое название => ";
	getline(cin, book.Name);

	char* newName = new char[book.Name.size() + 1];

	int i = 0;
	while (isspace(book.Name[i]))
		i++;

	newName[CapitalLetter] = toupper(book.Name[i++]);

	int j = 1;
	while (i < book.Name.size())
		if (isspace(book.Name[i - 1]) && isspace(book.Name[i]))
			i++;
		else
			newName[j++] = book.Name[i++];

	newName[j] = '\0';

	book.Name = newName;

	delete[] newName;
	
	cout << endl;
}

void EditWriter(Book& book)
{
	const int CapitalLetter = 0;

	cout << "Новый автор => ";
	getline(cin, book.Writer);

	char* newWriter = new char[book.Writer.size() + 1];

	int i = 0;
	while (isspace(book.Writer[i]))
		i++;

	newWriter[CapitalLetter] = toupper(book.Writer[i++]);

	int j = 1;
	while (i < book.Writer.size())
		if (isspace(book.Writer[i - 1]) && isspace(book.Writer[i]))
			i++;
		else
			newWriter[j++] = book.Writer[i++];

	newWriter[j] = '\0';

	book.Writer = newWriter;

	delete[] newWriter;

	cout << endl;
}

void EditPublisher(Book& book)
{
	const int CapitalLetter = 0;

	cout << "Новое издательство => ";
	getline(cin, book.Publisher);

	char* newPublisher = new char[book.Publisher.size() + 1];

	int i = 0;
	while (isspace(book.Publisher[i]))
		i++;

	newPublisher[CapitalLetter] = toupper(book.Publisher[i++]);

	int j = 1;
	while (i < book.Publisher.size())
		if (isspace(book.Publisher[i - 1]) && isspace(book.Publisher[i]))
			i++;
		else
			newPublisher[j++] = book.Publisher[i++];

	newPublisher[j] = '\0';

	book.Publisher = newPublisher;

	delete[] newPublisher;

	cout << endl;
}

void EditGenre(Book& book)
{
	const int CapitalLetter = 0;

	cout << "Новый жанр => ";
	getline(cin, book.Genre);

	char* newGenre = new char[book.Genre.size() + 1];

	int i = 0;
	while (isspace(book.Genre[i]))
		i++;

	newGenre[CapitalLetter] = toupper(book.Genre[i++]);

	int j = 1;
	while (i < book.Genre.size())
		if (isspace(book.Genre[i - 1]) && isspace(book.Genre[i]))
			i++;
		else
			newGenre[j++] = book.Genre[i++];

	newGenre[j] = '\0';

	book.Genre = newGenre;

	delete[] newGenre;

	cout << endl;
}

void EditingBooks(Book* library, const int librarySize)
{
	const int BooksSelectionStartRange = 0;
	const int CharactristicsNumber = 4;
	const int OptionsNumber = 5;
	const int CancelEdit = 5;

	void (*EditingCharacteristic[CharactristicsNumber])(Book&) = {
		EditName,
		EditWriter,
		EditPublisher,
		EditGenre };

	do
	{
		cout << "Редактирование книг." << endl << endl;
		cout << "\tСписок опций:" << endl;
		cout << "1.Редактировать название кинги;" << endl;
		cout << "2.Редактировать автора книги;" << endl;
		cout << "3.Редактировать издательство книги;" << endl;
		cout << "4.Редактировать жанр книги;" << endl;
		cout << "5.Закончить редактирование книг." << endl << endl;

		cout << "Выберите номер опции из списка" << endl;
		int selectedCharacteristic = CinValueInRange<int>(BooksSelectionStartRange, OptionsNumber);
		cout << endl;

		if (selectedCharacteristic == CancelEdit)
		{
			cout << "Редактирование окончено." << endl << endl;
			return;
		}

		ShowAllBooksName(library, librarySize);
		cout << "Выберите номер книги для редактирования или введите 0 для отмены редактирования" << endl;
		int selectedBook = CinValueInRange<int>(BooksSelectionStartRange, librarySize);
		cout << endl;

		if (selectedBook == BooksSelectionStartRange)
		{
			cout << "Отмена редактирования книги." << endl << endl;
			system("pause");
			system("cls");
			continue;
		}

		ShowOneBook(library[selectedBook - 1], selectedBook);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		EditingCharacteristic[selectedCharacteristic - 1](library[selectedBook - 1]);

		cout << endl;
		cout << "\tРезультат редактирования:" << endl;
		ShowOneBook(library[selectedBook - 1], selectedBook);

		system("pause");
		system("cls");

	} while (true);
}


bool IsStringsEqualWithoutSpaces(string &bookName, string &searchName)
{
	bool isCmp = false;

	char* bookNameWithoutSpace = new char[bookName.size() + 1];
	char* searchNameWithoutSpace = new char[searchName.size() + 1];

	int i = 0;
	for (int j = 0; j < bookName.size(); j++)
		if (!isspace(bookName[j]))
				bookNameWithoutSpace[i++] = bookName[j];

	bookNameWithoutSpace[i] = '\0';

	i = 0;
	for (int j = 0; j < searchName.size(); j++)
		if (!isspace(searchName[j]))
				searchNameWithoutSpace[i++] = searchName[j];

	searchNameWithoutSpace[i] = '\0';

	if(_stricmp(bookNameWithoutSpace, searchNameWithoutSpace) == 0)
		isCmp = true;

	delete[] bookNameWithoutSpace;
	delete[] searchNameWithoutSpace;

	return isCmp;
}

void SearchBookByWriter(Book* library, const int LibrarySize)
{
	cout << "Поиск книг по автору." << endl << endl;

	string searchedWriter;
	cout << "Введите автора книги => ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, searchedWriter);
	cout << endl;

	bool isNotFound = true;

	for (int i = 0; i < LibrarySize; i++)
	{
		if (IsStringsEqualWithoutSpaces(library[i].Writer, searchedWriter))
		{
			ShowOneBook(library[i], i + 1);
			isNotFound = false;
		}
	}

	if (isNotFound)
		cout << "Книг, написанных данным автором нет! " << endl << endl;
}

void SearchBookByName(Book* library, const int LibrarySize)
{
	cout << "Поиск книг по названию." << endl << endl;

	string searchedName;
	cout << "Введите название книги => ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, searchedName);
	cout << endl;

	bool isNotFound = true;

	for (int i = 0; i < LibrarySize; i++)
	{
		if (IsStringsEqualWithoutSpaces(library[i].Name, searchedName))
		{
			ShowOneBook(library[i], i + 1);
			isNotFound = false;
		}
	}

	if(isNotFound)
		cout << "Книги с таким названием нет! " << endl << endl;
}


bool IsComparedStrings(string &str1, string &str2)
{
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	return str1.compare(str2) < 0;;
}

void SortBookByName(Book* library, const int librarySize)
{
	sort(library, library + librarySize,
		[](Book left, Book right)
		{
			return IsComparedStrings(left.Name, right.Name);
		});

	cout << "Сортировка книг по названиям завершена!" << endl << endl;
}

void SortBookByWriter(Book* library, const int librarySize) 
{
	sort(library, library + librarySize,
		[](Book left, Book right)
		{
			return IsComparedStrings(left.Writer, right.Writer);
		});

	cout << "Сортировка книг по авторам завершена!" << endl << endl;
}

void SortBookByPublisher(Book* library, const int librarySize) 
{
	sort(library, library + librarySize,
		[](Book left, Book right)
		{
			return IsComparedStrings(left.Publisher, right.Publisher);
		});

	cout << "Сортировка книг по издательствам завершена!" << endl << endl;
}

void main()
{
	const int LibrarySize = 10;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	Book library[LibrarySize];

	FillLibrary(library);

	int choseMenuItem;

	do
	{
		choseMenuItem = Menu();

		system("pause");
		system("cls");

		switch ((MenuItems)choseMenuItem)
		{

		case MenuItems::EditBook:
			EditingBooks(library, LibrarySize);
			break;

		case MenuItems::PrintAllBooks:
			ShowLibrary(library, LibrarySize);
			break;

		case MenuItems::SearchByWriter:
			SearchBookByWriter(library, LibrarySize);
			break;

		case MenuItems::SearchByName:
			SearchBookByName(library, LibrarySize);
			break;

		case MenuItems::SortByName:
			SortBookByName(library, LibrarySize);
			break;

		case MenuItems::SortByWriter:
			SortBookByWriter(library, LibrarySize);
			break;

		case MenuItems::SortByPublisher:
			SortBookByPublisher(library, LibrarySize);
			break;

		case MenuItems::ExitProgram:
			cout << "Завершение работы программы . . ." << endl << endl;
			system("pause");
			return;

		default:
			break;
		}

		system("pause");
		system("cls");

	} while (true);
}