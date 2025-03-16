﻿namespace NP_HW2_Client.Common.Extensions;

public static class TaskExtensions
{
	public static async void FireAndForgetSafeAsync(this Task task)
	{
		try
		{
			await task;
		}
		catch
		{
			// ignored
		}
	}
}