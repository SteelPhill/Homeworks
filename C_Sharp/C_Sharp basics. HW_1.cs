using System;

namespace ActualHomework;

public class ConsoleReadNumber
{
    public int ReadInt()
    {
        if (!int.TryParse(Console.ReadLine(), out var number))
            throw new Exception("Введено некорректное число!");

        return number;
    }

    public decimal ReadDecimal()
    {
        if (!decimal.TryParse(Console.ReadLine(), out var number))
            throw new Exception("Введено некорректное число!");

        return number;
    }
}

public class ConsoleReadDigit
{
    public int Read()
    {
        int digit = Console.ReadKey().KeyChar - '0';

        if (digit < 0 || digit > 9)
            throw new Exception("Введенный символ не является цифрой!");

        return digit;
    }
}


//          ЗАДАНИЕ №1

/*
 * Пользователь вводит с клавиатуры число в диапазоне от 1 до 100.
 * Если число кратно 3 (делится на 3 без остатка) нужно вывести слово Fizz.
 * Если число кратно 5 нужно вывести слово Buzz. 
 * Если число кратно 3 и 5 нужно вывести Fizz Buzz.
 * Если число не кратно не 3 и 5 нужно вывести само число. 
 * Если пользователь ввел значение не в диапазоне от 1 до 100 
 * требуется вывести сообщение об ошибке.
 */

//public class Task1
//{
//    public static void Main()
//    {
//        const int BeginRange = 1;
//        const int EndRange = 100;

//        var consoleReadNumber = new ConsoleReadNumber();

//        try
//        {
//            Console.Write($"Введите число в диапазоне от {BeginRange} до {EndRange} и нажмите Enter => ");
//            var value = consoleReadNumber.ReadInt();
//            if (value < BeginRange || value > EndRange)
//                throw new Exception("Введенное число не входит в указанный диапазон!");

//            Console.WriteLine();

//            Console.Write("\tРезультат: ");

//            if (value % 3 == 0)
//                Console.Write("Fizz ");

//            if (value % 5 == 0)
//                Console.Write("Buzz");

//            if (value % 3 != 0 && value % 5 != 0)
//                Console.Write(value);
//        }
//        catch (Exception message)
//        {
//            Console.Write($"\nError: {message.Message}");
//        }

//        Console.WriteLine();

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}


//          ЗАДАНИЕ №2

/*
 * Пользователь вводит с клавиатуры два числа. 
 * Первое число — это значение, второе число процент,
 * который необходимо посчитать.
 * Например, мы ввели с клавиатуры 90 и 10. 
 * Требуется вывести на экран 10 процентов от 90. 
 * Результат: 9.
 */

//public class Task2
//{
//    public static void Main()
//    {
//        const decimal Multiplier = 0.01M;

//        var consoleReadNumber = new ConsoleReadNumber();

//        try
//        {
//            Console.Write("Введите число и нажмите Enter => ");
//            var value = consoleReadNumber.ReadDecimal();

//            Console.Write("Введите процент нажмите Enter => ");
//            var percent = consoleReadNumber.ReadDecimal();

//            Console.WriteLine();

//            decimal result = value * (percent * Multiplier);

//            Console.WriteLine($"{percent} процент(-а,-ов) от числа {value} = {result:0.##}");
//        }
//        catch (Exception message)
//        {
//            Console.WriteLine($"\nError: {message.Message}");
//        }

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}


//          ЗАДАНИЕ №3

/*
 * Пользователь вводит с клавиатуры четыре цифры.
 * Необходимо создать число, содержащее эти цифры. 
 * Например, если с клавиатуры введено 1, 5, 7, 8 
 * тогда нужно сформировать число 1578.
 */

//public class Task3
//{
//    public static void Main()
//    {
//        const int DigitsInNumber = 4;
//        const int Multiplier = 10;

//        var consoleReadDigit = new ConsoleReadDigit();

//        try
//        {
//            int result = 0;
//            int inputDigit;

//            for (int i = 1; i <= DigitsInNumber; i++)
//            {
//                Console.Write($"Введите {i}-ую цифру => ");
//                inputDigit = consoleReadDigit.Read();

//                Console.WriteLine();

//                result += inputDigit;

//                if (i == DigitsInNumber)
//                    break;

//                result *= Multiplier;
//            }

//            Console.WriteLine($"\n\tРезультат: {result}");
//        }
//        catch (Exception message)
//        {
//            Console.WriteLine($"\n\nError: {message.Message}");
//        }

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}


//          ЗАДАНИЕ №4

/*
 * Пользователь вводит шестизначное число.
 * После чего пользователь вводит номера разрядов для обмена цифр.
 * Например, если пользователь ввёл один и шесть — это значит,
 * что надо обменять местами первую и шестую цифры.
 * Число 723895 должно превратиться в 523897.
 * Если пользователь ввел не шестизначное число требуется вывести сообщение об ошибке.
 */

//public class Task4
//{
//    public static void Main()
//    {
//        const int NumberSize = 6;

//        var consoleReadNumber = new ConsoleReadNumber();
//        var consoleReadDigit = new ConsoleReadDigit();

//        try
//        {
//            Console.Write("Введите шестизначное целое число и нажмите Enter => ");
//            string inputStr = consoleReadNumber.ReadInt().ToString();
//            if (inputStr.Length != NumberSize)
//                throw new Exception("Введено некорректное число!");
//            Console.WriteLine();

//            Console.Write("Введите позицию первого разряда => ");
//            int firstBit = consoleReadDigit.Read();
//            Console.WriteLine();
//            if (firstBit < 1 || firstBit > 6)
//                throw new Exception("Введен некорректный разряд!");

//            Console.Write("Введите позицию второго разряда => ");
//            int secondBit = consoleReadDigit.Read();
//            Console.WriteLine();
//            if (secondBit < 1 || secondBit > 6)
//                throw new Exception("Введен некорректный разряд!");

//            char[] inputStrInChars = inputStr.ToCharArray();

//            (inputStrInChars[firstBit - 1], inputStrInChars[secondBit - 1]) =
//                (inputStrInChars[secondBit - 1], inputStrInChars[firstBit - 1]);

//            int result = int.Parse(new string(inputStrInChars));

//            Console.WriteLine($"\n\tРезультат: {result}");
//        }
//        catch (Exception message)
//        {
//            Console.WriteLine($"\nError: {message.Message}");
//        }

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}


//          ЗАДАНИЕ №5

/*
 * Пользователь вводит с клавиатуры дату.
 * Приложение должно отобразить название сезона и дня недели.
 * Например, если введено 22.12.2021, 
 * приложение должно отобразить Winter Wednesday.
 */

//enum Months
//{
//    January = 1,
//    February = 2,
//    March = 3,
//    April = 4,
//    May = 5,
//    June = 6,
//    July = 7,
//    August = 8,
//    September = 9,
//    October = 10,
//    November = 11,
//    December = 12
//}

//public class Task5
//{
//    public static void Main()
//    {
//        try
//        {
//            Console.Write("Введите дату и нажмите Enter => ");
//            string inputStr = Console.ReadLine();
//            Console.WriteLine();
//            if (!DateTime.TryParse(inputStr, out var date))
//                throw new Exception("Введена некорректная дата!");

//            switch ((Months)date.Month)
//            {
//                case Months.March:
//                case Months.April:
//                case Months.May:
//                    Console.Write("\tSpring");
//                    break;
//                case Months.June:
//                case Months.July:
//                case Months.August:
//                    Console.Write("\tSummer");
//                    break;
//                case Months.September:
//                case Months.October:
//                case Months.November:
//                    Console.Write("\tAutumn");
//                    break;
//                case Months.December:
//                case Months.January:
//                case Months.February:
//                    Console.Write("\tWinter");
//                    break;
//            }

//            Console.WriteLine($" {date.DayOfWeek.ToString()}");
//        }
//        catch (Exception message)
//        {
//            Console.WriteLine($"Error: {message.Message}");
//        }

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}


//          ЗАДАНИЕ №6

/*
 * Пользователь вводит с клавиатуры показания температуры. 
 * В зависимости от выбора пользователя программа переводит 
 * температуру из Фаренгейта в Цельсий или наоборот.
 */

//public class Task6
//{
//    public static void Main()
//    {
//        var consoleReadNumber = new ConsoleReadNumber();
//        var consoleReadDigit = new ConsoleReadDigit();

//        try
//        {
//            Console.WriteLine("Выберите единицы измерения температуры:");
//            Console.WriteLine("1.Цельсия");
//            Console.WriteLine("2.Фаренгейта");
//            Console.Write("=> ");
//            int measUnit = consoleReadDigit.Read();
//            Console.WriteLine();
//            if (measUnit != 1 && measUnit != 2)
//                throw new Exception("Введен некорректный символ!");

//            Console.Write("\nВведите температуру и нажмите Enter => ");
//            var degrees = consoleReadNumber.ReadDecimal();
//            Console.WriteLine();

//            if (measUnit == 1)
//                Console.WriteLine($"\t{degrees}°C = {degrees * 9 / 5 + 32:0.##}°F");
//            else
//                Console.WriteLine($"\t{degrees}°F = {5 * (degrees - 32) / 9:0.##}°C");
//        }
//        catch (Exception message)
//        {
//            Console.WriteLine($"\nError: {message.Message}");
//        }

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}


//          ЗАДАНИЕ №7

/*
 * Пользователь вводит с клавиатуры два числа.
 * Нужно показать все четные числа в указанном диапазоне.
 * Если границы диапазона указаны неправильно требуется произвести нормализацию границ.
 * Например, пользователь ввел 20 и 11, требуется нормализация,
 * после которой начало диапазона станет равно 11, а конец 20.
 */

//public class Task7
//{
//    public static void Main()
//    {
//        var consoleReadNumber = new ConsoleReadNumber();

//        try
//        {
//            Console.Write("Введите первое целое число и нажмите Enter => ");
//            var firstNumber = consoleReadNumber.ReadInt();

//            Console.Write("Введите второе целое число и нажмите Enter => ");
//            var secondNumber = consoleReadNumber.ReadInt();

//            Console.WriteLine();

//            if (firstNumber > secondNumber)
//                (firstNumber, secondNumber) = (secondNumber, firstNumber);

//            Console.WriteLine($"Чётные числа в диапазоне от {firstNumber} до {secondNumber}:\n");

//            for (int i = firstNumber; i <= secondNumber; i++)
//                if (i % 2 == 0)
//                    Console.Write($"{i} ");

//            Console.WriteLine();
//        }
//        catch (Exception message)
//        {
//            Console.WriteLine($"\nError: {message.Message}");
//        }

//        Console.Write("\nНажмите любую клавишу для завершения программы . . .");
//        Console.ReadKey();
//    }
//}