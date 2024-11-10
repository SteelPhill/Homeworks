using System;

namespace Game2048;

public static class Program
{
	[STAThread]
	public static void Main()
	{
        Locator.Current.Locate<App>().Run();
	}
}