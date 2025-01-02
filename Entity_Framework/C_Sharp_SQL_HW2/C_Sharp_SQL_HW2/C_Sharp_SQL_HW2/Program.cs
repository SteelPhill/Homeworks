using C_Sharp_SQL_HW2.Menus;
using C_Sharp_SQL_HW2.Menus.Logic;

namespace C_Sharp_SQL_HW2;

public static class Program
{
    public static async Task Main()
    {
        await StaticConsoleMenu.RunAsync(typeof(MainMenu));
    }
}