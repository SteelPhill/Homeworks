#include <iostream>
#include <string>
using namespace std;


//			ВСТРЕЧА №15 (ЗАДАНИЯ №1 И №2)


//string to_string(const string& str)
//{
//	return str;
//}
//
//template <typename TValue>
//class Stack
//{
//	struct StackNode
//	{
//		TValue Value;
//		StackNode* Next;
//
//		StackNode(const TValue& value, StackNode* next)
//		{
//			Value = value;
//			Next = next;
//		}
//	};
//
//	StackNode* head;
//	int size;
//
//	void HeadCopy(StackNode* ptrOtherHead)
//	{
//		Clear();
//
//		if (ptrOtherHead == nullptr)
//			return;
//
//		StackNode* ptrHead = nullptr;
//		StackNode* ptrLast = nullptr;
//		StackNode* temp = nullptr;
//
//		while (ptrOtherHead != nullptr)
//		{
//			temp = new StackNode(ptrOtherHead->Value, nullptr);
//
//			if (ptrHead == nullptr)
//				ptrHead = temp;
//			else
//				ptrLast->Next = temp;
//
//			ptrLast = temp;
//
//			ptrOtherHead = ptrOtherHead->Next;
//		}
//
//		head = ptrHead;
//	}
//
//public:
//	Stack()
//	{
//		head = nullptr;
//		size = 0;
//	}
//
//	Stack(const Stack<TValue>& other)
//	{
//		HeadCopy(other.head);
//		size = other.size;
//	}
//
//	Stack(Stack<TValue>&& other)
//	{
//		head = other.head;
//		size = other.size;
//
//		other.head = nullptr;
//		other.size = 0;
//	}
//
//	~Stack()
//	{
//		Clear();
//	}
//
//	Stack& operator=(const Stack<TValue>& right)
//	{
//		HeadCopy(right.head);
//		size = right.size;
//
//		return *this;
//	}
//
//	Stack& operator=(Stack<TValue>&& right)
//	{
//		head = right.head;
//		size = right.size;
//
//		right.head = nullptr;
//		right.size = 0;
//
//		return *this;
//	}
//
//	Stack<TValue> operator+(const Stack<TValue>& right) const
//	{
//		if (right.IsEmpty())
//			return *this;
//
//		if (IsEmpty())
//			return right;
//
//		Stack<TValue> result;
//		result.HeadCopy(head);
//
//		Stack<TValue> tempRightStack1;
//		tempRightStack1.HeadCopy(right.head);
//
//		Stack<TValue> tempRightStack2;
//
//		while (!tempRightStack1.IsEmpty())
//		{
//			tempRightStack2.Push(tempRightStack1.head->Value);
//			tempRightStack1.Pop();
//		}
//
//		while (!tempRightStack2.IsEmpty())
//		{
//			result.Push(tempRightStack2.head->Value);
//			tempRightStack2.Pop();
//		}
//
//		result.size = size + right.size;
//
//		return result;
//	}
//
//	Stack<TValue> operator*(const Stack<TValue>& right) const
//	{
//		Stack<TValue> result;
//
//		if (IsEmpty() || right.IsEmpty())
//			return result;
//
//		Stack<TValue> tempLeftStack;
//		tempLeftStack.HeadCopy(head);
//
//		Stack<TValue> tempRightStack;
//		tempRightStack.HeadCopy(right.head);
//
//		TValue* arrTempLeft = new TValue[size];
//		TValue* arrTempRight = new TValue[right.size];
//
//		for (int i = 0; i < size; i++)
//		{
//			arrTempLeft[i] = tempLeftStack.head->Value;
//			tempLeftStack.Pop();
//		}
//
//		for (int i = 0; i < right.size; i++)
//		{
//			arrTempRight[i] = tempRightStack.head->Value;
//			tempRightStack.Pop();
//		}
//
//		for (int i = size - 1; i >= 0; i--)
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
//		while (!IsEmpty())
//		{
//			const StackNode* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//
//		size = 0;
//		head = nullptr;
//	}
//
//	void Copy(const Stack<TValue>& other)
//	{
//		Clear();
//
//		if (other.IsEmpty())
//			return;
//
//		HeadCopy(other.head);
//
//		size = other.size;
//	}
//
//	bool IsEmpty() const
//	{
//		return head == nullptr;
//	}
//
//	void Pop()
//	{
//		if (IsEmpty())
//			return;
//
//		const StackNode* forDelete = head;
//
//		head = head->Next;
//
//		delete forDelete;
//
//		size--;
//	}
//
//	void Push(const TValue& value)
//	{
//		if (IsEmpty())
//			head = new StackNode(value, nullptr);
//		else
//			head = new StackNode(value, head);
//
//		size++;
//	}
//
//	int Size() const
//	{
//		return size;
//	}
//
//	void Swap(Stack<TValue>& right)
//	{
//		Stack<TValue> tempLeft;
//		Stack<TValue> tempRight;
//
//		int tempLeftSize = size;
//		int tempRightSize = right.size;
//
//		tempLeft.HeadCopy(head);
//		tempRight.HeadCopy(right.head);
//
//		HeadCopy(tempRight.head);
//		right.HeadCopy(tempLeft.head);
//
//		right.size = tempLeftSize;
//		size = tempRightSize;
//	}
//
//	const TValue& Top() const
//	{
//		return head->Value;
//	}
//
//	string ToString() const
//	{
//		string result;
//
//		if (!IsEmpty())
//			result += "Stack is NOT empty\n\rSize: " +
//				to_string(size) + "\n\rTop: " +
//				to_string(head->Value) + "\n\r";
//		else
//			result += "Stack is empty\n\rSize: " +
//				to_string(size) + "\n\r";
//
//		return result;
//	}
//};
//
//void main()
//{
//	cout << "\tOriginal stacks:" << endl;
//
//	Stack <string> stack1;
//	stack1.Push("11");
//	stack1.Push("22");
//	stack1.Push("33");
//	stack1.Push("44");
//	stack1.Push("55");
//	cout << "Stack1:" << endl << stack1.ToString();
//	
//	Stack <string> stack2;
//	stack2.Push("33");
//	stack2.Push("55");
//	stack2.Push("77");
//	stack2.Push("99");
//	cout << "Stack2:" << endl << stack2.ToString() << endl;
//
//	cout << "\tSwap() test:" << endl;
//	stack1.Swap(stack2);
//	cout << "Stack1:" << endl << stack1.ToString();
//	cout << "Stack2:" << endl << stack2.ToString() << endl;
//
//	cout << "\tCopy constructor test:" << endl;
//	Stack <string> stackResult(stack1);
//	cout << "StackResult:" << endl << stackResult.ToString() << endl;
//
//	cout << "\tOperator&&= test:" << endl;
//	stack1.Clear();
//	cout << "Stack1:" << endl << stack1.ToString();
//	cout << "StackResult:" << endl << stackResult.ToString();
//	stack1 = move(stackResult);
//	cout << "    Use move():" << endl;
//	cout << "Stack1:" << endl << stack1.ToString();
//	cout << "StackResult:" << endl << stackResult.ToString() << endl;
//	stackResult.Clear();
//
//	cout << "\tOperator+ test:" << endl;
//	stackResult = stack1 + stack2;
//	cout << "StackResult:" << endl << stackResult.ToString() << endl;
//	stackResult.Clear();
//
//	cout << "\tOperator* test:" << endl;
//	stackResult = stack1 * stack2;
//	cout << "StackResult:" << endl << stackResult.ToString() << endl;
//	stackResult.Clear();
//
//	cout << "\tOperator&= test:" << endl;
//	stackResult = stack1;
//	cout << "StackResult:" << endl << stackResult.ToString() << endl;
//	stackResult.Clear();
//
//	cout << "\tCopy() test:" << endl;
//	stackResult.Copy(stack2);
//	cout << "StackResult:" << endl << stackResult.ToString() << endl;
//
//	system("pause");
//}