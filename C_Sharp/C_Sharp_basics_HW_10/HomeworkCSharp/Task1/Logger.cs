using System;
using System.IO;

namespace HomeworkCSharp;

public class Logger : ILogger
{
    private string format;
    private string logFilePath;

    public EventHandler ConsoleLogWrite;

    public Logger(string configFilePath, string logFilePath)
    {
        format = File.ReadAllText(configFilePath);
        this.logFilePath = logFilePath;
    }

    public void Log(LogType logType, string message)
    {
        var log = format
            .Replace("[Date]", DateTime.Now.ToShortDateString())
            .Replace("[Time]", DateTime.Now.ToShortTimeString())
            .Replace("[Type]", logType.ToString())
            .Replace("[Message]", message);

        File.AppendAllText(logFilePath, log + "\n");

        ConsoleLogWrite?.Invoke(this, EventArgs.Empty);
    }
}