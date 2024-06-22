#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
using namespace std;


//			¬—“–≈„ј є20

/*—оздайте иерархию классов по работе с файлами. Ѕазовый
класс умеет открывать файл и отображать его содержимое
в консоль, первый класс потомка открывает файл и
отображает содержимое в виде ASCII-кодов символов,
расположенных в файле, второй класс потомка открывает
файл и показывает его содержимое в двоичном виде и т.д.
ƒл¤ отображени¤ содержимого файла в базовом классе
определена виртуальна¤ функци¤
- void Display(const char * path);
- path Ч путь к файлу.
ѕотомки создают свою реализацию виртуальной функции.*/

//class FileReader
//{
//protected:
//	virtual ~FileReader() = default;
//	virtual void Display(const char* path) const = 0;
//};
//
//class ASCIIFileReader : public FileReader
//{
//public:
//	void Display(const char* path) const override
//	{
//		ifstream file;
//		file.open(path);
//
//		if (!file.is_open())
//			throw string("invalid file");
//
//		if (file.peek() == EOF)
//			throw string("file is empty");
//
//		string str;
//
//		while (getline(file, str))
//			cout << str << endl;
//
//		file.close();
//	}
//};
//
//class BinaryCodeFileReader : public FileReader
//{
//public:
//	void Display(const char* path) const override
//	{
//		const int byteSize = 8;
//
//		ifstream file;
//		file.open(path);
//
//		if (!file.is_open())
//			throw string("invalid file");
//
//		if (file.peek() == EOF)
//			throw string("file is empty");
//
//		char ch;
//
//		while (file.get(ch))
//		{
//			if (ch == '\n')
//				cout << endl;
//			else
//				cout << bitset<byteSize>(ch).to_string() + ' ';
//		}
//
//		file.close();
//	}
//};
//
//void CreateFile(const char* path)
//{
//	ofstream file;
//	file.open(path);
//
//	if (!file.is_open())
//		throw string("file not create");
//
//	file << "qW" << endl;
//	file << "ErT" << endl;
//	file << "y!." << endl;
//
//	file.close();
//}
//
//void main()
//{
//	const char* path = "¬стреча є20.txt";
//
//	try
//	{
//		CreateFile(path);
//	}
//	catch (const string& error)
//	{
//		cout << "Error: " << error << endl;
//	}
//
//	ASCIIFileReader fileReader1;
//	BinaryCodeFileReader fileReader2;
//
//	try
//	{
//		cout << "\tASCII file reader:" << endl << endl;
//		fileReader1.Display(path);
//	}
//	catch (const string& error)
//	{
//		cout << "Error: " << error << endl;
//	}
//
//	cout << endl;
//
//	try
//	{
//		cout << "\tBinary code file reader:" << endl << endl;
//		fileReader2.Display(path);
//	}
//	catch (const string& error)
//	{
//		cout << "Error: " << error << endl;
//	}
//
//	remove(path);
//
//	cout << endl;
//	system("pause");
//}


//			¬—“–≈„ј є21

//			«јƒјЌ»≈ є1

/*—оздать абстрактный базовый класс с виртуальной
функцией Ч корни уравнени¤. —оздать производные классы:
класс линейных уравнений и класс квадратных уравнений.
ќпределить функцию вычислени¤ корней уравнений.*/

//class Equation
//{
//protected:
//	virtual ~Equation() = default;
//	virtual void EquationRoot() = 0;
//};
//
//class LinearEquation : public Equation
//{
//	double a;
//	double b;
//	double x;
//
//public:
//	LinearEquation(const double a, const double b)
//	{
//		this->a = a;
//		this->b = b;
//		x = 0;
//	}
//
//	double GetA() const { return a; }
//	double GetB() const { return b; }
//	double GetX() const { return x; }
//
//	void SetA(const double a) { this->a = a; }
//	void SetB(const double b) { this->b = b; }
//
//	void EquationRoot() override
//	{
//		x = 0;
//
//		if (a == 0 && b == 0)
//			throw string("true for all x");
//
//		if (a == 0)
//			throw string("a = 0 - is error");
//
//		if (b == 0)
//			return;
//
//		x = -b / a;
//	}
//};
//
//class QuadraticEquation : public Equation
//{
//	double a;
//	double b;
//	double c;
//	double x1;
//	double x2;
//
//	int FindDiscriminant()
//	{
//		return b * b - 4 * a * c;
//	}
//
//public:
//	QuadraticEquation(const double a, const double b, const double c)
//	{
//		this->a = a;
//		this->b = b;
//		this->c = c;
//		x1 = 0;
//		x2 = 0;
//	}
//
//	double GetA() const { return a; }
//	double GetB() const { return b; }
//	double GetC() const { return c; }
//	double GetX1() const { return x1; }
//	double GetX2() const { return x2; }
//
//	void SetA(const double a) { this->a = a; }
//	void SetB(const double b) { this->b = b; }
//	void SetC(const double c) { this->c = c; }
//
//	void EquationRoot() override
//	{
//		x1 = x2 = 0;
//
//		if (a == 0)
//			throw string("a = 0 - is error");
//
//		if (b == 0 && c == 0)
//			return;
//
//		int discriminant = FindDiscriminant();
//
//		if (discriminant < 0)
//			throw string("there are no roots");
//
//		if (discriminant == 0)
//		{
//			x1 = -b / (2 * a);
//			x2 = x1;
//		}
//
//		else if (discriminant > 0)
//		{
//			x1 = (-b + sqrt(discriminant)) / (2 * a);
//			x2 = (-b - sqrt(discriminant)) / (2 * a);
//		}
//	}
//};
//
//void main()
//{
//	LinearEquation equation1(2, -4);
//
//	QuadraticEquation equation2(1, -3, 2);
//
//	try
//	{
//		equation1.EquationRoot();
//		cout << "The result of calculating the root using a linear equation: " << 
//			"x = " << equation1.GetX() << endl;
//
//	}
//	catch (const string& msg)
//	{
//		cout << "Exception in linear equation: " << msg << endl;
//	}
//
//	try
//	{
//		equation2.EquationRoot();
//		cout << endl << "The result of calculating the root using a quadratic equation: " <<
//			"x1 = " << equation2.GetX1() << ", x2 = " << equation2.GetX2() << endl;
//	}
//	catch (const string& msg)
//	{
//		cout << endl << "Exception in quadratic equation: " << msg << endl;
//	}
//
//	cout << endl;
//	system("pause");
//}


//			¬—“–≈„ј є21

//			«јƒјЌ»≈ є2

/*—оздайте абстрактный класс Shape дл¤ рисовани¤
плоских фигур. ќпределите виртуальные методы:
Show() Ч вывод на экран информации о фигуре,
Save() Ч сохранение фигуры в файл,
Load() Ч считывание фигуры из файла.
ќпределите производные классы:
Square Ч квадрат, который характеризуетс¤ координатами левого верхнего угла и длиной стороны;
Rectangle Ч пр¤моугольник с заданными координатами верхнего левого угла и размерами;
Circle Ч окружность с заданными координатами центра и радиусом;
Ellipse Ч эллипс с заданными координатами верхнего угла описанного вокруг него пр¤моугольника со сторонами,
параллельными ос¤м координат, и размерами этого пр¤моугольника.
—оздайте массив фигур, сохраните фигуры в файл,
загрузите в другой массив и отобразите информацию
о каждой из фигур.*/

//class MyShape
//{
//protected:
//	struct Point
//	{
//		int X;
//		int Y;
//
//		Point() : Point(1, 1)
//		{
//		}
//
//		Point(const int x, const int y)
//		{
//			X = x;
//			Y = y;
//		}
//	};
//
//	Point initialCoordinate;
//	string type;
//
//	MyShape(const int x, const int y, const string& type)
//	{
//		if (x < 1 || y < 1)
//			throw string("incorrect coordinates");
//
//		initialCoordinate.X = x;
//		initialCoordinate.Y = y;
//		this->type = type;
//	}
//
//public:
//	virtual ~MyShape() = default;
//
//	string GetType() const { return type; }
//	int GetX() const { return initialCoordinate.X; }
//	int GetY() const { return initialCoordinate.Y; }
//
//	void SetX(const int x)
//	{
//		if (x < 1)
//			throw string("incorrect coordinates");
//
//		initialCoordinate.X = x;
//	}
//
//	void SetY(const int y)
//	{
//		if (y < 1)
//			throw string("incorrect coordinates");
//
//		initialCoordinate.Y = y;
//	}
//
//	virtual void Print(const char contourElement) const = 0;
//	virtual void Save(const char* path) const = 0;
//	virtual void Load(const char* path) = 0;
//	virtual void Show() const = 0;
//};
//
//class MySquare : public MyShape
//{
//	int width;
//
//	inline static const string type = "square";
//
//public:
//	MySquare() : MySquare(1, 1, 0)
//	{
//	}
//
//	MySquare(const int x, const int y, const int width) : MyShape(x, y, type)
//	{
//		if (width < 0)
//			throw string("incorrect size");
//
//		this->width = width;
//	}
//
//	int GetWidth() const { return width; }
//
//	void SetWidth(const int width)
//	{
//		if (width < 0)
//			throw string("incorrect size");
//
//		this->width = width;
//	}
//
//	void Print(const char contourElement) const override
//	{
//		if (width == 0)
//			return;
//
//		for (int i = 1; i < initialCoordinate.Y; i++)
//			cout << endl;
//
//		for (int i = 1; i < initialCoordinate.X; i++)
//			cout << " ";
//
//		if (width == 1)
//		{
//			cout << contourElement << endl;
//			return;
//		}
//
//		for (int i = 0; i < width; i++)
//			cout << contourElement << " ";
//		cout << endl;
//
//		for (int i = 1; i < width - 1; i++)
//		{
//			for (int j = 1; j < initialCoordinate.X; j++)
//				cout << " ";
//			cout << contourElement;
//
//			for (int j = 1; j < (width - 1) * 2; j++)
//				cout << " ";
//			cout << contourElement;
//
//			cout << endl;
//		}
//
//		for (int i = 1; i < initialCoordinate.X; i++)
//			cout << " ";
//
//		for (int i = 0; i < width; i++)
//			cout << contourElement << " ";
//
//		cout << endl;
//	}
//
//	void Save(const char* path) const override
//	{
//		ofstream file;
//		file.open(path, ios::app);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		file << type;
//		file << endl;
//		file << width;
//		file << endl;
//		file << initialCoordinate.X;
//		file << endl;
//		file << initialCoordinate.Y;
//		file << endl;
//
//		file.close();
//	}
//
//	void Load(const char* path) override
//	{
//		ifstream file;
//		file.open(path);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		string temp;
//
//		while (getline(file, temp))
//			if (temp == type)
//				break;
//
//		getline(file, temp);
//		width = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.X = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.Y = stoi(temp);
//
//		file.close();
//
//		if (width < 0)
//			throw string("incorrect size");
//
//		if (initialCoordinate.X < 1 || initialCoordinate.Y < 1)
//			throw string("incorrect coordinates");
//	}
//
//	void Show() const override
//	{
//		Print('*');
//
//		cout << endl << "Shape type:\t    " << type << endl;
//		cout << "Width:\t\t    " << width << endl;
//		cout << "Begin coordinates:  x = " << initialCoordinate.X
//			<< ", y = " << initialCoordinate.Y << endl;
//	}
//};
//
//class MyRectangle : public MyShape
//{
//	int width;
//	int height;
//
//	inline static const string type = "rectangle";
//
//public:
//	MyRectangle() : MyRectangle(1, 1, 0, 0)
//	{
//	}
//
//	MyRectangle(const int x, const int y, const int width, const int height)
//		: MyShape(x, y, type)
//	{
//		if (width < 0 || height < 0)
//			throw string("incorrect size");
//
//		this->width = width;
//		this->height = height;
//	}
//
//	int GetWidth() const { return width; }
//	int GetHeight() const { return height; }
//
//	void SetWidth(const int width)
//	{
//		if (width < 0)
//			throw string("incorrect size");
//
//		this->width = width;
//	}
//
//	void SetHeight(const int height)
//	{
//		if (height < 0)
//			throw string("incorrect size");
//
//		this->height = height;
//	}
//
//	void Print(const char contourElement) const override
//	{
//		if (width == 0 || height == 0)
//			return;
//
//		for (int i = 1; i < initialCoordinate.Y; i++)
//			cout << endl;
//
//		for (int i = 1; i < initialCoordinate.X; i++)
//			cout << " ";
//
//		if (width == 1 && height == 1)
//		{
//			cout << contourElement << endl;
//			return;
//		}
//		else if (width == 1)
//		{
//			for (int i = 0; i < height; i++)
//			{
//				cout << contourElement << endl;
//				for (int j = 1; j < initialCoordinate.X; j++)
//					cout << " ";
//			}
//
//			cout << endl;
//			return;
//		}
//
//		for (int i = 0; i < width; i++)
//			cout << contourElement << " ";
//		cout << endl;
//
//		if (height == 1)
//			return;
//
//		for (int i = 1; i < height - 1; i++)
//		{
//			for (int j = 1; j < initialCoordinate.X; j++)
//				cout << " ";
//			cout << contourElement;
//
//			for (int j = 1; j < (width - 1) * 2; j++)
//				cout << " ";
//			cout << contourElement;
//
//			cout << endl;
//		}
//
//		for (int i = 1; i < initialCoordinate.X; i++)
//			cout << " ";
//
//		for (int i = 0; i < width; i++)
//			cout << contourElement << " ";
//
//		cout << endl;
//	}
//
//	void Save(const char* path) const override
//	{
//		ofstream file;
//		file.open(path, ios::app);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		file << type;
//		file << endl;
//		file << width;
//		file << endl;
//		file << height;
//		file << endl;
//		file << initialCoordinate.X;
//		file << endl;
//		file << initialCoordinate.Y;
//		file << endl;
//
//		file.close();
//	}
//
//	void Load(const char* path) override
//	{
//		ifstream file;
//		file.open(path);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		string temp;
//
//		while (getline(file, temp))
//			if (temp == type)
//				break;
//
//		getline(file, temp);
//		width = stoi(temp);
//		getline(file, temp);
//		height = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.X = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.Y = stoi(temp);
//
//		file.close();
//
//		if (width < 0 || height < 0)
//			throw string("incorrect size");
//
//		if (initialCoordinate.X < 1 || initialCoordinate.Y < 1)
//			throw string("incorrect coordinates");
//	}
//
//	void Show() const override
//	{
//		Print('*');
//
//		cout << endl << "Shape type:\t    " << type << endl;
//		cout << "Width:\t\t    " << width << endl;
//		cout << "Height:\t\t    " << height << endl;
//		cout << "Begin coordinates:  x = " << initialCoordinate.X
//			<< ", y = " << initialCoordinate.Y << endl;
//	}
//};
//
//class MyCircle : public MyShape
//{
//	int radius;
//
//	inline static const string type = "circle";
//
//public:
//	MyCircle() : MyCircle(1, 1, 0)
//	{
//	}
//
//	MyCircle(const int x, const int y, const int radius) : MyShape(x, y, type)
//	{
//		if (radius < 0 || x - radius <= 0 || y - radius <= 0)
//			throw string("incorrect size");
//
//		this->radius = radius;
//	}
//
//	int GetRadius() const { return radius; }
//
//	void SetRadius(const int radius)
//	{
//		if (initialCoordinate.X - radius <= 0 || initialCoordinate.Y - radius <= 0)
//			throw string("incorrect size");
//
//		this->radius = radius;
//	}
//
//	void Print(const char contourElement) const override
//	{
//		if (radius == 0)
//			return;
//
//		int beginX = initialCoordinate.X - radius;
//		int beginY = initialCoordinate.Y - radius;
//		int diametr = radius * 2;
//
//		for (int i = 1; i < beginY; i++)
//			cout << endl;
//
//		for (int i = 0; i < beginX; i++)
//			cout << " ";
//
//		for (int i = 1; i < diametr; i++)
//			cout << contourElement;
//		cout << endl;
//
//		for (int i = 0; i < diametr - 1; i++)
//		{
//			for (int j = 0; j < beginX - 1; j++)
//				cout << " ";
//			cout << contourElement;
//
//			for (int j = 1; j < diametr; j++)
//				cout << " ";
//			cout << contourElement;
//
//			cout << endl;
//		}
//
//		for (int i = 0; i < beginX; i++)
//			cout << " ";
//
//		for (int i = 1; i < diametr; i++)
//			cout << contourElement;
//		cout << endl;
//	}
//
//	void Save(const char* path) const override
//	{
//		ofstream file;
//		file.open(path, ios::app);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		file << type;
//		file << endl;
//		file << radius;
//		file << endl;
//		file << initialCoordinate.X;
//		file << endl;
//		file << initialCoordinate.Y;
//		file << endl;
//
//		file.close();
//	}
//
//	void Load(const char* path) override
//	{
//		ifstream file;
//		file.open(path);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		string temp;
//
//		while (getline(file, temp))
//			if (temp == type)
//				break;
//
//		getline(file, temp);
//		radius = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.X = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.Y = stoi(temp);
//
//		file.close();
//
//		if (radius < 0)
//			throw string("incorrect size");
//
//		if (initialCoordinate.X - radius <= 0 || initialCoordinate.Y - radius <= 0)
//			throw string("incorrect coordinates");
//	}
//
//	void Show() const override
//	{
//		Print('*');
//
//		cout << endl << "Shape type:\t    " << type << endl;
//		cout << "Radius:\t\t    " << radius << endl;
//		cout << "Center coordinates: x = " << initialCoordinate.X
//			<< ", y = " << initialCoordinate.Y << endl;
//	}
//};
//
//class MyEllipse : public MyShape
//{
//	int width;
//	int height;
//
//	inline static const string type = "ellipse";
//
//public:
//	MyEllipse() : MyEllipse(1, 1, 0, 0)
//	{
//	}
//
//	MyEllipse(const int x, const int y, const int width, const int height)
//		: MyShape(x, y, type)
//	{
//		if (width < 0 || height < 0)
//			throw string("incorrect size");
//
//		this->width = width;
//		this->height = height;
//	}
//
//	int GetWidth() const { return width; }
//	int GetHeight() const { return height; }
//
//	void SetWidth(const int width)
//	{
//		if (width < 0)
//			throw string("incorrect size");
//
//		this->width = width;
//	}
//
//	void SetHeight(const int height)
//	{
//		if (height < 0)
//			throw string("incorrect size");
//
//		this->height = height;
//	}
//
//	void Print(const char contourElement) const override
//	{
//		if (width == 0 || height == 0)
//			return;
//
//		for (int i = 1; i < initialCoordinate.Y; i++)
//			cout << endl;
//
//		if (width == 1 && height == 1)
//		{
//			for (int i = 1; i < initialCoordinate.X; i++)
//				cout << " ";
//			cout << contourElement << endl;
//			return;
//		}
//		else if (width == 1)
//		{
//			for (int i = 0; i < height; i++)
//			{
//				for (int i = 1; i < initialCoordinate.X; i++)
//					cout << " ";
//				cout << contourElement << endl;
//			}
//
//			cout << endl;
//			return;
//		}
//		else if (height == 1)
//		{
//			for (int i = 1; i < initialCoordinate.X; i++)
//				cout << " ";
//
//			for (int i = 0; i < width; i++)
//				cout << contourElement << " ";
//
//			cout << endl;
//			return;
//		}
//		else if (width == 2 || height == 2)
//		{
//			for (int i = 0; i < height; i++)
//			{
//				for (int j = 1; j < initialCoordinate.X; j++)
//					cout << " ";
//
//				for (int j = 0; j < width; j++)
//					cout << contourElement << " ";
//				cout << endl;
//			}
//
//			return;
//		}
//
//		for (int i = 0; i < initialCoordinate.X; i++)
//			cout << " ";
//
//		for (int i = 2; i < width; i++)
//			cout << " " << contourElement;
//		cout << endl;
//
//		for (int i = 1; i < height - 1; i++)
//		{
//			for (int j = 1; j < initialCoordinate.X; j++)
//				cout << " ";
//			cout << contourElement;
//
//			for (int j = 1; j < (width - 1) * 2; j++)
//				cout << " ";
//			cout << contourElement;
//
//			cout << endl;
//		}
//
//		for (int i = 0; i < initialCoordinate.X; i++)
//			cout << " ";
//
//		for (int i = 2; i < width; i++)
//			cout << " " << contourElement;
//
//		cout << endl;
//	}
//
//	void Save(const char* path) const override
//	{
//		ofstream file;
//		file.open(path, ios::app);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		file << type;
//		file << endl;
//		file << width;
//		file << endl;
//		file << height;
//		file << endl;
//		file << initialCoordinate.X;
//		file << endl;
//		file << initialCoordinate.Y;
//		file << endl;
//
//		file.close();
//	}
//
//	void Load(const char* path) override
//	{
//		ifstream file;
//		file.open(path);
//
//		if (!file.is_open())
//			throw string("file not open");
//
//		string temp;
//
//		while (getline(file, temp))
//			if (temp == type)
//				break;
//
//		getline(file, temp);
//		width = stoi(temp);
//		getline(file, temp);
//		height = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.X = stoi(temp);
//		getline(file, temp);
//		initialCoordinate.Y = stoi(temp);
//
//		file.close();
//
//		if (width < 0 || height < 0)
//			throw string("incorrect size");
//
//		if (initialCoordinate.X < 1 || initialCoordinate.Y < 1)
//			throw string("incorrect coordinates");
//	}
//
//	void Show() const override
//	{
//		Print('*');
//
//		cout << endl << "Shape type:\t    " << type << endl;
//		cout << "Width:\t\t    " << width << endl;
//		cout << "Height:\t\t    " << height << endl;
//		cout << "Begin coordinates:  x = " << initialCoordinate.X
//			<< ", y = " << initialCoordinate.Y << endl;
//	}
//};
//
//void ShapeTest(const char* path)
//{
//	const int ShapesNumber = 4;
//	const int DividingLineLength = 40;
//
//	MyShape* savedShapes[ShapesNumber];
//	savedShapes[0] = new MySquare(1, 1, 4);
//	savedShapes[1] = new MyRectangle(2, 2, 9, 3);
//	savedShapes[2] = new MyCircle(4, 4, 2);
//	savedShapes[3] = new MyEllipse(3, 3, 10, 4);
//
//	for (int i = 0; i < ShapesNumber; i++)
//		savedShapes[i]->Save(path);
//
//	MyShape* uploadedShapes[ShapesNumber];
//	uploadedShapes[0] = new MyCircle;
//	uploadedShapes[1] = new MyEllipse;
//	uploadedShapes[2] = new MySquare;
//	uploadedShapes[3] = new MyRectangle;
//
//	for (int i = 0; i < ShapesNumber; i++)
//		uploadedShapes[i]->Load(path);
//
//	for (int j = 0; j < DividingLineLength; j++)
//		cout << "_";
//	cout << endl;
//
//	for (int i = 0; i < ShapesNumber; i++)
//	{
//		uploadedShapes[i]->Show();
//		for (int j = 0; j < DividingLineLength; j++)
//			cout << "_";
//		cout << endl;
//	}
//
//	for (int i = 0; i < ShapesNumber; i++)
//	{
//		delete savedShapes[i];
//		delete uploadedShapes[i];
//	}
//}
//
//void main()
//{
//	const char* path = "¬стреча є21(«адание 2).txt";
//
//	try
//	{
//		ShapeTest(path);
//	}
//	catch (const string& error)
//	{
//		cout << "Error: " << error << endl;
//	}
//
//	remove(path);
//
//	cout << endl;
//	system("pause");
//}