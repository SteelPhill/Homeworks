using System.Net.Sockets;
using System.Text;

namespace P20250214_client;

public static class Program
{
	/*
	public static async Task Main()
	{
		using var tcpClient = new TcpClient();
		await tcpClient.ConnectAsync("127.0.0.1", 8888);

		// сообщения для отправки
		// сообщение завершается конечным символом - \n,
		// который символизирует окончание сообщения
		var messages = new string[]
		{
			"Hello METANIT.COM\n",
			"Hello Tcplistener\n",
			"Bye METANIT.COM\n", "END\n"
		};
		// получаем NetworkStream для взаимодействия с сервером
		var stream = tcpClient.GetStream();
		foreach (var message in messages)
		{
			// считыванием строку в массив байт
			byte[] data = Encoding.UTF8.GetBytes(message);
			// отправляем данные
			await stream.WriteAsync(data);
			await Task.Delay(5000);
		}

		Console.WriteLine("Все сообщения отправлены");
		Console.ReadKey();
	}
	*/

	/*
	public static async Task Main()
	{
		using var tcpClient = new TcpClient();
		await tcpClient.ConnectAsync("127.0.0.1", 8888);

		// слова для отправки для получения перевода
		var words = new[] { "red", "yellow", "blue" };
		// получаем NetworkStream для взаимодействия с сервером
		var stream = tcpClient.GetStream();

		// буфер для входящих данных
		var response = new List<byte>();
		var bytesRead = 10; // для считывания байтов из потока
		foreach (var word in words)
		{
			await Task.Delay(2000);

			// считыванием строку в массив байт
			// при отправке добавляем маркер завершения сообщения - \n
			var data = Encoding.UTF8.GetBytes(word + '\n');
			// отправляем данные
			await stream.WriteAsync(data);

			// считываем данные до конечного символа
			while ((bytesRead = stream.ReadByte()) != '\n')
				// добавляем в буфер
				response.Add((byte) bytesRead);

			var translation = Encoding.UTF8.GetString(response.ToArray());
			Console.WriteLine($"Слово {word}: {translation}");
			response.Clear();
		}

		// отправляем маркер завершения подключения - END
		await stream.WriteAsync(Encoding.UTF8.GetBytes("END\n"));
		Console.WriteLine("Все сообщения отправлены");
		Console.ReadKey();
	}
	*/

	public static async Task Main()
	{
		//await ClientTask1();
		await ClientTask2();

		Console.ReadKey();
	}

	private static async Task ClientTask1()
	{
		using var tcpClient = new TcpClient();
		await tcpClient.ConnectAsync("127.0.0.1", 8888);

		await using var stream = tcpClient.GetStream();
		await WriteLineToStreamAsync(stream, "Привет, сервер!");

		var input = await ReadLineFromStreamAsync(stream);

		var now = DateTime.Now;
		var ip = tcpClient.Client.RemoteEndPoint;

		Console.WriteLine($"В {now} от [{ip}] получена строка: {input}");
	}

	private static async Task ClientTask2()
	{
		while (true)
		{
			Console.Write("Введите запрос к серверу: ");
			var request = Console.ReadLine();

			using var tcpClient = new TcpClient();
			await tcpClient.ConnectAsync("127.0.0.1", 8888);

			var stream = tcpClient.GetStream();
			await WriteLineToStreamAsync(stream, request);

			using var reader = new StreamReader(stream);
			var response = await ReadLineFromStreamAsync(stream);

			Console.WriteLine($"Ответ от сервера: {response}");
		}
	}

	private static async Task<string?> ReadLineFromStreamAsync(Stream stream)
	{
		using var reader = new StreamReader(stream, leaveOpen: true);
		return await reader.ReadLineAsync();
	}

    private static async Task WriteLineToStreamAsync(Stream stream, string? message)
	{
		await using var writer = new StreamWriter(stream, leaveOpen: true);
		await writer.WriteLineAsync(message);
	}
}