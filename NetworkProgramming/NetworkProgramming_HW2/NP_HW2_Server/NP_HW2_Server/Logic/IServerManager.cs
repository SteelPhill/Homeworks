namespace NP_HW2_Server.Logic;

public interface IServerManager
{
    Task StartAsync();
    void Stop();
}