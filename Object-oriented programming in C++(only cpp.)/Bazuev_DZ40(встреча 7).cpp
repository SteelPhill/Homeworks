#include <iostream>
#include <format>
using namespace std;


//			ВСТРЕЧА №7


//			ЗАДАЧА №1

/*Создать класс Overcoat (верхняя одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция ==).
2. Операцию присваивания одного объекта в другой 
(операция =).
3. Сравнение по цене двух пальто одного типа (операция >)*/

//class Overcoat
//{
//	string type;
//	double price;
//
//	const string missingType = "";
//
//public:
//
//	Overcoat() : Overcoat(missingType, 0)
//	{
//	}
//
//	explicit Overcoat(const string type) : Overcoat(type, 0)
//	{
//	}
//
//	Overcoat(const string type, const double price)
//	{
//		this->type = type;
//		this->price = price;
//	}
//
//	Overcoat(const Overcoat& other)
//	{
//		type = other.type;
//		price = other.price;
//	}
//
//	string GetType() const { return type; }
//	double GetPrice() const { return price; }
//
//	void SetType(const string type) { this->type = type; }
//	void SetPrice(const double price) { this->price = price; }
//
//	bool IsCorrect() const { return type != missingType && price >= 0; }
//
//	bool operator==(const Overcoat& other) const { return type.compare(other.type) == 0; }
//
//	bool operator>(const Overcoat& other) const { return price > other.price; }
//
//	Overcoat operator=(const Overcoat& other)
//	{
//		type = other.type;
//		price = other.price;
//	}
//
//	void ShowPriceTag() const 
//	{ 
//		if (IsCorrect())
//			cout << format("Тип:  {}\n\rЦена: {:.2f}", type, price) << endl;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Overcoat overcoat1("пальто", 299.99);
//	cout << "overcoat1:" << endl;
//	overcoat1.ShowPriceTag();
//
//	cout << endl;
//
//	Overcoat overcoat2("куртка", 150);
//	cout << "overcoat2:" << endl;
//	overcoat2.ShowPriceTag();
//
//	cout << endl;
//
//	Overcoat overcoat3 = overcoat1;
//	cout << "overcoat3:" << endl;
//	overcoat3.ShowPriceTag();
//
//	cout << endl;
//
//	if (overcoat1 == overcoat2)
//		cout << "overcoat1 == overcoat2" << endl << endl;
//	else
//		cout << "overcoat1 != overcoat2" << endl << endl;
//
//	if (overcoat1 == overcoat3)
//		cout << "overcoat1 == overcoat3" << endl << endl;
//	else
//		cout << "overcoat1 != overcoat3" << endl << endl;
//
//	if (overcoat1 > overcoat2)
//		cout << "overcoat1 > overcoat2" << endl << endl;
//	else
//		cout << "overcoat1 <= overcoat2" << endl << endl;
//
//	if (overcoat1 > overcoat3)
//		cout << "overcoat1 > overcoat3" << endl << endl;
//	else
//		cout << "overcoat1 <= overcoat3" << endl << endl;
//
//	system("pause");
//}


//			ЗАДАЧА №2

/*Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция ==).
2. Операцию присваивания одного объекта в другой 
(операция =).
3. Сравнение двух квартир по цене (операция >).*/

//class Flat
//{
//	double square;
//	double price;
//
//public:
//
//	Flat() : Flat(0, 0)
//	{
//	}
//
//	explicit Flat(const double square) : Flat(square, 0)
//	{
//	}
//
//	Flat(const double square, const double price)
//	{
//		this->square = square;
//		this->price = price;
//	}
//
//	Flat(const Flat& other)
//	{
//		square = other.square;
//		price = other.price;
//	}
//
//	double GetSquare() const { return square; }
//	double GetPrice() const { return price; }
//
//	void SetSquare(const double square) { this->square = square; }
//	void SetPrice(const double price) { this->price = price; }
//
//	bool IsCorrect() const { return square > 0 && price >= 0; }
//
//	bool operator==(const Flat& other) const { return square == other.square; }
//
//	bool operator>(const Flat& other) const { return price > other.price; }
//
//	Flat operator=(const Flat& other)
//	{
//		square = other.square;
//		price = other.price;
//	}
//
//	void ShowPriceTag() const
//	{
//		if (IsCorrect())
//			cout << format("Площадь: {:.2f}\n\rЦена:    {:.2f}", square, price) << endl;
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Flat flat1(60, 299.99);
//	cout << "flat1:" << endl;
//	flat1.ShowPriceTag();
//
//	cout << endl;
//
//	Flat flat2(35.5, 150);
//	cout << "flat2:" << endl;
//	flat2.ShowPriceTag();
//
//	cout << endl;
//
//	Flat flat3 = flat1;
//	cout << "flat3:" << endl;
//	flat3.ShowPriceTag();
//
//	cout << endl;
//
//	if (flat1 == flat2)
//		cout << "flat1 == flat2" << endl << endl;
//	else
//		cout << "flat1 != flat2" << endl << endl;
//
//	if (flat1 == flat3)
//		cout << "flat1 == flat3" << endl << endl;
//	else
//		cout << "flat1 != flat3" << endl << endl;
//
//	if (flat1 > flat2)
//		cout << "flat1 > flat2" << endl << endl;
//	else
//		cout << "flat1 <= flat2" << endl << endl;
//
//	if (flat1 > flat3)
//		cout << "flat1 > flat3" << endl << endl;
//	else
//		cout << "flat1 <= flat3" << endl << endl;
//
//	system("pause");
//}