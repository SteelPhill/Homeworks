using Nito.AsyncEx;
using SystemProgramming_HW_3.Extensions;
using SystemProgramming_HW_3.Helpers;

namespace SystemProgramming_HW_3;

/*
 *          Задание 1:
 *          
 * Создайте консольное приложение, генерирующее набор простых чисел в диапазоне, указанном пользователем. 
 * Если не указана нижняя граница, поток с стартует с 2. 
 * Если не указана верхняя граница, генерирование происходит до завершения приложения.
 * Используйте механизм потоков. Числа должны отображаться в консоли.
 * 
 *          Задание 2 
 * 
 * Добавьте к первому заданию поток, генерирующий набор чисел Фибоначчи. 
 * Числа должны отображаться в консоли.
 * 
 *          Задание 3
 * 
 * Добавьте ко второму заданию кнопки для полной остановки каждого из потоков. 
 * Одна кнопка на один поток. 
 * Если пользователь нажал на кнопку остановки, поток полностью прекращает свою работу.
 * 
 *          Задание 4
 * 
 * Добавьте к третьему заданию кнопки для приостановления и возобновления каждого из потоков. 
 * Например, пользователь может приостановить генерацию чисел Фибоначчи по нажатию на кнопку.
 * Продолжение генерации возможно по нажатию на другую кнопку.
 * 
 *          Задание 5
 * 
 * Добавьте к четвертому заданию возможность полного рестарта потоков с новыми границами.
 * 
 */

public static class Program
{
    //private static readonly ManualResetEvent ManualResetPrimesEvent = new (true);
    //private static readonly ManualResetEvent ManualResetFibonacciEvent = new (true);
    private static readonly AsyncManualResetEvent ManualResetPrimesEvent = new (true);
    private static readonly AsyncManualResetEvent ManualResetFibonacciEvent = new (true);

    private static CancellationTokenSource? PrimesCancellationTokenSource;
    private static CancellationTokenSource? FibonacciCancellationTokenSource;

    private static bool IsExit = false;

    public static void Main()
    {
        Constants.Commands.ForEach(Console.WriteLine);

        while (true)
        {
            switch (Console.ReadKey().Key)
            {
                case ConsoleKey.F1:
                    if (PrimesCancellationTokenSource?.IsCancellationRequested != null)
                        break;
                    PrimesCancellationTokenSource = new();
                    GenerateAndPrintPrimes(PrimesCancellationTokenSource.Token);
                    break;

                case ConsoleKey.F2:
                    if (FibonacciCancellationTokenSource?.IsCancellationRequested != null ||
                        PrimesCancellationTokenSource?.IsCancellationRequested == null)
                        break;
                    FibonacciCancellationTokenSource = new();
                    GenerateAndPrintFibonacci(FibonacciCancellationTokenSource.Token);
                    break;

                case ConsoleKey.F3:
                    if (PrimesCancellationTokenSource != null)
                        PausePrintPrimes();
                    break;

                case ConsoleKey.F4:
                    if (FibonacciCancellationTokenSource != null)
                        PausePrintFibonacci();
                    break;

                case ConsoleKey.F5:
                    if (PrimesCancellationTokenSource != null)
                        ResumePrintPrimes();
                    break;

                case ConsoleKey.F6:
                    if (FibonacciCancellationTokenSource != null)
                        ResumePrintFibonacci();
                    break;

                case ConsoleKey.F7:
                    if (PrimesCancellationTokenSource != null)
                        CancelPrintPrimes();
                    break;

                case ConsoleKey.F8:
                    if (FibonacciCancellationTokenSource != null)
                        CancelPrintFibonacci();
                    break;

                case ConsoleKey.F9:
                    Restart();
                    break;

                case ConsoleKey.F10:
                    Exit();
                    break;

                default:
                    break;
            }

            if (PrimesCancellationTokenSource?.IsCancellationRequested == true &&
                FibonacciCancellationTokenSource?.IsCancellationRequested == true ||
                IsExit)
                break;
        }

        Console.WriteLine();
        Console.WriteLine("Нажмите любую клавишу...");
        Console.ReadKey();
    }

    private static void GenerateAndPrintPrimes(CancellationToken cancellationToken)
    {
        Console.WriteLine();

        Console.WriteLine("Введите значение начала диапазона или введите 0, для использования значения по-умолчанию");
        var primeBegin = ConsoleReadHelper.ReadUlong(" => ");
        if (primeBegin == 0)
            primeBegin = 2;

        Console.WriteLine("Введите значение конца диапазона или введите 0, для использования значения по-умолчанию");
        var primeEnd = ConsoleReadHelper.ReadUlong(" => ");
        if (primeEnd == 0)
            primeEnd = ulong.MaxValue;

        if (primeBegin > primeEnd)
            (primeBegin, primeEnd) = (primeEnd, primeBegin);

        Console.WriteLine();

        ResumePrintPrimes();

        Task.Run(async () =>
        {
            for (var i = primeBegin; i <= primeEnd; i++)
            {
                if (!IsPrime(i))
                    continue;

                //do
                //{
                //    cancellationToken.ThrowIfCancellationRequested();
                //} while (!ManualResetPrimesEvent.WaitOne(Constants.TimeDelay));

                await ManualResetPrimesEvent.WaitAsync(cancellationToken);

                Console.WriteLine($"Простое:   {i}");
                await Task.Delay(Constants.TimeDelay);
            }
        }, cancellationToken);
    }

    private static bool IsPrime(ulong number)
    {
        if (number < 2)
            return false;

        for (ulong i = 2; i <= Math.Sqrt(number); i++)
            if (number % i == 0)
                return false;

        return true;
    }

    private static void GenerateAndPrintFibonacci(CancellationToken cancellationToken)
    {
        Task.Delay(Constants.TimeDelay, cancellationToken).Wait(cancellationToken);

        ResumePrintFibonacci();

        Task.Run(async () =>
        {
            for (var i = ulong.MinValue; i <= ulong.MaxValue; i++)
            {
                //do
                //{
                //    cancellationToken.ThrowIfCancellationRequested();
                //} while (!ManualResetFibonacciEvent.WaitOne(Constants.TimeDelay));

                await ManualResetFibonacciEvent.WaitAsync(cancellationToken);

                Console.WriteLine($"Фибоначчи: {GetFibonacci(i)}");
                await Task.Delay(Constants.TimeDelay);
            }
        }, cancellationToken);
    }

    private static ulong GetFibonacci(ulong number)
    {
        return number <= 1 ? number : GetFibonacci(number - 1) + GetFibonacci(number - 2);
    }

    private static void Restart()
    {
        if (PrimesCancellationTokenSource == null && FibonacciCancellationTokenSource == null)
            return;

        if (PrimesCancellationTokenSource != null &&
            PrimesCancellationTokenSource?.IsCancellationRequested == false)
        {
            CancelPrintPrimes();
            PrimesCancellationTokenSource = new();
        }

        if (FibonacciCancellationTokenSource != null &&
            FibonacciCancellationTokenSource?.IsCancellationRequested == false)
        {
            CancelPrintFibonacci();
            FibonacciCancellationTokenSource = new();
        }

        if (PrimesCancellationTokenSource != null &&
            PrimesCancellationTokenSource?.IsCancellationRequested == false)
            GenerateAndPrintPrimes(PrimesCancellationTokenSource.Token);

        if (FibonacciCancellationTokenSource != null &&
            FibonacciCancellationTokenSource?.IsCancellationRequested == false)
            GenerateAndPrintFibonacci(FibonacciCancellationTokenSource.Token);
    }

    private static void Exit()
    {
        if (PrimesCancellationTokenSource != null)
            CancelPrintPrimes();

        if (FibonacciCancellationTokenSource != null)
            CancelPrintFibonacci();

        IsExit = true;
    }

    private static void PausePrintPrimes()
    {
        ManualResetPrimesEvent.Reset();
    }

    private static void PausePrintFibonacci()
    {
        ManualResetFibonacciEvent.Reset();
    }

    private static void ResumePrintPrimes()
    {
        ManualResetPrimesEvent.Set();
    }

    private static void ResumePrintFibonacci()
    {
        ManualResetFibonacciEvent.Set();
    }

    private static void CancelPrintPrimes()
    {
        PrimesCancellationTokenSource?.Cancel();
        ManualResetPrimesEvent.Reset();
    }

    private static void CancelPrintFibonacci()
    {
        FibonacciCancellationTokenSource?.Cancel();
        ManualResetFibonacciEvent.Reset();
    }
}