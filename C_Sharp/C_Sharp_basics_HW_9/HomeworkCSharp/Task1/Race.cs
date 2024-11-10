using System;
using System.Collections.Generic;

namespace HomeworkCSharp;

public class Race
{
    private List<Car> cars = new List<Car>();

    public event EventHandler CarFinished;
    public event EventHandler<Car> ParticipantAnnouncing;

    public List<Car> GetCars() => cars;

    public void AddCar(Car car)
    {
        cars.Add(car);

        ParticipantAnnouncing?.Invoke(this, car);
    }

    public void RemoveCars() => cars?.Clear();

    public void Tick()
    {
        var isRaceEnd = false;

        foreach (var car in cars)
        {
            car.Drive();

            if (car.IsFinished())
                isRaceEnd = true;
        }

        if (isRaceEnd)
            CarFinished?.Invoke(this, EventArgs.Empty);
    }
}