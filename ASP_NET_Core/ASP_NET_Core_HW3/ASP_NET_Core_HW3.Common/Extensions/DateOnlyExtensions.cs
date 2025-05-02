namespace ASP_NET_Core_HW3.Common.Extensions;

public static class DateOnlyExtensions
{
    public static DateTime ToDateTime(this DateOnly dateOnly)
    {
        return dateOnly.ToDateTime(default);
    }
}