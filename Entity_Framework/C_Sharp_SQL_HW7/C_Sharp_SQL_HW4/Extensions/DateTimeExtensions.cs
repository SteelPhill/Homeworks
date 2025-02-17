namespace C_Sharp_SQL_HW4.Extensions;

public static class DateTimeExtensions
{
	public static DateOnly ToDateOnly(this DateTime dateTime)
	{
		return DateOnly.FromDateTime(dateTime);
	}
}