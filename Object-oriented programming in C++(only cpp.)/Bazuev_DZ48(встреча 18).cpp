#include <iostream>
#include <string>
#include <vector>
using namespace std;


//			ВСТРЕЧА №18


//			ЗАДАНИЕ №1

/*Создать базовый класс «Домашнее животное» и производные
классы «Собака», «Кошка», «Попугай». С помощью конструктора
установить имя каждого животного и его характеристики.*/

//class Pet
//{
//protected:
//	string nickname;
//
//	Pet(const string& nickname)
//	{
//		this->nickname = nickname;
//	}
//
//public:
//	virtual void Show() const = 0;
//};
//
//class Dog : public Pet
//{
//	string breed;
//
//public:
//	explicit Dog(const string& nickname) : Dog(nickname, "")
//	{
//	}
//
//	Dog(const string& nickname, const string& breed) : Pet(nickname)
//	{
//		this->breed = breed;
//	}
//
//	string GetNickname() const { return nickname; }
//	string GetBreed() const { return breed; }
//
//	void SetNickname(const string& nickname) { this->nickname = nickname; }
//	void SetBreed(const string& breed) { this->breed = breed; }
//
//	void Show() const override
//	{ 
//		cout << "Nickname: " << nickname << endl;
//		cout << "Breed: " << breed << endl;
//	}
//};
//
//class Cat : public Pet
//{
//	double weigth;
//
//public:
//	explicit Cat(const string& nickname) : Cat(nickname, 0)
//	{
//	}
//
//	Cat(const string& nickname, const double weigth) : Pet(nickname)
//	{
//		this->weigth = weigth;
//	}
//
//	string GetNickname() const { return nickname; }
//	double GetWeigth() const { return weigth; }
//
//	void SetNickname(const string& nickname) { this->nickname = nickname; }
//	void SetWeigth(const double weigth) { this->weigth = weigth; }
//
//	void Show() const override
//	{
//		cout << "Nickname: " << nickname << endl;
//		cout << "Weigth: " << weigth << endl;
//	}
//};
//
//class Parrot : public Pet
//{
//	string color;
//
//public:
//	explicit Parrot(const string& nickname) : Parrot(nickname, "")
//	{
//	}
//
//	Parrot(const string& nickname, const string& color) : Pet(nickname)
//	{
//		this->color = color;
//	}
//
//	string GetNickname() const { return nickname; }
//	string GetColor() const { return color; }
//
//	void SetNickname(const string& nickname) { this->nickname = nickname; }
//	void SetColor(const string& color) { this->color = color; }
//
//	void Show() const override
//	{
//		cout << "Nickname: " << nickname << endl;
//		cout << "Color: " << color << endl;
//	}
//};
//
//void main()
//{
//	vector<Pet*> pets;
//	pets.push_back(new Dog("Chappy", "sheepdog"));
//	pets.push_back(new Cat("Snowball", 4.5));
//	pets.push_back(new Parrot("Kesha", "red"));
//
//	cout << "\tDog" << endl;
//	pets.at(0)->Show();
//	cout << "\tCat" << endl;
//	pets.at(1)->Show();
//	cout << "\tParrot" << endl;
//	pets.at(2)->Show();
//	
//	delete pets.at(0);
//	delete pets.at(1);
//	delete pets.at(2);
//
//	cout << endl;
//	system("pause");
//}


//			ЗАДАНИЕ №2

/*Описать базовый класс «Строка».
Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра
C-строку (заканчивается нулевым байтом);
3) конструктор копирования;
4) оператор присваивания;
5) получение длины строки;
6) очистка строки (сделать строку пустой);
7) деструктор;
8) конкатенация строк (перегрузить операторы + и +=);
9) проверка на равенство (==) и на неравенство (!=).
Описать класс «Битовая строка» производный от класса «Строка»
(Строки данного класса могут содержать только символы ‘0’ и ‘1’).
Если в основе инициализирующей строки встретятся любые символы,
отличные от допустимых, то «Битовая строка» становится пустой.
Содержимое строки рассматривается как двоичное представление
целого числа со знаковым разрядом. Отрицательные числа хранятся
в дополнительном коде.
Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра
C-строку;
3) конструктор копирования;
4) оператор присваивания;
4) деструктор;
5) изменение знака числа (перевод числа в дополнительный код);
8) сложение битовых строк (перегрузить операторы + и +=);
9) проверка на равенство (==) и на неравенство (!=).*/

//string to_string(const char* str)
//{
//	return str;
//}
//
//class String
//{
//protected:
//	char* charString;
//
//	explicit String(const int size)
//	{
//		charString = new char[size + 1];
//
//		uninitialized_fill(charString, charString + size, ' ');
//
//		charString[size] = '\0';
//	}
//
//public:
//	String()
//	{
//		charString = nullptr;
//	}
//
//	explicit String(const char* charString)
//	{
//		this->charString = nullptr;
//		SetString(charString);
//	}
//
//	String(const String& other)
//	{
//		charString = nullptr;
//		SetString(other.charString);
//	}
//
//	String(String&& other)
//	{
//		charString = other.charString;
//		other.charString = nullptr;
//	}
//
//	~String()
//	{
//		Clear();
//	}
//
//	virtual void SetString(const char* charString)
//	{
//		Clear();
//
//		if (charString == nullptr)
//			return;
//
//		int size = strlen(charString) + 1;
//
//		this->charString = new char[size];
//
//		strcpy_s(this->charString, size, charString);
//	}
//
//	String& operator=(const String& right)
//	{
//		if (this == &right)
//			return *this;
//
//		SetString(right.charString);
//
//		return *this;
//	}
//
//	String& operator=(String&& right)
//	{
//		if (this == &right)
//			return *this;
//
//		if (!IsEmpty())
//			Clear();
//
//		charString = right.charString;
//		right.charString = nullptr;
//
//		return *this;
//	}
//
//	String operator+(const String& right) const
//	{
//		if (right.IsEmpty())
//			return String(*this);
//
//		if (IsEmpty())
//			return String(right);
//
//		int sizeResult = strlen(charString) + strlen(right.charString);
//
//		String result(sizeResult);
//
//		strcpy_s(result.charString, sizeResult + 1, charString);
//		strcat_s(result.charString, sizeResult + 1, right.charString);
//
//		return result;
//	}
//
//	void operator+=(const String& right) 
//	{
//		*this = *this + right;
//	}
//
//	bool operator==(const String& right) const
//	{
//		if (IsEmpty() && right.IsEmpty())
//			return true;
//		else if (IsEmpty() || right.IsEmpty())
//			return false;
//
//		return strcmp(charString, right.charString) == 0;
//	}
//
//	bool operator!=(const String& right) const
//	{
//		if (IsEmpty() && right.IsEmpty())
//			return false;
//		else if (IsEmpty() || right.IsEmpty())
//			return true;
//
//		return strcmp(charString, right.charString) != 0;
//	}
//
//	void Clear()
//	{
//		if (!IsEmpty())
//			delete[] charString;
//
//		charString = nullptr;
//	}
//
//	bool IsEmpty() const
//	{
//		return charString == nullptr;
//	}
//
//	int Size() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		return strlen(charString);
//	}
//
//	virtual string ToString() const
//	{
//		string result = "";
//
//		if (!IsEmpty())
//			result += to_string(charString);
//
//		return result;
//	}	
//};
//
//class BitString : public String
//{
//	bool IsCorrect(const char* charBitString) const
//	{
//		if (charBitString == nullptr)
//			return true;
//
//		for (int i = 0; charBitString[i] != '\0'; i++)
//			if (charBitString[i] != '0' && charBitString[i] != '1')
//				return false;
//
//		return true;
//	}
//
//	void InvertBitNumber()
//	{
//		for (int i = 0; i < strlen(charString); i++)
//			if (charString[i] == '0')
//				charString[i] = '1';
//			else if (charString[i] == '1')
//				charString[i] = '0';
//	}
//
//	void AddOneToBinaryNumber()
//	{
//		char tempAdditionResult = '1';
//
//		for (int i = strlen(charString) - 1; i >= 0 && tempAdditionResult == '1'; i--)
//			if (tempAdditionResult == '1')
//			{
//				if (charString[i] == '1')
//				{
//					charString[i] = '0';
//				}
//				else if (charString[i] == '0')
//				{
//					charString[i] = '1';
//					tempAdditionResult = '0';
//				}
//			}
//	}
//
//	explicit BitString(const int size) : String(size)
//	{
//	}
//
//public:
//	BitString() : String()
//	{
//	}
//
//	explicit BitString(const char* charBitString)
//	{
//		charString = nullptr;
//
//		if (!IsCorrect(charBitString))
//			return;
//
//		SetString(charBitString);
//	}
//
//	BitString(const BitString& other)
//	{
//		charString = nullptr;
//
//		if (!IsCorrect(other.charString))
//			return;
//
//		SetString(other.charString);
//	}
//
//	BitString(BitString&& other)
//	{
//		if (!IsCorrect(other.charString))
//		{
//			charString = nullptr;
//			other.charString = nullptr;
//			return;
//		}
//
//		charString = other.charString;
//		other.charString = nullptr;
//	}
//
//	~BitString()
//	{
//	}
//
//	void SetString(const char* charString) override
//	{
//		const int DigitsInByte = 8;
//
//		Clear();
//
//		if (charString == nullptr || !IsCorrect(charString))
//			return;
//
//		int additionalZerosNumber = strlen(charString) % DigitsInByte;
//
//		if (additionalZerosNumber != 0)
//			additionalZerosNumber = abs(DigitsInByte - additionalZerosNumber);
//
//		int size = strlen(charString) + additionalZerosNumber + 1;
//
//		this->charString = new char[size];
//
//		int i = 0;
//		for (; i < additionalZerosNumber; i++)
//			this->charString[i] = '0';
//		this->charString[i] = '\0';
//
//		strcat_s(this->charString, size, charString);
//	}
//
//	BitString operator=(const BitString& right)
//	{
//		if (this == &right)
//			return *this;
//
//		if (!IsCorrect(right.charString))
//			return BitString();
//
//		SetString(right.charString);
//
//		return *this;
//	}
//
//	BitString& operator=(BitString&& right)
//	{
//		if (this == &right)
//			return *this;
//
//		if (!IsEmpty())
//			Clear();
//
//		if (!IsCorrect(right.charString))
//		{
//			right.charString = nullptr;
//			return *this;
//		}
//
//		charString = right.charString;
//		right.charString = nullptr;
//
//		return *this;
//	}
//
//	BitString operator+(const BitString& right) const
//	{
//		if (right.IsEmpty() || !IsCorrect(right.charString))
//			return BitString(*this);
//
//		if (IsEmpty() || !IsCorrect(charString))
//			return BitString(right);
//
//		int sizeResult = strlen(charString) + strlen(right.charString);
//
//		BitString result(sizeResult);
//
//		strcpy_s(result.charString, sizeResult + 1, charString);
//		strcat_s(result.charString, sizeResult + 1, right.charString);
//
//		return result;
//	}
//
//	void operator+=(const BitString& right)
//	{
//		*this = *this + right;
//	}
//
//	bool operator==(const BitString& right) const
//	{
//		if (IsEmpty() && right.IsEmpty())
//			return true;
//		else if (IsEmpty() || right.IsEmpty())
//			return false;
//
//		return strcmp(charString, right.charString) == 0;
//	}
//
//	bool operator!=(const BitString& right) const
//	{
//		if (IsEmpty() && right.IsEmpty())
//			return false;
//		else if (IsEmpty() || right.IsEmpty())
//			return true;
//
//		return strcmp(charString, right.charString) != 0;
//	}
//
//	bool IsCorrect() const
//	{
//		if (IsEmpty())
//			return true;
//
//		for (int i = 0; charString[i] != '\0'; i++)
//			if (charString[i] != '0' && charString[i] != '1')
//				return false;
//
//		return true;
//	}
//
//	void ChangeBinaryNumberSign()
//	{
//		if (IsEmpty())
//			return;
//
//		InvertBitNumber();
//		AddOneToBinaryNumber();
//	}
//
//	string ToString() const override
//	{
//		const int DigitsNumberBetweenSpaces = 4;
//
//		if (IsEmpty())
//			return "";
//
//		string result = "";
//
//		result += charString[0];
//
//		for (int i = 1; i < strlen(charString); i++)
//		{
//			if (i % DigitsNumberBetweenSpaces == 0)
//				result += ' ';
//
//			result += charString[i];
//		}
//
//		return result;
//	}
//};
//
//void main()
//{
//	const char OneHundredOnBinary[8] = "1100100";
//
//	BitString wrongBinaryString("0110a11");
//	cout << "WrongBinaryString: " << wrongBinaryString.ToString() << endl << endl;
//
//	cout << endl << "\tOriginal strings" << endl << endl;
//	BitString str1(OneHundredOnBinary);
//	cout << "str1: " << str1.ToString() << endl;
//	BitString str2(str1);
//	cout << "str2: " << str2.ToString() << endl << endl;
//
//	cout << endl << "\tChangeBinaryNumberSign test" << endl << endl;
//	str2.ChangeBinaryNumberSign();
//	cout << "str2: " << str2.ToString() << endl << endl;
//
//	cout << endl << "\tOperator== and Operator!= test" << endl << endl;
//	if (str1 == str2)
//		cout << "str1 == str2" << endl << endl;
//	if (str1 != str2)
//		cout << "str1 != str2" << endl << endl;
//
//	cout << endl << "\tOperator+ test" << endl << endl;
//	BitString result = str1 + str2;
//	cout << "result: " << result.ToString() << endl << endl;
//
//	cout << endl << "\tOperator+= test" << endl << endl;
//	result += str1;
//	cout << "result: " << result.ToString() << endl << endl;
//
//	cout << endl << "\tClear test" << endl << endl;
//	result.Clear();
//	cout << "result: " << result.ToString() << endl << endl;
//
//	system("pause");
//}