using System;
using System.Linq;
using System.Text;

namespace ActualHomework;

public class Program
{
    public static void Main()
    {
        //Task1();
        //Task2();
        //Task3();

        Console.ReadKey();
    }

    /*     
     *          ЗАДАНИЕ №1
     * Напишите метод, который отображает квадрат из некоторого символа. 
     * Метод принимает в качестве параметра: длину стороны квадрата, символ.
     */

    public static void Task1()
    {
        const int Size = 5;
        const char Symbol = '*';

        Console.WriteLine($"Квадрат {Size} на {Size} состоящий из символа {Symbol}:\r\n");
        PrintSquare(Size, Symbol);
    }

    private static void PrintSquare(int size, char symbol)
    {
        const int HorizontalFacesNumber = 2;

        if (size <= 0)
            return;

        if (size == 1)
        {
            Console.WriteLine(symbol);
            return;
        }

        var stringBuilder = new StringBuilder();

        stringBuilder.Append(symbol, size);
        stringBuilder.Append("\r\n");

        for (int i = 0; i < size - HorizontalFacesNumber; i++)
        {
            stringBuilder.Append(symbol);
            stringBuilder.Append(' ', size - HorizontalFacesNumber);
            stringBuilder.Append(symbol);
            stringBuilder.Append("\r\n");
        }

        Console.WriteLine(stringBuilder.Append(symbol, size).ToString());
    }

    /*     
     *          ЗАДАНИЕ №2
     * Напишите метод, который проверяет является ли переданное число «палиндромом». 
     * Число передаётся в качестве параметра. 
     * Если число палиндром нужно вернуть из метода true, иначе false. 
     * Палиндром — число, которое читается одинаково как справа налево, так и слева направо.
     * Например: 
     * 1221 — палиндром; 
     * 3443 — палиндром; 
     * 7854 — не палиндром.
     */

    public static void Task2()
    {
        int[] values = { 1221, 34443, 7878 };

        foreach (var value in values)
            if (IsPalindrome(value))
                Console.WriteLine($"{value} - палиндром");
            else
                Console.WriteLine($"{value} - не палиндром");
    }

    private static bool IsPalindrome(int value)
    {
        var strValue = value.ToString();

        if (strValue.Take(strValue.Length / 2).ToArray().SequenceEqual(
            strValue.Reverse().Take(strValue.Length / 2).ToArray()))
            return true;
        else
            return false;
    }

    /*     
     *          ЗАДАНИЕ №3
     * Напишите метод, фильтрующий массив на основании переданных параметров. 
     * Метод принимает параметры:
     * оригинальный_массив, 
     * массив_с_данными_для_фильтрации.
     * Метод возвращает оригинальный массив без элементов, которые есть в массиве для фильтрации. 
     * Например: 
     * 1 2 6 -1 88 7 6 — оригинальный массив; 
     * 6 88 7 — массив для фильтрации; 
     * 1 2 -1 — результат работы метода.
     */

    public static void Task3()
    {
        int[] originalArray = { 1, 2, 6, -1, 88, 7, 6 };
        int[] arrayForFiltering = { 6, 88, 7, 9 };

        Console.WriteLine($"{string.Join(" ", originalArray)} - оригинальный массив.");
        Console.WriteLine($"{string.Join(" ", arrayForFiltering)} - массив для фильтрации.");
        Console.WriteLine($"{string.Join(" ", ArrayFilter(originalArray, arrayForFiltering))} - результат работы метода.");
    }

    private static int[] ArrayFilter(int[] originalArray, int[] arrayForFiltering)
    {
        return originalArray.Where(x => !arrayForFiltering.Contains(x)).ToArray();
    }
}

/*     
*          ЗАДАНИЕ №4
* Создайте класс «Веб-сайт». 
* Необходимо хранить в полях класса: 
* название сайта, путь к сайту, описание сайта, ip адрес сайта. 
* Реализуйте методы класса для ввода данных, вывода данных, 
* реализуйте доступ к отдельным полям через методы класса. 
*/

public class Website
{
    public string Name { get; set; }
    public string URL { get; set; }
    public string Description { get; set; }
    public string IP { get; set; }

    public void ReadData()
    {
        Console.Write("Enter website name => ");
        Name = Console.ReadLine();

        Console.Write("Enter website URL => ");
        URL = Console.ReadLine();

        Console.Write("Enter website description => ");
        Description = Console.ReadLine();

        Console.Write("Enter website IP address => ");
        IP = Console.ReadLine();
    }

    public void WriteData()
    {
        Console.WriteLine($"Website name: {Name}");
        Console.WriteLine($"Website URL: {URL}");
        Console.WriteLine($"Website description: {Description}");
        Console.WriteLine($"Website IP address: {IP}");
    }
}

/*     
*          ЗАДАНИЕ №5
* Создайте класс «Журнал». 
* Необходимо хранить в полях класса: 
* название журнала, год основания, описание журнала, 
* контактный телефон, контактный e-mail. 
* Реализуйте методы класса для ввода данных,
* вывода данных, реализуйте доступ к отдельным полям через методы класса. 
*/

public class Journal
{
    public string Name { get; set; }
    public int FoundationYear  { get; set; }
    public string Description { get; set; }
    public int Phone { get; set; }
    public string EMail { get; set; }

    public void ReadData()
    {
        Console.Write("Enter journal name => ");
        Name = Console.ReadLine();

        Console.Write("Enter journal foundation year => ");
        try
        {
            FoundationYear = int.Parse(Console.ReadLine());
        }
        catch (Exception) { }

        Console.Write("Enter journal description => ");
        Description = Console.ReadLine();

        Console.Write("Enter contact phone => ");
        try
        {
            Phone = int.Parse(Console.ReadLine());
        }
        catch (Exception) { }

        Console.Write("Enter contact e-mail => ");
        EMail = Console.ReadLine();
    }

    public void WriteData()
    {
        Console.WriteLine($"Journal name: {Name}");
        Console.WriteLine($"Journal foundation year: {FoundationYear}");
        Console.WriteLine($"Journal description: {Description}");
        Console.WriteLine($"Contact phone: {Phone}");
        Console.WriteLine($"Contact e-mail: {EMail}");
    }
}

/*     
*          ЗАДАНИЕ №6
* Создайте класс «Магазин». 
* Необходимо хранить в полях класса: 
* название магазина, адрес, описание профиля магазина, 
* контактный телефон, контактный e-mail. 
* Реализуйте методы класса для ввода данных, вывода данных, 
* реализуйте доступ к отдельным полям через методы класса. 
*/

public class Store
{
    public string Name { get; set; }
    public string Address { get; set; }
    public string Description { get; set; }
    public int Phone { get; set; }
    public string EMail { get; set; }

    public void ReadData()
    {
        Console.Write("Enter store name => ");
        Name = Console.ReadLine();

        Console.Write("Enter store address => ");
        Address = Console.ReadLine();

        Console.Write("Enter store description => ");
        Description = Console.ReadLine();

        Console.Write("Enter contact phone => ");
        try
        {
            Phone = int.Parse(Console.ReadLine());
        }
        catch (Exception) { }

        Console.Write("Enter contact e-mail => ");
        EMail = Console.ReadLine();
    }

    public void WriteData()
    {
        Console.WriteLine($"Store name: {Name}");
        Console.WriteLine($"Store address: {Address}");
        Console.WriteLine($"Store description: {Description}");
        Console.WriteLine($"Contact phone: {Phone}");
        Console.WriteLine($"Contact e-mail: {EMail}");
    }
}