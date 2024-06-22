#include <iostream>
#include <Windows.h>
using namespace std;


//			ВСТРЕЧА №3

/*Разработать класс String, который в дальнейшем будет 
использоваться для работы со строками. Класс должен 
содержать: 
Конструктор по умолчанию, позволяющий создать 
строку длиной 80 символов; 
Конструктор, позволяющий создавать строку произвольного размера; 
Конструктор, который создаёт строку и инициализирует её строкой,
полученной от пользователя. 
Необходимо создать деструктор, а также использовать 
механизмы делегирования конструкторов, если это возможно.
Класс должен содержать методы для ввода строк с клавиатуры и 
вывода строк на экран. Также нужно реализовать 
статическую функцию-член, которая будет возвращать 
количество созданных объектов строк.*/

class String
{
	char* charString;

	static const int defaultSize = 81;
	static const int stringBuffer = 256;

	static inline int objectsCreatedNumber = 0;

public:

	String() : String(defaultSize)
	{	
	}

	explicit String(const int size)
	{
		objectsCreatedNumber++;

		charString = new char[size];

		uninitialized_fill(charString, charString + size - 1, ' ');

		charString[size - 1] = '\0';
	}

	explicit String(const char* charString)
	{
		objectsCreatedNumber++;

		SetCharString(charString);
	}

	String(const String& other)
	{
		objectsCreatedNumber++;

		SetCharString(other.GetCharString());
	}

	~String()
	{
		if (charString != nullptr)
			delete[] charString;
	}

	void SetCharString(const char* newCharString)
	{
		if (newCharString == nullptr)
		{
			charString = nullptr;
			return;
		}

		if (charString != nullptr)
			delete[] charString;

		int size = strlen(newCharString) + 1;

		charString = new char[size];

		strcpy_s(charString, size, newCharString);
	}

	static int GetObjectsCreatedNumber() { return objectsCreatedNumber; }

	const char* GetCharString() const { return charString; }

	int Size() const { return strlen(charString); }

	void Copy(const String& other) { SetCharString(other.GetCharString()); }

	void ShowString() const { cout << charString << endl; }

	void InputString()
	{
		char newString[stringBuffer];

		gets_s(newString, stringBuffer);

		SetCharString(newString);
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	String str1("Qwerty");
	cout << "str1:\t\t";
	str1.ShowString();
	cout << "size str1:\t";
	cout << str1.Size() << endl << endl;

	String str2;
	cout << "str2:\t\t";
	str2.ShowString();
	cout << "size str2:\t";
	cout << str2.Size() << endl << endl;

	String str3;
	str3.Copy(str1);
	cout << "str3:\t\t";
	str3.ShowString();
	cout << "size str3:\t";
	cout << str3.Size() << endl << endl;

	cout << "Введите str2 => ";
	str2.InputString();

	cout << endl;

	cout << "str2:\t\t";
	str2.ShowString();
	cout << "size str2:\t";
	cout << str2.Size() << endl << endl;

	cout << "Создано объектов класса String: ";
	cout << String::GetObjectsCreatedNumber() << endl << endl;

	system("pause");
}