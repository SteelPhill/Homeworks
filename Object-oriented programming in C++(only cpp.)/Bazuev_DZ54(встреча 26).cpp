#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//			ВСТРЕЧА №26

/*Создать класс СПРАВОЧНИК со следующими полями:
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.
Реализовать следующие возможности:
1. Поиск по названию;
2. Поиск по владельцу;
3. Поиск по номеру телефона;
4. Поиск по роду деятельности;
5. Показ всех записей и добавление.
Вся информация, должна сохранятся в файле, должна
быть реализована возможность добавления новых данных.*/

class Company
{
	string companyName;
	string owner;
	string phone;
	string address;
	string activityType;

public:
	Company() : Company("", "", "", "", "")
	{
	}

	Company(
		const string& companyName,
		const string& owner,
		const string& phone,
		const string& address,
		const string& activityType)
	{
		this->companyName = companyName;
		this->owner = owner;
		this->phone = phone;
		this->address = address;
		this->activityType = activityType;
	}

	void SetCompanyName(const string& companyName) { this->companyName = companyName; }
	void SetOwner(const string& owner) { this->owner = owner; }
	void SetPhone(const string& phone) { this->phone = phone; }
	void SetAddress(const string& address) { this->address = address; }
	void SetActivityType(const string& activityType) { this->activityType = activityType; }

	string GetCompanyName() const { return companyName; }
	string GetOwner() const { return owner; }
	string GetPhone() const { return phone; }
	string GetAddress() const { return address; }
	string GetActivityType() const { return activityType; }

	string ToString() const
	{
		return "Company: " + companyName + "\r\n" +
			"Owner: " + owner + "\r\n" +
			"Phone: " + phone + "\r\n" +
			"Address: " + address + "\r\n" +
			"Activity: " + activityType + "\r\n";
	}

	void Show() const
	{
		cout << ToString() << endl;
	}
};

class CompaniesDirectoryFileHandler
{
	string directoryFileName;

public:
	CompaniesDirectoryFileHandler() : CompaniesDirectoryFileHandler("")
	{
	}

	CompaniesDirectoryFileHandler(const string& directoryFileName)
	{
		this->directoryFileName = directoryFileName;
	}

	void SetFileName(const string& directoryFileName)
	{
		this->directoryFileName = directoryFileName;
	}

	string GetFileName() const
	{
		return directoryFileName;
	}

	Company SearchByCompanyName(const string& companyName) const
	{
		const int StringsNumberToSkip = 4;

		ifstream file;
		file.open(directoryFileName);

		if (!file.is_open())
			throw string("file not open!");

		Company result;
		string tempStr;

		while (true)
		{
			file >> tempStr;

			if (file.eof())
				break;

			if (tempStr == "Company:")
			{
				file.get();
				getline(file, tempStr);

				if (tempStr == companyName)
				{
					result.SetCompanyName(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetOwner(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetPhone(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetAddress(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetActivityType(tempStr);

					break;
				}

				for (int i = 1; i <= StringsNumberToSkip; i++)
					getline(file, tempStr);
			}
		}

		file.close();

		return result;
	}

	Company SearchByOwner(const string& owner) const
	{
		const int StringsNumberToSkip = 3;

		ifstream file;
		file.open(directoryFileName);

		if (!file.is_open())
			throw string("file not open!");

		Company result;
		string tempStr;

		while (true)
		{
			file >> tempStr;

			if (file.eof())
				break;

			file.get();
			getline(file, tempStr);
			result.SetCompanyName(tempStr);

			file >> tempStr;

			if (tempStr == "Owner:")
			{
				file.get();
				getline(file, tempStr);

				if (tempStr == owner)
				{
					result.SetOwner(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetPhone(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetAddress(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetActivityType(tempStr);

					break;
				}

				for (int i = 1; i <= StringsNumberToSkip; i++)
					getline(file, tempStr);
			}

			result.SetCompanyName("");
		}

		file.close();

		return result;
	}

	Company SearchByPhone(const string& phone) const
	{
		const int StringsNumberToSkip = 2;

		ifstream file;
		file.open(directoryFileName);

		if (!file.is_open())
			throw string("file not open!");

		Company result;
		string tempStr;

		while (true)
		{
			file >> tempStr;

			if (file.eof())
				break;

			file.get();
			getline(file, tempStr);
			result.SetCompanyName(tempStr);

			file >> tempStr;
			file.get();
			getline(file, tempStr);
			result.SetOwner(tempStr);

			file >> tempStr;

			if (tempStr == "Phone:")
			{
				file.get();
				getline(file, tempStr);

				if (tempStr == phone)
				{
					result.SetPhone(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetAddress(tempStr);

					file >> tempStr;
					file.get();
					getline(file, tempStr);
					result.SetActivityType(tempStr);

					break;
				}

				for (int i = 1; i <= StringsNumberToSkip; i++)
					getline(file, tempStr);
			}

			result.SetCompanyName("");
			result.SetOwner("");
		}

		file.close();

		return result;
	}

	Company SearchByActivityType(const string& activityType) const
	{
		ifstream file;
		file.open(directoryFileName);

		if (!file.is_open())
			throw string("file not open!");

		Company result;
		string tempStr;

		while (true)
		{
			file >> tempStr;

			if (file.eof())
				break;

			file.get();
			getline(file, tempStr);
			result.SetCompanyName(tempStr);

			file >> tempStr;
			file.get();
			getline(file, tempStr);
			result.SetOwner(tempStr);

			file >> tempStr;
			file.get();
			getline(file, tempStr);
			result.SetPhone(tempStr);

			file >> tempStr;
			file.get();
			getline(file, tempStr);
			result.SetAddress(tempStr);

			file >> tempStr;

			if (tempStr == "Activity:")
			{
				file.get();
				getline(file, tempStr);

				if (tempStr == activityType)
				{
					result.SetActivityType(tempStr);
					break;
				}
			}

			result.SetCompanyName("");
			result.SetOwner("");
			result.SetPhone("");
			result.SetAddress("");
		}

		file.close();

		return result;
	}

	void ShowDirectory() const
	{
		ifstream file;
		file.open(directoryFileName);

		if (!file.is_open())
			throw string("file not open!");

		string tempStr;

		while (true)
		{
			file >> tempStr;

			if (file.eof())
				break;

			if (tempStr == "Company:")
			{
				cout << tempStr;
				getline(file, tempStr);
				cout << tempStr << endl;

				getline(file, tempStr);
				cout << tempStr << endl;

				getline(file, tempStr);
				cout << tempStr << endl;

				getline(file, tempStr);
				cout << tempStr << endl;

				getline(file, tempStr);
				cout << tempStr << endl;
			}

			cout << endl;
		}

		file.close();
	}

	void AddCompany(const Company& newCompany) const
	{
		ofstream file;
		file.open(directoryFileName, ios::app);

		if (!file.is_open())
			throw string("file not open!");

		file << "Company: " << newCompany.GetCompanyName() << endl;
		file << "Owner: " << newCompany.GetOwner() << endl;
		file << "Phone: " << newCompany.GetPhone() << endl;
		file << "Address: " << newCompany.GetAddress() << endl;
		file << "Activity: " << newCompany.GetActivityType() << endl;

		file.close();
	}
};

void CreatingInitialFile(const string& directoryFileName)
{
	ofstream file;
	file.open(directoryFileName);

	if (!file.is_open())
		throw string("file not open!");

	file << "Company: Company 1" << endl;
	file << "Owner: Owner 1" << endl;
	file << "Phone: Phone 1" << endl;
	file << "Address: Address 1" << endl;
	file << "Activity: ActivityType 1" << endl;

	file << "Company: Company 2" << endl;
	file << "Owner: Owner 2" << endl;
	file << "Phone: Phone 2" << endl;
	file << "Address: Address 2" << endl;
	file << "Activity: ActivityType 2" << endl;

	file << "Company: Company 3" << endl;
	file << "Owner: Owner 3" << endl;
	file << "Phone: Phone 3" << endl;
	file << "Address: Address 3" << endl;
	file << "Activity: ActivityType 3" << endl;

	file.close();
}

void DirectoryTest(const string& directoryFileName)
{
	CompaniesDirectoryFileHandler directory(directoryFileName);

	cout << "\tDirectory content" << endl << endl;
	directory.ShowDirectory();
	cout << endl;

	cout << "\tAddCompany test" << endl << endl;
	Company newCompany("newCompany", "newOwner", "newPhone", "newAddress", "newActivityType");
	directory.AddCompany(newCompany);
	directory.ShowDirectory();
	cout << endl;

	cout << "\tSearchByCompanyName test" << endl << endl;
	directory.SearchByCompanyName("Company 2").Show();
	cout << endl;

	cout << "\tSearchByOwner test" << endl << endl;
	directory.SearchByOwner("Owner 3").Show();
	cout << endl;

	cout << "\tSearchByPhone test" << endl << endl;
	directory.SearchByPhone("Phone 1").Show();
	cout << endl;

	cout << "\tSearchByActivityType test" << endl << endl;
	directory.SearchByActivityType("newActivityType").Show();
}

void main()
{
	const char* directoryFileName = "directory.txt";

	try
	{
		CreatingInitialFile(directoryFileName);

		DirectoryTest(directoryFileName);
	}
	catch (const string& error)
	{
		cout << "Error: " << error << endl << endl;
	}

	//remove(directoryFileName);

	system("pause");
}