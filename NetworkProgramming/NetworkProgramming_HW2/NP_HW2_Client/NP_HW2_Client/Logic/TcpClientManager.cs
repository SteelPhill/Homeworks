using Newtonsoft.Json;
using NP_HW2_Client.Common.Extensions;
using System.Net.Sockets;

namespace NP_HW2_Client.Logic;

public class TcpClientManager : IClientManager
{
    private DateTime firstRequestTime;
    private int requestCount = 0;

    private TcpClient? _client;
    private NetworkStream? _stream;

    public async Task ConnectAsync()
    {
        _client = new TcpClient();

        try
        {
            await _client.ConnectAsync(Constants.ServerIP, Constants.ServerPort);
        }
        catch
        {
            throw new Exception("Не удалось подключится к серверу!");
        }

        _stream = _client.GetStream();
    }

    public async Task<TValue?> SendAsync<TValue>(string message)
    {
        if (_client == null || !_client.Connected)
            throw new Exception("Отсутствует подключение к серверу!");

        if (firstRequestTime.AddHours(1) <= DateTime.Now)
            requestCount = 0;

        if (requestCount >= Constants.MaxRequestsPerHour)
            throw new Exception("Превышено количество запросов в час (10)!");

        if (requestCount == 0)
            firstRequestTime = DateTime.Now;     

        string? input;

        try
        {
            await StreamExtensions.WriteToStreamAsync(_stream!, message, CancellationToken.None);

            input = await StreamExtensions.ReadFromStreamAsync(_stream!, CancellationToken.None);
        }
        catch
        {
            throw new Exception("Соединение с сервером разорвано!");
        }

        if (input == null)
            throw new Exception("Соединение с сервером разорвано!");

        var values = JsonConvert.DeserializeObject<TValue>(input);

        requestCount++;

        return values;
    }

    public void Disconnect()
    {
        _stream?.Close();
        _client?.Close();
    }
}