﻿using System;

namespace SystemProgramming_HW_1.Extensions;

public static class DateTimeExtensions
{
    public static DateOnly ToDateOnly(this DateTime dateTime)
    {
            return DateOnly.FromDateTime(dateTime);
    }
}