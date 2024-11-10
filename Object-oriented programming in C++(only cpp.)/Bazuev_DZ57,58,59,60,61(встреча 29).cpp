#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <Windows.h>
using namespace std;


//			ВСТРЕЧА №29

/*Создайте приложение для работы автосалона. 
Необходимо хранить информацию о продаваемых автомобилях
(название, год выпуска, объем двигателя, цену).
Реализуйте интерфейс для добавления данных, удаления данных,
отображения данных, сортировке данных по различным
параметрам, поиску данных по различным параметрам.
При реализации используйте контейнеры, функторы и алгоритмы.*/

class Car
{
	string name;
	int makeYear;
	double engineCapacity;
	double cost;

public:
	Car() : Car("", 0, 0, 0)
	{
	}

	Car(const string& name,
		const int makeYear,
		const double engineCapacity,
		const double cost)
	{
		SetName(name);
		SetMakeYear(makeYear);
		SetEngineCapacity(engineCapacity);
		SetCost(cost);
	}

	string GetName() const { return name; }
	void SetName(const string& name) { this->name = name; }

	int GetMakeYear() const { return makeYear; }
	void SetMakeYear(const int makeYear) { this->makeYear = makeYear; }

	double GetEngineCapacity() const { return engineCapacity; }
	void SetEngineCapacity(const double engineCapacity) { this->engineCapacity = engineCapacity; }

	double GetCost() const { return cost; }
	void SetCost(const double cost) { this->cost = cost; }
};

class ICarDB
{
public:
	virtual int GetSize() = 0;
	virtual void Add(const Car& car) = 0;
	virtual void Delete(const int index) = 0;
	virtual void Swap(const int firstIndex, const int secondIndex) = 0;

	virtual Car operator[](const int index) const = 0;
	virtual Car& operator[](const int index) = 0;
};

class CarDB : public ICarDB
{
	vector<Car> cars;

public:
	int GetSize() override
	{
		return cars.size();
	}

	void Add(const Car& car) override
	{
		cars.push_back(car);
	}

	void Delete(const int index) override
	{
		cars.erase(cars.begin() + index);
	}

	void Swap(const int firstIndex, const int secondIndex) override
	{
		swap(cars[firstIndex], cars[secondIndex]);
	}

	Car operator[](const int index) const override
	{
		return cars[index];
	}

	Car& operator[](const int index) override
	{
		return cars[index];
	}
};

class ICarFinder
{
public:
	virtual vector<Car> FindByName(const string& name) const = 0;
	virtual vector<Car> FindByMakeYear(const int makeYear) const = 0;
	virtual vector<Car> FindByEngineCapacity(const double engineCapacity) const = 0;
	virtual vector<Car> FindByCost(const double cost) const = 0;
};

class CarFinder : public ICarFinder
{
	ICarDB* carDB;

	vector<Car> FindBy(const function<bool(const Car&)>& predicate) const
	{
		vector<Car> result;
		for (int i = 0; i < carDB->GetSize(); i++)
			if (predicate((*carDB)[i]))
				result.push_back((*carDB)[i]);

		return result;
	}

public:
	explicit CarFinder(ICarDB* carDB)
	{
		this->carDB = carDB;
	}

	vector<Car> FindByName(const string& name) const override
	{
		return FindBy([&](const Car& car) { return car.GetName() == name; });
	}

	vector<Car> FindByMakeYear(const int makeYear) const override
	{
		return FindBy([&](const Car& car) { return car.GetMakeYear() == makeYear; });
	}

	vector<Car> FindByEngineCapacity(const double engineCapacity) const override
	{
		return FindBy([&](const Car& car) { return car.GetEngineCapacity() == engineCapacity; });
	}

	vector<Car> FindByCost(const double cost) const override
	{
		return FindBy([&](const Car& car) { return car.GetCost() == cost; });
	}
};

class ICarSorter
{
public:
	virtual void SortByName() = 0;
	virtual void SortByMakeYear() = 0;
	virtual void SortByEngineCapacity() = 0;
	virtual void SortByCost() = 0;
};

class CarSorter : public ICarSorter
{
	ICarDB* carDB;

	/*void SortBy(const function<bool(const Car&, const Car&)>& isSwapNeeded)
	{
		for (int i = 0; i < carDB->GetSize(); i++)
			for (int j = i + 1; j < carDB->GetSize(); j++)
				if (isSwapNeeded((*carDB)[i], (*carDB)[j]))
					carDB->Swap(i, j);
	}*/

	template <typename TValue>
	void SortBy(const function<TValue(const Car&)>& getProperty)
	{
		for (int i = 0; i < carDB->GetSize(); i++)
			for (int j = i + 1; j < carDB->GetSize(); j++)
				if (getProperty((*carDB)[i]) > getProperty((*carDB)[j]))
					carDB->Swap(i, j);
	}

public:
	explicit CarSorter(ICarDB* carDB)
	{
		this->carDB = carDB;
	}

	void SortByName() override
	{
		//SortBy([](const Car& car1, const Car& car2)
		//{
		//	return car1.GetName() > car2.GetName();
		//});
		SortBy<string>([](const Car& car) { return car.GetName(); });
	}

	void SortByMakeYear() override
	{
		//SortBy([](const Car& car1, const Car& car2)
		//{
		//	return car1.GetMakeYear() > car2.GetMakeYear();
		//});
		SortBy<int>([](const Car& car) { return car.GetMakeYear(); });
	}

	void SortByEngineCapacity() override
	{
		//SortBy([](const Car& car1, const Car& car2)
		//{
		//	return car1.GetEngineCapacity() > car2.GetEngineCapacity();
		//});
		SortBy<double>([](const Car& car) { return car.GetEngineCapacity(); });
	}

	void SortByCost() override
	{
		//SortBy([](const Car& car1, const Car& car2)
		//{
		//	return car1.GetCost() > car2.GetCost();
		//});
		SortBy<double>([](const Car& car) { return car.GetCost(); });
	}
};

class ICarWriter
{
public:
	virtual void Write(const Car& car) = 0;
};

class ConsoleCarWriter : public ICarWriter
{
public:
	void Write(const Car& car) override
	{
		cout << "Name: " << car.GetName() << endl;
		cout << "Make year: " << car.GetMakeYear() << endl;
		cout << "Engine capacity: " << car.GetEngineCapacity() << endl;
		cout << "Cost: " << car.GetCost() << endl;
	}
};

class ICarReader
{
public:
	virtual void Read() = 0;
};

class ConsoleCarReader : public ICarReader
{
	ICarDB* carDB;

public:
	explicit ConsoleCarReader(ICarDB* carDB)
	{
		this->carDB = carDB;
	}

	void Read() override
	{
		Car car;
		string temp;
		int makeYear;
		double engineCapacity;
		double cost;

		cout << "Name => ";
		getline(cin, temp);
		car.SetName(temp);
	
		do
		{
			cout << "Make year => ";
			getline(cin, temp);
			try
			{
				makeYear = stoi(temp);
			}
			catch (...)
			{
				continue;
			}
			break;
		} while (true);
		car.SetMakeYear(makeYear);

		do
		{
			cout << "Engine capacity => ";
			getline(cin, temp);
			try
			{
				engineCapacity = stod(temp);
			}
			catch (...)
			{
				continue;
			}
			break;
		} while (true);
		car.SetEngineCapacity(engineCapacity);

		do
		{
			cout << "Cost => ";
			getline(cin, temp);
			try
			{
				cost = stod(temp);
			}
			catch (...)
			{
				continue;
			}
			break;
		} while (true);
		car.SetCost(cost);

		carDB->Add(car);
	}
};

class ICarDealership
{
public:
	virtual void Menu() const = 0;
};

class CarDealership : public ICarDealership
{
	ICarDB* carDB;

	int InputItemNumber(const int beginRange, const int endRange) const
	{
		int result = 0;
		string temp;

		do
		{
			cout << " => ";
			getline(cin, temp);

			try
			{
				result = stoi(temp);
			}
			catch (...)
			{
				continue;
			}

		} while (result < beginRange || result > endRange);

		return result;
	}

	void PrintMenu() const
	{
		cout << "\tMenu:" << endl << endl;
		cout << "1  Add car" << endl;
		cout << "2  Delete car" << endl;
		cout << "3  Print cars" << endl;
		cout << "4  Find car by name" << endl;
		cout << "5  Find car by make year" << endl;
		cout << "6  Find car by engine capacity" << endl;
		cout << "7  Find car by cost" << endl;
		cout << "8  Sort cars by name" << endl;
		cout << "9  Sort cars by make year" << endl;
		cout << "10 Sort cars by engine capacity" << endl;
		cout << "11 Sort cars by cost" << endl;
		cout << "12 Exit" << endl;
	}

public:
	CarDealership()
	{
		carDB = new CarDB();
		carDB->Add(Car("Toyota", 2001, 1.8, 199.99));
		carDB->Add(Car("Ford", 1985, 2.4, 300.0));
		carDB->Add(Car("Audi", 1993, 2.0, 299.99));
	}

	void Menu() const override
	{
		const int FirstMenuItem = 1;
		const int LastMenuItem = 12;

		enum class CarDealershipItems
		{
			AddCar = 1,
			DeleteCar = 2,
			PrintCars = 3,
			FindCarByName = 4,
			FindCarByMakeYear = 5,
			FindCarByEngineCapacity = 6,
			FindCarByCost = 7,
			SortCarsByName = 8,
			SortCarsByMakeYear = 9,
			SortCarsByEngineCapacity = 10,
			SortCarsByCost = 11,
			Exit = 12
		};

		ICarFinder* carFinder = new CarFinder(carDB);
		ICarSorter* carSorter = new CarSorter(carDB);
		ICarWriter* carWriter = new ConsoleCarWriter();
		ICarReader* carReader = new ConsoleCarReader(carDB);
		vector<Car> cars;
		string temp;

		do
		{
			PrintMenu();
			cout << endl << "Select a menu item" << endl;
			CarDealershipItems choice =
				(CarDealershipItems)InputItemNumber(FirstMenuItem, LastMenuItem);

			system("cls");

			switch (choice)
			{
			case CarDealershipItems::AddCar:
			{
				carReader->Read();
				cout << endl;
				system("pause");
				break;
			}
			case CarDealershipItems::DeleteCar:
			{
				cout << "Input the number of the car to be deleted" << endl;
				int selectedNumberCar = InputItemNumber(1, carDB->GetSize());
				carDB->Delete(selectedNumberCar - 1);
				break;
			}
			case CarDealershipItems::PrintCars:
			{
				for (int i = 0; i < carDB->GetSize(); i++)
				{
					cout << "Car №" << i + 1 << ":" << endl;
					carWriter->Write((*carDB)[i]);
					cout << endl;
				}

				system("pause");
				break;
			}
			case CarDealershipItems::FindCarByName:
			{
				cout << "Searched name => ";
				getline(cin, temp);

				cout << endl << "\tSearch result:" << endl << endl;
				cars = carFinder->FindByName(temp);
				for_each(cars.begin(), cars.end(), [&](const Car& car)
					{
						carWriter->Write(car);
						cout << endl;
					});

				cout << endl;
				system("pause");
				break;
			}
			case CarDealershipItems::FindCarByMakeYear:
			{
				cout << "Searched make year => ";
				getline(cin, temp);

				int makeYear;

				try
				{
					makeYear = stoi(temp);
				}
				catch (...)
				{
					break;
				}

				cout << endl << "\tSearch result:" << endl << endl;
				cars = carFinder->FindByMakeYear(makeYear);
				for_each(cars.begin(), cars.end(), [&](const Car& car)
					{
						carWriter->Write(car);
					});

				cout << endl;
				system("pause");
				break;
			}
			case CarDealershipItems::FindCarByEngineCapacity:
			{
				cout << "Searched engine capacity => ";
				getline(cin, temp);

				double engineCapacity;

				try
				{
					engineCapacity = stod(temp);
				}
				catch (...)
				{
					break;
				}

				cout << endl << "\tSearch result:" << endl << endl;
				cars = carFinder->FindByEngineCapacity(engineCapacity);
				for_each(cars.begin(), cars.end(), [&](const Car& car)
					{
						carWriter->Write(car);
					});

				cout << endl;
				system("pause");
				break;
			}
			case CarDealershipItems::FindCarByCost:
			{
				cout << "Searched cost => ";
				getline(cin, temp);

				double cost;

				try
				{
					cost = stod(temp);
				}
				catch (...)
				{
					break;
				}

				cout << endl << "\tSearch result:" << endl << endl;
				cars = carFinder->FindByCost(cost);
				for_each(cars.begin(), cars.end(), [&](const Car& car)
					{
						carWriter->Write(car);
					});

				cout << endl;
				system("pause");
				break;
			}
			case CarDealershipItems::SortCarsByName:
			{
				carSorter->SortByName();
				break;
			}
			case CarDealershipItems::SortCarsByMakeYear:
			{
				carSorter->SortByMakeYear();
				break;
			}
			case CarDealershipItems::SortCarsByEngineCapacity:
			{
				carSorter->SortByEngineCapacity();
				break;
			}
			case CarDealershipItems::SortCarsByCost:
			{
				carSorter->SortByCost();
				break;
			}
			case CarDealershipItems::Exit:
			{
				delete carDB;
				delete carFinder;
				delete carSorter;
				delete carWriter;
				delete carReader;

				return;
			}
			}

			system("cls");

		} while (true);
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ICarDealership* carDealership = new CarDealership();
	carDealership->Menu();
	delete carDealership;
}