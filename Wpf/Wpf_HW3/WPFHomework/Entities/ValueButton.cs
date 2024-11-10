using System.Windows.Controls.Primitives;
using System.Windows.Input;

namespace WPFHomework.Entities;

public class ValueButton
{
    public Key Key { get; set; }
    public ToggleButton Button { get; set; }
    public char LowercaseValue { get; set; }
    public char UppercaseValue { get; set;}

    public ValueButton(Key key, ToggleButton button, char lowercaseValue, char uppercaseValue)
    {
        Key = key;
        Button = button;
        LowercaseValue = lowercaseValue;
        UppercaseValue = uppercaseValue;
    }
}