#define NOMINMAX
#define ESC 27

#include <iostream>
#include <conio.h>
#include <format>
#include <windows.h>
using namespace std;


//			ВСТРЕЧА №5

/*Разработать класс Reservoir(водоем). Класс должен обязательно иметь поле «название».
Класс должен содержать:
конструктор по умолчанию, конструктор с параметрами,
при необходимости реализовать деструктор и конструктор копирования.
Добавить методы для:
1. Определения приблизительного объема (ширина*длина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному
типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).
Написать интерфейс для работы с классом. Реализовать
динамический массив объектов класса с возможностью
добавления, удаления объектов из массива. Реализовать
возможность записи информации об объектах массива
в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функции-члены
(например, для отображения данных о водоёме и т.д.)*/

class Reservoir
{
	char* name;
	char* type;
	double length;
	double width;
	double depth;

public:

	Reservoir() : Reservoir(nullptr, nullptr, 0, 0, 0)
	{
	}

	explicit Reservoir(const char* name) : Reservoir(name, nullptr, 0, 0, 0)
	{
	}

	Reservoir(const char* name, const char* type) : Reservoir(name, type, 0, 0, 0)
	{
	}

	Reservoir(
		const char* name,
		const char* type,
		const double length,
		const double width,
		const double depth)
	{
		if (name == nullptr)
		{
			this->name = nullptr;
			this->type = nullptr;
			this->length = 0;
			this->width = 0;
			this->depth = 0;

			return;
		}

		int sizeStr;

		sizeStr = strlen(name) + 1;
		this->name = new char[sizeStr];
		strcpy_s(this->name, sizeStr, name);

		if (type != nullptr)
		{
			sizeStr = strlen(type) + 1;
			this->type = new char[sizeStr];
			strcpy_s(this->type, sizeStr, type);
		}
		else
			this->type = nullptr;

		this->length = length;
		this->width = width;
		this->depth = depth;
	}

	Reservoir(const Reservoir& other)
	{
		if (other.name == nullptr)
		{
			name = nullptr;
			type = nullptr;
			length = 0;
			width = 0;
			depth = 0;

			return;
		}

		int sizeStr;

		sizeStr = strlen(other.name) + 1;
		name = new char[sizeStr];
		strcpy_s(name, sizeStr, other.name);

		if (other.type != nullptr)
		{
			sizeStr = strlen(other.type) + 1;
			type = new char[sizeStr];
			strcpy_s(type, sizeStr, other.type);
		}
		else
			type = nullptr;

		length = other.length;
		width = other.width;
		depth = other.depth;
	}

	~Reservoir()
	{
		if (name != nullptr)
			delete[] name;

		if (type != nullptr)
			delete[] type;
	}

	const char* GetName() const { return name; }
	const char* GetType() const { return type; }
	double GetLength() const { return length; }
	double GetWidth() const { return width; }
	double GetDepth() const { return depth; }

	void SetName(const char* name)
	{ 
		if (name == nullptr)
			return;

		if (this->name != nullptr)
			delete[] this->name;

		int sizeStr = strlen(name) + 1;
		this->name = new char[sizeStr];
		strcpy_s(this->name, sizeStr, name);
	}

	void SetType(const char* type) 
	{
		if (type == nullptr)
			return;

		if (this->type != nullptr)
			delete[] this->type;

		int sizeStr = strlen(type) + 1;
		this->type = new char[sizeStr];
		strcpy_s(this->type, sizeStr, type);
	}

	void SetLength(const double length) { this->length = length; }
	void SetWidth(const double width) { this->width = width; }
	void SetDepth(const double depth) { this->depth = depth; }

	void Copy(const Reservoir& other)
	{
		if (other.name == nullptr)
		{
			name = nullptr;
			type = nullptr;
			length = 0;
			width = 0;
			depth = 0;

			return;
		}

		int sizeStr;

		sizeStr = strlen(other.name) + 1;
		name = new char[sizeStr];
		strcpy_s(name, sizeStr, other.name);

		if (other.type != nullptr)
		{
			sizeStr = strlen(other.type) + 1;
			type = new char[sizeStr];
			strcpy_s(type, sizeStr, other.type);
		}
		else
			type = nullptr;

		length = other.length;
		width = other.width;
		depth = other.depth;
	}

	void Remove()
	{
		length = 0;
		width = 0;
		depth = 0;

		if (name != nullptr)
		{
			delete[] name;
			name = nullptr;
		}

		if (type != nullptr)
		{
			delete[] type;
			type = nullptr;
		}
	}

	double Volume() const { return length * width * depth; }

	double Square() const { return length * width; }

	bool IsTypesMatch(const Reservoir& other) const
	{
		if (type != nullptr && other.type != nullptr)
			return strcmp(type, other.type) == 0;

		return false;
	}

	bool SameTypeSquareComparison(Reservoir& other) const
	{
		if (!IsTypesMatch(other))
			return false;

		return Square() == other.Square();
	}

	string ToString() const
	{
		if (name == nullptr)
			return "";

		string reservoirData = "Название:\t";
		if (name != nullptr)
			reservoirData += string(name);
		reservoirData += "\n\r";

		reservoirData += "Тип:\t\t";
		if (type != nullptr)
			reservoirData += string(type);
		reservoirData += "\n\r";

		reservoirData += "Длина:\t\t";
		if (length != 0)
			reservoirData += format("{:.1f}", length) + "м.";
		reservoirData += "\n\r";

		reservoirData += "Ширина:\t\t";
		if (width != 0)
			reservoirData += format("{:.1f}", width) + "м.";
		reservoirData += "\n\r";

		reservoirData += "Глубина:\t";
		if (depth != 0)
			reservoirData += format("{:.1f}", depth) + "м.";
		reservoirData += "\n\r";

		return reservoirData;
	}
};

class ReservoirDatabase
{
	Reservoir* reservoirs;
	int quantity;

	enum class ReservoirDatabaseMenuItems
	{
		show = '1',
		add = '2',
		copy = '3',
		remove = '4',
		calculateVolume = '5',
		calculateSquare = '6',
		typesComparison = '7',
		squareComparison = '8',
		exit = ESC
	};

	int InputPosition() const
	{
		int position;

		do
		{
			cout << "Введите порядковый номер водоёма и нажмите Enter => ";
			cin >> position;

			if (position < 1 || position > quantity)
				cout << "Водоёма под таким порядковым номером нет! Повторите ввод!" << endl << endl;

		} while (position < 1 || position > quantity);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return position;
	}

	bool IsReservoirsEmpty() const { return quantity == 0; }

public:

	ReservoirDatabase() : ReservoirDatabase(nullptr, 0)
	{
	}

	ReservoirDatabase(const Reservoir* reservoirs, const int quantity)
	{
		if (reservoirs == nullptr)
		{
			this->reservoirs = nullptr;
			this->quantity = 0;
			return;
		}

		this->quantity = quantity;

		this->reservoirs = new Reservoir[this->quantity];

		for (int i = 0; i < quantity; i++)
		{
			this->reservoirs[i].SetName(reservoirs[i].GetName());
			this->reservoirs[i].SetType(reservoirs[i].GetType());
			this->reservoirs[i].SetLength(reservoirs[i].GetLength());
			this->reservoirs[i].SetWidth(reservoirs[i].GetWidth());
			this->reservoirs[i].SetDepth(reservoirs[i].GetDepth());
		}
	}

	ReservoirDatabase(const ReservoirDatabase& other)
	{
		if (other.reservoirs == nullptr)
		{
			reservoirs = nullptr;
			quantity = 0;
			return;
		}

		quantity = other.quantity;

		reservoirs = new Reservoir[quantity];

		for (int i = 0; i < quantity; i++)
		{
			reservoirs[i].SetName(other.reservoirs[i].GetName());
			reservoirs[i].SetType(other.reservoirs[i].GetType());
			reservoirs[i].SetLength(other.reservoirs[i].GetLength());
			reservoirs[i].SetWidth(other.reservoirs[i].GetWidth());
			reservoirs[i].SetDepth(other.reservoirs[i].GetDepth());
		}
	}

	~ReservoirDatabase()
	{
		if (reservoirs != nullptr)
			delete[] reservoirs;
	}

	Reservoir* GetReservoirs() const { return reservoirs; }

	int GetQuantity() const { return quantity; }

	void Add(const Reservoir& newReservoir)
	{
		quantity += 1;

		Reservoir* newReservoirs = new Reservoir[quantity];

		for (int i = 0; i < quantity - 1; i++)
		{
			newReservoirs[i].SetName(reservoirs[i].GetName());
			newReservoirs[i].SetType(reservoirs[i].GetType());
			newReservoirs[i].SetLength(reservoirs[i].GetLength());
			newReservoirs[i].SetWidth(reservoirs[i].GetWidth());
			newReservoirs[i].SetDepth(reservoirs[i].GetDepth());
		}

		newReservoirs[quantity - 1].SetName(newReservoir.GetName());
		newReservoirs[quantity - 1].SetType(newReservoir.GetType());
		newReservoirs[quantity - 1].SetLength(newReservoir.GetLength());
		newReservoirs[quantity - 1].SetWidth(newReservoir.GetWidth());
		newReservoirs[quantity - 1].SetDepth(newReservoir.GetDepth());

		delete[] reservoirs;

		reservoirs = newReservoirs;
	}

	void CopyByIndex(const int index)
	{	
		Reservoir copy;

		copy.Copy(reservoirs[index]);

		Add(copy);
	}

	void RemoveByIndex(const int index)
	{
		if (index < 0 || index >= quantity)
			return;

		quantity -= 1;

		Reservoir* newReservoirs = new Reservoir[quantity];

		int i = 0;
		for (; i < index; i++)
		{
			newReservoirs[i].SetName(reservoirs[i].GetName());
			newReservoirs[i].SetType(reservoirs[i].GetType());
			newReservoirs[i].SetLength(reservoirs[i].GetLength());
			newReservoirs[i].SetWidth(reservoirs[i].GetWidth());
			newReservoirs[i].SetDepth(reservoirs[i].GetDepth());
		}

		reservoirs[i].Remove();

		for (; i < quantity; i++)
		{
			newReservoirs[i].SetName(reservoirs[i + 1].GetName());
			newReservoirs[i].SetType(reservoirs[i + 1].GetType());
			newReservoirs[i].SetLength(reservoirs[i + 1].GetLength());
			newReservoirs[i].SetWidth(reservoirs[i + 1].GetWidth());
			newReservoirs[i].SetDepth(reservoirs[i + 1].GetDepth());
		}

		delete[] reservoirs;

		reservoirs = newReservoirs;
	}

	void ShowReservoirDatabase() const
	{
		for (int i = 0; i < quantity; i++)
			cout << "\tВодоём №" << i + 1 << ":\n\r" << reservoirs[i].ToString() << endl;
	}

	void ReservoirDatabaseMenu()
	{
		ReservoirDatabaseMenuItems choice;

		do
		{
			cout << "\tМеню" << endl << endl;
			cout << "1 - Показать все водоёмы" << endl;
			cout << "2 - Добавить водоём" << endl;
			cout << "3 - Скопировать водоём" << endl;
			cout << "4 - Удалить водоём" << endl;
			cout << "5 - Узнать объём водоёма" << endl;
			cout << "6 - Узнать площадь водоёма" << endl;
			cout << "7 - Сравнить типы водоёмов" << endl;
			cout << "8 - Сравнить площади однотипных водоёмов" << endl << endl;
			cout << "ESC - Выход" << endl << endl;

			cout << "Выберите пункт меню => ";
			choice = (ReservoirDatabaseMenuItems)_getch();

			system("cls");

			switch (choice)
			{
			case ReservoirDatabaseMenuItems::show:
			{
				cout << "\tСписок водоёмов" << endl << endl;

				if (IsReservoirsEmpty())
					cout << "Список водоёмов пуст!" << endl;
				else
					ShowReservoirDatabase();

				break;
			}
			case ReservoirDatabaseMenuItems::add:
			{
				cout << "\tДобавление водоёма" << endl << endl;

				Add(InputNewReservoir());
				break;
			}
			case ReservoirDatabaseMenuItems::copy:
			{
				cout << "\tСоздание копии водоёма" << endl << endl;

				if (IsReservoirsEmpty())
					cout << "Список водоёмов пуст!" << endl;
				else
					CopyByIndex(InputPosition() - 1);

				break;
			}
			case ReservoirDatabaseMenuItems::remove:
			{
				cout << "\tУдаление водоёма" << endl << endl;

				if (IsReservoirsEmpty())
					cout << "Список водоёмов пуст!" << endl;
				else
					RemoveByIndex(InputPosition() - 1);

				break;
			}
			case ReservoirDatabaseMenuItems::calculateVolume:
			{
				cout << "\tРасчёт объёма водоёма" << endl << endl;

				if (IsReservoirsEmpty())
				{
					cout << "Список водоёмов пуст!" << endl;
					break;
				}

				int index = InputPosition() - 1;
				cout << endl;

				cout << format("Объём водоёма \"{}\": {:.2f}л.", reservoirs[index].GetName(), reservoirs[index].Volume()) << endl;

				break;
			}
			case ReservoirDatabaseMenuItems::calculateSquare:
			{
				cout << "\tРасчёт площади водоёма" << endl << endl;

				if (IsReservoirsEmpty())
				{
					cout << "Список водоёмов пуст!" << endl;
					break;
				}

				int index = InputPosition() - 1;
				cout << endl;

				cout << format("Площадь водоёма \"{}\": {:.2f}кв.м.", reservoirs[index].GetName(), reservoirs[index].Square()) << endl;

				break;
			}
			case ReservoirDatabaseMenuItems::typesComparison:
			{
				cout << "\tСравнение типов водоёмов" << endl << endl;

				if (quantity < 2)
				{
					cout << "В списке недостаточно водоёмов для сравнения!" << endl;
					break;
				}

				cout << "Первый водоём:" << endl;
				int index1 = InputPosition() - 1;
				cout << endl;

				cout << "Второй водоём:" << endl;
				int index2 = InputPosition() - 1;
				cout << endl;

				cout << format("Типы водоёмов \"{}\" и \"{}\"", reservoirs[index1].GetName(), reservoirs[index2].GetName());

				if (reservoirs[index1].IsTypesMatch(reservoirs[index2]))
					cout << " совпадают" << endl;
				else
					cout << " отличаются" << endl;

				break;
			}
			case ReservoirDatabaseMenuItems::squareComparison:
			{
				cout << "\tСравнение площади и типов водоёмов" << endl << endl;

				if (quantity < 2)
				{
					cout << "В списке недостаточно водоёмов для сравнения!" << endl;
					break;
				}

				cout << "Первый водоём:" << endl;
				int index1 = InputPosition() - 1;
				cout << endl;

				cout << "Второй водоём:" << endl;
				int index2 = InputPosition() - 1;
				cout << endl;

				if (reservoirs[index1].SameTypeSquareComparison(reservoirs[index2]))
					cout << format("Тип и площадь водоёмов \"{}\" и \"{}\" совпадают", reservoirs[index1].GetName(), reservoirs[index2].GetName());
				else
					cout << format("Тип и/или площадь водоёмов \"{}\" и \"{}\" отличаются", reservoirs[index1].GetName(), reservoirs[index2].GetName());

				cout << endl;

				break;
			}
			case ReservoirDatabaseMenuItems::exit:
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

	static Reservoir InputNewReservoir()
	{
		const int buffer = 128;

		Reservoir newReservoir;

		char strTemp[buffer];

		cout << "Название => ";
		gets_s(strTemp, buffer);
		newReservoir.SetName(strTemp);

		cout << "Тип => ";
		gets_s(strTemp, buffer);
		newReservoir.SetType(strTemp);

		double doubleTemp;

		cout << "Длина => ";
		cin >> doubleTemp;
		newReservoir.SetLength(doubleTemp);

		cout << "Ширина => ";
		cin >> doubleTemp;
		newReservoir.SetWidth(doubleTemp);

		cout << "Глубина => ";
		cin >> doubleTemp;
		newReservoir.SetDepth(doubleTemp);

		return newReservoir;
	}
};

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Reservoir r1("Ижевский пруд", "пруд", 12500, 2500, 3);
	Reservoir r2(r1);
	Reservoir r3("Воткинский пруд", "пруд", 13000, 2000, 4);
	Reservoir r4("Дикое", "озеро", 1000, 100, 7);
	Reservoir r5("Карлутка", "река", 12400, 3, 1);

	ReservoirDatabase UdmReservoirs;

	UdmReservoirs.Add(r1);
	UdmReservoirs.Add(r2);
	UdmReservoirs.Add(r3);
	UdmReservoirs.Add(r4);
	UdmReservoirs.Add(r5);

	UdmReservoirs.ReservoirDatabaseMenu();
}