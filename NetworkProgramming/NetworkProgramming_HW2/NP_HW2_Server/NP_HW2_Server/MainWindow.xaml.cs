using System.Collections.ObjectModel;
using System.Windows;
using NP_HW2_Server.Common.Loggers;
using NP_HW2_Server.Database.Context;
using NP_HW2_Server.Logic;

namespace NP_HW2_Server;

/*
 *          Задание №1
 *          
 * Создайте серверное приложение с помощью, которого можно узнавать кулинарные рецепты.
 * Типичный пример работы:
 * - клиентское приложение подключается к серверу;
 * - клиентское приложение посылает запрос с указанием списка продуктов;
 * - сервер возвращает рецепты, содержащие указанные продукты;
 * - клиент может послать новый запрос или отключиться. 
 * Одновременно к серверу может быть подключено большое количество клиентов.
 * 
 *          Задание №2
 *          
 * Добавьте к первому заданию ограничение по количеству запросов 
 * для конкретного клиента за определенный промежуток времени. 
 * Например, клиент не может послать больше, чем 10 запросов за час.
 * 
 *          Задание №3
 *          
 * Добавьте оконный интерфейс для управления сервером. 
 * Также добавьте оконный интерфейс для управления клиентом.
 * 
 *          Задание №4
 *          
 * Добавьте механизм логирования в сервер. 
 * Этот механизм должны сохранять информацию о клиентах, их запросах, времени соединения и т.д
 * 
 *          Задание №5
 *          
 * Добавьте в ответ сервера картинку финального блюда. 
 * Например, если сервер возвращает рецепт салата Цезарь, 
 * нужно послать клиенту сам рецепт, а также изображение уже готового салата Цезарь.
 * 
 */

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    private readonly IServerManager _tcpServerLogic;

    public ObservableCollection<string> LogMessages { get; set; } = [];

    public MainWindow()
    {
        InitializeComponent();

        DataContext = this;

        _tcpServerLogic = new RecipeTcpServerManager(
            new ApplicationContext(),
            new FileLogger(),
            new UILogger(LogMessages));
    }

    private async void Start_Click(object sender, RoutedEventArgs e)
    {
        StartButton.IsEnabled = false;
        StopButton.IsEnabled = true;

        InfoTextBlock.Text = "Сервер запущен!";

        await Task.Run(() => _tcpServerLogic.StartAsync());
    }

    private void Stop_Click(object sender, RoutedEventArgs e)
    {
        StartButton.IsEnabled = true;
        StopButton.IsEnabled = false;

        InfoTextBlock.Text = "Работа сервера остановлена!";

        _tcpServerLogic.Stop();
    }
}