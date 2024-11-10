using System.Collections.Generic;

namespace ActualHomework;

interface IMenuSelector
{
    int Select(
        string programName,
        List<IMenuCommand> commands,
        int selector);
}