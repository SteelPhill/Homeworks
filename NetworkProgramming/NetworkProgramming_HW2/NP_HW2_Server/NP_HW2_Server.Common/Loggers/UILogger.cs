using System.Collections.ObjectModel;
using System.Windows;

namespace NP_HW2_Server.Common.Loggers;

public class UILogger : ILogger
{
    private readonly ObservableCollection<string> _logMessages;

    public UILogger(ObservableCollection<string> logMessages)
    {
        _logMessages = logMessages;
    }

    public void LogMessage(string message)
    {
        message = $"{DateTime.Now:yyyy.MM.dd HH:mm:ss.ffff} {message}";

        Application.Current.Dispatcher.Invoke(() => _logMessages.Add(message));
    }
}