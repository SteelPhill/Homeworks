using NP_HW2_Server.Common.Extensions;
using Nito.AsyncEx;
using System.IO;

namespace NP_HW2_Server.Common.Loggers;

public class FileLogger : ILogger
{
	private static readonly string LogFileName = $"logs\\log-{DateTime.Now:yyyy-MM-dd_HH-mm-ss}.txt";
	private static readonly AsyncLock LogMessageAsyncLock = new();

	public void LogMessage(string message)
	{
		LogMessageAsync(message).FireAndForgetSafeAsync();
	}

	private static async Task LogMessageAsync(string message)
	{
		message = $"{DateTime.Now:yyyy.MM.dd HH:mm:ss.ffff} {message}";	

        using var _ = await LogMessageAsyncLock.LockAsync();

        message += Environment.NewLine;

        var logFileDirectory = Path.GetDirectoryName(LogFileName);
		if (!string.IsNullOrEmpty(logFileDirectory))
			Directory.CreateDirectory(logFileDirectory);

		await File.AppendAllTextAsync(LogFileName, message);
	}
}