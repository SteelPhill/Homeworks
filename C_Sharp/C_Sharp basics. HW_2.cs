using System;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ActualHomework;

public class Program
{
    public static void Main()
    {
        //Task1();
        //Task2();
        //Task3();
        //Task4();
        //Task5();
        //Task6();
        //Task7();

        Console.ReadKey();
    }

    /*     
     *          ЗАДАНИЕ №1
     * Объявить одномерный (5 элементов) массив с именем A и 
     * двумерный массив (3 строки, 4 столбца) дробных чисел с именем B.
     * Заполнить одномерный массив А числами, введенными с клавиатуры пользователем,
     * а двумерный массив В случайными числами с помощью циклов. 
     * Вывести на экран значения массивов: массива А в одну строку,
     * массива В — в виде матрицы. Найти в данных массивах общий максимальный элемент,
     * минимальный элемент, общую сумму всех элементов, общее произведение всех элементов,
     * сумму четных элементов массива А, сумму нечетных столбцов массива В.
     */

    public static void Task1()
    {
        const int Size = 5;
        const int Rows = 3;
        const int Columns = 4;
        const decimal BeginRange = 1;
        const decimal EndRange = 9;
        const int DecimalPlaces = 2;

        var fillArray = new FillArray();
        var fillMatrix = new FillMatrix();
        IArrayWriter arrayWriter = new ConsoleArrayWriter();
        IMatrixWriter matrixWriter = new ConsoleMatrixWriter();

        int[] A = new int[Size];
        decimal[,] B = new decimal[Rows, Columns];

        Console.WriteLine("Заполните одномерный массив A, состоящий из 5 элементов:");
        fillArray.Manual(A);

        fillMatrix.Random(B, BeginRange, EndRange);

        Console.Write("\nОдномерный массив A: ");
        arrayWriter.Write(A);

        Console.WriteLine("\nДвумерный массив B: ");
        matrixWriter.Write(B, DecimalPlaces);

        decimal[] B2 = B.Cast<decimal>().ToArray();

        decimal min = Math.Min((decimal)A.Min(), B2.Min());
        Console.WriteLine($"Минимальный элемент в A и B: {Math.Round(min, DecimalPlaces)}");

        decimal max = Math.Max((decimal)A.Max(), B2.Max());
        Console.WriteLine($"Максимальный элемент в A и B: {Math.Round(max, DecimalPlaces)}");

        decimal sum = (decimal)A.Sum() + B2.Sum();
        Console.WriteLine($"Сумма элементов A и B: {Math.Round(sum, DecimalPlaces)}");

        decimal mult = (decimal)A.Aggregate((x, y) => x * y) * B2.Aggregate((x, y) => x * y);
        Console.WriteLine($"Произведение элементов A и B: {Math.Round(mult, DecimalPlaces)}");

        int evenSumA = A.Where((x) => x % 2 == 0).Sum();
        Console.WriteLine($"Сумма чётных элементов A: {evenSumA}");

        Console.Write("Сумма элементов нечётных столбцов B: ");
        Console.WriteLine(Math.Round(OddColumnsSum(B), DecimalPlaces));
    }

    private static int OddColumnsSum(int[,] matrix)
    {
        int result = 0;

        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                if (j % 2 == 0)
                    result += matrix[i, j];

        return result;
    }

    private static decimal OddColumnsSum(decimal[,] matrix)
    {
        decimal result = 0;

        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                if (j % 2 == 0)
                    result += matrix[i, j];

        return result;
    }

    /*      
     *          ЗАДАНИЕ №2
     * Дан двумерный массив размерностью 5×5, 
     * заполненный случайными числами из диапазона от –100 до 100. 
     * Определить сумму элементов массива, 
     * расположенных между минимальным и максимальным элементами.
     */

    public static void Task2()
    {
        const int Rows = 5;
        const int Columns = 5;
        const int BeginRange = -100;
        const int EndRange = 100;

        IMatrixWriter matrixWriter = new ConsoleMatrixWriter();
        var fillMatrix = new FillMatrix();
        int[,] matrix = new int[Rows, Columns];
        fillMatrix.Random(matrix, BeginRange, EndRange);

        Console.WriteLine("Двумерный массив: ");
        matrixWriter.Write(matrix);

        var begin = IndexesMinElement(matrix);
        Console.WriteLine($"\nМинимальный элемент: {matrix[begin.Row, begin.Column]}");

        var end = IndexesMaxElement(matrix);
        Console.WriteLine($"Максимальный элемент: {matrix[end.Row, end.Column]}");

        if (begin.Row > end.Row ||
            begin.Row == end.Row && begin.Column > end.Column)
            (begin, end) = (end, begin);

        begin = NextElementIndexes(Rows, Columns, begin.Row, begin.Column);
        end = PreviousElementIndexes(Rows, Columns, end.Row, end.Column);

        Console.Write("\nСумма чисел между минимальным и максимальным элементами: ");
        Console.WriteLine(SumInRange(matrix, begin.Row, begin.Column, end.Row, end.Column));
    }

    private static (int Row, int Column) IndexesMinElement(int[,] matrix)
    {
        int rowIndex = matrix.GetLength(0) - 1;
        int columnIndex = matrix.GetLength(1) - 1;
        int min = matrix[rowIndex, columnIndex];

        for (int i = matrix.GetLength(0) - 1; i >= 0; i--)
            for (int j = matrix.GetLength(1) - 1; j >= 0; j--)
                if (matrix[i, j] < min)
                {
                    min = matrix[i, j];
                    rowIndex = i;
                    columnIndex = j;
                }

        return (rowIndex, columnIndex);
    }

    private static (int Row, int Column) IndexesMaxElement(int[,] matrix)
    {
        int rowIndex = 0;
        int columnIndex = 0;
        int max = matrix[rowIndex, columnIndex];

        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                if (matrix[i, j] > max)
                {
                    max = matrix[i, j];
                    rowIndex = i;
                    columnIndex = j;
                }

        return (rowIndex, columnIndex);
    }

    private static (int Row, int Column) NextElementIndexes(
        int rows,
        int columns,
        int rowIndex,
        int columnIndex)
    {
        if (columnIndex == columns - 1 && rowIndex != rows - 1)
            return (++rowIndex, 0);
        else if (columnIndex == columns - 1 && rowIndex == rows - 1)
            return (0, 0);
        else
            return (rowIndex, ++columnIndex);
    }

    private static (int Row, int Column) PreviousElementIndexes(
        int rows,
        int columns,
        int rowIndex,
        int columnIndex)
    {
        if (columnIndex == 0 && rowIndex != 0)
            return (--rowIndex, columns - 1);
        else if (columnIndex == 0 && rowIndex == 0)
            return (rows - 1, columns - 1);
        else
            return (rowIndex, --columnIndex);
    }

    private static int SumInRange(
        int[,] matrix,
        int rowBegin,
        int columnBegin,
        int rowEnd,
        int columnEnd)
    {
        int sum = 0;

        for (int i = rowBegin; i <= rowEnd; i++)
        {
            int j = 0;

            if (i == rowBegin)
                j = columnBegin;

            for (; j < matrix.GetLength(1); j++)
            {
                sum += matrix[i, j];

                if (i == rowEnd && j == columnEnd)
                    break;
            }
        }

        return sum;
    }

    /*      
     *          ЗАДАНИЕ №3   
     * Пользователь вводит строку с клавиатуры.
     * Необходимо зашифровать данную строку используя шифр Цезаря. 
     * Из Википедии:
     * Шифр Цезаря — это вид шифра подстановки, 
     * в котором каждый символ в открытом тексте заменяется символом,
     * находящимся на некотором постоянном числе позиций левее или правее него в алфавите.
     * Например, в шифре со сдвигом вправо на 3, A была бы заменена на D, B станет E, и так далее.
     * Подробнее тут: https://en.wikipedia.org/wiki/Caesar_cipher. 
     * Кроме механизма шифровки, реализуйте механизм расшифрования.
     */

    public static void Task3()
    {
        const int Key = 3;

        //Console.WriteLine("Введите текст на русском или английском языке для его дальнейшего шифрования");
        //Console.Write("\n=> ");
        //string originalText = Console.ReadLine();

        string originalText = "Caesar Шифр";

        string cipher = CaesarCipherEncryption(originalText, Key);

        Console.WriteLine($"Изначальный текст: {originalText}");
        Console.WriteLine($"Зашифрованный текст: {cipher}");
        Console.WriteLine($"Расшифрованный текст: {CaesarCipherDecryption(cipher, Key)}");
    }

    private static int SearchLetterIndex(char[] alphabet, char letter)
    {
        for (int i = 0; i < alphabet.Length; i++)
            if (letter == alphabet[i])
                return i;

        return -1;
    }

    private static char ShiftLetterRight(char[] alphabet, char letter, int key)
    {
        return alphabet[(SearchLetterIndex(alphabet, letter) + key) % alphabet.Length];
    }

    private static char ShiftLetterLeft(char[] alphabet, char letter, int key)
    {
        int index = (SearchLetterIndex(alphabet, letter) - key + alphabet.Length) % alphabet.Length;

        if (index < 0)
            index += alphabet.Length;

        return alphabet[index];
    }

    public static string CaesarCipherEncryption(string text, int key)
    {
        char[] upperRusAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ".ToCharArray();
        char[] lowerRusAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя".ToCharArray();
        char[] upperEngAlphabet = Enumerable.Range('A', 'Z' - 'A' + 1).Select(c => (char)c).ToArray();
        char[] lowerEngAlphabet = Enumerable.Range('a', 'z' - 'a' + 1).Select(c => (char)c).ToArray();
        var result = new StringBuilder();

        for (int i = 0; i < text.Length; i++)
            if (char.IsUpper(text[i]))
            {
                if (upperRusAlphabet.Contains(text[i]))
                    result.Append(ShiftLetterRight(upperRusAlphabet, text[i], key));
                else
                    result.Append(ShiftLetterRight(upperEngAlphabet, text[i], key));
            }
            else if (char.IsLower(text[i]))
            {
                if (lowerRusAlphabet.Contains(text[i]))
                    result.Append(ShiftLetterRight(lowerRusAlphabet, text[i], key));
                else
                    result.Append(ShiftLetterRight(lowerEngAlphabet, text[i], key));
            }
            else
                result.Append(text[i]);

        return result.ToString();
    }

    public static string CaesarCipherDecryption(string text, int key)
    {
        char[] upperRusAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ".ToCharArray();
        char[] lowerRusAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя".ToCharArray();
        char[] upperEngAlphabet = Enumerable.Range('A', 'Z' - 'A' + 1).Select(c => (char)c).ToArray();
        char[] lowerEngAlphabet = Enumerable.Range('a', 'z' - 'a' + 1).Select(c => (char)c).ToArray();
        var result = new StringBuilder();

        for (int i = 0; i < text.Length; i++)
            if (char.IsUpper(text[i]))
            {
                if (upperRusAlphabet.Contains(text[i]))
                    result.Append(ShiftLetterLeft(upperRusAlphabet, text[i], key));
                else
                    result.Append(ShiftLetterLeft(upperEngAlphabet, text[i], key));
            }
            else if (char.IsLower(text[i]))
            {
                if (lowerRusAlphabet.Contains(text[i]))
                    result.Append(ShiftLetterLeft(lowerRusAlphabet, text[i], key));
                else
                    result.Append(ShiftLetterLeft(lowerEngAlphabet, text[i], key));
            }
            else
                result.Append(text[i]);

        return result.ToString();
    }

    /*      
     *          ЗАДАНИЕ №4     
     * Создайте приложение, которое производит операции над матрицами:
     * - Умножение матрицы на число;
     * - Сложение матриц; 
     * - Произведение матриц.
     */

    public static void Task4()
    {
        const int Rows = 3;
        const int Columns = 3;
        const int BeginRange = 1;
        const int EndRange = 9;
        const decimal Multiplier = 1.5M;

        var fillMatrix = new FillMatrix();
        IMatrixWriter matrixWriter = new ConsoleMatrixWriter();

        int[,] matrix1 = new int[Rows, Columns];
        fillMatrix.Random(matrix1, BeginRange, EndRange);

        int[,] matrix2 = new int[Rows, Columns];
        fillMatrix.Random(matrix2, BeginRange, EndRange);

        Console.WriteLine("Первая матрица:");
        matrixWriter.Write(matrix1);

        Console.WriteLine("\nВторая матрица:");
        matrixWriter.Write(matrix2);

        try
        {
            Console.WriteLine("\nСумма матриц:");
            matrixWriter.Write(MatrixSum(matrix1, matrix2));

            Console.WriteLine("\nПроизведение матриц:");
            matrixWriter.Write(MatrixMult(matrix1, matrix2));
        }
        catch (Exception e)
        {
            Console.WriteLine($"Error: {e.ToString()}");
        }

        Console.WriteLine($"\nРезультат умножения первой матрицы на число {Multiplier}:");
        matrixWriter.Write(MultMatrixByNumber(matrix1, Multiplier));
    }

    private static decimal[,] MultMatrixByNumber(int[,] matrix, decimal multiplier)
    {
        decimal[,] result = new decimal[matrix.GetLength(0), matrix.GetLength(1)];

        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                result[i, j] = matrix[i, j] * multiplier;

        return result;
    }

    private static int[,] MatrixSum(int[,] matrix1, int[,] matrix2)
    {
        if (matrix1.GetLength(0) != matrix2.GetLength(0) && matrix1.GetLength(1) != matrix2.GetLength(1))
            throw new Exception("Матрицы невозможно суммировать");

        int[,] result = new int[matrix1.GetLength(0), matrix1.GetLength(1)];

        for (int i = 0; i < matrix1.GetLength(0); i++)
            for (int j = 0; j < matrix1.GetLength(1); j++)
                result[i, j] = matrix1[i, j] + matrix2[i, j];

        return result;
    }

    private static int[,] MatrixMult(int[,] matrix1, int[,] matrix2)
    {
        if (matrix1.GetLength(0) != matrix2.GetLength(1))
            throw new Exception("Матрицы невозможно перемножить");

        int[,] result = new int[matrix1.GetLength(0), matrix2.GetLength(1)];

        for (int i = 0; i < matrix1.GetLength(0); i++)
            for (int j = 0; j < matrix2.GetLength(1); j++)
                for (int k = 0; k < matrix2.GetLength(0); k++)
                    result[i, j] += matrix1[i, k] * matrix2[k, j];

        return result;
    }

    /*      
     *          ЗАДАНИЕ №5   
     * Пользователь с клавиатуры вводит в строку арифметическое выражение.
     * Приложение должно посчитать его результат.
     * Необходимо поддерживать только две операции: + и –.
     */

    public static void Task5()
    {
        //Console.WriteLine("Введите арифметическую операцию сложения(+) или вычитания(-) с двумя операндами.");
        //Console.WriteLine("Операнды необходимо разделять пробелами.");
        //Console.Write("\n\t=> ");
        //string originalText = Console.ReadLine();

        string originalText = " 56  -  60  ";
        Console.WriteLine($"Выражение: {originalText}");

        string[] processedExpression = originalText
            .Split()
            .Where(s => s.Any(ch => char.IsDigit(ch) || char.IsSymbol(ch) || char.IsPunctuation(ch)))
            .ToArray();

        try
        {
            decimal value1 = decimal.Parse(processedExpression[0]);
            decimal value2 = decimal.Parse(processedExpression[2]);

            if (processedExpression[1] == "+")
                Console.WriteLine($"\nРезультат операции: {value1 + value2}");
            else if (processedExpression[1] == "-")
                Console.WriteLine($"\nРезультат операции: {value1 - value2}");
            else
                throw new Exception();
        }
        catch (Exception)
        {
            Console.WriteLine("\nОшибка: неверный формат выражения!");
        }
    }

    /*      
     *          ЗАДАНИЕ №6     
     * Пользователь с клавиатуры вводит некоторый текст. 
     * Приложение должно изменять регистр первой буквы каждого
     * предложения на букву в верхнем регистре.
     * Например, если пользователь ввёл:
     * «today is a good day for walking. i will try to walk near the sea». 
     * Результат работы приложения:
     * «Today is a good day for walking. I will try to walk near the sea».
     */

    public static void Task6()
    {
        //Console.WriteLine("Введите текст");
        //Console.Write("\n=> ");
        //string text = Console.ReadLine();

        string text = "«today is a good day for walking. i will try to walk near the sea».";
        string separators = ".!?";
        var stringBuilder = new StringBuilder();
        bool isNewOffer = false;

        for (int i = 0; i < text.Length; i++)
        {
            if (separators.Contains(text[i]) || i == 0)
                isNewOffer = true;

            if (isNewOffer && char.IsLetter(text[i]))
            {
                stringBuilder.Append(char.ToUpper(text[i]));
                isNewOffer = false;
                continue;
            }

            stringBuilder.Append(text[i]);
        }

        Console.WriteLine($"Результат: {stringBuilder.ToString()}");
    }

    /*      
     *          ЗАДАНИЕ №7
     * Создайте приложение, проверяющее текст на недопустимые слова. 
     * Если недопустимое слово найдено, оно должно быть заменено на набор символов *.
     * По итогам работы приложения необходимо показать статистику действий.
     * Например, если и у нас есть такой текст: 
     * The evil would may be cured,
     * but not the evil name.
     * Недопустимое слово: evil.
     * Результат работы:
     * The **** would may be cured,
     * but not the **** name.
     * Статистика: 2 замены слова evil.
     */

    public static void Task7()
    {
        string text = "The evil would may be cured,\r\nbut not the Evil name.";
        string badWord = "evil";
        char substitute = '*';
        string stars = new string(substitute, badWord.Length);
        var stringBuilder = new StringBuilder();
        int count = 0;
        string[] splitText = text.Split();

        for (int i = 0; i < splitText.Length; i++)
        {
            if (string.IsNullOrEmpty(splitText[i]))
            {
                stringBuilder.Append("\r\n");
                continue;
            }

            if (splitText[i].IndexOf(badWord, StringComparison.OrdinalIgnoreCase) >= 0 &&
                splitText[i].Length == badWord.Length + splitText[i].Count(ch => char.IsPunctuation(ch)))
            {
                stringBuilder.Append(Regex.Replace(splitText[i], badWord, stars, RegexOptions.IgnoreCase));
                count++;
            }
            else
                stringBuilder.Append(splitText[i]);

            stringBuilder.Append(" ");
        }

        Console.WriteLine($"\tИзначальный текст:");
        Console.WriteLine($"{text}\n");

        Console.WriteLine($"\tТекст после замены слова {badWord} на {stars}:");
        Console.WriteLine($"{stringBuilder.ToString()}\n");

        Console.WriteLine($"Количество замен: {count}");
    }
}



public class FillArray
{
    public void InOrder(int[] arr, int begin)
    {
        arr = Enumerable.Range(begin, arr.Length).ToArray();
    }

    public void Random(int[] arr, int begin, int end)
    {
        var random = new Random(DateTime.Now.Millisecond);

        for (int i = 0; i < arr.Length; i++)
            arr[i] = random.Next(begin, end);
    }

    public void Random(decimal[] arr, decimal begin, decimal end)
    {
        var random = new Random(DateTime.Now.Millisecond);

        for (int i = 0; i < arr.Length; i++)
            arr[i] = (decimal)random.NextDouble() * (end - begin) + begin;
    }

    public void Manual(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            do
            {
                Console.Write($"[{i}] => ");
            }
            while (!int.TryParse(Console.ReadLine(), out arr[i]));
        }
    }

    public void Manual(decimal[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            do
            {
                Console.Write($"[{i}] => ");
            }
            while (!decimal.TryParse(Console.ReadLine(), out arr[i]));
        }
    }
}

public class FillMatrix
{
    public void Random(int[,] matrix, int begin, int end)
    {
        var random = new Random(DateTime.Now.Millisecond);

        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                matrix[i, j] = random.Next(begin, end);
    }

    public void Random(decimal[,] matrix, decimal begin, decimal end)
    {
        var random = new Random(DateTime.Now.Millisecond);

        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                matrix[i, j] = (decimal)random.NextDouble() * (end - begin) + begin;
    }

    public void Manual(int[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                do
                {
                    Console.Write($"[{i},{j}] => ");
                }
                while (!int.TryParse(Console.ReadLine(), out matrix[i, j]));
            }
        }
    }

    public void Manual(decimal[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                do
                {
                    Console.Write($"[{i},{j}] => ");
                }
                while (!decimal.TryParse(Console.ReadLine(), out matrix[i, j]));
            }
        }
    }
}

interface IArrayWriter
{
    void Write(int[] arr);
    void Write(decimal[] arr, int decimalPlaces = 1);
}

public class ConsoleArrayWriter : IArrayWriter
{
    public void Write(int[] arr)
    {
        Console.WriteLine(string.Join(" ", arr));
    }

    public void Write(decimal[] arr, int decimalPlaces = 1)
    {
        var result = new StringBuilder();

        for (int i = 0; i < arr.Length; i++)
        {
            result.Append(Math.Round(arr[i], decimalPlaces));
            result.Append(' ');
        }

        Console.WriteLine(result.ToString());
    }
}

interface IMatrixWriter
{
    void Write(int[,] matrix);
    void Write(decimal[,] matrix, int decimalPlaces = 1);
}

public class ConsoleMatrixWriter : IMatrixWriter
{
    public void Write(int[,] matrix)
    {
        var result = new StringBuilder();

        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                result.Append(matrix[i, j]);
                result.Append('\t');
            }

            result.Append('\n');
        }

        Console.WriteLine(result.ToString());
    }

    public void Write(decimal[,] matrix, int decimalPlaces = 1)
    {
        var result = new StringBuilder();

        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                result.Append(Math.Round(matrix[i, j], decimalPlaces));
                result.Append('\t');
            }

            result.Append('\n');
        }

        Console.WriteLine(result.ToString());
    }
}