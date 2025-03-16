using System.IO;

namespace NP_HW2_Server.Common.Extensions;

public static class StreamExtensions
{
	public static async Task<string?> ReadFromStreamAsync(Stream stream, CancellationToken token)
	{
		using var reader = new StreamReader(stream, leaveOpen: true);
		return await reader.ReadLineAsync(token);
	}

	public static async Task WriteToStreamAsync(Stream stream, string? message, CancellationToken token)
	{
		await using var writer = new StreamWriter(stream, leaveOpen: true);
		await writer.WriteLineAsync(message.AsMemory(), token);
	}
}