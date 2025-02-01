using System;

namespace SystemProgramming_HW_1;

public static class StaticMessageBox
{
    public enum Button
    {
        Оk = 0,
        ОkCancel = 1,
        YesNo = 4
    }

    public enum Answer
    {
        Cancel = 2,
        Yes = 6,
        No = 7
    }

    public static Answer Show(string text, string caption, Button button)
    {
        return (Answer)WinApi.MessageBox(IntPtr.Zero, text, caption, (uint)button);
    }
}