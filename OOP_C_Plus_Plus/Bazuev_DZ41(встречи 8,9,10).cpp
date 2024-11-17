#include <iostream>
#include <string>
#include <span>
#include <format>
#include <algorithm>
#include <Windows.h>
using namespace std;


//			ВСТРЕЧА №8 (String) И ВСТРЕЧА №9

/*Добавить в уже существующий класс String
конструктор переноса.*/

/*В ранее созданный класс String добавьте перегрузку [], (), 
преобразования типа к int:
[] — возвращает элемент по указанному индексу;
() — ищет символ в строке, если символ есть возвращает индекс, если нет –1.
Преобразование к int возвращает длину строки.*/

//class String
//{
//	char* charString;
//
//	static const int defaultSize = 81;
//
//	static inline int objectsCreatedNumber = 0;
//
//public:
//	String() : String(defaultSize)
//	{
//	}
//
//	explicit String(const int size)
//	{
//		objectsCreatedNumber++;
//
//		charString = new char[size];
//
//		uninitialized_fill(charString, charString + size - 1, ' ');
//
//		charString[size - 1] = '\0';
//	}
//
//	explicit String(const char* str)
//	{
//		objectsCreatedNumber++;
//
//		SetString(str);
//	}
//
//	String(const String& other)
//	{
//		objectsCreatedNumber++;
//
//		*this = other;
//	}
//
//	String(String&& other)
//	{
//		objectsCreatedNumber++;
//
//		charString = other.charString;
//
//		other.charString = nullptr;
//	}
//
//	~String()
//	{
//		if (charString != nullptr)
//			delete[] charString;
//	}
//
//	void SetString(const char* newCharString)
//	{
//		if (charString != nullptr)
//			delete[] charString;
//
//		if (newCharString == nullptr)
//		{
//			charString = nullptr;
//			return;
//		}
//
//		int size = strlen(newCharString) + 1;
//
//		charString = new char[size];
//
//		strcpy_s(charString, size, newCharString);
//	}
//
//	const char* GetString() const
//	{ 
//		return charString;
//	}
//
//	static int GetObjectsCreatedNumber() 
//	{ 
//		return objectsCreatedNumber;
//	}
//
//	String& operator=(const String& other)
//	{
//		SetString(other.charString);
//
//		return *this;
//	}
//
//	String& operator=(String&& other)
//	{
//		if (this == &other)
//			return *this;
//
//		if (charString != nullptr)
//			delete[] charString;
//
//		charString = other.charString;
//
//		other.charString = nullptr;
//
//		return *this;
//	}
//
//	char operator[](const int index) const
//	{ 
//		if (charString != nullptr)
//			return charString[index];
//
//		return ' ';
//	}
//
//	int operator()(const char symbol) const
//	{
//		if (charString == nullptr)
//			return -1;
//
//		char* temp = strchr(charString, symbol);
//
//		if (temp == nullptr)
//			return -1;
//
//		return strlen(charString) - strlen(temp);
//	}
//
//	operator int() const 
//	{ 
//		if (charString != nullptr)
//			return strlen(charString);
//
//		return 0;
//	}
//
//	int Size() const 
//	{ 
//		return (int)*this;
//	}
//
//	void Copy(const String& other)
//	{ 
//		SetString(other.GetString());
//	}
//
//	string ToString() const
//	{
//		string result = "";
//
//		if (charString != nullptr)
//			result += charString;
//
//		return result;
//	}
//
//	void ShowString() const
//	{ 
//		if (charString != nullptr)
//			cout << charString;
//		cout << endl;
//	}
//
//	void InputString()
//	{
//		const int stringBuffer = 256;
//
//		char newString[stringBuffer];
//
//		gets_s(newString, stringBuffer);
//
//		SetString(newString);
//	}
//};
//
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	String str1("Qwerty");
//	cout << "str1:\t\t" << str1.ToString() << endl;
//
//	cout << endl << "Copy constructor test:" << endl;
//	String str2 = str1;
//	cout << "str2:\t\t" << str2.ToString() << endl;
//	cout << "str1:\t\t" << str1.ToString() << endl;
//
//	cout << endl << "Moving constructor test:" << endl;
//	String str3(move(str2));
//	cout << "str3:\t\t" << str3.ToString() << endl;
//	cout << "str2:\t\t" << str2.ToString() << endl;
//
//	cout << endl << "Operator&&= test:" << endl;
//	str2 = move(str3);
//	cout << "str2:\t\t" << str2.ToString() << endl;
//	cout << "str3:\t\t" << str3.ToString() << endl;
//
//	cout << endl << "Operator[] test:" << endl;
//	cout << "Символ по индексу 2 в str1: " << str1[2] << endl;
//
//	cout << endl << "Operator() test:" << endl;
//	cout << "Символ 'e' в str1 находится по индексу: " << str1('e') << endl;
//
//	cout << endl << "Operator(int) test:" << endl;
//	cout << "Длина str1: " << (int)str1 << endl;
//
//	cout << endl << "Создано объектов класса String: ";
//	cout << String::GetObjectsCreatedNumber() << endl << endl;
//
//	system("pause");
//}


//			ВСТРЕЧА №8 (Array)

/*Добавить в уже существующий класс Array конструктор переноса.*/

//class Array
//{
//	int size;
//	int* arr;
//
//	static void FixSize(int& size)
//	{
//		if (size < 0)
//			size = 0;
//	}
//
//	static int GetRandomValue(const int startRange, const int endRange)
//	{
//		return rand() % (endRange - startRange + 1) + startRange;
//	}
//
//public:
//	Array()
//	{
//		size = 0;
//		arr = nullptr;
//	}
//
//	explicit Array(const int size) : Array(size, 0)
//	{
//	}
//
//	Array(int size, const int value)
//	{
//		FixSize(size);
//
//		this->size = size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			arr[i] = value;
//	}
//
//	Array(int* arr, int size)
//	{
//		FixSize(size);
//
//		this->size = size;
//		this->arr = new int[size];
//		for (int i = 0; i < size; i++)
//			this->arr[i] = arr[i];
//	}
//
//	Array(const Array& other)
//	{
//		size = other.size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			arr[i] = other.arr[i];
//	}
//
//	Array(Array&& other)
//	{
//		size = other.size;
//		arr = other.arr;
//
//		other.size = 0;
//		other.arr = nullptr;
//	}
//
//	~Array()
//	{
//		if (arr != nullptr)
//			delete[] arr;
//	}
//
//	int Size() const
//	{
//		return size;
//	}
//
//	int& At(const int index)
//	{
//		return arr[index];
//	}
//
//	int At(const int index) const
//	{
//		return arr[index];
//	}
//
//	bool IsEmpty() const
//	{
//		return size == 0;
//	}
//
//	void Clear()
//	{
//		size = 0;
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		arr = nullptr;
//	}
//
//	void Resize(int size)
//	{
//		FixSize(size);
//
//		int* newArr = size == 0 ? nullptr : new int[size];
//		int minSize = min(this->size, size);
//		for (int i = 0; i < minSize; i++)
//			newArr[i] = arr[i];
//		for (int i = minSize; i < size; i++)
//			newArr[i] = 0;
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = size;
//		arr = newArr;
//	}
//
//	void Randomize(const int startRange, const int endRange)
//	{
//		if (IsEmpty())
//			return;
//
//		for (int i = 0; i < size; i++)
//			arr[i] = GetRandomValue(startRange, endRange);
//	}
//
//	void Sort(bool desc = false)
//	{
//		if (IsEmpty())
//			return;
//
//		if (desc)
//			sort(arr, arr + size, [](int& a, int& b) { return a > b; });
//		else
//			sort(arr, arr + size, [](int& a, int& b) { return a < b; });
//	}
//
//	void Swap(const int firstIndex, const int secondIndex)
//	{
//		swap(arr[firstIndex], arr[secondIndex]);
//	}
//
//	void Concatenate(const Array& other)
//	{
//		if (other.IsEmpty())
//			return;
//
//		int newSize = size + other.size;
//		int* newArr = new int[newSize];
//		for (int i = 0; i < size; i++)
//			newArr[i] = arr[i];
//		for (int i = 0; i < other.size; i++)
//			newArr[size + i] = other.arr[i];
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = newSize;
//		arr = newArr;
//	}
//
//	void Insert(const int index, const int value)
//	{
//		int newSize = size + 1;
//		int* newArr = new int[newSize];
//		for (int i = 0; i < index; i++)
//			newArr[i] = arr[i];
//		newArr[index] = value;
//		for (int i = index; i < size; i++)
//			newArr[i + 1] = arr[i];
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = newSize;
//		arr = newArr;
//	}
//
//	void InsertFront(const int value)
//	{
//		Insert(0, value);
//	}
//
//	void InsertBack(const int value)
//	{
//		Insert(size, value);
//	}
//
//	void Remove(const int index)
//	{
//		if (size <= 1)
//		{
//			Clear();
//			return;
//		}
//
//		int newSize = size - 1;
//		int* newArr = new int[newSize];
//		for (int i = 0; i < index; i++)
//			newArr[i] = arr[i];
//		for (int i = index; i < newSize; i++)
//			newArr[i] = arr[i + 1];
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		this->size = newSize;
//		arr = newArr;
//	}
//
//	void RemoveFront()
//	{
//		Remove(0);
//	}
//
//	void RemoveBack()
//	{
//		Remove(size - 1);
//	}
//
//	void Replace(const int oldValue, const int newValue)
//	{
//		for (int i = 0; i < size; i++)
//			if (arr[i] == oldValue)
//				arr[i] = newValue;
//	}
//
//	double GetAverage() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int sum = 0;
//		for (int x : span(arr, arr + size))
//			sum += x;
//
//		return (double)sum / size;
//	}
//
//	int GetSum() const
//	{
//		int sum = 0;
//		for (int x : span(arr, arr + size))
//			sum += x;
//
//		return sum;
//	}
//
//	int GetMin() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int min = arr[0];
//		for (int x : span(arr, arr + size))
//			if (x < min)
//				min = x;
//
//		return min;
//	}
//
//	int GetMax() const
//	{
//		if (IsEmpty())
//			return 0;
//
//		int max = arr[0];
//		for (int x : span(arr, arr + size))
//			if (x > max)
//				max = x;
//
//		return max;
//	}
//
//	int Find(const int value) const
//	{
//		for (int i = 0; i < size; i++)
//			if (arr[i] == value)
//				return i;
//
//		return -1;
//	}
//
//	int FindLast(const int value) const
//	{
//		for (int i = size - 1; i >= 0; i--)
//			if (arr[i] == value)
//				return i;
//
//		return -1;
//	}
//
//	Array& operator=(const Array& other)
//	{
//		if (this == &other)
//			return *this;
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		size = other.size;
//		arr = new int[size];
//		for (int i = 0; i < size; i++)
//			arr[i] = other.arr[i];
//
//		return *this;
//	}
//
//	Array& operator=(Array&& other)
//	{
//		if (this == &other)
//			return *this;
//
//		if (arr != nullptr)
//			delete[] arr;
//
//		size = other.size;
//		arr = other.arr;
//
//		other.size = 0;
//		other.arr = nullptr;
//
//		return *this;
//	}
//
//	int& operator[](const int index)
//	{
//		return arr[index];
//	}
//
//	int operator[](const int index) const
//	{
//		return arr[index];
//	}
//
//	Array operator+(const int value) const
//	{
//		Array temp(*this);
//		temp.Resize(temp.Size() + value);
//
//		return temp;
//	}
//
//	friend Array operator+(const int value, const Array& other)
//	{
//		return other + value;
//	}
//
//	Array operator+(const Array& other) const
//	{
//		Array temp(*this);
//		temp.Concatenate(other);
//
//		return temp;
//	}
//
//	string ToString() const
//	{
//		return ToString(", ");
//	}
//
//	string ToString(const string separator) const
//	{
//		if (IsEmpty())
//			return "";
//
//		string str = to_string(arr[0]);
//		for (int x : span(arr + 1, arr + size))
//			str += separator + to_string(x);
//
//		return str;
//	}
//};
//
//void main()
//{
//	int temp[] = { 1, 2, 3, 4 };
//
//	Array arr1(temp, size(temp));
//	cout << "arr1 = [" << arr1.ToString() << "] with size = " << arr1.Size() << endl;
//
//	cout << endl << "Operator&&= test" << endl;
//	Array arr2;
//	arr2 = move(arr1);
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//	cout << "arr1 = [" << arr1.ToString() << "] with size = " << arr1.Size() << endl;
//
//	cout << endl << "Moving constructor test" << endl;
//	Array arr3(move(arr2));
//	cout << "arr3 = [" << arr3.ToString() << "] with size = " << arr3.Size() << endl;
//	cout << "arr2 = [" << arr2.ToString() << "] with size = " << arr2.Size() << endl;
//
//	cout << endl;
//	system("pause");
//}


//			ВСТРЕЧА №10

/*Создайте класс с именем Date для хранения даты (или 
используйте ранее созданный). 
В классе должна быть функция-член, которая увеличивает день на 1.
Напишите соответствующие конструкторы и функции-члены. 
В классе должны быть перегружены операциии ++, --, 
!=, ==, >, <, >>, <<, =, +=, -=, ().
Используйте обычную и дружественную перегрузку.*/

//class TimeSpan
//{
//	static const int MillisecondsInSecond = 1000;
//	static const int SecondsInMinute = 60;
//	static const int MinutesInHour = 60;
//	static const int HoursInDay = 24;
//
//	long long totalMilliseconds;
//
//public:
//	TimeSpan() : TimeSpan(0)
//	{
//	}
//
//	explicit TimeSpan(
//		const long long totalMilliseconds)
//	{
//		this->totalMilliseconds = totalMilliseconds;
//	}
//
//	explicit TimeSpan(
//		const long long hours,
//		const long long minutes,
//		const long long seconds)
//		: TimeSpan(0, hours, minutes, seconds, 0)
//	{
//	}
//
//	explicit TimeSpan(
//		const long long days,
//		const long long hours,
//		const long long minutes,
//		const long long seconds)
//		: TimeSpan(days, hours, minutes, seconds, 0)
//	{
//	}
//
//	explicit TimeSpan(
//		const long long days,
//		const long long hours,
//		const long long minutes,
//		const long long seconds,
//		const long long milliseconds)
//		: TimeSpan(((((long long)days
//			* HoursInDay + hours)
//			* MinutesInHour + minutes)
//			* SecondsInMinute + seconds)
//			* MillisecondsInSecond + milliseconds)
//	{
//	}
//
//	int GetDays() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond
//			/ SecondsInMinute
//			/ MinutesInHour
//			/ HoursInDay;
//	}
//
//	int GetHours() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond
//			/ SecondsInMinute
//			/ MinutesInHour
//			% HoursInDay;
//	}
//
//	long long GetTotalHours() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond
//			/ SecondsInMinute
//			/ MinutesInHour;
//	}
//
//	int GetMinutes() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond
//			/ SecondsInMinute
//			% MinutesInHour;
//	}
//
//	long long GetTotalMinutes() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond
//			/ SecondsInMinute;
//	}
//
//	int GetSeconds() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond
//			% SecondsInMinute;
//	}
//
//	long long GetTotalSeconds() const
//	{
//		return totalMilliseconds
//			/ MillisecondsInSecond;
//	}
//
//	int GetMilliseconds() const
//	{
//		return totalMilliseconds
//			% MillisecondsInSecond;
//	}
//
//	long long GetTotalMilliseconds() const
//	{
//		return totalMilliseconds;
//	}
//
//	TimeSpan operator+(const TimeSpan& right) const
//	{
//		return TimeSpan(totalMilliseconds + right.GetTotalMilliseconds());
//	}
//
//	TimeSpan operator-(const TimeSpan& right) const
//	{
//		return TimeSpan(totalMilliseconds - right.GetTotalMilliseconds());
//	}
//
//	TimeSpan AddDays(const long long days)
//	{
//		totalMilliseconds += days
//			* HoursInDay
//			* MinutesInHour
//			* SecondsInMinute
//			* MillisecondsInSecond;
//
//		return *this;
//	}
//
//	TimeSpan AddHours(const long long hours)
//	{
//		totalMilliseconds += hours
//			* MinutesInHour
//			* SecondsInMinute
//			* MillisecondsInSecond;
//
//		return *this;
//	}
//
//	TimeSpan AddMinutes(const long long minutes)
//	{
//		totalMilliseconds += minutes
//			* SecondsInMinute
//			* MillisecondsInSecond;
//
//		return *this;
//	}
//
//	TimeSpan AddSeconds(const long long seconds)
//	{
//		totalMilliseconds += seconds
//			* MillisecondsInSecond;
//
//		return *this;
//	}
//
//	TimeSpan AddMilliseconds(const long long milliseconds)
//	{
//		totalMilliseconds += milliseconds;
//
//		return *this;
//	}
//
//	string ToString(
//		const bool isOmitDaysIfZero = false,
//		const bool isOmitMillisecondsIfZero = false) const
//	{
//		return ToString(
//			".",
//			":",
//			".",
//			isOmitDaysIfZero,
//			isOmitMillisecondsIfZero);
//	}
//
//	string ToString(
//		const string& daysSeparator,
//		const string& timeSeparator,
//		const string& millisecondsSeparator,
//		const bool isOmitDaysIfZero = false,
//		const bool isOmitMillisecondsIfZero = false) const
//	{
//		return ToString(
//			daysSeparator,
//			timeSeparator,
//			timeSeparator,
//			millisecondsSeparator,
//			isOmitDaysIfZero,
//			isOmitMillisecondsIfZero);
//	}
//
//	string ToString(
//		const string& daysHoursSeparator,
//		const string& hoursMinutesSeparator,
//		const string& minutesSecondsSeparator,
//		const string& secondsMillisecondsSeparator,
//		const bool isOmitDaysIfZero = false,
//		const bool isOmitMillisecondsIfZero = false) const
//	{
//		string result;
//		if (totalMilliseconds < 0)
//			result += "-";
//
//		if (!isOmitDaysIfZero || GetDays() != 0)
//			result += to_string(abs(GetDays())) + daysHoursSeparator;
//
//		result += format("{:02}", abs(GetHours()));
//		result += hoursMinutesSeparator;
//		result += format("{:02}", abs(GetMinutes()));
//		result += minutesSecondsSeparator;
//		result += format("{:02}", abs(GetSeconds()));
//
//		if (!isOmitMillisecondsIfZero || GetMilliseconds() != 0)
//			result += secondsMillisecondsSeparator + format("{:03}", abs(GetMilliseconds()));
//
//		return result;
//	}
//
//	TimeSpan operator=(const TimeSpan& right)
//	{
//		totalMilliseconds = right.GetTotalMilliseconds();
//
//		return *this;
//	}
//
//	TimeSpan operator+=(const TimeSpan& right)
//	{
//		*this = *this + right;
//
//		return *this;
//	}
//
//	TimeSpan operator-=(const TimeSpan& right)
//	{
//		*this = *this - right;
//
//		return *this;
//	}
//
//	TimeSpan& operator++()
//	{
//		totalMilliseconds++;
//
//		return *this;
//	}
//
//	TimeSpan operator++(int)
//	{
//		TimeSpan result(*this);
//
//		++*this;
//
//		return result;
//	}
//
//	TimeSpan& operator--()
//	{
//		totalMilliseconds--;
//
//		return *this;
//	}
//
//	TimeSpan operator--(int)
//	{
//		TimeSpan result(*this);
//
//		--*this;
//
//		return result;
//	}
//
//	TimeSpan operator()(
//		const long long days,
//		const long long hours,
//		const long long minutes,
//		const long long seconds,
//		const long long milliseconds)
//	{
//		this->totalMilliseconds = ((((long long)days * HoursInDay + hours) * 
//			MinutesInHour + minutes) * SecondsInMinute + seconds) * MillisecondsInSecond + milliseconds;
//
//		return *this;
//	}
//
//	bool operator==(const TimeSpan& right) const
//	{
//		return totalMilliseconds == right.GetTotalMilliseconds();
//	}
//
//	bool operator!=(const TimeSpan& right) const
//	{
//		return totalMilliseconds != right.GetTotalMilliseconds();
//	}
//
//	bool operator>(const TimeSpan& right) const
//	{
//		return totalMilliseconds > right.GetTotalMilliseconds();
//	}
//
//	bool operator<(const TimeSpan& right) const
//	{
//		return totalMilliseconds < right.GetTotalMilliseconds();
//	}
//
//	friend ostream& operator<<(ostream& output, const TimeSpan& timeSpan)
//	{
//		return output << timeSpan.ToString();
//	}
//
//	friend istream& operator>>(istream& input, TimeSpan& timeSpan)
//	{
//		int temp;
//
//		input >> temp;
//		timeSpan.totalMilliseconds = temp;
//
//		return input;
//	}
//};
//
//class DateTime
//{
//	static const int MillisecondsInSecond = 1000;
//	static const int SecondsInMinute = 60;
//	static const int MinutesInHour = 60;
//	static const int HoursInDay = 24;
//	inline static const int DaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	static const int MonthsInYear = 12;
//
//	unsigned short year;
//	unsigned char month;
//	unsigned char day;
//	unsigned char hours;
//	unsigned char minutes;
//	unsigned char seconds;
//	unsigned short milliseconds;
//
//	static int GetDaysInMonth(const unsigned short year, const unsigned char month)
//	{
//		int days = DaysInMonth[month - 1];
//		if (month == 2 && IsLeapYear(year))
//			days++;
//
//		return days;
//	}
//
//	static bool IsLeapYear(const unsigned short year)
//	{
//		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
//	}
//
//	static int GetLeapYearsCount(const unsigned short year, const unsigned char month)
//	{
//		int years = year;
//		if (month <= 2)
//			years--;
//
//		return years / 4 - years / 100 + years / 400;
//	}
//
//	long long GetTotalDays() const
//	{
//		long long days = year * 365LLU + day;
//		for (int i = 0; i < month - 1; i++)
//			days += DaysInMonth[i];
//
//		return days + GetLeapYearsCount(year, month);
//	}
//
//	long long GetTotalMillisecondsOfCurrentDay() const
//	{
//		return (((long long)hours *
//			MinutesInHour + minutes)
//			* SecondsInMinute + seconds)
//			* MillisecondsInSecond + milliseconds;
//	}
//
//public:
//	DateTime()
//		: DateTime(1970, 1, 1, 0, 0, 0, 0)
//	{
//	}
//
//	DateTime(
//		const unsigned short year,
//		const unsigned char month,
//		const unsigned char day)
//		: DateTime(year, month, day, 0, 0, 0, 0)
//	{
//	}
//
//	DateTime(
//		const unsigned short year,
//		const unsigned char month,
//		const unsigned char day,
//		const unsigned char hours,
//		const unsigned char minutes,
//		const unsigned char seconds)
//		: DateTime(year, month, day, hours, minutes, seconds, 0)
//	{
//	}
//
//	DateTime(
//		const unsigned short year,
//		const unsigned char month,
//		const unsigned char day,
//		const unsigned char hours,
//		const unsigned char minutes,
//		const unsigned char seconds,
//		const unsigned short milliseconds)
//	{
//		SetYear(year);
//		SetMonth(month);
//		SetDay(day);
//		SetHours(hours);
//		SetMinutes(minutes);
//		SetSeconds(seconds);
//		SetMilliseconds(milliseconds);
//	}
//
//	unsigned short GetYear() const
//	{
//		return year;
//	}
//
//	void SetYear(const unsigned short year)
//	{
//		this->year = year;
//	}
//
//	unsigned char GetMonth() const
//	{
//		return month;
//	}
//
//	void SetMonth(const unsigned char month)
//	{
//		this->month = month;
//
//		if (this->month < 1)
//			this->month = 1;
//
//		if (this->month > MonthsInYear)
//			this->month = MonthsInYear;
//	}
//
//	unsigned char GetDay() const
//	{
//		return day;
//	}
//
//	void SetDay(const unsigned char day)
//	{
//		this->day = day;
//
//		if (this->day < 1)
//			this->day = 1;
//
//		const int daysInMonth = GetDaysInMonth(year, month);
//		if (this->day > daysInMonth)
//			this->day = (unsigned char)daysInMonth;
//	}
//
//	unsigned char GetHours() const
//	{
//		return hours;
//	}
//
//	void SetHours(const unsigned char hours)
//	{
//		this->hours = hours;
//
//		if (this->hours >= HoursInDay)
//			this->hours = HoursInDay - 1;
//	}
//
//	unsigned char GetMinutes() const
//	{
//		return minutes;
//	}
//
//	void SetMinutes(const unsigned char minutes)
//	{
//		this->minutes = minutes;
//
//		if (this->minutes >= MinutesInHour)
//			this->minutes = MinutesInHour - 1;
//	}
//
//	unsigned char GetSeconds() const
//	{
//		return seconds;
//	}
//
//	void SetSeconds(const unsigned char seconds)
//	{
//		this->seconds = seconds;
//
//		if (this->seconds >= SecondsInMinute)
//			this->seconds = SecondsInMinute - 1;
//	}
//
//	unsigned short GetMilliseconds() const
//	{
//		return milliseconds;
//	}
//
//	void SetMilliseconds(const unsigned short milliseconds)
//	{
//		this->milliseconds = milliseconds;
//
//		if (this->milliseconds >= MillisecondsInSecond)
//			this->milliseconds = MillisecondsInSecond - 1;
//	}
//
//	DateTime AddYears(const long long years)
//	{
//		year += years;
//
//		return *this;
//	}
//
//	DateTime IncrementMonth()
//	{
//		month++;
//		if (month > MonthsInYear)
//		{
//			year++;
//			month = 1;
//		}
//
//		return *this;
//	}
//
//	DateTime DecrementMonth()
//	{
//		month--;
//		if (month < 1)
//		{
//			year--;
//			month = MonthsInYear;
//		}
//
//		return *this;
//	}
//
//	DateTime AddMonths(const long long months)
//	{
//		for (int i = 0; i < months; i++)
//			IncrementMonth();
//		for (int i = 0; i > months; i--)
//			DecrementMonth();
//
//		return *this;
//	}
//
//	DateTime IncrementDay()
//	{
//		day++;
//		if (day > GetDaysInMonth(year, month))
//		{
//			IncrementMonth();
//			day = 1;
//		}
//
//		return *this;
//	}
//
//	DateTime DecrementDay()
//	{
//		day--;
//		if (day < 1)
//		{
//			DecrementMonth();
//			day = (unsigned char)GetDaysInMonth(year, month);
//		}
//
//		return *this;
//	}
//
//	DateTime AddDays(const long long days)
//	{
//		for (int i = 0; i < days; i++)
//			IncrementDay();
//		for (int i = 0; i > days; i--)
//			DecrementDay();
//
//		return *this;
//	}
//
//	DateTime AddHours(const long long hours)
//	{
//		long long daysLeft = hours / HoursInDay;
//		int newHours = this->hours + hours % HoursInDay;
//		if (newHours < 0)
//		{
//			daysLeft--;
//			newHours += HoursInDay;
//		}
//		if (newHours >= HoursInDay)
//		{
//			daysLeft++;
//			newHours -= HoursInDay;
//		}
//
//		this->hours = (unsigned char)newHours;
//		AddDays(daysLeft);
//
//		return *this;
//	}
//
//	DateTime AddMinutes(const long long minutes)
//	{
//		long long hoursLeft = minutes / MinutesInHour;
//		int newMinutes = this->minutes + minutes % MinutesInHour;
//		if (newMinutes < 0)
//		{
//			hoursLeft--;
//			newMinutes += MinutesInHour;
//		}
//		if (newMinutes >= MinutesInHour)
//		{
//			hoursLeft++;
//			newMinutes -= MinutesInHour;
//		}
//
//		this->minutes = (unsigned char)newMinutes;
//		AddHours(hoursLeft);
//
//		return *this;
//	}
//
//	DateTime AddSeconds(const long long seconds)
//	{
//		long long minutesLeft = seconds / SecondsInMinute;
//		int newSeconds = this->seconds + seconds % SecondsInMinute;
//		if (newSeconds < 0)
//		{
//			minutesLeft--;
//			newSeconds += SecondsInMinute;
//		}
//		if (newSeconds >= SecondsInMinute)
//		{
//			minutesLeft++;
//			newSeconds -= SecondsInMinute;
//		}
//
//		this->seconds = (unsigned char)newSeconds;
//		AddMinutes(minutesLeft);
//
//		return *this;
//	}
//
//	DateTime AddMilliseconds(const long long milliseconds)
//	{
//		long long secondsLeft = milliseconds / MillisecondsInSecond;
//		int newMilliseconds = this->milliseconds + milliseconds % MillisecondsInSecond;
//		if (newMilliseconds < 0)
//		{
//			secondsLeft--;
//			newMilliseconds += MillisecondsInSecond;
//		}
//		if (newMilliseconds >= MillisecondsInSecond)
//		{
//			secondsLeft++;
//			newMilliseconds -= MillisecondsInSecond;
//		}
//
//		this->milliseconds = (unsigned short)newMilliseconds;
//		AddSeconds(secondsLeft);
//
//		return *this;
//	}
//
//	DateTime operator+(const TimeSpan& right) const
//	{
//		DateTime result(*this);
//		result.AddMilliseconds(right.GetTotalMilliseconds());
//
//		return result;
//	}
//
//	friend DateTime operator+(const TimeSpan& left, const DateTime& right)
//	{
//		return right + left;
//	}
//
//	TimeSpan operator-(const DateTime& right) const
//	{
//		const int daysDifference =
//			GetTotalDays() - right.GetTotalDays();
//
//		const int millisecondsDifference =
//			GetTotalMillisecondsOfCurrentDay() - right.GetTotalMillisecondsOfCurrentDay();
//
//		return TimeSpan(daysDifference, 0, 0, 0, millisecondsDifference);
//	}
//
//	DateTime operator-(const TimeSpan& right) const
//	{
//		DateTime result(*this);
//		result.AddMilliseconds(-right.GetTotalMilliseconds());
//
//		return result;
//	}
//
//	string ToString(const bool isOmitMillisecondsIfZero = false) const
//	{
//		return ToString(
//			".",
//			".",
//			"T",
//			":",
//			":",
//			".",
//			isOmitMillisecondsIfZero);
//	}
//
//	string ToString(
//		const string& yearMonthSeparator,
//		const string& monthDaySeparator,
//		const string& dateTimeSeparator,
//		const string& hoursMinutesSeparator,
//		const string& minutesSecondsSeparator,
//		const string& secondsMillisecondsSeparator,
//		const bool isOmitMillisecondsIfZero = false) const
//	{
//		string result;
//
//		result += to_string(year);
//		result += yearMonthSeparator;
//		result += format("{:02}", month);
//		result += monthDaySeparator;
//		result += format("{:02}", day);
//		result += dateTimeSeparator;
//		result += format("{:02}", hours);
//		result += hoursMinutesSeparator;
//		result += format("{:02}", minutes);
//		result += minutesSecondsSeparator;
//		result += format("{:02}", seconds);
//
//		if (!isOmitMillisecondsIfZero || milliseconds != 0)
//			result += secondsMillisecondsSeparator + format("{:03}", milliseconds);
//
//		return result;
//	}
//
//	DateTime operator=(const DateTime& right)
//	{
//		SetYear(right.year);
//		SetMonth(right.month);
//		SetDay(right.day);
//		SetHours(right.hours);
//		SetMinutes(right.minutes);
//		SetSeconds(right.seconds);
//		SetMilliseconds(right.milliseconds);
//
//		return *this;
//	}
//
//	DateTime operator+=(const TimeSpan& right) 
//	{
//		*this = *this + right;
//
//		return *this;
//	}
//
//	friend DateTime operator+=(const TimeSpan& left, DateTime& right) 
//	{
//		return right += left;
//	}
//
//	DateTime operator-=(const TimeSpan& right) 
//	{
//		*this = *this - right;
//
//		return *this;
//	}
//
//	DateTime& operator++()
//	{
//		IncrementDay();
//
//		return *this;
//	}
//
//	DateTime operator++(int) 
//	{
//		DateTime result(*this);
//
//		++*this;
//
//		return result;
//	}
//
//	DateTime& operator--() 
//	{
//		DecrementDay();
//
//		return *this;
//	}
//
//	DateTime operator--(int) 
//	{
//		DateTime result(*this);
//
//		--*this;
//
//		return result;
//	}
//
//	DateTime operator()(
//		const unsigned short year,
//		const unsigned char month,
//		const unsigned char day,
//		const unsigned char hours,
//		const unsigned char minutes,
//		const unsigned char seconds,
//		const unsigned short milliseconds) 
//	{
//		SetYear(year);
//		SetMonth(month);
//		SetDay(day);
//		SetHours(hours);
//		SetMinutes(minutes);
//		SetSeconds(seconds);
//		SetMilliseconds(milliseconds);
//
//		return *this;
//	}
//
//	bool operator==(const DateTime& right) const 
//	{
//		if (year != right.year)
//			return false;
//		if (month != right.month)
//			return false;
//		if (day != right.day)
//			return false;
//		if (hours != right.hours)
//			return false;
//		if (minutes != right.minutes)
//			return false;
//		if (seconds != right.seconds)
//			return false;
//		if (milliseconds != right.milliseconds)
//			return false;
//
//		return true;
//	}
//
//	bool operator!=(const DateTime& right) const 
//	{
//		if (*this == right)
//			return false;
//
//		return true;
//	}
//
//	bool operator>(const DateTime& right) const 
//	{
//		if (year > right.year)
//			return true;
//		if (month > right.month)
//			return true;
//		if (day > right.day)
//			return true;
//		if (hours > right.hours)
//			return true;
//		if (minutes > right.minutes)
//			return true;
//		if (seconds > right.seconds)
//			return true;
//		if (milliseconds > right.milliseconds)
//			return true;
//
//		return false;
//	}
//
//	bool operator<(const DateTime& right) const 
//	{
//		if (*this > right)
//			return false;
//
//		return true;
//	}
//
//	friend ostream& operator<<(ostream& output, const DateTime& dateTime) 
//	{
//		return output << dateTime.ToString();
//	}
//
//	friend istream& operator>>(istream& input, DateTime& dateTime) 
//	{
//		int temp;
//
//		input >> temp;
//		dateTime.SetYear(temp);
//		input >> temp;
//		dateTime.SetMonth(temp);
//		input >> temp;
//		dateTime.SetDay(temp);
//		input >> temp;
//		dateTime.SetHours(temp);
//		input >> temp;
//		dateTime.SetMinutes(temp);
//		input >> temp;
//		dateTime.SetSeconds(temp);
//		input >> temp;
//		dateTime.SetMilliseconds(temp);
//
//		return input;
//	}
//};
//
//void main()
//{
//	cout << "\tDateTime test" << endl << endl;
//
//	TimeSpan timeSpan1(1, 1, 1, 1, 1);
//
//	DateTime dateTime1(2024, 05, 28, 12, 30, 15, 100);
//	cout << "Operator<< test" << endl;
//	cout << "dateTime1: " << dateTime1 << endl;
//
//	DateTime dateTime2;
//	/*cout << endl << "Operator>> test" << endl;
//	cin >> dateTime2;*/
//	cout << "dateTime2: " << dateTime2 << endl;
//
//	cout << endl << "Operator= test" << endl;
//	dateTime2 = dateTime1;
//	cout << "dateTime2: " << dateTime2 << endl;
//
//	cout << endl << "Operator+= test" << endl;
//	dateTime2 += timeSpan1;
//	cout << "dateTime2: " << dateTime2 << endl;
//
//	cout << endl << "friend Operator+= test" << endl;
//	timeSpan1 += dateTime2;
//	cout << "dateTime2: " << dateTime2 << endl;
//
//	cout << endl << "Operator-= test" << endl;
//	dateTime2 -= timeSpan1;
//	cout << "dateTime2: " << dateTime2 << endl;
//
//	cout << endl << "postfix Operator++ test" << endl;
//	cout << "dateTime2: " << dateTime2++ << endl;
//
//	cout << endl << "prefix Operator++ test" << endl;
//	cout << "dateTime2: " << ++dateTime2 << endl;
//
//	cout << endl << "postfix Operator-- test" << endl;
//	cout << "dateTime2: " << dateTime2-- << endl;
//
//	cout << endl << "prefix Operator-- test" << endl;
//	cout << "dateTime2: " << --dateTime2 << endl;
//
//	cout << endl << "Operator() test" << endl;
//	dateTime2(2024, 05, 28, 10, 30, 15, 100);
//	cout << "dateTime2: " << dateTime2 << endl << endl;
//
//	cout << endl << "dateTime1 and dateTime2 now:" << endl;
//	cout << "dateTime1: " << dateTime1 << endl;
//	cout << "dateTime2: " << dateTime2 << endl;
//
//	cout << endl << "Operator!= test" << endl;
//	cout << "dateTime1 != dateTime2: ";
//	if (dateTime1 != dateTime2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl << "Operator== test" << endl;
//	cout << "dateTime1 == dateTime2: ";
//	if (dateTime1 == dateTime2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl << "Operator> test" << endl;
//	cout << "dateTime1 > dateTime2: ";
//	if (dateTime1 > dateTime2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl << "Operator< test" << endl;
//	cout << "dateTime1 < dateTime2: ";
//	if (dateTime1 < dateTime2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//
//	cout << endl << endl << "\tTimeSpan test" << endl << endl;
//
//	timeSpan1(1, 10, 30, 20, 100);
//	cout << "Operator<< test" << endl;
//	cout << "timeSpan1: " << timeSpan1 << endl;
//
//	TimeSpan timeSpan2;
//	/*cout << endl << "Operator>> test" << endl;
//	cin >> timeSpan2;*/
//	cout << "timeSpan2: " << timeSpan2 << endl;
//
//	cout << endl << "Operator= test" << endl;
//	timeSpan2 = timeSpan1;
//	cout << "timeSpan2: " << timeSpan2 << endl;
//
//	cout << endl << "Operator+= test" << endl;
//	timeSpan2 += timeSpan1;
//	cout << "timeSpan2: " << timeSpan2 << endl;
//
//	cout << endl << "Operator-= test" << endl;
//	timeSpan2 -= timeSpan1;
//	cout << "timeSpan2: " << timeSpan2 << endl;
//
//	cout << endl << "postfix Operator++ test" << endl;
//	cout << "timeSpan2: " << timeSpan2++ << endl;
//
//	cout << endl << "prefix Operator++ test" << endl;
//	cout << "timeSpan2: " << ++timeSpan2 << endl;
//
//	cout << endl << "postfix Operator-- test" << endl;
//	cout << "timeSpan2: " << timeSpan2-- << endl;
//
//	cout << endl << "prefix Operator-- test" << endl;
//	cout << "timeSpan2: " << --timeSpan2 << endl;
//
//	cout << endl << "Operator() test" << endl;
//	timeSpan2(1, 10, 30, 20, 200);
//	cout << "timeSpan2: " << timeSpan2 << endl << endl;
//
//	cout << endl << "timeSpan1 and timeSpan2 now:" << endl;
//	cout << "timeSpan1: " << timeSpan1 << endl;
//	cout << "timeSpan2: " << timeSpan2 << endl;
//
//	cout << endl << "Operator!= test" << endl;
//	cout << "timeSpan1 != timeSpan2: ";
//	if (timeSpan1 != timeSpan2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl << "Operator== test" << endl;
//	cout << "timeSpan1 == timeSpan2: ";
//	if (timeSpan1 == timeSpan2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl << "Operator> test" << endl;
//	cout << "timeSpan1 > timeSpan2: ";
//	if (timeSpan1 > timeSpan2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl << "Operator< test" << endl;
//	cout << "timeSpan1 < timeSpan2: ";
//	if (timeSpan1 < timeSpan2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//
//	cout << endl;
//	system("pause");
//}