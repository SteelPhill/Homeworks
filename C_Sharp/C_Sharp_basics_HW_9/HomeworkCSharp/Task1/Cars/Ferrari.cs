namespace HomeworkCSharp;

public class Ferrari : Car
{
    private static string name = "Феррари";
    private static int StartSpeed = 24;
    private new static int MaxSpeed = 55;
    private new static int SpeedChangeTolerance = 21;

    public Ferrari()
        : base(name, StartSpeed, MaxSpeed, SpeedChangeTolerance) { }
}