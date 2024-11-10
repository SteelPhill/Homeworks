﻿using System;

namespace HomeworkCSharp;

public class C_Sharp_basics_HW_9
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
    }

    /*     
     *          Встреча №7 (ЗАДАНИЕ №1 (Игра «Автомобильные гонки»))
     *          
     * Разработать игру "Автомобильные гонки" с использованием делегатов.
     * 1. В игре использовать несколько типов автомобилей: 
     *    спортивные, легковые, грузовые и автобусы.
     * 2. Принцип игры: Автомобили двигаются от старта к финишу со скоростями, 
     *    которые изменяются в установленных пределах случайным образом. 
     *    Победителем считается автомобиль, пришедший к финишу первым.
     *    
     * Рекомендации по выполнению работы: 
     * 1. Разработать абстрактный класс «автомобиль» (классCar). 
     *       Собрать в нем все общие поля, свойства (например, скорость)
     *       методы (например, ехать).
     * 2. Разработать классы автомобилей с конкретной реализацией конструкторов
     *    и методов, свойств. В классы автомобилей добавить необходимые события
     *    (например, финиш). 
     * 3. Класс игры должен производить запуск соревнований автомобилей, 
     *    выводить сообщения о текущем положении автомобилей, 
     *    выводить сообщение об автомобиле, победившем в гонках.
     *    Создать делегаты, обеспечивающие вызов методов из классов автомобилей
     *    (например, выйти на старт, начать гонку). 
     * 4. Игра заканчивается, когда какой-то из автомобилей проехал определенное
     *    расстояние (старт в положении 0, финиш в положении 100). 
     *    Уведомление об окончании гонки (прибытии какого-либо автомобиля на финиш)
     *    реализовать с помощью событий.)
    */

    private static void Task1()
    {
        IMenu mainMenu = new ConsoleMenu(Constants.RaceTitle);

        mainMenu.AddCommand(new StartRaceCommand());

        mainMenu.Start();
    }

    /*     
     *          Встреча №8 (ЗАДАНИЕ №1 (Программа «Карточная игра!»))
     *          
     * Создать модель карточной игры. 
     * Требования: 
     * 1. Класс Game формирует и обеспечивает: 
     * 1.1.1. Список игроков (минимум 2); 
     * 1.1.2. Колоду карт (36 карт); 
     * 1.1.3. Перетасовку карт (случайным образом); 
     * 1.1.4. Раздачу карт игрокам(равными частями каждому игроку); 
     * 1.1.5. Игровой процесс. Принцип: Игроки кладут по одной карте. 
     *        У кого карта больше, то тот игрок забирает все карты 
     *        и кладет их в конец своей колоды. Упрощение: 
     *        при совпадении карт забирает первый игрок, шестерка не забирает туза. 
     *        Выигрывает игрок, который забрал все карты. 
     * 2. Класс Player (набор имеющихся карт, вывод имеющихся карт). 
     * 3. Класс Karta (масть и тип карты (6–10, валет, дама, король, туз).
    */

    private static void Task2()
    {
        IMenu mainMenu = new ConsoleMenu(Constants.CardGameTitle);

        mainMenu.AddCommand(new NewGameCommand());
        mainMenu.AddCommand(new RulesCommand());

        mainMenu.Start();
    }
}