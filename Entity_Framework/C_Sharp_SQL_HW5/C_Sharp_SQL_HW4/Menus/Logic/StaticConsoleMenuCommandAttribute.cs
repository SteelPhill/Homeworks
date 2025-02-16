namespace C_Sharp_SQL_HW4.Menus.Logic;

[AttributeUsage(AttributeTargets.Method)]
public class StaticConsoleMenuCommandAttribute : Attribute
{
	public string DisplayText { get; }

	public StaticConsoleMenuCommandAttribute(string displayText)
	{
		DisplayText = displayText;
	}
}