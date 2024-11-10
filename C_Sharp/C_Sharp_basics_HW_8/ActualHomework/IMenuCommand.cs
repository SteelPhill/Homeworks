namespace ActualHomework;

public interface IMenuCommand
{
    string GetDiscription();
    void Execute(Team team);
}