namespace HomeworkCSharp;

public class Lamborghini : Car
{
    private static string name = "Ламборгини";
    private static int StartSpeed = 25;
    private new static int MaxSpeed = 50;
    private new static int SpeedChangeTolerance = 20;

    public Lamborghini()
        : base(name, StartSpeed, MaxSpeed, SpeedChangeTolerance) { }
}