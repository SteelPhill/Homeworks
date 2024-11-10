using Game2048.Entities;
using MahApps.Metro.Converters;
using System;
using System.Globalization;

namespace Game2048.Converters;

public class CellValuesToBackgroundConverter : MarkupConverter
{
    protected override object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        if (value is not CellValues cellValues)
            throw new Exception("Argument value is not CellValues");

        switch (cellValues)
        {
            case CellValues.Empty:
                return Utile.StateValueColor[CellValues.Empty].Background;
            case CellValues.Two:
                return Utile.StateValueColor[CellValues.Two].Background;
            case CellValues.Four:
                return Utile.StateValueColor[CellValues.Four].Background;
            case CellValues.Eight:
                return Utile.StateValueColor[CellValues.Eight].Background;
            case CellValues.Sixteen:
                return Utile.StateValueColor[CellValues.Sixteen].Background;
            case CellValues.ThirtyTwo:
                return Utile.StateValueColor[CellValues.ThirtyTwo].Background;
            case CellValues.SixtyFour:
                return Utile.StateValueColor[CellValues.SixtyFour].Background;
            case CellValues.OneHundredTwentyEight:
                return Utile.StateValueColor[CellValues.OneHundredTwentyEight].Background;
            case CellValues.TwoHundredFiftySix:
                return Utile.StateValueColor[CellValues.TwoHundredFiftySix].Background;
            case CellValues.FiveHundredTwelve:
                return Utile.StateValueColor[CellValues.FiveHundredTwelve].Background;
            case CellValues.OneThousandTwentyFour:
                return Utile.StateValueColor[CellValues.OneThousandTwentyFour].Background; 
            case CellValues.TwoThousandFortyEight:
                return Utile.StateValueColor[CellValues.TwoThousandFortyEight].Background;
            default:
                throw new Exception("Invalid CellValues");
        }
    }

    protected override object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}