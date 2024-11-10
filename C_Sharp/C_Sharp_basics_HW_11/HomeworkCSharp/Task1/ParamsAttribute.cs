using System;

namespace HomeworkCSharp;

[AttributeUsage(AttributeTargets.Property)]
public class ParamsAttribute : Attribute
{
    public string PropertyIniPath { get; set; }
    public ParamsAttribute(string propertyIniPath)
        => PropertyIniPath = Constants.CurrentDirectory + "\\" + propertyIniPath;
}