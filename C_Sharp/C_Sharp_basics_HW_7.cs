using System;
using System.Collections.Generic;

namespace ActualHomework;

public class C_Sharp_basics_HW_7
{
    public static void Main()
    {
        Task1();
        //Task2();
        //Task3();
        //Task4();

        Console.ReadKey();
    }

    private static void Task1()
    {
        var money1 = new Money(10, 70);
        var product = new Product("Gum", money1);
        Console.WriteLine($"Product:\n{product}");

        var money2 = new Money(2, 50);
        Console.WriteLine($"Product Cost({product.Cost}) + {money2} = " +
            $"{(product += money2).Cost}");
        Console.WriteLine();
        var money3 = new Money(12, 90);
        Console.WriteLine($"Product Cost({product.Cost}) - {money3} = " +
            $"{(product -= money3).Cost}");
    }

    private static void Task2()
    {
        const string TeapotDesc = "Полое изделие (сосуд) различной формы " +
            "с крышкой, ручкой и носиком (или без),\nпредназначенное " +
            "для кипячения воды и заваривания чая";
        const string MicrowaveDesc = "Электроприбор, позволяющий совершать " +
            "разогрев водосодержащих веществ\nблагодаря электромагнитному " +
            "излучению и предназначенный для быстрого приготовления,\n" +
            "подогрева или размораживания пищи.";
        const string CarDesc = "Моторное безрельсовое дорожное и/или внедорожное, " +
            "чаще всего автономное,\nтранспортное средство, используемое для " +
            "перевозки людей и/или грузов.";
        const string SteamboatDesc = "Самоходное судно, на котором в качестве " +
            "главной энергетической установки\nиспользуется паровая машина, " +
            "приводимая в действие паром от судовых паровых котлов.";

        Console.WriteLine("\tУстройства:\n");
        List<Device> devices = new List<Device>();
        devices.Add(new Teapot("Чайник", TeapotDesc));
        devices.Add(new Microwave("Микроволновая печь", MicrowaveDesc));
        devices.Add(new Car("Автомобиль", CarDesc));
        devices.Add(new Steamboat("Пароход", SteamboatDesc));
        foreach (var device in devices)
        {
            Console.Write("Тип: ");
            device.Show();
            Console.Write("Звук: ");
            device.Sound();
            Console.WriteLine("Описание:");
            device.Desc();
            Console.WriteLine();
        }
    }

    private static void Task3()
    {
        const string ViolinAndVioloncelloDesc = 
            "Четырехструнный смычковый музыкальный инструмент";
        const string TrambonDesc = 
            "Медный духовой музыкальный инструмент";
        const string UkuleleDesk = 
            "Четырехструнный щипковый музыкальный инструмент";

        Console.WriteLine("\tМузыкальные инструменты:\n");
        List<MusicalInstrument> instruments = 
            new List<MusicalInstrument>();
        instruments.Add(new Violin("Скрипка", ViolinAndVioloncelloDesc));
        instruments.Add(new Trambon("Тромбон", TrambonDesc));
        instruments.Add(new Ukulele("Укулеле", UkuleleDesk));
        instruments.Add(new Violoncello("Виолончель", ViolinAndVioloncelloDesc));
        foreach (var instrument in instruments)
        {
            Console.Write("Тип: ");
            instrument.Show();
            Console.Write("Звук: ");
            instrument.Sound();
            Console.Write("Описание: ");
            instrument.Desc();
            Console.WriteLine("История:");
            instrument.History();
            Console.WriteLine();
        }
    }

    private static void Task4()
    {
        Console.WriteLine("Должности:\n");
        List<Worker> workers = new List<Worker>();
        workers.Add(new President());
        workers.Add(new Security());
        workers.Add(new Manager());
        workers.Add(new Engineer());
        foreach (var worker in workers)
            worker.Print();
    }
}

/*     
*          ЗАДАНИЕ №1
* Запрограммируйте класс Money (объект класса оперирует одной валютой) 
* для работы с деньгами. В классе должны быть предусмотрены 
* поле для хранения целой части денег(доллары, евро,гривны и т.д.) и 
* поле для хранения копеек (центы, евроценты, копейки и т.д.). 
* Реализовать методы для вывода суммы на экран, задания значений для частей. 
* На базе класса Money создать класс Product для работы с продуктом или товаром. 
* Реализовать метод, позволяющий уменьшить цену на заданное число. 
* Для каждого из классов реализовать необходимые методы и поля.
*/

public class Money
{
    private int rubles;
    private int kopecks;
    private const int KopecksInRuble = 100;

    public Money() : this(0, 0) { }

    public Money(int ruble, int kopeck)
    {
        Rubles = ruble;
        Kopecks = kopeck;
    }

    public int Rubles
    {
        get => rubles;

        set
        {
            if (value < 0)
            {
                rubles = 0;
                return;
            }

            rubles = value;
        }
    }

    public int Kopecks
    {
        get => kopecks;

        set
        {
            if (value < 0)
            {
                kopecks = 0;
                return;
            }

            kopecks = value % KopecksInRuble;
            rubles += value / KopecksInRuble;
        }
    }

    public override string ToString()
    {
        return $"{rubles}rub. {kopecks}kop.";
    }
}

public class Product
{
    public Money Cost { get; set; }
    public string Name { get; set; }

    public Product(string name, Money cost)
    {
        Name = name;
        Cost = cost;
    }

    public static Product operator +(Product product, Money amount)
    {
        return new Product(
            product.Name,
            new Money(
                product.Cost.Rubles + amount.Rubles, 
                product.Cost.Kopecks + amount.Kopecks));
    }

    public static Product operator +(Money amount, Product product)
    {
        return new Product(
            product.Name,
            new Money(
                product.Cost.Rubles + amount.Rubles, 
                product.Cost.Kopecks + amount.Kopecks));
    }

    public static Product operator -(Product product, Money amount)
    {
        const int KopecksInRuble = 100;
        int rubles = 0;
        int kopecks = 0;

        if (product.Cost.Kopecks < amount.Kopecks)
        {
            rubles = product.Cost.Rubles - amount.Rubles - 1;
            kopecks = rubles < 0 
                ? 0 
                : KopecksInRuble - (amount.Kopecks - product.Cost.Kopecks);

            return new Product(product.Name, new Money(rubles, kopecks));
        }

        rubles = product.Cost.Rubles - amount.Rubles;
        kopecks = rubles < 0 ? 0 : product.Cost.Kopecks - amount.Kopecks;
        return new Product(product.Name, new Money(rubles, kopecks));
    }

    public override string ToString()
    {
        return $"Name: {Name}\nCost: {Cost}\n";
    }
}

/*     
*          ЗАДАНИЕ №2
* Создать базовый класс «Устройство» и производные классы 
* «Чайник», «Микроволновка», «Автомобиль», «Пароход». 
* С помощью конструктора установить имя каждого устройства и 
* его характеристики. Реализуйте для каждого из классов методы: 
* - Sound — издает звук устройства (пишем текстом в консоль);
* - Show — отображает название устройства;
* - Desc — отображает описание устройства.
*/

public abstract class Device
{
    abstract public void Sound();
    abstract public void Show();
    abstract public void Desc();
}

public class Teapot : Device
{
    private string title;
    private string description;

    public Teapot(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук работы чайника\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }
}

public class Microwave : Device
{
    private string title;
    private string description;

    public Microwave(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук работы микроволновой печи\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }
}

public class Car : Device
{
    private string title;
    private string description;

    public Car(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук работы автомобильной системы\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }
}

public class Steamboat : Device
{
    private string title;
    private string description;

    public Steamboat(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук работы пароходной системы\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }
}

/*     
*          ЗАДАНИЕ №3
* Создать базовый класс «Музыкальный инструмент» и 
* производные классы «Скрипка», «Тромбон», «Укулеле», «Виолончель». 
* С помощью конструктора установить имя каждого музыкального инструмента 
* и его характеристики. Реализуйте для каждого из классов методы: 
* - Sound — издает звук музыкального инструмента (пишем текстом в консоль); 
* - Show — отображает название музыкального инструмента; 
* - Desc — отображает описание музыкального инструмента; 
* - History — отображает историю создания музыкального инструмента.
*/

public abstract class MusicalInstrument
{
    abstract public void Sound();
    abstract public void Show();
    abstract public void Desc();
    abstract public void History();
}

public class Violin : MusicalInstrument
{
    private string title;
    private string description;

    public Violin(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук игры на скрипке\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }

    public override void History()
    {
        Console.WriteLine("Первые упоминания о скрипке " +
            "датируются началом 16 века в Италии.");
    }
}

public class Trambon : MusicalInstrument
{
    private string title;
    private string description;

    public Trambon(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук игры на тромбоне\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }

    public override void History()
    {
        Console.WriteLine("Тромбон появился в 15 веке,");
        Console.WriteLine("но само название \"тромбон\" " +
            "появилось немного позже - в 17 веке.");
        Console.WriteLine("Первоначально инструмент называли сакбут.");
    }
}

public class Ukulele : MusicalInstrument
{
    private string title;
    private string description;

    public Ukulele(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук игры на укулеле\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }

    public override void History()
    {
        Console.WriteLine("Укулеле появилась на Гавайских островах " +
            "во второй половине 19 века.");
        Console.WriteLine("Там её под названием машети да браса " +
            "завезли португальцы с острова Майдера.");
    }
}

public class Violoncello : MusicalInstrument
{
    private string title;
    private string description;

    public Violoncello(string title, string description)
    {
        this.title = title;
        this.description = description;
    }

    public override void Sound()
    {
        Console.WriteLine("\"Звук игры на виолончели\"");
    }

    public override void Show()
    {
        Console.WriteLine(title);
    }

    public override void Desc()
    {
        Console.WriteLine(description);
    }

    public override void History()
    {
        Console.WriteLine("Первое упоминание о виолончели " +
            "датируются началом 16 века.");
    }
}

/*     
*          ЗАДАНИЕ №4
* Создать абстрактный базовый класс Worker (работник) 
* с методом Print(). Создайте четыре производных класса: 
* President, Security, Manager, Engineer. 
* Переопределите метод Print() для вывода информации, 
* соответствующей каждому типу работника.
*/

public abstract class Worker
{
    abstract public void Print();
}

public class President : Worker
{
    public override void Print()
    {
        Console.WriteLine("Президент");
    }
}

public class Security : Worker
{
    public override void Print()
    {
        Console.WriteLine("Секьюрити");
    }
}

public class Manager : Worker
{
    public override void Print()
    {
        Console.WriteLine("Менеджер");
    }
}

public class Engineer : Worker
{
    public override void Print()
    {
        Console.WriteLine("Инженер");
    }
}