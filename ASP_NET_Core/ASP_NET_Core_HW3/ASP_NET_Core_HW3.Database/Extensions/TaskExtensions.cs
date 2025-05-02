namespace ASP_NET_Core_HW3.Database.Extensions;

public static class TaskExtensions
{
	public static async void FireAndForgetSafeAsync(this Task task)
	{
		try
		{
			await task.ConfigureAwait(false);
		}
		catch (Exception)
		{
			// ignored
		}
	}
}