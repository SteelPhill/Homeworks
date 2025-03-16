namespace NP_HW2_Client.Logic;

public interface IClientManager
{
    Task ConnectAsync();
    void Disconnect();
    Task<TValue?> SendAsync<TValue>(string message);
}