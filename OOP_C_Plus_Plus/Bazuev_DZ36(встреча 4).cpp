#include <iostream>
#include <Windows.h>
using namespace std;


//			ВСТРЕЧА №4

/*Создайте программу, имитирующую многоквартирный дом. 
Необходимо иметь классы “Человек”, “Квартира”, “Дом”.
Класс “Квартира” содержит динамический массив объектов
класса “Человек”. Класс “Дом” содержит массив объектов
класса “Квартира”. 
Каждый из классов содержит переменные-члены и функции-члены,
которые необходимы для предметной области класса.
Обращаем ваше внимание, что память под строковые значения 
выделяется динамически. Например, для ФИО в классе “Человек”.
Не забывайте обеспечить классы различными конструкторами
(конструктор копирования обязателен), деструкторами.
В main протестировать работу полученного набора классов.*/

class Person
{
	char* fullName;

public:

	Person() : Person(nullptr)
	{
	}

	explicit Person(const char* fullName)
	{
		if (fullName == nullptr)
		{
			this->fullName = nullptr;
			return;
		}

		int sizeFullName = strlen(fullName) + 1;

		this->fullName = new char[sizeFullName];

		strcpy_s(this->fullName, sizeFullName, fullName);
	}

	Person(const Person& other)
	{
		if (other.fullName == nullptr)
		{
			fullName = nullptr;
			return;
		}

		int sizeFullName = strlen(other.fullName) + 1;

		fullName = new char[sizeFullName];

		strcpy_s(fullName, sizeFullName, other.fullName);
	}

	~Person()
	{
		if (fullName != nullptr)
			delete[] fullName;
	}

	const char* GetFullName() const { return fullName; }

	void SetFullName(const char* value)
	{
		if (value == nullptr)
		{
			RemovePerson();
			return;
		}

		int sizeFullName = strlen(value) + 1;
		fullName = new char[sizeFullName];
		strcpy_s(fullName, sizeFullName, value);
	}

	void RemovePerson()
	{
		if (fullName != nullptr)
		{
			delete[] fullName;
			fullName = nullptr;
		}
	}

	void ShowPerson() const
	{
		if (fullName != nullptr)
			cout << "ФИО: " << fullName << endl;
	}
};

class Flat
{
	Person* residents;
	int residentNumbersInFlat;

public:

	Flat() : Flat(nullptr, 0)
	{
	}

	Flat(const Person* residents, const int residentNumbersInFlat)
	{
		this->residentNumbersInFlat = residentNumbersInFlat;

		if (residents == nullptr)
		{
			this->residents = nullptr;
			return;
		}

		this->residents = new Person[residentNumbersInFlat];

		for (int i = 0; i < residentNumbersInFlat; i++)
			this->residents[i] = residents[i];
	}

	Flat(const Flat& other)
	{
		residentNumbersInFlat = other.residentNumbersInFlat;

		if (other.residents == nullptr)
		{
			residents = nullptr;
			return;
		}

		residents = new Person[residentNumbersInFlat];

		for (int i = 0; i < residentNumbersInFlat; i++)
			residents[i] = other.residents[i];

	}

	~Flat()
	{
		if (residents != nullptr)
			delete[] residents;
	}

	const Person* GetResidents() const { return residents; }

	int GetResidentNumbersInFlat() const { return residentNumbersInFlat; }

	void AddResident(const char* newResident)
	{
		int newFlatSize = residentNumbersInFlat + 1;

		Person* newResidentsNumber = new Person[newFlatSize];

		int i = 0;
		for (; i < residentNumbersInFlat; i++)
			newResidentsNumber[i].SetFullName(residents[i].GetFullName());
		newResidentsNumber[i].SetFullName(newResident);

		residentNumbersInFlat = newFlatSize;

		delete[] residents;

		residents = newResidentsNumber;
	}

	int SearchResident(const char* searchedResident) const
	{
		for (int i = 0; i < residentNumbersInFlat; i++)
			if (strcmp(residents[i].GetFullName(), searchedResident) == 0)
				return i;

		return -1;
	}

	void RemoveResident(const char* removedResident)
	{
		if (residentNumbersInFlat == 0)
			return;

		int indexRemovedResident = SearchResident(removedResident);

		if (indexRemovedResident == -1)
			return;

		int newFlatSize = residentNumbersInFlat - 1;

		Person* newResidentsNumber = new Person[newFlatSize];

		int i = 0;
		for (; i < indexRemovedResident; i++)
			newResidentsNumber[i].SetFullName(residents[i].GetFullName());
	
		residents[i].RemovePerson();

		for (; i < newFlatSize; i++)
			newResidentsNumber[i].SetFullName(residents[i + 1].GetFullName());

		residentNumbersInFlat = newFlatSize;

		delete[] residents;

		residents = newResidentsNumber;
	}

	void ClearFlat()
	{
		if (residentNumbersInFlat == 0)
			return;

		for (int i = 0; i < residentNumbersInFlat; i++)
			residents[i].RemovePerson();

		residentNumbersInFlat = 0;

		delete[] residents;

		residents = nullptr;
	}

	void ShowFlat() const
	{
		for (int i = 0; i < residentNumbersInFlat; i++)
			residents[i].ShowPerson();
	}
};

class House
{
	static const int flatNumbersInHouse = 5;
	Flat house[flatNumbersInHouse];

	bool IsIndexCorrect(const bool index) const
	{
		return index >= 0 && index < flatNumbersInHouse;
	}

public:

	House()
	{
		house[0].AddResident("Петров Алексей Игоревич");
		house[0].AddResident("Петрова Анна Викторовна");
		house[0].AddResident("Петров Иван Алексеевич");

		house[1].AddResident("Иванов Василий Григорьевич");
		house[1].AddResident("Иванова Галина Семёнова");

		house[2].AddResident("Васильев Степан Петрович");
		house[2].AddResident("Васильева Валентина Эдуардовна");

		house[3].AddResident("Шишкин Александр Владимирович");

		house[4].AddResident("Волков Марат Романович");
		house[4].AddResident("Волкова Наталья Александровна");
		house[4].AddResident("Волков Константин Маратович");
		house[4].AddResident("Медведева Марина Васильевна");
	}

	House(const House& other)
	{
		for (int i = 0; i < flatNumbersInHouse; i++)
			house[i] = other.house[i];
	}

	void AddResidentByIndex(const int flatIndex, const char* fullName)
	{
		if (IsIndexCorrect(flatIndex))
			house[flatIndex].AddResident(fullName);
	}

	void RemoveResidentByIndex(const int flatIndex, const char* fullName)
	{
		if (house[flatIndex].GetResidentNumbersInFlat() > 0 && IsIndexCorrect(flatIndex))
			house[flatIndex].RemoveResident(fullName);
	}

	void ClearFlatByIndex(const int flatIndex)
	{
		if (house[flatIndex].GetResidentNumbersInFlat() > 0 && IsIndexCorrect(flatIndex))
			house[flatIndex].ClearFlat();
	}

	void ClearHouse()
	{
		for (int i = 0; i < flatNumbersInHouse; i++)
			if (house[i].GetResidentNumbersInFlat() > 0)
				house[i].ClearFlat();
	}

	void ShowHouseResidents()
	{
		cout << "\tСписок жильцов дома:" << endl << endl;

		for (int i = 0; i < flatNumbersInHouse; i++)
		{
			cout << "Квартира №" << i + 1 << ":" << endl;

			if (house[i].GetResidentNumbersInFlat() > 0)
				house[i].ShowFlat();

			cout << endl;
		}
	}
};

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	House house;

	house.ShowHouseResidents();

	/*house.AddResidentByIndex(3, "Ёлкина Эльвира Фёдоровна");
	house.ShowHouseResidents();

	house.RemoveResidentByIndex(3, "Ёлкина Эльвира Фёдоровна");
	house.ShowHouseResidents();

	house.ClearFlatByIndex(2);
	house.ShowHouseResidents();

	house.ClearHouse();
	house.ShowHouseResidents();

	house.AddResidentByIndex(3, "Ёлкина Эльвира Фёдоровна");
	house.ShowHouseResidents();*/

	system("pause");
}