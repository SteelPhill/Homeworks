namespace ASP_NET_Core_HW3.Common.Extensions;

public static class DateTimeExtensions
{
    public static DateOnly ToDateOnly(this DateTime dateTime)
    {
        return DateOnly.FromDateTime(dateTime);
    }
}