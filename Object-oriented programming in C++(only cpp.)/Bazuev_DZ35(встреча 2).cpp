#define NOMINMAX
#define ESC 27

#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;


//			Встреча №2

/*Создайте приложение "Телефонная книга". Необходимо 
хранить данные об абоненте (ФИО, домашний телефон, 
рабочий телефон, мобильный телефон, дополнительная 
информация о контакте) внутри соответствующего класса.
Наполните класс переменными-членами, функциями-членами,
конструкторами, inline-функциями-членами, 
используйте инициализаторы, реализуйте деструктор. 
Обязательно необходимо выделять динамически память 
под ФИО. Предоставьте пользователю возможность добавлять 
новых абонентов, удалять абонентов, искать абонентов по ФИО,
показывать всех абонентов, сохранять 
информацию в файл и загружать из файла.*/

class Abonent
{
	char* fullName;
	string homePhone;
	string workPhone;
	string mobilePhone;
	string additionalInfo;

public:

	Abonent() : Abonent(nullptr, "", "", "", "")
	{
	}

	Abonent(
		const char* fullName,
		const string homePhone,
		const string workPhone,
		const string mobilePhone) : Abonent(fullName, homePhone, workPhone, mobilePhone, "")
	{
	}

	Abonent(
		const char* fullName,
		const string homePhone,
		const string workPhone,
		const string mobilePhone,
		const string additionalInfo)
	{
		if (fullName != nullptr)
		{
			int sizeFullName = strlen(fullName) + 1;

			this->fullName = new char[sizeFullName];

			strcpy_s(this->fullName, sizeFullName, fullName);
		}
		else
			this->fullName = nullptr;

		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->mobilePhone = mobilePhone;
		this->additionalInfo = additionalInfo;
	}

	Abonent(const Abonent& other)
	{
		if (other.fullName != nullptr)
		{
			int sizeFullName = strlen(other.fullName) + 1;

			fullName = new char[sizeFullName];

			strcpy_s(fullName, sizeFullName, other.fullName);
		}
		else
			this->fullName = nullptr;

		homePhone = other.homePhone;
		workPhone = other.workPhone;
		mobilePhone = other.mobilePhone;
		additionalInfo = other.additionalInfo;
	}

	~Abonent()
	{
		if (fullName != nullptr)
			delete[] fullName;
	}

	char* GetFullName() { return fullName; }
	string GetHomePhone() { return homePhone; }
	string GetWorkPhone() { return workPhone; }
	string GetMobilePhone() { return mobilePhone; }
	string GetAdditionalInfo() { return additionalInfo; }

	void SetFullName(const char* value)
	{
		int sizeFullName = strlen(value) + 1;
		fullName = new char[sizeFullName];
		strcpy_s(fullName, sizeFullName, value);
	}
	void SetHomePhone(const string value) { homePhone = value; }
	void SetWorkPhone(const string value) { workPhone = value; }
	void SetMobilePhone(const string value) { mobilePhone = value; }
	void SetAdditionalInfo(const string value) { additionalInfo = value; }
};

class AbonentDatabase
{
	vector<Abonent> abonentDatabase;

	enum class AbonentDatabaseMenuItems
	{
		show = '1',
		add = '2',
		remove = '3',
		search = '4',
		exit = ESC
	};

	int SelectionAbonentIndex()
	{
		int lastAbonentPosition = abonentDatabase.size();

		int choice;

		do
		{
			cout << "Введите позиционный номер абонента => ";
			cin >> choice;

			if(choice <= 0 || choice > lastAbonentPosition)
				cout << "Ошибка! Повторите ввод." << endl;

		} while (choice <= 0 || choice > lastAbonentPosition);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return choice - 1;
	}

public:

	AbonentDatabase()
	{
		Abonent abonent1("Петров Алексей Игоревич", "562148", "452169", "89765224896", "Директор");
		Abonent abonent2("Иванов Иван Семенович", "563474", "695234", "89216897453", "Бухгалтер");
		Abonent abonent3("Стрелкова Лидия Вадимовна", "563148", "735984", "89712638594", "Уборщик");
		Abonent abonent4("Пупкин Денис Глебович", "568970", "553298", "89326598234");

		abonentDatabase.push_back(abonent1);
		abonentDatabase.push_back(abonent2);
		abonentDatabase.push_back(abonent3);
		abonentDatabase.push_back(abonent4);
	}

	AbonentDatabase(vector<Abonent>& newAbonentDatabase)
	{
		for (int i = 0; i < abonentDatabase.size(); i++)
			newAbonentDatabase.push_back(abonentDatabase.at(i));
	}

	vector<Abonent> GetAbonentDatabase() { return abonentDatabase; }

	void ShowAbonentByIndex(const int index)
	{
		cout << "\tАбонент №" << index + 1 << endl;
		cout << "ФИО:\t\t\t\t" << abonentDatabase.at(index).GetFullName() << endl;
		cout << "Домашний телефон:\t\t" << abonentDatabase.at(index).GetHomePhone() << endl;
		cout << "Рабочий телефон:\t\t" << abonentDatabase.at(index).GetWorkPhone() << endl;
		cout << "Мобильный телефон:\t\t" << abonentDatabase.at(index).GetMobilePhone() << endl;
		cout << "Дополнительная информация:\t" << abonentDatabase.at(index).GetAdditionalInfo() << endl;
	}

	void ShowAbonentDatabase()
	{
		cout << "\t\tТелефонная книга" << endl << endl;

		if (abonentDatabase.size() == 0)
		{
			cout << "Телефонная книга пуста!" << endl;
			return;
		}

		for (int i = 0; i < abonentDatabase.size(); i++)
		{
			cout << "\tАбонент №" << i + 1 << endl;
			cout << "ФИО:\t\t\t\t" << abonentDatabase.at(i).GetFullName() << endl;
			cout << "Домашний телефон:\t\t" << abonentDatabase.at(i).GetHomePhone() << endl;
			cout << "Рабочий телефон:\t\t" << abonentDatabase.at(i).GetWorkPhone() << endl;
			cout << "Мобильный телефон:\t\t" << abonentDatabase.at(i).GetMobilePhone() << endl;
			cout << "Дополнительная информация:\t" << abonentDatabase.at(i).GetAdditionalInfo() << endl << endl;
		}
	}

	void AddAbonent()
	{
		const int buffer = 128;

		cout << "\tДобавление абонента" << endl << endl;

		Abonent newAbonent;

		cout << "ФИО => ";
		char fullName[buffer];
		gets_s(fullName, buffer);
		newAbonent.SetFullName(fullName);

		cout << "Домашний телефон => ";
		string homePhone;
		getline(cin, homePhone);
		newAbonent.SetHomePhone(homePhone);

		cout << "Рабочий телефон => ";
		string workPhone;
		getline(cin, workPhone);
		newAbonent.SetWorkPhone(workPhone);

		cout << "Мобильный телефон => ";
		string mobilePhone;
		getline(cin, mobilePhone);
		newAbonent.SetMobilePhone(mobilePhone);

		cout << "Дополнительная информация => ";
		string additionalInfo;
		getline(cin, additionalInfo);
		newAbonent.SetAdditionalInfo(additionalInfo);

		abonentDatabase.push_back(newAbonent);
	}

	void RemoveAbonent()
	{
		cout << "\tУдаление абонента" << endl << endl;

		if (abonentDatabase.size() == 0)
		{
			cout << "Телефонная книга пуста!" << endl;
			return;
		}

		int removeAbonentIndex = SelectionAbonentIndex();

		for (int i = removeAbonentIndex; i < abonentDatabase.size() - 1; i++)
		{
			abonentDatabase.at(i).SetFullName(abonentDatabase.at(i + 1).GetFullName());
			abonentDatabase.at(i).SetHomePhone(abonentDatabase.at(i + 1).GetHomePhone());
			abonentDatabase.at(i).SetWorkPhone(abonentDatabase.at(i + 1).GetWorkPhone());
			abonentDatabase.at(i).SetMobilePhone(abonentDatabase.at(i + 1).GetMobilePhone());
			abonentDatabase.at(i).SetAdditionalInfo(abonentDatabase.at(i + 1).GetAdditionalInfo());
		}

		abonentDatabase.erase(abonentDatabase.end() - 1);
	}

	int SearchAbonent()
	{
		const int buffer = 128;

		cout << "\tПоиск абонента по ФИО" << endl << endl;

		if (abonentDatabase.size() != 0)
		{
			cout << "ФИО => ";
			char searchFullName[buffer];
			gets_s(searchFullName, buffer);

			cout << endl;

			for (int i = 0; i < abonentDatabase.size(); i++)
				if (strcmp(abonentDatabase.at(i).GetFullName(), searchFullName) == 0)
					return i;
		}

		return -1;
	}

	void AbonentDatabaseMenu()
	{
		AbonentDatabaseMenuItems choice;

		do
		{
			cout << "\tМеню" << endl << endl;
			cout << "1 - Показать телефонную книгу" << endl;
			cout << "2 - Добавить пользователя" << endl;
			cout << "3 - Удалить пользователя" << endl;
			cout << "4 - Найти пользователя по ФИО" << endl << endl;
			cout << "ESC - Выход" << endl << endl;

			cout << "Выберите пункт меню => ";
			choice = (AbonentDatabaseMenuItems)_getch();

			system("cls");

			switch (choice)
			{
			case AbonentDatabaseMenuItems::show:
				ShowAbonentDatabase();
				break;
			
			case AbonentDatabaseMenuItems::add:
				AddAbonent();
				break;
			
			case AbonentDatabaseMenuItems::remove:
				RemoveAbonent();
				break;
			
			case AbonentDatabaseMenuItems::search:
			{
				int searchAbonentIndex = SearchAbonent();
				if (searchAbonentIndex != -1)
					ShowAbonentByIndex(searchAbonentIndex);
				else
					cout << "Абонент отсутствует в телефонной книге или телефонная книга пуста!" << endl;
				break;
			}
			case AbonentDatabaseMenuItems::exit:
				return;

			default:
				system("cls");
				continue;
			}

			cout << endl;
			system("pause");
			system("cls");

		} while (true);
	}
};

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	AbonentDatabase phoneBook;

	phoneBook.AbonentDatabaseMenu();
}