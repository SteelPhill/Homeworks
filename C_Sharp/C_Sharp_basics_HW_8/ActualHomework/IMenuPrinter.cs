using System.Collections.Generic;

namespace ActualHomework;

interface IMenuPrinter
{
    void Print(
        string programName,
        List<IMenuCommand> commands,
        int selector);
}