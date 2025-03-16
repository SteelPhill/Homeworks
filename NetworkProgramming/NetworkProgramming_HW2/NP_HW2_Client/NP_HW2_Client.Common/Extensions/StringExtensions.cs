using System.Text.RegularExpressions;

namespace NP_HW2_Client.Common.Extensions;

public static class StringExtensions
{
	public static string GetRegexGroup(this string str, Regex regex, string groupName)
	{
		return regex.Match(str).Groups[groupName].Value;
	}

	public static int ToInt(this string str)
	{
		return int.Parse(str);
	}

	public static decimal ToDecimal(this string str)
	{
		return decimal.Parse(str);
	}

	public static DateOnly ToDateOnly(this string str)
	{
		return DateOnly.Parse(str);
	}
}