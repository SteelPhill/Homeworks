using System.Collections.Generic;

namespace HomeworkCSharp;

interface IMenuPrinter
{
    void Print(
        string title,
        List<IMenuCommand> commands,
        ref int selector);
}