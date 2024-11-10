using System.Windows.Controls.Primitives;
using System.Windows.Input;

namespace WPFHomework.Entities;

public class SystemButton
{
    public Key Key { get; set; }
    public ToggleButton Button { get; set; }

    public SystemButton(Key key, ToggleButton button)
    {
        Key = key;
        Button = button;
    }
}