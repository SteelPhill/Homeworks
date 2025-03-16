using System.Net.Sockets;
using System.Net;
using Newtonsoft.Json;
using NP_HW2_Server.Database.Context;
using System.Text.RegularExpressions;
using NP_HW2_Server.Domain.Entities;
using NP_HW2_Server.Common.Loggers;
using NP_HW2_Server.Common.Extensions;

namespace NP_HW2_Server.Logic;

public class RecipeTcpServerManager : IServerManager
{
    private readonly IApplicationContext _applicationContext;
    private readonly ILogger[] _loggers;

    private readonly TcpListener _tcpListener;
    private readonly List<Task> _activeClientTasks;

    private CancellationTokenSource _cancellationTokenSource;

    public RecipeTcpServerManager(IApplicationContext applicationContext, params ILogger[] loggers)
    {
        _applicationContext = applicationContext;
        _loggers = loggers;

        _tcpListener = new TcpListener(IPAddress.Parse(Constants.IP), Constants.Port);
        _activeClientTasks = [];

        _cancellationTokenSource = new();
    }

    public async Task StartAsync()
    {
        _cancellationTokenSource = new();

        try
        {
            _tcpListener.Start();

            _loggers.ForEach(l => l.LogMessage("Сервер запущен"));

            while (!_cancellationTokenSource.Token.IsCancellationRequested)
            {
                try
                {
                    var client = await _tcpListener.AcceptTcpClientAsync(_cancellationTokenSource.Token);
                    var clientTask = HandleClientAsync(client, _cancellationTokenSource.Token);
                    _activeClientTasks.Add(clientTask);
                }
                catch (OperationCanceledException)
                {
                    _loggers.ForEach(l => l.LogMessage("Сервер завершает работу..."));
                    break;
                }
                catch
                {
                    _loggers.ForEach(l => l.LogMessage("Ошибка при подключении клиента"));
                }
            }
        }
        finally
        {
            _tcpListener.Stop();

            await Task.WhenAll(_activeClientTasks);
            _activeClientTasks.Clear();

            _loggers.ForEach(l => l.LogMessage("Работа сервера остановлена"));
        }
    }

    private async Task HandleClientAsync(TcpClient client, CancellationToken token)
    {
        try
        {
            using (client)
            {
                _loggers.ForEach(l => l.LogMessage($"подключен клиент [{client.Client.RemoteEndPoint}]"));

                await using var stream = client.GetStream();

                while (client.Connected && !token.IsCancellationRequested)
                {
                    var input = await StreamExtensions.ReadFromStreamAsync(stream, token);

                    _loggers.ForEach(l => l.LogMessage($"запрос от клиента [{client.Client.RemoteEndPoint}]: {input}"));

                    if (input == null)
                    {
                        _loggers.ForEach(l => l.LogMessage($"отключен клиент [{client.Client.RemoteEndPoint}]"));
                        return;
                    }

                    var ingredients = input
                        .Split(Constants.Separator, StringSplitOptions.RemoveEmptyEntries);

                    var relevantRecipes = new List<Recipe>();

                    foreach (var recipe in _applicationContext.Recipes)
                        foreach (var ingredient in ingredients)
                        {
                            var pattern = @"\b" + Regex.Escape(ingredient.Trim()) + @"\b";

                            var matches = Regex.Matches(
                                string.Join(Constants.Connector, recipe.Ingredients), 
                                pattern, 
                                RegexOptions.IgnoreCase);

                            if (matches.Count > 0)
                                relevantRecipes.Add(recipe);
                        }

                    var response = JsonConvert.SerializeObject(relevantRecipes.Distinct());
                    await StreamExtensions.WriteToStreamAsync(stream, response, token);
                }                
            }
        }
        catch (OperationCanceledException)
        {
            _loggers.ForEach(l => l.LogMessage("Обработка клиентов прервана"));
        }
        catch
        {
            _loggers.ForEach(l => l.LogMessage("Ошибка при обработке запроса"));
        }
    }

    public void Stop()
    {
        _cancellationTokenSource.Cancel();
    }
}