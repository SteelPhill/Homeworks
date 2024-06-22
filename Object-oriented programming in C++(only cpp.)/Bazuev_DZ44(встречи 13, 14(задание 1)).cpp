#include <iostream>
using namespace std;


//			ВСТРЕЧА №13

/*Есть строка символов, признаком конца, которой является ;. 
В строке могут быть фигурные, круглые, квадратные скобки.
Скобки могут быть открывающими и закрывающими.
Необходимо проверить корректность расстановки скобок. 
При этом необходимо, чтобы выполнились следующие правила:
1. Каждая открывающая скобка должна иметь справа 
такую же закрывающую. Обратное также должно быть верно.
2. Открывающие и закрывающие пары скобок разных 
типов должны быть правильно расположены по отношению друг к другу.
- Пример правильной строки: ({x-y-z}*[x+2y]-(z+4x));
- Пример неправильной строки:([x-y-z}*[x+2y)-{z+4x)].
Если все правила соблюдены выведите информационное 
сообщение о корректности строки, иначе покажите строку 
до места возникновения первой ошибки.*/

//class Stack
//{
//	struct Node
//	{
//		char Value;
//		Node* Next;
//
//		Node(const char value, Node* next)
//		{
//			Value = value;
//			Next = next;
//		}
//	};
//
//	Node* head;
//
//public:
//	Stack()
//	{
//		head = nullptr;
//	}
//
//	~Stack()
//	{
//		Clear();
//	}
//
//	bool IsEmpty() const
//	{
//		return head == nullptr;
//	}
//
//	void Clear()
//	{
//		while (head != nullptr)
//		{
//			const Node* forDelete = head;
//			head = head->Next;
//			delete forDelete;
//		}
//	}
//
//	void Push(const char value)
//	{
//		if (IsEmpty())
//			head = new Node(value, nullptr);
//		else
//			head = new Node(value, head);
//	}
//
//	void Pop()
//	{
//		if (IsEmpty())
//			return;
//
//		const Node* forDelete = head;
//
//		head = head->Next;
//
//		delete forDelete;
//	}
//
//	char Top() const
//	{
//		if (IsEmpty())
//			return '\0';
//
//		return head->Value;
//	}
//};
//
//void CheckBracketsPlacementCorrect(const char* expression, char* result)
//{
//	const int buffer = 8;
//
//	if (expression == nullptr)
//	{
//		strcpy_s(result, buffer, "nullptr");
//		return;
//	}
//
//	Stack bracketsStack;
//
//	int i = 0;
//
//	for (; expression[i] != '\0'; i++)
//	{
//		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
//			bracketsStack.Push(expression[i]);
//
//		if (expression[i] == ')')
//		{
//			if (bracketsStack.Top() != '(')
//				break;
//			else
//				bracketsStack.Pop();
//		}
//		else if (expression[i] == '}')
//		{
//			if (bracketsStack.Top() != '{')
//				break;
//			else
//				bracketsStack.Pop();
//		}
//		else if (expression[i] == ']')
//		{ 
//			if (bracketsStack.Top() != '[')
//				break;
//			else
//				bracketsStack.Pop();
//		}
//	}
//
//	if (expression[i] != '\0' || !bracketsStack.IsEmpty())
//	{
//		for (int j = 0; j < i; j++)
//			result[j] = expression[j];
//		result[i] = '\0';
//		return;
//	}
//
//	strcpy_s(result, buffer, "correct");
//}
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//
//	const char* expression = "( a + b ) * { arr [i] }";
//
//	char result[256];
//
//	CheckBracketsPlacementCorrect(expression, result);
//
//	cout << "\tВарианты результата проверки:" << endl;
//	cout << "-Скобки расставлены корректно - correct;" << endl;
//	cout << "-Скобки расставлены некорректно - показывает строку до возникновения ошибки;" << endl;
//	cout << "-Строке присвоено значение \"nullptr\" - nullptr." << endl << endl;
//
//	cout << "Результат: " << result << endl << endl;
//
//	system("pause");
//}


//			ВСТРЕЧА №14 (ЗАДАНИЕ №1)

/*Создать имитационную модель "остановка маршрутных 
такси". Необходимо вводить следующую информацию: 
среднее время между появлениями пассажиров на остановке в разное время суток,
среднее время между появлениями маршруток на остановке в разное время суток, 
тип остановки (конечная или нет). Необходимо определить: среднее время 
пребывание человека на остановке, достаточный интервал времени между приходами
маршруток, чтобы на остановке находилось не более N людей одновременно.
Количество свободных мест в маршрутке является случайной величиной.*/

//class Passenger
//{
//	int passengerNumber;
//
//	static inline int totalPassengers = 0;
//
//public:
//	Passenger()
//	{
//		passengerNumber = ++totalPassengers;
//	}
//
//	int GetPassengerNumber() const { return passengerNumber; }
//};
//
//class Bus
//{
//	int availableSeatsNumber;
//
//	static const int minAvailableSeatsNumber = 0;
//	static const int maxAvailableSeatsNumber = 15;
//
//public:
//	Bus(const bool isFinalStop = false)
//	{
//		if (isFinalStop)
//			availableSeatsNumber = maxAvailableSeatsNumber;
//		else
//			availableSeatsNumber = rand() % (maxAvailableSeatsNumber - minAvailableSeatsNumber + 1) + minAvailableSeatsNumber;
//	}
//
//	int GetAvailableSeatsNumber() const { return availableSeatsNumber; }
//};
//
//template <typename TValue>
//class Queue
//{
//	struct Node
//	{
//		TValue Value;
//		Node* Next;
//
//		Node(const TValue& value, Node* next)
//		{
//			Value = value;
//			Next = next;
//		}
//	};
//
//	Node* head;
//	Node* tail;
//	int size;
//
//public:
//	Queue()
//	{
//		head = tail = nullptr;
//		size = 0;
//	}
//
//	~Queue()
//	{
//		Clear();
//	}
//
//	bool IsEmpty() const
//	{
//		return head == nullptr;
//	}
//
//	void Clear()
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
//	void Push(const TValue& value)
//	{
//		if (IsEmpty())
//			head = tail = new Node(value, nullptr);
//		else
//			tail = tail->Next = new Node(value, nullptr);
//
//		size++;
//	}
//
//	void Pop()
//	{
//		if (IsEmpty())
//			return;
//
//		const Node* forDelete = head;
//
//		head = head->Next;
//		if (head == nullptr)
//			tail = nullptr;
//
//		delete forDelete;
//
//		size--;
//	}
//
//	int Size() const
//	{
//		return size;
//	}
//};
//
//class BusStop
//{
//	int hoursNow;
//	bool isFinalStop;
//	int busesNumberPerHour;
//	int passengersNumberPerHour;
//
//	const double minutesPerHour = 60;
//
//	bool IsHourEnterCorrect(const int hoursNow)
//	{
//		return hoursNow >= 0 && hoursNow < 24;
//	}
//
//	int BusesNumberPerHourDependingOnDayTime() const 
//	{
//		if (hoursNow >= 6 && hoursNow < 11 || hoursNow >= 15 && hoursNow < 19)
//			return 7;
//		else if (hoursNow >= 11 && hoursNow < 13)
//			return 3;
//		else if (hoursNow >= 13 && hoursNow < 15 || hoursNow >= 19 && hoursNow < 22)
//			return 6;
//
//		return 0;
//	}
//
//	int PassengersNumberPerHourDependingOnDayTime() const
//	{
//		if (hoursNow == 6 || hoursNow >= 20 && hoursNow < 22)
//			return 37;
//		else if (hoursNow >= 7 && hoursNow < 9 || hoursNow >= 16 && hoursNow < 18)
//			return 93;
//		else if (hoursNow == 10 || hoursNow >= 13 && hoursNow < 16)
//			return 61;
//		else if (hoursNow >= 11 && hoursNow < 13 || hoursNow >= 18 && hoursNow < 20)
//			return 45;
//		
//		return 0;
//	}
//
//public:
//	BusStop(const int hoursNow, const bool isFinalStop = false)
//	{
//		if (IsHourEnterCorrect(hoursNow))
//			this->hoursNow = hoursNow;
//		else
//			this->hoursNow = -1;
//
//		this->isFinalStop = isFinalStop;
//
//		busesNumberPerHour = BusesNumberPerHourDependingOnDayTime();
//		passengersNumberPerHour = PassengersNumberPerHourDependingOnDayTime();
//	}
//
//	int GetHoursNow() const { return hoursNow; }
//	bool GetIsFinalStop() const { return isFinalStop; }
//	int GetBusesNumberPerHour() const { return busesNumberPerHour; }
//	int GetPassengersNumberPerHour() const { return passengersNumberPerHour; }
//
//	void SetHoursNow(const int hoursNow)
//	{
//		if (IsHourEnterCorrect(hoursNow))
//			this->hoursNow = hoursNow;
//		else
//			this->hoursNow = -1;
//
//		busesNumberPerHour = BusesNumberPerHourDependingOnDayTime();
//		passengersNumberPerHour = PassengersNumberPerHourDependingOnDayTime();
//	}
//
//	void SetIsFinalStop(const bool isFinalStop)
//	{
//		this->isFinalStop = isFinalStop;
//	}
//
//	double AverageMinutesNumberPassengerStayOnStopPerHour() const
//	{
//		if (busesNumberPerHour == 0)
//			return 0;
//
//		double totalWaitingTime = 0;
//		Queue <Passenger>passengersQueue;
//		double timeIntervalBetweenBuses = minutesPerHour / busesNumberPerHour;
//
//		int averageNewPassengersNumberBetweenBusTrip = ceil((double)passengersNumberPerHour / busesNumberPerHour);
//
//		for (int i = 0; i < busesNumberPerHour; i++)
//		{
//			for (int j = 0; j < averageNewPassengersNumberBetweenBusTrip; j++)
//			{
//				Passenger passenger;
//				passengersQueue.Push(passenger);
//			}
//			
//			Bus bus(isFinalStop);
//		
//			for (int j = 0; j < bus.GetAvailableSeatsNumber() && passengersQueue.Size() != 0; j++)
//				passengersQueue.Pop();
//
//			totalWaitingTime += passengersQueue.Size() * timeIntervalBetweenBuses;
//		}
//
//		return totalWaitingTime / passengersNumberPerHour;
//	}
//
//	double CalculateIntervalBetweenBuses(const int maxPeopleNumberWaitOnStop) const
//	{
//		if (busesNumberPerHour == 0)
//			return 0;
//
//		return minutesPerHour / passengersNumberPerHour * (maxPeopleNumberWaitOnStop + 1);
//	}
//};
//
//void main()
//{
//	setlocale(LC_ALL, "ru");
//	srand(time(0));
//
//	const int HourIsItNow = 8;
//	const int MaxPeopleNumberWaitOnStop = 4;
//
//	BusStop busStop(HourIsItNow);
//
//	if (busStop.GetIsFinalStop())
//		cout << "Это конечная остановка." << endl << endl;
//	else
//		cout << "Это неконечная остановка." << endl << endl;
//
//	cout << "Среднее количество автобусов в " << HourIsItNow << "ч.: " << busStop.GetBusesNumberPerHour() << endl;
//	cout << "Среднее количество пассажиров в " << HourIsItNow << "ч.: " << busStop.GetPassengersNumberPerHour() << endl << endl;
//
//	cout << "Среднее время ождиния автобуса в " << HourIsItNow << "ч.: " << 
//		busStop.AverageMinutesNumberPassengerStayOnStopPerHour() << "мин." << endl << endl;
//
//	cout << "Необходимый интервал между автобусами в " << HourIsItNow << "ч.," << endl <<
//		"для предотвращения скопления более " << MaxPeopleNumberWaitOnStop << " пассажиров на остановке: не более " << 
//		busStop.CalculateIntervalBetweenBuses(MaxPeopleNumberWaitOnStop) << "мин." << endl << endl;
//
//	system("pause");
//}