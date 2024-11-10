using System.Collections.Generic;

namespace HomeworkCSharp;

interface IMenuSelector
{
    int Select(
        string title,
        List<IMenuCommand> commands,
        ref int selector);
}