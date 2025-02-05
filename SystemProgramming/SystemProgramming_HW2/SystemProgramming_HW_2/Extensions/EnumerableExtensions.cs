using System;
using System.Collections.Generic;

namespace SystemProgramming_HW_2.Extensions;

public static class EnumerableExtensions
{
    public static void ForEach<TValue>(this IEnumerable<TValue> values, Action<TValue> action)
    {
        foreach (var value in values)
            action(value);
    }

    public static IEnumerable<T> AsEnumerable<T>(this T item)
    {
        yield return item;
    }
}