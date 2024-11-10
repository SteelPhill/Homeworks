using Game2048.Entities;
using System;
using System.Collections.Generic;
using System.Windows.Media;

namespace Game2048;

public static class Utile
{
    public static readonly Dictionary<CellValues, (Brush Background, Brush Foreground)> StateValueColor = new()
    {
         { CellValues.Empty, (Brushes.LightGray, Brushes.LightGray) },
         { CellValues.Two, (Brushes.White, Brushes.Gray) },
         { CellValues.Four, (Brushes.Cornsilk, Brushes.Gray) },
         { CellValues.Eight, (Brushes.SandyBrown, Brushes.White) },
         { CellValues.Sixteen, (Brushes.Coral, Brushes.White) },
         { CellValues.ThirtyTwo, (Brushes.Tomato, Brushes.White) },
         { CellValues.SixtyFour, (Brushes.OrangeRed, Brushes.White) },
         { CellValues.OneHundredTwentyEight, (new SolidColorBrush(Color.FromRgb(255,200,80)), Brushes.White) },
         { CellValues.TwoHundredFiftySix, (new SolidColorBrush(Color.FromRgb(255,200,60)), Brushes.White) },
         { CellValues.FiveHundredTwelve, (new SolidColorBrush(Color.FromRgb(255,200,40)), Brushes.White) },
         { CellValues.OneThousandTwentyFour, (new SolidColorBrush(Color.FromRgb(255,200,20)), Brushes.White) },
         { CellValues.TwoThousandFortyEight, (new SolidColorBrush(Color.FromRgb(255,200,0)), Brushes.White) }
    };

    public static readonly Random Random = new();
}