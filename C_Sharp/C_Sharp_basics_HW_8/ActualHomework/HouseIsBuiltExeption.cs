using System;

namespace ActualHomework;

public class HouseIsBuiltExeption : Exception
{
    private string message;

    public HouseIsBuiltExeption() {}

    public HouseIsBuiltExeption(string message)
    {
        this.message = message;
    }

    public override string Message => message;
}