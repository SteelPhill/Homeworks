﻿namespace C_Sharp_SQL_HW4.Menus.Logic;

public class StaticConsoleCommand
{
	public string DisplayText { get; }
	public Action? InvokeMethod { get; }
	public Func<Task>? InvokeMethodAsync { get; }

	public StaticConsoleCommand(
		string displayText,
		Action? invokeMethod,
		Func<Task>? invokeMethodAsync)
	{
		DisplayText = displayText;
		InvokeMethod = invokeMethod;
		InvokeMethodAsync = invokeMethodAsync;
	}
}