using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;

namespace HomeworkCSharp;

public class C_Sharp_basics_HW_10
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
     *          Встреча №9 (Задание №1 (Программа «Logger»))
     *          
     * Общие сведения
     * - Файл регистрации, протокол, журнал и лог (анг. log) - 
     *   специальный файл с записями о действиях пользователя программы
     *   (работы программы) в хронологическом порядке.
     * - Файл конфигурации или ini-файл (анг. Initialization file) -
     *   специальный файл, который содержит данные настроек для 
     *   Microsoft Windows или приложений.
     *   
     * Реализовать программный модуль (класс Logger), позволяющий записывать 
     * информацию о работе программы в log-файл. Каждая запись информации в
     * log-файл должна содержать следующие поля: дата и время, тип сообщения 
     * (ошибка, exception, тестовое сообщение, информационное сообщение,
     * предупреждение), имя текущего пользователя, текст сообщения.
     * При этом должна быть реализована настройка данного класса. 
     * В данной настройке указывается маска записи информации в log-файл
     * т.е. порядок информации в записи и наличие указанных полей.
     * Настройка считывается из файла конфигурации (ini-файла).
    */

    private static void Task1()
    {
        var configFilePath = Directory.GetCurrentDirectory() + "\\Config.ini";
        var logFilePath = Directory.GetCurrentDirectory() + "\\Logs.log";

        var logger = new Logger(configFilePath, logFilePath);

        logger.ConsoleLogWrite += LogBeenWrittenShow;

        for (var i = 0; i < Enum.GetNames(typeof(LogType)).Length; i++)
            logger.Log((LogType)i, $"Message{i + 1}");
    }

    private static void LogBeenWrittenShow(object obj, EventArgs eventArgs)
    {
        Console.WriteLine($"Log was written to file: {obj.GetType()
            ?.GetField(
                "logFilePath",
                BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic)
            ?.GetValue(obj)}");
    }

    /*     
     *          Встреча №10 (Задание №2) и Встреча №11 (Задание №2)
     *          
     * С помощью класса XmlTextWriter (или подобных инструментов)
     * напишите приложение, сохраняющее в xml-файл информацию о заказах.
     * Каждый заказ представляет собой несколько товаров. 
     * Информацию, характеризующую заказы и товары разработать самостоятельно.
     * 
     *          Встреча №11 (Задание №4)
     *          
     * Прочитайте XML-документ, полученный в задании 2 с помощью
     * классов XmlDocument и XmlTextReader (или подобных инструментов)
     * и выведете полученную информацию на экран.
    */

    private static void Task2()
    {
        var xmlFilePath = Directory.GetCurrentDirectory() + "\\Orders.txt";

        IOrdersXmlSerializer serializer = new OrdersXmlSerializer();
        var dividingLine = new string('-', Constants.DividingLineLength);

        var orders = new List<Order> { new(1), new(2), new(3) };

        for (var i = 0; i < orders.Count; i++)
            for (var j = 0; j < Constants.ProductsNumber; j++)
                orders[i].AddProduct(
                    new Product(j + 1, $"product{j + 1}", $"description{j + 1}"));

        serializer.Serialize(orders, xmlFilePath);
        var ordersFromXml = serializer.Deserialize(xmlFilePath);

        Console.WriteLine("Результат десериализации:\n");
        Console.WriteLine($"{dividingLine}\n");

        foreach (var order in ordersFromXml)
        {
            Console.WriteLine("\tOrder:");
            Console.Write($"{order.ToString()}");
            Console.WriteLine($"{dividingLine}\n");
        }
    }
}