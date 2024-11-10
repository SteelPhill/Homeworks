using System;
using System.Threading;

namespace HomeworkCSharp;

public class StartRaceCommand : IMenuCommand
{
    static RaceTrackWriter trackWriter = new RaceTrackWriter();
    static RaceResultWriter resultWriter = new RaceResultWriter();

    public string Description()
    {
        return "Начать гонку";
    }

    public void Execute()
    {
        var race = new Race();

        Console.WriteLine("Участники гонки:\n");
        race.ParticipantAnnouncing += ShowParticipants;

        race.AddCar(new Ferrari());
        race.AddCar(new Lamborghini());
        race.AddCar(new Ford());
        race.AddCar(new Chevrolet());

        Console.WriteLine("\nНажмите любую клавишу...");
        Console.ReadKey();
        Console.Clear();

        race.CarFinished += CarFinishedMessage;

        try
        {
            do
            {
                trackWriter.Write(race);
                race.Tick();
                Thread.Sleep(Constants.TimeDelay);
                Console.Clear();

            } while (true);
        }
        catch (EndRaceException)
        {
            resultWriter.Write(race);
        }
    }

    private void ShowParticipants(object sender, Car car)
        => Console.WriteLine($"Автомобиль: {car.Name}");

    private void CarFinishedMessage(object sender, EventArgs eventArgs)
    {
        Console.Clear();
        Console.WriteLine("Гонка окончена!\n");

        throw new EndRaceException();
    }
}