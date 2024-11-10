namespace HomeworkCSharp;

interface IMenu
{
    void AddCommand(IMenuCommand command);
    void Start();
}