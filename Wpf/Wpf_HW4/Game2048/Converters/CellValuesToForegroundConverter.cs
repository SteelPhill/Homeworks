using Game2048.Entities;
using MahApps.Metro.Converters;
using System;
using System.Globalization;

namespace Game2048.Converters;

public class CellValuesToForegroundConverter : MarkupConverter
{
    protected override object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        if (value is not CellValues cellValues)
            throw new Exception("Argument value is not CellValues");

        switch (cellValues)
        {
            case CellValues.Empty:
                return Utile.StateValueColor[CellValues.Empty].Foreground;
            case CellValues.Two:
                return Utile.StateValueColor[CellValues.Two].Foreground;
            case CellValues.Four:
                return Utile.StateValueColor[CellValues.Four].Foreground;
            case CellValues.Eight:
                return Utile.StateValueColor[CellValues.Eight].Foreground;
            case CellValues.Sixteen:
                return Utile.StateValueColor[CellValues.Sixteen].Foreground;
            case CellValues.ThirtyTwo:
                return Utile.StateValueColor[CellValues.ThirtyTwo].Foreground;
            case CellValues.SixtyFour:
                return Utile.StateValueColor[CellValues.SixtyFour].Foreground;
            case CellValues.OneHundredTwentyEight:
                return Utile.StateValueColor[CellValues.OneHundredTwentyEight].Foreground;
            case CellValues.TwoHundredFiftySix:
                return Utile.StateValueColor[CellValues.TwoHundredFiftySix].Foreground;
            case CellValues.FiveHundredTwelve:
                return Utile.StateValueColor[CellValues.FiveHundredTwelve].Foreground;
            case CellValues.OneThousandTwentyFour:
                return Utile.StateValueColor[CellValues.OneThousandTwentyFour].Foreground;
            case CellValues.TwoThousandFortyEight:
                return Utile.StateValueColor[CellValues.TwoThousandFortyEight].Foreground;
            default:
                throw new Exception("Invalid CellValues");
        }
    }

    protected override object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}