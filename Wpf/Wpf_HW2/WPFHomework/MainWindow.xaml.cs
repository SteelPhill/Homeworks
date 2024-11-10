using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;

namespace WPFHomework;

/*          Урок №1 (Задание №2)
 *    
 * Необходимо разработать приложение «Калькулятор».
 * В верхней части приложения необходимо использовать два поля для ввода текста.
 * Первое используется для отображения предыдущих операций, а второе - для ввода текущего числа.
 * Оба поля должны запрещать редактировать свое содержимое посредством клавиатурного ввода. 
 * Данные поля будут заполняться автоматически при нажатии на соответствующие кнопки, расположенные ниже.
 * Кнопки «0» - «9» добавляют соответствующую цифру в конец текущего числа.
 * При этом должны выполняться проверки, не допускающие неправильного ввода.
 * Например, нельзя вводить числа, начинающиеся с ноля, после которого нет десятичной точки.
 * Кнопка «.» добавляет (если это возможно) десятичную точку в текущее число.
 * Кнопки «/», «*», «+», «-» выполняют соответствующую операцию над результатом предыдущей операции
 * и текущим числом.
 * Кнопка «=» вычисляет выражение и выводит результат.
 * Кнопка «CE» очищает текущее число.
 * Кнопка «C» очищает текущее число и предыдущее выражение.
 * Кнопка «<» очищает последний введенный символ в текущем числе (выражении).
 *    
 */

public enum Digits
{
    Zero = '0',
    One = '1',
    Two = '2',
    Three = '3',
    Four = '4',
    Five = '5',
    Six = '6',
    Seven = '7',
    Eight = '8',
    Nine = '9'
}

public enum OperatorTypes
{
    Multiplication,
    Division,
    Summation,
    Difference
}

public enum ErrorTypes
{
    DivisionByZero,
    IncorrectExpression,
    OutOfValidRange
}

public partial class Calculator : Window
{
    private static readonly decimal Epsilon = 1E-14M;
    private static readonly char Point = ',';
    private static readonly char Space = ' ';
    private static readonly Dictionary<OperatorTypes, char> SupportedOperators = new()
    {
        { OperatorTypes.Multiplication, '*' },
        { OperatorTypes.Division, '/' },
        { OperatorTypes.Summation, '+' },
        { OperatorTypes.Difference, '-' }
    };
    private static readonly Dictionary<ErrorTypes, string> Errors = new()
    {
        { ErrorTypes.DivisionByZero, "<Division by zero>" },
        { ErrorTypes.IncorrectExpression, "<Incorrect expression>" },
        { ErrorTypes.OutOfValidRange, "<Out of valid range>" }
    };

    private bool isFraction;

    public Calculator()
    {
        InitializeComponent();
    }

    private decimal Calculate(decimal left, decimal right, string operation)
        => operation switch
    {
        "*" => left * right,
        "/" => left / right,
        "+" => left + right,
        "-" => left - right,
        _ => default
    };

    private bool CheckLastSymbolEquals(string expression, char symbol)
        => expression.Last() == symbol;

    private bool CheckLastWasOperation(string expression, OperatorTypes operation)
        => expression[expression.Length - 2]
        == SupportedOperators[operation];

    private bool IsDivisionByZero(string operation, decimal rightNumber)
       => operation == SupportedOperators[OperatorTypes.Division].ToString()
       && rightNumber == 0;

    private bool IsFirstPriorityOperation(string operation)
        => operation == SupportedOperators[OperatorTypes.Multiplication].ToString()
        || operation == SupportedOperators[OperatorTypes.Division].ToString();

    private bool IsLastWasFraction(string expression)
        => expression.Reverse().TakeWhile(c => c != Space).Any(c => c == Point);

    private bool IsLastWasMessageError(string text)
        => Errors.Any(p => p.Value == text);

    private bool IsLastWasOperation(string expression)
        => expression.Length > 2 && SupportedOperators.Values.Contains(
            expression[expression.Length - 2]);

    private string ReplaceByIndex(string text, int index, char symbol)
        => text.Remove(text.Length - 1).Insert(text.Length - 1, symbol.ToString());

    private decimal DiscardZerosAfterPoint(decimal value)
    {
        if (Math.Abs(value % 1) < Epsilon)
            return (long)value;

        return decimal.Parse(new string(value.ToString()
            .Reverse()
            .SkipWhile(c => c == (char)Digits.Zero)
            .Reverse()
            .ToArray()));
    }

    private bool IsLastNumberContainsOneDigit(string expression)
    {
        if (expression.Length == 1)
            return true;

        if (expression.Length >= 3 && SupportedOperators.Any(
            p => p.Value == expression[expression.Length - 3]))
            return true;

        return false;
    }

    private void NotZeroDigitClick(char digit)
    {
        if (IsLastWasMessageError(LargeTextBlock.Text))
            LargeTextBlock.Text = string.Empty;

        if (IsLastNumberContainsOneDigit(LargeTextBlock.Text)
            && CheckLastSymbolEquals(LargeTextBlock.Text, (char)Digits.Zero))
            LargeTextBlock.Text = ReplaceByIndex(
                LargeTextBlock.Text, LargeTextBlock.Text.Length - 1, digit);
        else
            LargeTextBlock.Text += digit;
    }

    private void OperationClick(OperatorTypes operation)
    {
        if (IsLastWasMessageError(LargeTextBlock.Text))
            LargeTextBlock.Text = string.Empty;

        var isLastWasOperation = IsLastWasOperation(LargeTextBlock.Text);

        if (LargeTextBlock.Text == string.Empty
            || CheckLastSymbolEquals(LargeTextBlock.Text, Point)
            || isLastWasOperation
            && CheckLastWasOperation(LargeTextBlock.Text, operation))
            return;

        if (isLastWasOperation)
            LargeTextBlock.Text =
                LargeTextBlock.Text.Remove(LargeTextBlock.Text.Length - 3);

        LargeTextBlock.Text +=
            $" {SupportedOperators[operation]} ";

        isFraction = false;
    }

    private bool TryGetExpressionResult(
        List<string> operators,
        List<decimal> numbers,
        out decimal result)
    {
        result = 0;

        for (var i = 0; i < operators.Count; i++)
        {
            if (IsFirstPriorityOperation(operators[i]))
            {
                if (IsDivisionByZero(operators[i], numbers[i + 1]))
                    return false;

                numbers[i] =
                    Calculate(numbers[i], numbers[i + 1], operators[i]);

                numbers.RemoveAt(i + 1);
                operators.RemoveAt(i);
                i--;
            }
        }

        for (var i = 0; i < operators.Count; i++)
        {
            numbers[i] =
                Calculate(numbers[i], numbers[i + 1], operators[i]);

            numbers.RemoveAt(i + 1);
            operators.RemoveAt(i);
            i--;
        }

        result = numbers[0];
        return true;
    }

    private void Equally_Click(object sender, RoutedEventArgs e)
    {
        if (LargeTextBlock.Text == string.Empty
            || IsLastWasOperation(LargeTextBlock.Text))
            return;

        if (IsLastWasMessageError(LargeTextBlock.Text))
        {
            LargeTextBlock.Text = string.Empty;
            return;
        }

        isFraction = false;

        var operators = LargeTextBlock.Text
            .Split(Space)
            .Where(s => s.Length == 1 && SupportedOperators.Values.Contains(
                s.First()))
            .ToList();

        var numbersAsString = LargeTextBlock.Text
            .Split(Space)
            .Where(s => !SupportedOperators.Values.Contains(s.Last()))
            .ToList();

        try
        {
            var numbers = numbersAsString.Select(decimal.Parse).ToList();

            if (numbers.Count == 1 && operators.Count == 0)
            {
                numbers[0] = DiscardZerosAfterPoint(numbers[0]);
                SmallTextBlock.Text = LargeTextBlock.Text = numbers[0].ToString();

                if (!long.TryParse(numbers.First().ToString(), out var _))
                    isFraction = true;
                return;
            }

            if (!TryGetExpressionResult(operators, numbers, out var result))
            {
                LargeTextBlock.Text = Errors[ErrorTypes.DivisionByZero];
                return;
            }

            SmallTextBlock.Text = LargeTextBlock.Text;

            result = DiscardZerosAfterPoint(result);
            LargeTextBlock.Text = result.ToString();

            if (!long.TryParse(result.ToString(), out _))
                isFraction = true;
        }
        catch (FormatException)
        {
            LargeTextBlock.Text = Errors[ErrorTypes.IncorrectExpression];
        }
        catch (OverflowException)
        {
            LargeTextBlock.Text = Errors[ErrorTypes.OutOfValidRange];
        }
    }

    private void Backspace_Click(object sender, RoutedEventArgs e)
    {
        if (LargeTextBlock.Text == string.Empty)
            return;

        if (IsLastWasMessageError(LargeTextBlock.Text))
        {
            LargeTextBlock.Text = string.Empty;
            return;
        }

        if (CheckLastSymbolEquals(LargeTextBlock.Text, Point))
            isFraction = false;

        if (IsLastWasOperation(LargeTextBlock.Text))
            LargeTextBlock.Text =
                LargeTextBlock.Text.Remove(LargeTextBlock.Text.Length - 2);

        LargeTextBlock.Text =
            LargeTextBlock.Text.Remove(LargeTextBlock.Text.Length - 1);

        if (LargeTextBlock.Text.Length == 1 && CheckLastSymbolEquals(
            LargeTextBlock.Text, SupportedOperators[OperatorTypes.Difference]))
            LargeTextBlock.Text = 
                LargeTextBlock.Text.Remove(LargeTextBlock.Text.Length - 1);

        if (IsLastWasFraction(LargeTextBlock.Text))
            isFraction = true;
    }

    private void Point_Click(object sender, RoutedEventArgs e)
    {
        if (isFraction || LargeTextBlock.Text == string.Empty
            || IsLastWasOperation(LargeTextBlock.Text))
            return;

        if (IsLastWasMessageError(LargeTextBlock.Text))
        {
            LargeTextBlock.Text = string.Empty;
            return;
        }

        if (!isFraction)
            LargeTextBlock.Text += Point;

        isFraction = true;
    }

    private void CE_Click(object sender, RoutedEventArgs e)
    {
        LargeTextBlock.Text = string.Empty;
        isFraction = false;
    }

    private void C_Click(object sender, RoutedEventArgs e)
    {
        LargeTextBlock.Text = SmallTextBlock.Text = string.Empty;
        isFraction = false;
    }

    private void Multiplication_Click(object sender, RoutedEventArgs e)
        => OperationClick(OperatorTypes.Multiplication);

    private void Division_Click(object sender, RoutedEventArgs e)
        => OperationClick(OperatorTypes.Division);

    private void Plus_Click(object sender, RoutedEventArgs e)
        => OperationClick(OperatorTypes.Summation);

    private void Minus_Click(object sender, RoutedEventArgs e)
        => OperationClick(OperatorTypes.Difference);

    private void Zero_Click(object sender, RoutedEventArgs e)
    {
        if (IsLastWasMessageError(LargeTextBlock.Text))
            LargeTextBlock.Text = string.Empty;

        if (IsLastNumberContainsOneDigit(LargeTextBlock.Text)
            && CheckLastSymbolEquals(LargeTextBlock.Text, (char)Digits.Zero))
            return;

        LargeTextBlock.Text += (char)Digits.Zero;
    }

    private void One_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.One);

    private void Two_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Two);

    private void Three_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Three);

    private void Four_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Four);

    private void Five_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Five);

    private void Six_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Six);

    private void Seven_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Seven);

    private void Eight_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Eight);

    private void Nine_Click(object sender, RoutedEventArgs e)
        => NotZeroDigitClick((char)Digits.Nine);
}