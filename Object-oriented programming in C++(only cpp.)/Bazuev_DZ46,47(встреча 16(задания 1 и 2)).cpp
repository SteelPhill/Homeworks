#include <iostream>
#include <string>
using namespace std;


//			ВСТРЕЧА №16 (ЗАДАНИЯ №1 И №2)

/*Реализовать шаблонный класс "Очередь" на основе двусвязного списка.*/

/*В существующий класс двусвязного списка добавить:
операцию клонирования списка (функция должна возвращать
адрес головы клонированного списка), перегрузить
оператор + (оператор должен возвращать адрес головы
нового списка, содержащего элементы обоих списков для
которых вызывался оператор), перегрузить оператор *
(оператор должен возвращать адрес головы нового списка,
содержащего только общие элементы обоих списков для
которых вызывался оператор).*/

string to_string(const string& str)
{
	return str;
}

template <typename TValue>
class DoublyLinkedListQueue
{
	struct Node
	{
		TValue Value;
		Node* Next;
		Node* Prev;

		Node(const TValue& value, Node* prev, Node* next)
		{
			Value = value;
			Next = next;
			Prev = prev;
		}
	};

	Node* head;
	Node* tail;
	int size;

public:
	DoublyLinkedListQueue()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	DoublyLinkedListQueue(const DoublyLinkedListQueue<TValue>& other)
	{
		if (other.IsEmpty())
		{
			size = 0;
			head = tail = nullptr;
			return;
		}

		size = other.size;

		Node* current = other.head;
		head = tail = new Node(current->Value, nullptr, nullptr);
		for (current = current->Next; current != nullptr; current = current->Next)
			tail = tail->Next = new Node(current->Value, tail, nullptr);
	}

	DoublyLinkedListQueue(DoublyLinkedListQueue<TValue>&& other)
	{
		head = other.head;
		tail = other.tail;
		size = other.size;

		other.head = nullptr;
		other.tail = nullptr;
		other.size = 0;
	}

	~DoublyLinkedListQueue()
	{
		Clear();
	}

	DoublyLinkedListQueue& operator=(const DoublyLinkedListQueue<TValue>& right)
	{
		if (this == &right)
			return *this;

		Clear();

		size = right.size;

		Node* current = right.head;
		head = tail = new Node(current->Value, nullptr, nullptr);
		for (current = current->Next; current != nullptr; current = current->Next)
			tail = tail->Next = new Node(current->Value, tail, nullptr);

		return *this;
	}

	DoublyLinkedListQueue& operator=(DoublyLinkedListQueue<TValue>&& right)
	{
		if (this == &right)
			return *this;

		Clear();

		head = right.head;
		tail = right.tail;
		size = right.size;

		right.head = nullptr;
		right.tail = nullptr;
		right.size = 0;

		return *this;
	}

	DoublyLinkedListQueue<TValue> operator+(const DoublyLinkedListQueue<TValue>& right) const
	{
		if (right.IsEmpty())
			return *this;

		if (IsEmpty())
			return right;

		DoublyLinkedListQueue<TValue> result(*this);
		DoublyLinkedListQueue<TValue> temp(right);

		for (int i = 0; i < right.size; i++)
		{
			result.Push(temp.head->Value);
			temp.Pop();
		}

		result.size = size + right.size;

		return result;
	}

	DoublyLinkedListQueue<TValue> operator*(const DoublyLinkedListQueue<TValue>& right) const
	{
		DoublyLinkedListQueue<TValue> result;

		if (IsEmpty() || right.IsEmpty())
			return result;

		DoublyLinkedListQueue<TValue> tempLeftQueue(*this);
		DoublyLinkedListQueue<TValue> tempRightQueue(right);

		TValue* arrTempLeft = new TValue[size];
		TValue* arrTempRight = new TValue[right.size];

		for (int i = 0; i < size; i++)
		{
			arrTempLeft[i] = tempLeftQueue.head->Value;
			tempLeftQueue.Pop();
		}

		for (int i = 0; i < right.size; i++)
		{
			arrTempRight[i] = tempRightQueue.head->Value;
			tempRightQueue.Pop();
		}

		for (int i = 0; i < size; i++)
			for (int j = 0; j < right.size; j++)
				if (arrTempLeft[i] == arrTempRight[j])
					result.Push(arrTempLeft[i]);

		delete[] arrTempLeft;
		delete[] arrTempRight;

		return result;
	}

	void Clear()
	{
		while (head != nullptr)
		{
			const Node* forDelete = head;
			head = head->Next;
			delete forDelete;
		}

		tail = nullptr;
		size = 0;
	}

	void Copy(const DoublyLinkedListQueue<TValue>& other)
	{
		if (this == &other)
			return;

		Clear();

		if (other.IsEmpty())
			return;

		size = other.size;

		Node* current = other.head;
		head = tail = new Node(current->Value, nullptr, nullptr);
		for (current = current->Next; current != nullptr; current = current->Next)
			tail = tail->Next = new Node(current->Value, tail, nullptr);
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Pop()
	{
		if (size <= 1)
		{
			Clear();
			return;
		}

		head = head->Next;
		delete head->Prev;
		head->Prev = nullptr;

		size--;
	}

	void Push(const TValue& value)
	{
		if (IsEmpty())
			head = tail = new Node(value, nullptr, nullptr);
		else
			tail = tail->Next = new Node(value, tail, nullptr);

		size++;
	}

	int Size() const
	{
		return size;
	}

	void Swap(DoublyLinkedListQueue<TValue>& right)
	{
		DoublyLinkedListQueue<TValue> temp(*this);

		Copy(right);
		right.Copy(temp);
	}

	const TValue& Front() const
	{
		return head->Value;
	}

	const TValue& Back() const
	{
		return tail->Value;
	}

	string ToString() const
	{
		string result;

		if (!IsEmpty())
			result += "Queue is NOT empty\n\rSize: " + to_string(size) +
			"\n\rFront: " + to_string(head->Value) +
			"\n\rBack: " + to_string(tail->Value) + "\n\r";
		else
			result += "Queue is empty\n\rSize: " +
			to_string(size) + "\n\r";

		return result;
	}
};

void main()
{
	cout << "\tOriginal queues:" << endl;

	DoublyLinkedListQueue <string> queue1;
	queue1.Push("11");
	queue1.Push("22");
	queue1.Push("33");
	queue1.Push("44");
	queue1.Push("55");
	cout << "  Queue1:" << endl << queue1.ToString();

	DoublyLinkedListQueue <string> queue2;
	queue2.Push("33");
	queue2.Push("55");
	queue2.Push("77");
	queue2.Push("99");
	cout << "  Queue2:" << endl << queue2.ToString() << endl;

	cout << "\tFront() and Back() test:" << endl;
	cout << "Queue1 front: " << queue1.Front() << endl;
	cout << "Queue1 back: " << queue1.Back() << endl << endl;

	cout << "\tSwap() test:" << endl;
	queue1.Swap(queue2);
	cout << "  Queue1:" << endl << queue1.ToString();
	cout << "  Queue2:" << endl << queue2.ToString() << endl;

	cout << "\tCopy constructor test:" << endl;
	DoublyLinkedListQueue <string> queueResult(queue1);
	cout << "  QueueResult:" << endl << queueResult.ToString() << endl;

	cout << "\tOperator&&= test:" << endl;
	queue1.Clear();
	cout << "  Queue1:" << endl << queue1.ToString();
	cout << "  QueueResult:" << endl << queueResult.ToString();
	queue1 = move(queueResult);
	cout << "    Use move():" << endl;
	cout << "  Queue1:" << endl << queue1.ToString();
	cout << "  QueueResult:" << endl << queueResult.ToString() << endl;
	queueResult.Clear();

	cout << "\tOperator+ test:" << endl;
	queueResult = queue1 + queue2;
	cout << "  QueueResult:" << endl << queueResult.ToString() << endl;
	queueResult.Clear();

	cout << "\tOperator* test:" << endl;
	queueResult = queue1 * queue2;
	cout << "  QueueResult:" << endl << queueResult.ToString() << endl;
	queueResult.Clear();

	cout << "\tOperator&= test:" << endl;
	queueResult = queue1;
	cout << "  QueueResult:" << endl << queueResult.ToString() << endl;
	queueResult.Clear();

	cout << "\tCopy() test:" << endl;
	queueResult.Copy(queue2);
	cout << "  QueueResult:" << endl << queueResult.ToString() << endl;

	system("pause");
}