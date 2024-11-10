using System;

namespace HomeworkCSharp;

public abstract class Car
{
    static Random random;

    public string Name { get; }
    public int Speed { get; private set; }
    public int Distance { get; private set; }
    public int MaxSpeed { get; }
    public int SpeedChangeTolerance { get; }

    public Car(
        string name,
        int speed,
        int maxSpeed,
        int speedChangeTolerance)
    {
        Name = name;
        Speed = speed;
        MaxSpeed = maxSpeed;
        SpeedChangeTolerance = speedChangeTolerance;

        random = new Random((int)DateTime.Now.Ticks);
    }

    public bool IsFinished() => Distance >= Constants.RaceDistance;

    public void Drive()
    {
        Distance += Speed;

        int temp;

        do
        {
            temp = random.Next(
                Speed - SpeedChangeTolerance,
                Speed + SpeedChangeTolerance);

        } while (temp < 0 || temp > MaxSpeed);

        Speed = temp;
    }
}