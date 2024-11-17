#include <iostream>
#include <string>
using namespace std;


//			ВСТРЕЧА №19


//			ЗАДАНИЕ №2

/*Используя механизм шаблонного наследования создайте
иерархию классов. Базовый класс под названием base
имеет следующие переменные-члены:
1. T1 value1; // некоторое значение.
2. T2 value2; // некоторое значение.
Потомок под названием child содержит дополнительные
переменные-члены:
1. T3 value3.
2. T4 value4.
Потомок под названием child2 добавляет такие переменные-члены:
1. T5 value5.
2. T6 value6.
Каждый класс имеет необходимый набор конструкторов,
деструкторов, функций-членов для работы со структурой
класса.
В main протестировать работу класса.*/

//string to_string(const string& str)
//{
//	return str;
//}
//
//template<typename TValue1, typename TValue2>
//class Base
//{
//	TValue1 value1;
//	TValue2 value2;
//
//public:
//	Base(const TValue1& value1, const TValue2& value2)
//	{
//		this->value1 = value1;
//		this->value2 = value2;
//	}
//
//	virtual ~Base()
//	{
//	}
//
//	void SetValue1(const const TValue1& value1) { this->value1 = value1; }
//	void SetValue2(const const TValue2& value2) { this->value2 = value2; }
//
//	const TValue1& GetValue1() const { return value1; }
//	const TValue2& GetValue2() const { return value2; }
//
//	string ToString() const
//	{
//		return "class Base(" + to_string(value1) +
//			", " + to_string(value2) + ")";
//	}
//};
//
//template<
//	typename TValue1, typename TValue2,
//	typename TValue3, typename TValue4>
//class Child : public Base<TValue1, TValue2>
//{
//	TValue3 value3;
//	TValue4 value4;
//
//public:
//	Child(
//		const TValue1& value1, const TValue2& value2,
//		const TValue3& value3, const TValue4& value4)
//		: Base<TValue1, TValue2>(value1, value2)
//	{
//		this->value3 = value3;
//		this->value4 = value4;
//	}
//
//	virtual ~Child()
//	{
//	}
//
//	void SetValue3(const const TValue3& value3) { this->value3 = value3; }
//	void SetValue4(const const TValue4& value4) { this->value4 = value4; }
//
//	const TValue3& GetValue3() const { return value3; }
//	const TValue4& GetValue4() const { return value4; }
//
//	string ToString() const 
//	{
//		return "class Child{" + to_string(value3) +
//			", " + to_string(value4) + "}";
//	}
//};
//
//template<
//	typename TValue1, typename TValue2,
//	typename TValue3, typename TValue4, 
//	typename TValue5, typename TValue6>
//class Child2 : public Child<TValue1, TValue2, TValue3, TValue4>
//{
//	TValue5 value5;
//	TValue6 value6;
//
//public:
//	Child2(
//		const TValue1& value1, const TValue2& value2,
//		const TValue3& value3, const TValue4& value4,
//		const TValue5& value5, const TValue6& value6)
//		: Child<TValue1, TValue2, TValue3, TValue4>(value1, value2, value3, value4)
//	{
//		this->value5 = value5;
//		this->value6 = value6;
//	}
//
//	~Child2()
//	{
//	}
//
//	void SetValue5(const const TValue5& value5) { this->value5 = value5; }
//	void SetValue6(const const TValue6& value6) { this->value6 = value6; }
//
//	const TValue5& GetValue5() const { return value5; }
//	const TValue6& GetValue6() const { return value6; }
//
//	string ToString() const 
//	{
//		return "class Child2[" + to_string(value5) +
//			", " + to_string(value6) + "]";
//	}
//};
//
//void main()
//{
//	Child2<int, int, int, int, int, int>* ptrChild2 = new Child2<int, int, int, int, int, int>(1, 2, 3, 4, 5, 6);
//	cout << ptrChild2->ToString() << endl << endl;
//	
//	Child<int, int, int, int>* ptrChild = ptrChild2;
//	cout << ptrChild->ToString() << endl << endl;
//
//	Base<int, int>* ptrBase = ptrChild;
//	cout << ptrBase->ToString() << endl << endl;
//
//	ptrChild = dynamic_cast<Child<int, int, int, int>*>(ptrBase);
//	cout << ptrChild->ToString() << endl << endl;
//
//	ptrChild2 = dynamic_cast<Child2<int, int, int, int, int, int>*>(ptrChild);
//	cout << ptrChild2->ToString() << endl << endl;
//
//	delete ptrChild2;
//
//	system("pause");
//}