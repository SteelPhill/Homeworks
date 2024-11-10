using System;
using System.Windows;
using System.Windows.Input;
using System.Collections.Generic;
using System.IO;
using System.Windows.Controls.Primitives;
using WPFHomework.Helpers;
using WPFHomework.Entities;
using WPFHomework.Enums;
using WPFHomework.Databases;
using System.Windows.Media;
using System.Windows.Documents;
using System.Windows.Controls;

namespace WPFHomework;

/*          Урок №2 (Задание №1)
 *    
 * Необходимо разработать приложение «Клавиатурный тренажер».
 * Главное окно приложения должно отображать клавиатуру с не интерактивными клавишами,
 * которые необходимы для того, чтобы помогать пользователю ориентироваться на клавиатуре, 
 * не смотря на нее.
 * При этом, при нажатии на каждую из клавиш, она должна подсвечиваться на экране. 
 * После запуска тренировочной сессии пользователю должна отобразиться произвольно 
 * сгенерированная строка для ввода, которая учитывает выбранный уровень сложности.
 * В верхней части окна должна отображаться статистическая информация: 
 * скорость набора корректного текста о количество допущенных ошибок.
 * Также в верхней части окна должны располагаться элементы управления, 
 * позволяющие настроить сложность генерируемой строки для ввода. 
 * При помощи «ползунка» пользователь может выбрать количество символов,
 * которые должны использоваться для генерируемой строки.
 * При этом можно указать необходимо ли генерировать строку с учетом регистра символов.
 * В качестве используемых символов могут быть все символы.
 * После нажатия на кнопку «Start» должна сгенерироваться или считаться из файла
 * строка символов с учетом заданных пользователем настроек. 
 * После этого нажимаемые пользователем клавиши должны учитываться и отображаться
 * в виде введенных правильно символов либо в виде ошибок.
 * При нажатии на клавиши Shift и Caps Lock, клавиатура в приложении должна 
 * менять отображаемые символы с учетом реально вводимых.
 * Также необходимо предусмотреть выключение тех элементов управления, 
 * которые не могут использоваться в текущем состоянии приложения.
 * Например, нельзя нажимать кнопку «Stop», если пользователь перед этим не нажал кнопку «Start».
 *    
 */

public partial class KeyboardTrainer : Window
{
    private static readonly ISerializer serializer = new Serializer();
    private static readonly Random random = new();
    private static DateTime startTime = new();

    private readonly ITrainingTextDB trainingTextDB;

    private readonly List<ValueButton> valueButtons = new();
    private readonly List<SystemButton> systemButtons = new();

    private (Key Key, ToggleButton Button, char Value) spaceButton;

    private bool isCapsLockOn;
    private int textIndex;
    private int fails;

    public KeyboardTrainer()
    {
        if (!File.Exists(Constants.TrainingTextsXmlPath))
            TrainingTextXmlCreator.Create();

        try
        {
            trainingTextDB = new TrainingTextDB(serializer
                .Deserialize<List<TrainingText>>(Constants.TrainingTextsXmlPath));
        }
        catch
        {
            MessageBox.Show($"Error when trying to read information from a file" +
                $" \"{Constants.TrainingTextsXmlName}\".{Environment.NewLine}" +
                $"{Environment.NewLine}The file has been deleted and will be " +
                $"recreated the next time the program is started.",
                "Error!");
            File.Delete(Constants.TrainingTextsXmlPath);
            Environment.Exit(0);
        }

        InitializeComponent();

        InitializeButtons();
    }

    private void InitializeButtons()
    {
        spaceButton = (Key.Space, Space, ' ');

        valueButtons.Add(new(Key.Oem3, Oem3, '`', '~'));
        valueButtons.Add(new(Key.D1, D1, '1', '!'));
        valueButtons.Add(new(Key.D2, D2, '2', '@'));
        valueButtons.Add(new(Key.D3, D3, '3', '#'));
        valueButtons.Add(new(Key.D4, D4, '4', '$'));
        valueButtons.Add(new(Key.D5, D5, '5', '%'));
        valueButtons.Add(new(Key.D6, D6, '6', '^'));
        valueButtons.Add(new(Key.D7, D7, '7', '&'));
        valueButtons.Add(new(Key.D8, D8, '8', '*'));
        valueButtons.Add(new(Key.D9, D9, '9', '('));
        valueButtons.Add(new(Key.D0, D0, '0', ')'));
        valueButtons.Add(new(Key.OemMinus, OemMinus, '-', '_'));
        valueButtons.Add(new(Key.OemPlus, OemPlus, '=', '+'));
        valueButtons.Add(new(Key.Q, Q, 'q', 'Q'));
        valueButtons.Add(new(Key.W, W, 'w', 'W'));
        valueButtons.Add(new(Key.E, E, 'e', 'E'));
        valueButtons.Add(new(Key.R, R, 'r', 'R'));
        valueButtons.Add(new(Key.T, T, 't', 'T'));
        valueButtons.Add(new(Key.Y, Y, 'y', 'Y'));
        valueButtons.Add(new(Key.U, U, 'u', 'U'));
        valueButtons.Add(new(Key.I, I, 'i', 'I'));
        valueButtons.Add(new(Key.O, O, 'o', 'O'));
        valueButtons.Add(new(Key.P, P, 'p', 'P'));
        valueButtons.Add(new(Key.Oem4, Oem4, '[', '{'));
        valueButtons.Add(new(Key.Oem6, Oem6, ']', '}'));
        valueButtons.Add(new(Key.Oem5, Oem5, '\\', '|'));
        valueButtons.Add(new(Key.A, A, 'a', 'A'));
        valueButtons.Add(new(Key.S, S, 's', 'S'));
        valueButtons.Add(new(Key.D, D, 'd', 'D'));
        valueButtons.Add(new(Key.F, F, 'f', 'F'));
        valueButtons.Add(new(Key.G, G, 'g', 'G'));
        valueButtons.Add(new(Key.H, H, 'h', 'H'));
        valueButtons.Add(new(Key.J, J, 'j', 'J'));
        valueButtons.Add(new(Key.K, K, 'k', 'K'));
        valueButtons.Add(new(Key.L, L, 'l', 'L'));
        valueButtons.Add(new(Key.Oem1, Oem1, ';', ':'));
        valueButtons.Add(new(Key.Oem7, Oem7, '\'', '"'));
        valueButtons.Add(new(Key.Z, Z, 'z', 'Z'));
        valueButtons.Add(new(Key.X, X, 'x', 'X'));
        valueButtons.Add(new(Key.C, C, 'c', 'C'));
        valueButtons.Add(new(Key.V, V, 'v', 'V'));
        valueButtons.Add(new(Key.B, B, 'b', 'B'));
        valueButtons.Add(new(Key.N, N, 'n', 'N'));
        valueButtons.Add(new(Key.M, M, 'm', 'M'));
        valueButtons.Add(new(Key.OemComma, OemComma, ',', '<'));
        valueButtons.Add(new(Key.OemPeriod, OemPeriod, '.', '>'));
        valueButtons.Add(new(Key.Oem2, Oem2, '/', '?'));

        systemButtons.Add(new(Key.Back, Back));
        systemButtons.Add(new(Key.Tab, Tab));
        systemButtons.Add(new(Key.CapsLock, CapsLock));
        systemButtons.Add(new(Key.Enter, Enter));
        systemButtons.Add(new(Key.LeftShift, LeftShift));
        systemButtons.Add(new(Key.RightShift, RightShift));
        systemButtons.Add(new(Key.LeftCtrl, LeftCtrl));
        systemButtons.Add(new(Key.LWin, LWin));
        systemButtons.Add(new(Key.LeftAlt, LeftAlt));
        systemButtons.Add(new(Key.RightAlt, RightAlt));
        systemButtons.Add(new(Key.RWin, RWin));
        systemButtons.Add(new(Key.RightCtrl, RightCtrl));
    }

    private void AddColoredSymbolToTextBlock(
        TextBlock textBlock,
        char symbol,
        SolidColorBrush color)
    {
        textBlock.Inlines
            .Add(new Run(symbol.ToString()) { Background = color });
    }

    private void ChangeButtonsValueToUppercase()
    {
        foreach (var vb in valueButtons)
            vb.Button.Content = vb.UppercaseValue;
    }

    private void ChangeButtonsValueToLowercase()
    {
        foreach (var vb in valueButtons)
            vb.Button.Content = vb.LowercaseValue;
    }

    private bool IsInputCorrect(ValueButton button)
    {
        if (CaseSensitiveCheckBox.IsChecked == false)
        {
            if (button.LowercaseValue == PBarTBlock1.Text[textIndex] ||
                button.UppercaseValue == PBarTBlock1.Text[textIndex])
                return true;
        }
        else
        {
            if (button.UppercaseValue == PBarTBlock1.Text[textIndex] &&
                ((IsShiftPressed() && !isCapsLockOn) || 
                (!IsShiftPressed() && isCapsLockOn)))
                return true;
            if (button.LowercaseValue == PBarTBlock1.Text[textIndex] &&
                ((!IsShiftPressed() && !isCapsLockOn) || 
                (IsShiftPressed() && isCapsLockOn)))
                return true;
        }

        return false;
    }

    private bool IsShiftPressed()
    {
        return Keyboard.IsKeyDown(Key.LeftShift) ||
            Keyboard.IsKeyDown(Key.RightShift);
    }

    private bool IsTypingFinished()
    {
        return PBarTBlock1.Text.Length + 1 == PBarTBlock2.Text.Length;
    }

    private bool TryGetValueButton(KeyEventArgs e, out ValueButton result)
    {
        foreach (var vb in valueButtons)
            if (e.Key == vb.Key)
            {
                result = vb;
                return true;
            }

        result = null;
        return false;
    }

    private bool TryGetSystemButton(KeyEventArgs e, out SystemButton result)
    {
        foreach (var sb in systemButtons)
            if (e.Key == sb.Key || e.SystemKey == sb.Key)
            {
                result = sb;
                return true;
            }

        result = null;
        return false;
    }

    private void TypingFinished()
    {
        DifficultySlider.IsEnabled = true;
        CaseSensitiveCheckBox.IsEnabled = true;
        Start.IsEnabled = true;
        Stop.IsEnabled = false;

        foreach (var vb in valueButtons)
            vb.Button.IsChecked = false;

        foreach (var sb in systemButtons)
            if (sb.Key != Key.CapsLock)
                sb.Button.IsChecked = false;

        spaceButton.Button.IsChecked = false;

        if (isCapsLockOn)
            ChangeButtonsValueToUppercase();
        else
            ChangeButtonsValueToLowercase();
    }

    private void TypingProgressed(bool isTypingError)
    {
        PBarTBlock2.Inlines.Remove(PBarTBlock2.Inlines.LastInline);

        if (isTypingError)
        {
            AddColoredSymbolToTextBlock(
                PBarTBlock2, PBarTBlock1.Text[textIndex], Brushes.Red);

            FailsTBlock.Text = (++fails).ToString();
        }
        else
            PBarTBlock2.Inlines.Add(PBarTBlock1.Text[textIndex].ToString());

        AddColoredSymbolToTextBlock(PBarTBlock2, Constants.Space, Brushes.Black);

        PBar.Value += 1;
        textIndex++;

        SpeedTBlock.Text =
            ((int)((PBarTBlock2.Text.Length - 1) /
            (DateTime.Now - startTime).TotalMinutes)).ToString();
    }

    private void Keyboard_KeyDown(object sender, KeyEventArgs e)
    {
        if (Start.IsEnabled)
            return;

        bool isTypingError = false;

        if (TryGetValueButton(e, out var vButton))
        {
            isTypingError = !IsInputCorrect(vButton);
            vButton.Button.IsChecked = true;
        }
        else if (e.Key == spaceButton.Key)
        {
            if (PBarTBlock1.Text[textIndex] != spaceButton.Value)
                isTypingError = true;
            spaceButton.Button.IsChecked = true;
        }

        if (vButton != null && vButton.Button.IsChecked == true || 
            spaceButton.Button.IsChecked == true)
        {
            TypingProgressed(isTypingError);

            if (IsTypingFinished())
                TypingFinished();

            return;
        }

        if (TryGetSystemButton(e, out var sButton))
        {
            if (sButton.Key == Key.CapsLock)
            {
                if (sButton.Button.IsChecked == true)
                {
                    ChangeButtonsValueToLowercase();
                    sButton.Button.IsChecked = isCapsLockOn = false;
                }
                else
                {
                    ChangeButtonsValueToUppercase();
                    sButton.Button.IsChecked = isCapsLockOn = true;
                }

                return;
            }

            if (sButton.Key == Key.LeftShift || sButton.Key == Key.RightShift)
                if (isCapsLockOn)
                    ChangeButtonsValueToLowercase();
                else
                    ChangeButtonsValueToUppercase();

            sButton.Button.IsChecked = true;
        }
    }

    private void Keyboard_KeyUp(object sender, KeyEventArgs e)
    {
        if (Start.IsEnabled || e.Key == Key.CapsLock)
            return;

        if (e.Key == spaceButton.Key)
        {
            spaceButton.Button.IsChecked = false;
            return;
        }

        if (TryGetValueButton(e, out var vButton))
        {
            vButton.Button.IsChecked = false;
            return;
        }

        if (TryGetSystemButton(e, out var sButton))
        {
            if (sButton.Key == Key.LeftShift || sButton.Key == Key.RightShift)
                if (isCapsLockOn)
                    ChangeButtonsValueToUppercase();
                else
                    ChangeButtonsValueToLowercase();

            sButton.Button.IsChecked = false;
        } 
    }

    private void Difficulty_ValueChanged(object sender,
        RoutedPropertyChangedEventArgs<double> e)
    {
        DifficultyTBlock.Text = DifficultySlider.Value.ToString();
    }

    private void Start_Click(object sender, RoutedEventArgs e)
    {
        DifficultySlider.IsEnabled = false;
        CaseSensitiveCheckBox.IsEnabled = false;
        Start.IsEnabled = false;
        Stop.IsEnabled = true;

        startTime = DateTime.Now;
        SpeedTBlock.Text = 0.ToString();

        fails = 0;
        FailsTBlock.Text = fails.ToString();

        DifficultyLevels difficulty =
            (DifficultyLevels)int.Parse(DifficultyTBlock.Text);

        PBar.Value = 0;
        textIndex = 0;
        PBarTBlock2.Text = string.Empty;
        AddColoredSymbolToTextBlock(PBarTBlock2, Constants.Space, Brushes.Black);

        int index = 0;

        do
        {
            index = random.Next(0, trainingTextDB.TrainingTexts.Count - 1);

        } while (trainingTextDB.TrainingTexts[index].Difficulty != difficulty);

        PBar.Maximum = trainingTextDB.TrainingTexts[index].Text.Length;
        PBarTBlock1.Text = trainingTextDB.TrainingTexts[index].Text;
    }

    private void Stop_Click(object sender, RoutedEventArgs e)
    {
        TypingFinished();
    }

    private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
    {
        if (e.Key == Key.Tab || e.Key == Key.Enter || e.Key == Key.Space)
        {
            DifficultySlider.Focusable = false;
            CaseSensitiveCheckBox.Focusable = false;
            Start.Focusable = false;
            Stop.Focusable = false;
        }
    }
}