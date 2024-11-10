namespace ActualHomework;

interface IMenu
{
    void AddComand(IMenuCommand command);
    void Start(Team team);
}