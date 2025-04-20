namespace ASP_NET_Core_HW2.Common.Extensions;

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