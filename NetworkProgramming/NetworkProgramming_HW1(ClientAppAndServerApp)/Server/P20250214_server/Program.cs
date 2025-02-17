using System.Net;
using System.Net.Sockets;
using System.Text;

namespace P20250214_server;

public static class Program
{
	/*
	public static async Task Main()
	{
		var tcpListener = new TcpListener(IPAddress.Parse("127.0.0.1"), 8888);
		try
		{
			tcpListener.Start(); // запускаем сервер
			Console.WriteLine("Сервер запущен. Ожидание подключений... ");

			while (true)
			{
				// получаем подключение в виде TcpClient
				using var tcpClient = await tcpListener.AcceptTcpClientAsync();
				// получаем объект NetworkStream для взаимодействия с клиентом
				var stream = tcpClient.GetStream();
				// буфер для входящих данных
				var buffer = new List<byte>();
				int bytesRead = 10;
				while (true)
				{
					// считываем данные до конечного символа
					while ((bytesRead = stream.ReadByte()) != '\n')
					{
						// добавляем в буфер
						buffer.Add((byte) bytesRead);
					}
					var message = Encoding.UTF8.GetString(buffer.ToArray());
					// если прислан маркер окончания взаимодействия,
					// выходим из цикла и завершаем взаимодействие с клиентом
					if (message == "END") break;
					Console.WriteLine($"Получено сообщение: {message}");
					buffer.Clear();
				}
			}
		}
		finally
		{
			tcpListener.Stop(); // останавливаем сервер
		}
	}
	*/

	/*
	public static async Task Main()
	{
		var tcpListener = new TcpListener(IPAddress.Any, 8888);
		var words = new Dictionary<string, string>
		{
			{ "red", "красный" },
			{ "blue", "синий" },
			{ "green", "зеленый" }
		};
		try
		{
			tcpListener.Start(); // запускаем сервер
			Console.WriteLine("Сервер запущен. Ожидание подключений... ");

			while (true)
			{
				// получаем подключение в виде TcpClient
				using var tcpClient = await tcpListener.AcceptTcpClientAsync();
				// получаем объект NetworkStream для взаимодействия с клиентом
				var stream = tcpClient.GetStream();
				// буфер для входящих данных
				var response = new List<byte>();
				var bytesRead = 10;
				while (true)
				{
					// считываем данные до конечного символа
					while ((bytesRead = stream.ReadByte()) != '\n')
						// добавляем в буфер
						response.Add((byte) bytesRead);

					var word = Encoding.UTF8.GetString(response.ToArray());

					// если прислан маркер окончания взаимодействия,
					// выходим из цикла и завершаем взаимодействие с клиентом
					if (word == "END") break;

					Console.WriteLine($"Запрошен перевод слова {word}");
					// находим слово в словаре и отправляем обратно клиенту
					if (!words.TryGetValue(word, out var translation))
						translation = "не найдено в словаре";
					// добавляем символ окончания сообщения 
					translation += '\n';
					// отправляем перевод слова из словаря
					await stream.WriteAsync(Encoding.UTF8.GetBytes(translation));
					response.Clear();
				}
			}
		}
		finally
		{
			tcpListener.Stop();
		}
	}
	*/

	public static async Task Main()
	{
		//await ServerTask1();
		await ServerTask2();
	}

	private static async Task ServerTask1()
	{
		var tcpListener = new TcpListener(IPAddress.Any, 8888);
		try
		{
			tcpListener.Start();
			Console.WriteLine("Сервер запущен. Ожидание подключений... ");

			while (true)
			{
				using var tcpClient = await tcpListener.AcceptTcpClientAsync();
				await using var stream = tcpClient.GetStream();

				var input = await ReadLineFromStreamAsync(stream);

				var now = DateTime.Now;
				var ip = tcpClient.Client.RemoteEndPoint;

				Console.WriteLine($"В {now} от [{ip}] получена строка: {input}");

				await WriteLineToStreamAsync(stream, "Привет, клиент!");
			}
		}
		finally
		{
			tcpListener.Stop();
		}
	}

	private static async Task ServerTask2()
	{
		var tcpListener = new TcpListener(IPAddress.Any, 8888);
		try
		{
			tcpListener.Start();
			Console.WriteLine("Сервер запущен. Ожидание подключений... ");

			while (true)
			{
				using var tcpClient = await tcpListener.AcceptTcpClientAsync();
				await using var stream = tcpClient.GetStream();

				var input = await ReadLineFromStreamAsync(stream);
				Console.WriteLine($"Запрос от клиента: {input}");

                await WriteLineToStreamAsync(stream,
					input switch
					{
						"date" => DateTime.Now.ToShortDateString(),
						"time" => DateTime.Now.ToLongTimeString(),
						_ => "Unknown command"
					});
			}
		}
		finally
		{
			tcpListener.Stop();
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