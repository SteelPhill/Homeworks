namespace HomeworkCSharp;

public class Ford : Car
{
    private static string name = "Форд";
    private static int StartSpeed = 23;
    private new static int MaxSpeed = 60;
    private new static int SpeedChangeTolerance = 22;

    public Ford()
        : base(name, StartSpeed, MaxSpeed, SpeedChangeTolerance) { }
}