#include <iostream>
using namespace std;


//			ВСТРЕЧА №23

/*В рамках предыдущих самостоятельных и домашних 
заданий вы создали набор классов по работе с различными
примитивными математическими операциями (дробь,
точка в двумерном пространстве, точка в трехмерном
пространстве и т.д.). Разместите уже созданные классы
в пространствах имён. Продумайте правильную структуру
созданных пространств. Используя механизм пространств
напишите код по тестированию полученного решения.*/

namespace pointNamespace
{
	class Point
	{
		int x, y;

	public:
		Point() : Point(0, 0)
		{
		}

		explicit Point(const int value) : Point(value, value)
		{
		}

		Point(const int x, const int y)
		{
			this->x = x;
			this->y = y;
		}

		int GetX() const { return x; }
		void SetX(const int x) { this->x = x; }

		int GetY() const { return y; }
		void SetY(const int y) { this->y = y; }
	};
}

void NamespaceTest1()
{
	cout << "NamespaceTest1:" << endl;
	pointNamespace::Point point(2, 4);
	cout << "point(" << point.GetX() << ", " << point.GetY() << ")" << endl << endl;
}

void NamespaceTest2()
{
	using namespace pointNamespace;

	cout << "NamespaceTest2:" << endl;
	Point point(3, 5);
	cout << "point(" << point.GetX() << ", " << point.GetY() << ")" << endl << endl;
}

void main()
{
	NamespaceTest1();

	NamespaceTest2();

	system("pause");
}