using System;
using System.Runtime.InteropServices;

namespace SystemProgramming_HW_2;

public static class WinApi
{
    public const uint WM_SETTEXT = 0x0C;
    public const uint WM_CLOSE = 0x10;

    [DllImport("user32.dll")]
    public static extern int MessageBox(
        IntPtr hWnd,
        string lpText,
        string lpCaption,
        uint uType);

    [DllImport("user32.dll")]
    public static extern IntPtr SendMessage(
        IntPtr hWnd,
        uint msg,
        int wParam,
        [MarshalAs(UnmanagedType.LPStr)] string lParam);

    [DllImport("user32.dll")]
    public static extern IntPtr FindWindow(
        string lpClassName,
        string lpWindowName);

    [DllImport("kernel32.dll")]
    public static extern bool Beep(
        uint dwFreq,
        uint dwDuration);

    [DllImport("user32.dll")]
    public static extern void MessageBeep(uint uType);
}