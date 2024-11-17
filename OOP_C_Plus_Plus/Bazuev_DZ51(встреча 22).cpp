#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;


//			ВСТРЕЧА №22 


//			ЗАДАНИЕ №1

/*Добавьте в класс двусвязного списка механизм обработки исключений.
На ваш выбор генерируйте исключения в случае ошибок. Например, 
нехватка памяти, попытка удаления из пустого списка и т.д.*/

//string to_string(const string& str)
//{
//	return str;
//}
//
//template <typename TValue>
//class DoublyLinkedListQueue
//{
//	struct Node
//	{
//		TValue Value;
//		Node* Next;
//		Node* Prev;
//
//		Node(const TValue& value, Node* prev, Node* next)
//		{
//			Value = value;
//			Next = next;
//			Prev = prev;
//		}
//	};
//
//	Node* head;
//	Node* tail;
//	int size;
//
//public:
//	DoublyLinkedListQueue()
//	{
//		head = nullptr;
//		tail = nullptr;
//		size = 0;
//	}
//
//	DoublyLinkedListQueue(const DoublyLinkedListQueue<TValue>& other)
//	{
//		if (other.IsEmpty())
//		{
//			size = 0;
//			head = tail = nullptr;
//			return;
//		}
//
//		size = other.size;
//
//		Node* current = other.head;
//		head = tail = new Node(current->Value, nullptr, nullptr);
//		for (current = current->Next; current != nullptr; current = current->Next)
//			tail = tail->Next = new Node(current->Value, tail, nullptr);
//	}
//
//	DoublyLinkedListQueue(DoublyLinkedListQueue<TValue>&& other)
//	{
//		head = other.head;
//		tail = other.tail;
//		size = other.size;
//
//		other.head = nullptr;
//		other.tail = nullptr;
//		other.size = 0;
//	}
//
//	~DoublyLinkedListQueue()
//	{
//		while (head != nullptr)
//		{
//			const Node* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//
//		tail = nullptr;
//		size = 0;
//	}
//
//	DoublyLinkedListQueue& operator=(const DoublyLinkedListQueue<TValue>& right)
//	{
//		if (this == &right)
//			throw string("objects refer to the same address");
//
//		while (head != nullptr)
//		{
//			const Node* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//
//		size = right.size;
//
//		Node* current = right.head;
//		head = tail = new Node(current->Value, nullptr, nullptr);
//		for (current = current->Next; current != nullptr; current = current->Next)
//			tail = tail->Next = new Node(current->Value, tail, nullptr);
//
//		return *this;
//	}
//
//	DoublyLinkedListQueue& operator=(DoublyLinkedListQueue<TValue>&& right)
//	{
//		if (this == &right)
//			throw string("objects refer to the same address");
//
//		while (head != nullptr)
//		{
//			const Node* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//
//		head = right.head;
//		tail = right.tail;
//		size = right.size;
//
//		right.head = nullptr;
//		right.tail = nullptr;
//		right.size = 0;
//
//		return *this;
//	}
//
//	DoublyLinkedListQueue<TValue> operator+(const DoublyLinkedListQueue<TValue>& right) const
//	{
//		if (right.IsEmpty())
//			return *this;
//
//		if (IsEmpty())
//			return right;
//
//		DoublyLinkedListQueue<TValue> result(*this);
//		DoublyLinkedListQueue<TValue> temp(right);
//
//		for (int i = 0; i < right.size; i++)
//		{
//			result.Push(temp.head->Value);
//			temp.Pop();
//		}
//
//		result.size = size + right.size;
//
//		return result;
//	}
//
//	DoublyLinkedListQueue<TValue> operator*(const DoublyLinkedListQueue<TValue>& right) const
//	{
//		DoublyLinkedListQueue<TValue> result;
//
//		if (IsEmpty() || right.IsEmpty())
//			return result;
//
//		DoublyLinkedListQueue<TValue> tempLeftQueue(*this);
//		DoublyLinkedListQueue<TValue> tempRightQueue(right);
//
//		TValue* arrTempLeft = new TValue[size];
//		TValue* arrTempRight = new TValue[right.size];
//
//		for (int i = 0; i < size; i++)
//		{
//			arrTempLeft[i] = tempLeftQueue.head->Value;
//			tempLeftQueue.Pop();
//		}
//
//		for (int i = 0; i < right.size; i++)
//		{
//			arrTempRight[i] = tempRightQueue.head->Value;
//			tempRightQueue.Pop();
//		}
//
//		for (int i = 0; i < size; i++)
//			for (int j = 0; j < right.size; j++)
//				if (arrTempLeft[i] == arrTempRight[j])
//					result.Push(arrTempLeft[i]);
//
//		delete[] arrTempLeft;
//		delete[] arrTempRight;
//
//		return result;
//	}
//
//	void Clear()
//	{
//		if (IsEmpty())
//			throw string("queue is empty");
//
//		while (head != nullptr)
//		{
//			const Node* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//
//		tail = nullptr;
//		size = 0;
//	}
//
//	void Copy(const DoublyLinkedListQueue<TValue>& other)
//	{
//		if (this == &other)
//			throw string("objects refer to the same address");
//
//		if (other.IsEmpty())
//			throw string("other queue is empty");
//
//		while (head != nullptr)
//		{
//			const Node* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//
//		size = other.size;
//
//		Node* current = other.head;
//		head = tail = new Node(current->Value, nullptr, nullptr);
//		for (current = current->Next; current != nullptr; current = current->Next)
//			tail = tail->Next = new Node(current->Value, tail, nullptr);
//	}
//
//	bool IsEmpty() const
//	{
//		return size == 0;
//	}
//
//	void Pop()
//	{
//		if (IsEmpty())
//			throw string("queue is empty");
//
//		if (size == 1)
//		{
//			Clear();
//			return;
//		}
//
//		head = head->Next;
//		delete head->Prev;
//		head->Prev = nullptr;
//
//		size--;
//	}
//
//	void Push(const TValue& value)
//	{
//		if (IsEmpty())
//			head = tail = new Node(value, nullptr, nullptr);
//		else
//			tail = tail->Next = new Node(value, tail, nullptr);
//
//		size++;
//	}
//
//	int Size() const
//	{
//		return size;
//	}
//
//	void Swap(DoublyLinkedListQueue<TValue>& right)
//	{
//		if (this == &right)
//			throw string("objects refer to the same address");
//
//		DoublyLinkedListQueue<TValue> temp(*this);
//
//		Copy(right);
//		right.Copy(temp);
//	}
//
//	const TValue& Front() const
//	{
//		return head->Value;
//	}
//
//	const TValue& Back() const
//	{
//		return tail->Value;
//	}
//
//	string ToString() const
//	{
//		string result;
//
//		if (!IsEmpty())
//			result += "Queue is NOT empty\n\rSize: " + to_string(size) +
//			"\n\rFront: " + to_string(head->Value) +
//			"\n\rBack: " + to_string(tail->Value) + "\n\r";
//		else
//			result += "Queue is empty\n\rSize: " +
//			to_string(size) + "\n\r";
//
//		return result;
//	}
//};
//
//void ExceptionsTest()
//{
//	DoublyLinkedListQueue <string> queue1;
//	DoublyLinkedListQueue <string>* ptrQueue1 = &queue1;
//	DoublyLinkedListQueue <string> queue2;
//
//	cout << "\tException \"Refer to the same address\" test" << endl << endl;
//
//	try
//	{
//		queue1.Swap(*ptrQueue1);
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	try
//	{
//		queue1.Copy(*ptrQueue1);
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	try
//	{
//		queue1 = *ptrQueue1;
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	try
//	{
//		queue1 = move(*ptrQueue1);
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	cout << endl << "\tException \"Is empty\" test" << endl << endl;
//
//	try
//	{
//		queue1.Clear();		
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	try
//	{		
//		queue1.Pop();
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	try
//	{
//		queue1.Copy(queue2);
//	}
//	catch (const string& message)
//	{
//		cout << "Error: " << message << endl;
//	}
//
//	cout << endl;
//}
//
//void main()
//{
//	ExceptionsTest();
//
//	system("pause");
//}


//			ЗАДАНИЕ №2

/*Создайте иерархию пользовательских классов-исключений. 
В ней должны быть классы для разных ситуаций. 
В качестве предметной области используйте ваши
практические и домашние задания. Например, должны
присутствовать классы для обработки всевозможных
математических ошибок, нехватки памяти, проблемам
по работе с файлами и т.д.*/

//class Exception
//{
//	string message;
//
//public:
//	Exception() : Exception("")
//	{
//	}
//
//	Exception(const string& message)
//	{
//		this->message = message;
//	}
//
//	string GetError() const
//	{
//		return message;
//	}
//};
//
//class DivisionByZero : public Exception
//{
//public:
//	DivisionByZero() : DivisionByZero("")
//	{
//	}
//
//	DivisionByZero(const string& message) : Exception(message)
//	{
//	}
//};
//
//class FileIsNotOpen : public Exception
//{
//public:
//	FileIsNotOpen() : FileIsNotOpen("")
//	{
//	}
//
//	FileIsNotOpen(const string& message) : Exception(message)
//	{
//	}
//};
//
//class IndexOutOfRange : public Exception
//{
//public:
//	IndexOutOfRange() : IndexOutOfRange("")
//	{
//	}
//
//	IndexOutOfRange(const string& message) : Exception(message)
//	{
//	}
//};
//
//class EmptyList : public Exception
//{
//public:
//	EmptyList() : EmptyList("")
//	{
//	}
//
//	EmptyList(const string& message) : Exception(message)
//	{
//	}
//};
//
//class ReferToSameAddress : public Exception
//{
//public:
//	ReferToSameAddress() : ReferToSameAddress("")
//	{
//	}
//
//	ReferToSameAddress(const string& message) : Exception(message)
//	{
//	}
//};
//
//class NegativeValue : public Exception
//{
//public:
//	NegativeValue() : NegativeValue("")
//	{
//	}
//
//	NegativeValue(const string& message) : Exception(message)
//	{
//	}
//};
//
//class MemoryLack : public Exception
//{
//public:
//	MemoryLack() : MemoryLack("")
//	{
//	}
//
//	MemoryLack(const string& message) : Exception(message)
//	{
//	}
//};
//
//void ExceptionsTest()
//{
//	try
//	{
//		int a = 5;
//		int b = 0;
//
//		if (b == 0)
//			throw DivisionByZero("Error: division by zero");
//
//		int c = a / b;
//	}
//	catch (const DivisionByZero& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//
//	try
//	{
//		ifstream file;
//		file.open("Some kind of file.txt");
//
//		if (!file.is_open())
//			throw FileIsNotOpen("Error: file is not open");
//
//		file.close();
//	}
//	catch (const FileIsNotOpen& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//
//	try
//	{
//		const int size = 5;
//		int arr1[size];
//
//		for (int i = 0; i < 15; i++)
//		{
//			if (i < 0 || i >= size)
//				throw IndexOutOfRange("Error: index out of range");
//
//			arr1[i] = 1;
//		}
//	}
//	catch (const IndexOutOfRange& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//
//	try
//	{
//		queue<int> q;
//
//		if (q.empty())
//			throw EmptyList("Error: list is empty");
//	}
//	catch (const EmptyList& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//
//	try
//	{
//		int x = 5;
//		int* ptrX = &x;
//
//		if (&x == ptrX)
//			throw ReferToSameAddress("Error: objects or variables refer to the same address");
//	}
//	catch (const ReferToSameAddress& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//
//	try
//	{
//		int y = -5;
//
//		if (y < 0)
//			throw NegativeValue("Error: negative value");
//	}
//	catch (const NegativeValue& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//
//	try
//	{
//		const int sizeStr1 = 5;
//		char str1[sizeStr1];
//
//		const int sizeStr2 = 7;
//		const char str2[sizeStr2] = "qwerty";
//
//		if (sizeStr1 < sizeStr2)
//			throw MemoryLack("Error: lack of memory");
//
//		strcpy_s(str1, sizeStr1, str2);
//	}
//	catch (const MemoryLack& message)
//	{
//		cout << message.GetError() << endl << endl;
//	}
//}
//
//void main()
//{
//	ExceptionsTest();
//
//	system("pause");
//}