namespace HomeworkCSharp;

public class Chevrolet : Car
{
    private static string name = "Шевроле";
    private static int StartSpeed = 26;
    private new static int MaxSpeed = 45;
    private new static int SpeedChangeTolerance = 19;

    public Chevrolet()
        : base(name, StartSpeed, MaxSpeed, SpeedChangeTolerance) { }
}