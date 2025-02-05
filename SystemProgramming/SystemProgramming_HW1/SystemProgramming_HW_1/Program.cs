using System;
using System.Collections.Generic;
using System.Threading;
using SystemProgramming_HW_1.Helpers;

namespace SystemProgramming_HW_1;

public static class Program
{
    public static void Main()
    {
        Task1();
        //Task2();
        //Task3();

        Console.WriteLine();
        Console.WriteLine("Нажмите любую клавишу...");
        Console.ReadKey();
    }

    /*      Задание №1
     *
     * Разработайте приложение,которое использует унаследованный код. 
     * Вам необходимо использовать функцию MessageBox из Windows API. 
     * Отобразите с помощью MessageBox информацию о вас. 
     * Данные должны быть показаны в нескольких MessageBox. 
     * 
     */

    public static void Task1()
    {
        WinApi.MessageBox(IntPtr.Zero, "Bazuev Philipp Vladimirovich", "Full name", 0);
        WinApi.MessageBox(IntPtr.Zero, "03.02.1993", "Date of birth", 0);
        WinApi.MessageBox(IntPtr.Zero, "Russian", "Nationality", 0);
    }

    /*      Задание №2
     *
     * Разработайте приложение, которое использует унаследованный код. 
     * Вам необходимо использовать функции FindWindow (поиск окна в системе), SendMessage (отсылка сообщений) из WindowsAPI. 
     * Приложение должно произвести поиск окна вашего оконного приложения (можно реализовать его с помощью Windows Forms и т.д.). 
     * Если окно найдено необходимо послать ему сообщение в зависимости от выбора пользователя:
     * - об изменении заголовка окна на заголовок, введенный  пользователем о закрытии окна; 
     * - ваш вариант.
     * 
     */

    public static void Task2()
    {
        var window = WinApi.FindWindow("notepad", null);

        if (window == 0)
        {
            Console.WriteLine("Окно не найдено!");
            return;
        }

        List<string> commands = new List<string>
        {
            "Изменить заголовок окна на введенный",
            "Изменить заголовок окна на текущую дату",
            "Завершить дочерний и текущий процессы"
        };

        while (true)
        {
            ConsoleMenuHelper.PrintCommands(commands, "Выход");

            var selector = ConsoleReadHelper.ReadInt(" => ", 0, commands.Count);

            switch (selector)
            {
                case 0:
                    return;
                case 1:
                    Console.WriteLine();
                    Console.Write("Введите новый заголовок => ");
                    WinApi.SendMessage(window, WinApi.WM_SETTEXT, 0, Console.ReadLine());
                    break;
                case 2:
                    WinApi.SendMessage(window, WinApi.WM_SETTEXT, 0, DateTime.Now.ToLongTimeString());
                    break;
                case 3:
                    WinApi.SendMessage(window, WinApi.WM_CLOSE, 0, null);
                    return;
            }

            Console.WriteLine();
            Console.WriteLine("Нажмите любую клавишу...");
            Console.ReadKey();
            Console.Clear();
        }
    }

    /*      Задание №3
     *
     * Разработайте приложение, которое использует унаследованный код. 
     * Вам необходимо использовать функции Beep и MessageBeep из Windows API.
     * С помощью импортированных функций сгенерируйте набор звуковых сигналов через определенные промежутки времени.
     * 
     */

    public static void Task3()
    {
        var beepQuantity = 5;

        for (var i = 0; i < beepQuantity; i++)
        {
            WinApi.Beep(1000, 500);
            Thread.Sleep(500);

            WinApi.MessageBeep(0);
            Thread.Sleep(1000);
        }
    }
}