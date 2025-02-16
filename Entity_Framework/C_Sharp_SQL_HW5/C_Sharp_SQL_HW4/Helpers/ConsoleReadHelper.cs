namespace C_Sharp_SQL_HW4.Helpers;

public static class ConsoleReadHelper
{
	public static int ReadInt(string message, int from = int.MinValue, int to = int.MaxValue)
	{
		while (true)
		{
			Console.Write(message);

			if (!int.TryParse(Console.ReadLine(), out var value))
			{
				Console.WriteLine("Введено некорректное число, повторите ввод");
				continue;
			}

			if (from > value || value > to)
			{
				Console.WriteLine($"Введенное число должно быть в диапазоне от {from} до {to}, повторите ввод");
				continue;
			}

			return value;
		}
	}

	public static string ReadString(string message)
	{
        Console.WriteLine();
        Console.Write(message);
        var inputStr = Console.ReadLine();
        if (string.IsNullOrEmpty(inputStr))
            throw new Exception("Введена пустая строка.");

		return inputStr;
    }
}