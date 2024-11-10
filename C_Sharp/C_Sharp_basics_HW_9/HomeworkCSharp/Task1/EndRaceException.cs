using System;

namespace HomeworkCSharp;

public class EndRaceException : Exception
{
    private string message;

    public EndRaceException() : this(default) { }

    public EndRaceException(string message) 
        => this.message = message;

    public override string Message => message;
}