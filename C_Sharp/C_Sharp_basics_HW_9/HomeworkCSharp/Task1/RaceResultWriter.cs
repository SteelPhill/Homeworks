using System;

namespace HomeworkCSharp;

public class RaceResultWriter : IRaceResultWriter
{
    public void Write(Race race)
    {
        Console.WriteLine("Результаты:\n");

        foreach (var car in race.GetCars())
        {
            Console.Write($"Автомобиль: {car.Name}\t-> ");

            if (car.Distance < Constants.RaceDistance)
                Console.WriteLine("проигравший");
            else
                Console.WriteLine("ПОБЕДИТЕЛЬ");
        }

        Console.WriteLine("\nНажмите любую клавишу...");
        Console.ReadKey();
    }
}