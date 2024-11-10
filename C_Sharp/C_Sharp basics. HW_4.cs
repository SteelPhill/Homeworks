using System;
using System.Collections.Generic;
using System.Linq;

namespace ActualHomework;

public class Program
{
    public static void Main()
    {
        try
        {
            Task1();
            //Task2();
            //Task3();
            //Task4();
        }
        catch (Exception ex)
        {
            Console.Clear();
            Console.WriteLine($"Ошибка: {ex.Message}");
        }

        Console.ReadKey();
    }


    /*     
     *          ЗАДАНИЕ №1
     * Создайте приложение калькулятор для перевода
     * числа из одной системы исчисления в другую. 
     * Пользователь с помощью меню выбирает направление перевода. 
     * Например, из десятичной в двоичную. После выбора направления, 
     * пользователь вводит число в исходной системе исчисления. 
     * Приложение должно перевести число в требуемую систему. 
     * Предусмотреть случай выхода за границы диапазона, 
     * определяемого типом int, неправильный ввод.
     */


    public static void Task1()
    {
        BinaryCalcMenu();
    }

    enum BinaryCalcMenuItems
    {
        FromDecimalToBinary = 1,
        FromBinaryToDecimal = 2,
        Help = 3,
        Quit = 0
    }

    private static void BinaryCalcMenu()
    {
        const int StartMenuRange = 0;
        const int EndMenuRange = 3;

        do
        {
            Console.WriteLine("\tБинарный калькулятор\n");
            Console.WriteLine("1. Перевод числа из десятичной системы в двоичную");
            Console.WriteLine("2. Перевод числа из двоичной системы в десятичную");
            Console.WriteLine("3. Справка");
            Console.WriteLine("0. Выход");

            var choice =
                (BinaryCalcMenuItems)ReadDigitInRange(StartMenuRange, EndMenuRange);

            Console.Clear();

            try
            {
                switch (choice)
                {
                    case BinaryCalcMenuItems.FromDecimalToBinary:
                        {
                            Console.WriteLine("Введите десятичное число:\n");
                            var number = ReadInt();
                            Console.Clear();
                            Console.Write($"Число {number} в двоичной системе: ");
                            Console.WriteLine(Convert.ToString(number, 2));
                            break;
                        }
                    case BinaryCalcMenuItems.FromBinaryToDecimal:
                        {
                            Console.WriteLine("Введите двоичное число:\n");
                            var binaryNumber = ReadBinaryString();
                            Console.Clear();
                            Console.Write($"Число {binaryNumber} в десятичной системе: ");
                            Console.WriteLine(Convert.ToInt32(binaryNumber, 2));
                            break;
                        }
                    case BinaryCalcMenuItems.Help:
                        {
                            Help();
                            break;
                        }
                    case BinaryCalcMenuItems.Quit:
                        {
                            Console.WriteLine("Завершение работы программы. . .");
                            return;
                        }
                }
            }
            catch (Exception ex)
            {
                Console.Clear();
                Console.WriteLine($"Ошибка: {ex.Message}");
            }

            Console.ReadKey();
            Console.Clear();

        } while (true);
    }

    private static int ReadDigitInRange(int start, int end)
    {
        var digit = 0;

        do
        {
            Console.Write("\n=> ");
            try
            {
                digit = int.Parse(Console.ReadKey().KeyChar.ToString());
            }
            catch (Exception)
            {
                continue;
            }
        } while (digit < start || digit > end);

        return digit;
    }

    private static string ReadBinaryString()
    {
        const byte MaxSize = 11;

        Console.Write("=> ");
        var binaryNumber = Console.ReadLine();

        if (binaryNumber.Length > MaxSize)
            throw new Exception("превышенно допустимое количество разрядов двоичного числа");

        if (!IsBinaryString(binaryNumber))
            throw new Exception("введенно некорректное двоичное число");

        return binaryNumber;
    }

    private static bool IsBinaryString(string binaryNumber)
    {
        return binaryNumber.All(ch => ch == '0' || ch == '1');
    }

    private static int ReadInt()
    {
        Console.Write("=> ");
        var input = Console.ReadLine();

        if (!int.TryParse(input, out var number))
            throw new Exception("введенно некорректное десятичное число");

        return number;
    }

    private static void Help()
    {
        Console.WriteLine("\tСправка\n");
        Console.WriteLine("- Двоичное число ограничено 11-ю разрядами;");
        Console.WriteLine("- Десятичное число ограниченно значениями -2 147 483 648 и 2 147 483 647;");
    }


    /*     
     *          ЗАДАНИЕ №2
     * Пользователь вводит словами цифру от 0 до 9. 
     * Приложение должно перевести слово в цифру. 
     * Например, если пользователь ввёл five, 
     * приложение должно вывести на экран 5. 
     */

    public static void Task2()
    {
        var digits = new Dictionary<string, int>()
            {
                {"zero", 0 },
                {"one", 1 },
                {"two", 2 },
                {"three", 3 },
                {"four", 4 },
                {"five", 5 },
                {"six", 6 },
                {"seven", 7 },
                {"eight", 8 },
                {"nine", 9 }
            };

        //Console.Write("Введите словами цифру от 0 до 9 => ");
        //var input = Console.ReadLine();

        var input = "Four";

        if (!digits.TryGetValue(input.ToLower(), out var value))
            throw new Exception("некорректное значение");

        Console.WriteLine($"\nРезультат: {value}");
    }


    /*     
     *          ЗАДАНИЕ №3
     * Создайте класс «Заграничный паспорт».
     * Вам необходимо хранить информацию о номере паспорта, 
     * ФИО владельца, дате выдачи и т.д. 
     * Предусмотреть механизмы для инициализации полей класса. 
     * Если значение для инициализации неверное, генерируйте исключение.
     */

    public static void Task3()
    {
        var passport = new InternationalPassport();

        passport.Series = 12;
        passport.Number = 1234567;
        passport.Surname = "Bazuev";
        passport.Name = "Philipp";
        passport.MiddleName = "Vladimirovich";
        passport.IssueDate = DateTime.Now;
        passport.PrintData();
    }


    /*     
     *          ЗАДАНИЕ №4
     * Пользователь вводит в строку с клавиатуры логическое выражение. 
     * Например, 3>2 или 7<3. Программа должна посчитать результат 
     * введенного выражения и дать результат true или false. 
     * В строке могут быть только целые числа и операторы: 
     * <, >, <=, >=, ==, !=. 
     * Для обработки ошибок ввода используйте механизм исключений.
     */

    public static void Task4()
    {
        var operations = new Dictionary<string, Func<int, int, bool>>()
        {
            { "<=", (x, y) => x <= y },
            { ">=", (x, y) => x >= y },
            { "<", (x, y) => x < y },
            { ">", (x, y) => x > y },
            { "==", (x, y) => x == y },
            { "!=", (x, y) => x != y }
        };

        //Console.WriteLine("Введите логическое выражение.");
        //Console.WriteLine("В строке могут быть только 2 целых числа и операторы: <, >, <=, >=, ==, !=.");
        //Console.Write("=> ");
        //var input = Console.ReadLine();

        var input = "3<=2";

        var logicalOperator = new string(input
            .Where(ch => new[] { '<', '>', '=', '!' }.Contains(ch))
            .ToArray());

        var values = input
            .Split(logicalOperator.ToArray(), StringSplitOptions.RemoveEmptyEntries)
            .ToArray();

        if (!int.TryParse(values[0], out var value1))
            throw new Exception("некорректный операнд");

        if (!int.TryParse(values[1], out var value2))
            throw new Exception("некорректный операнд");

        try
        {
            Console.WriteLine($"Результат: {operations[logicalOperator](value1, value2)}");
        }
        catch(Exception)
        {
            throw new Exception("некорректная операция");
        }
    }
}

public class InternationalPassport
{
    private int series;
    private int number;
    private string surname;
    private string name;
    private string middleName;
    private DateTime issueDate;

    const byte SeriesSize = 2;
    const byte NumberSize = 7;

    public InternationalPassport()
    {
        series = 0;
        number = 0;
        surname = null;
        name = null;
        middleName = null;
        issueDate = default(DateTime);
    }

    public int Series
    {
        get
        {
            return series;
        }
        set
        {
            if (value.ToString().Length != SeriesSize)
                throw new Exception("серия паспорта должна состоять из двух цифр");

            series = value;
        }
    }

    public int Number
    {
        get
        {
            return number;
        }
        set
        {
            if (value.ToString().Length != NumberSize)
                throw new Exception("номер паспорта должен состоять из семи цифр");

            number = value;
        }
    }

    public string Surname
    {
        get
        {
            return surname;
        }
        set
        {
            if (value.Any(ch => !char.IsLetter(ch) && ch != '-'))
                throw new Exception("фамилия должна состоять только из букв. " +
                    "Двойная фамилия может содержать тире");

            surname = value;
        }
    }

    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            if (value.Any(ch => !char.IsLetter(ch)))
                throw new Exception("имя должно состоять только из букв");

            name = value;
        }
    }

    public string MiddleName
    {
        get
        {
            return middleName;
        }
        set
        {
            if (value.Any(ch => !char.IsLetter(ch)))
                throw new Exception("отчество должно состоять только из букв");

            middleName = value;
        }
    }

    public DateTime IssueDate
    {
        get
        {
            return issueDate;
        }
        set
        {
            if (value < DateTime.Today)
                throw new Exception("паспорт не может быть выдан прошедшей датой");

            issueDate = value;
        }
    }

    public void PrintData()
    {
        Console.WriteLine($"Серия:       {series}");
        Console.WriteLine($"Номер:       {number}");
        Console.WriteLine($"Фамилия:     {surname}");
        Console.WriteLine($"Имя:         {name}");
        Console.WriteLine($"Отчество:    {middleName}");
        Console.WriteLine($"Дата выдачи: {issueDate.ToLongDateString()}");
    }
}