#include <iostream>
#include <string>
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
	int length;
	int width;
	int depth;

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
		const int length,
		const int width,
		const int depth)
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
	int GetLength() const { return length; }
	int GetWidth() const { return width; }
	int GetDepth() const { return depth; }

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

	void SetLength(const int length) { this->length = length; }
	void SetWidth(const int width) { this->width = width; }
	void SetDepth(const int depth) { this->depth = depth; }

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

	int Volume() const
	{
		return length * width * depth;
	}

	int Square() const
	{
		return length * width;
	}

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
			reservoirData += to_string(length) + "м.";
		reservoirData += "\n\r";

		reservoirData += "Ширина:\t\t";
		if (length != 0)
			reservoirData += to_string(width) + "м.";
		reservoirData += "\n\r";

		reservoirData += "Глубина:\t";
		if (length != 0)
			reservoirData += to_string(depth) + "м.";
		reservoirData += "\n\r";

		return reservoirData;
	}
};

class ReservoirDatabase
{
	Reservoir* reservoirs;
	int quantity;

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

	void AddReservoir(const Reservoir& newReservoir)
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

	void RemoveReservoirByIndex(const int index)
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
		cout << "\tСписок водоёмов" << endl << endl;
		for (int i = 0; i < quantity; i++)
			cout << "\tВодоём №" << i + 1 << ":\n\r" << reservoirs[i].ToString() << endl;
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

	UdmReservoirs.AddReservoir(r1);
	UdmReservoirs.AddReservoir(r2);
	UdmReservoirs.AddReservoir(r3);
	UdmReservoirs.AddReservoir(r4);
	UdmReservoirs.AddReservoir(r5);

	UdmReservoirs.ShowReservoirDatabase();

	cout << endl;

	cout << "Площадь Ижевского пруда: " << UdmReservoirs.GetReservoirs()[0].Square() << "м." << endl;
	cout << "Объём Ижевского пруда: " << UdmReservoirs.GetReservoirs()[0].Volume() << "м." << endl;

	if (UdmReservoirs.GetReservoirs()[0].IsTypesMatch(UdmReservoirs.GetReservoirs()[1]))
		cout << "Тип 1 и 2 водоёмов - равны" << endl;
	else
		cout << "Тип 1 и 2 водоёмов - НЕ равны" << endl;

	if (UdmReservoirs.GetReservoirs()[0].IsTypesMatch(UdmReservoirs.GetReservoirs()[2]))
		cout << "Тип 1 и 3 водоёмов - равны" << endl;
	else
		cout << "Тип 1 и 3 водоёмов - НЕ равны" << endl;

	if (UdmReservoirs.GetReservoirs()[0].IsTypesMatch(UdmReservoirs.GetReservoirs()[3]))
		cout << "Тип 1 и 4 водоёмов - равны" << endl;
	else
		cout << "Тип 1 и 4 водоёмов - НЕ равны" << endl;

	if (UdmReservoirs.GetReservoirs()[0].SameTypeSquareComparison(UdmReservoirs.GetReservoirs()[1]))
		cout << "Тип и площадь 1 и 2 водоёмов - равны" << endl;
	else
		cout << "Тип или площадь 1 и 2 водоёмов - НЕ равны" << endl;

	if (UdmReservoirs.GetReservoirs()[0].SameTypeSquareComparison(UdmReservoirs.GetReservoirs()[2]))
		cout << "Тип и площадь 1 и 3 водоёмов - равны" << endl;
	else
		cout << "Тип или площадь 1 и 3 водоёмов - НЕ равны" << endl;

	cout << endl << endl;

	UdmReservoirs.RemoveReservoirByIndex(3);
	UdmReservoirs.ShowReservoirDatabase();

	system("pause");
}