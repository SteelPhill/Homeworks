using System;

namespace Game2048;

public static class Constants
{
    public static readonly string UsersFileName = "2048UsersDB.xml";
    public static readonly string UsersFilePath = Environment.CurrentDirectory + "\\" + UsersFileName;
    public static readonly int FieldSideSize = 4;
    public static readonly int NinetyPercent = 90;
    public static readonly int OneHundredPercent = 100;
    public static readonly int InitialNonEmptyCellsNumber = 2;
    public static readonly string FileReadingError = $"The file \"Users.xml\" it is impossible to read.{Environment.NewLine}" +
        $"To run the program, it must be corrected or deleted.{Environment.NewLine}If you delete it, all achievements will be lost.";

}