using System;

namespace HomeworkCSharp;

public class RaceTrackWriter : IRaceTrackWriter
{
    public void Write(Race race)
    {
        var trackReducedScale = 
            Constants.RaceDistance / Constants.ScaleDivider;

        Console.WriteLine("Гонка в процессе...\n");

        foreach (var car in race.GetCars())
        {
            Console.WriteLine($"{car.Name}:");
            Console.Write("Start ");

            for (var i = 0; i < trackReducedScale; i++)
            {
                if (i == car.Distance / Constants.ScaleDivider)
                    Console.Write(Constants.Car);
                else
                    Console.Write(Constants.Road);
            }

            Console.Write(" Finish");
            Console.WriteLine("\n");
        }
    }
}