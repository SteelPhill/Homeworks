using System;
using System.Collections.Generic;

namespace HomeworkCSharp;

public class C_Sharp_basics_HW_11
{
    public static void Main()
    {
        try
        {
            Task1();
            //Task2();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }

        Console.WriteLine("\nНажмите любую клавишу...");
        Console.ReadKey();
    }

    /*     
     *          Встреча №12 (Задание №1 (Программа «Атрибут [ParamsAttribute]»))
     *          
     * Создать атрибут, который должен быть применен только к свойствам класса.
     * Данный атрибут должен предписывать свойству класса брать значение
     * из указанного ini-файла. Имя ini-файла, из которого требуется брать значение
     * для свойства, указывается через параметр атрибута. 
     * Требование: для работы программы создать 3–4 ini-файла, 
     * в которых должны храниться значения для свойств. 
    */

    private static void Task1()
    {
        IPersonPropertySetter propertySetter = new PersonPropertySetter();
        var person = new Person();
        var type = typeof(Person);

        propertySetter.Set(type.GetProperty("Name"), out string name);
        person.Name = name;

        propertySetter.Set(type.GetProperty("Age"), out int age);
        person.Age = age;

        propertySetter.Set(type.GetProperty("Height"), out int height);
        person.Height = height;

        propertySetter.Set(type.GetProperty("Weight"), out int weight);
        person.Weight = weight;

        Console.WriteLine($"Name:\t{person.Name}");
        Console.WriteLine($"Age:\t{person.Age}");
        Console.WriteLine($"Height:\t{person.Height}");
        Console.WriteLine($"Weight:\t{person.Weight}");
    }

    /*     
     *          Встреча №12 (Задание №2 (Программа «Пользовательский атрибут»)
     *          
     * Придумать пользовательский атрибут (самостоятельно). 
     * Данный атрибут должен выполнять прикладную задачу (а не демонстрационную).
     * Проверить его функциональность.
    */

    private static void Task2()
    {
        IPersonValidator personValidator = new PersonValidator();

        var person1 = new Person();
        person1.Name = "Петя";
        person1.Age = 17;

        var person2 = new Person();
        person2.Name = "Коля";
        person2.Age = 18;

        var person3 = new Person();
        person3.Name = "Саша";
        person3.Age = 30;

        var persons = new List<Person>() { person1, person2, person3 };

        Console.WriteLine(
            $"Ограничение по возрасту - от 18 лет{Environment.NewLine}");

        foreach (var person in persons)
        {
            Console.WriteLine($"Имя:\t {person.Name}");
            Console.WriteLine($"Возраст: {person.Age}");

            if (personValidator.AgeValidate(person))
                Console.WriteLine("Доступ:  разрешён");
            else
                Console.WriteLine("Доступ:  закрыт");

            Console.WriteLine();
        }
    }
}