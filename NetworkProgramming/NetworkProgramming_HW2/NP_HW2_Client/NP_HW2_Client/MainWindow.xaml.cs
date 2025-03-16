using NP_HW2_Client.Domain.Entities;
using NP_HW2_Client.Logic;
using System.Windows;
using System.Windows.Controls;

namespace NP_HW2_Client;

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
    private readonly IClientManager _tcpClientLogic = new TcpClientManager();

    public MainWindow()
    {
        InitializeComponent();
    }

    private async void Start_Click(object sender, RoutedEventArgs e)
    {
        try
        {
            await _tcpClientLogic.ConnectAsync();

            StartButton.IsEnabled = false;
            StopButton.IsEnabled = true;
            SendButton.IsEnabled = true;

            InfoTextBlock.Text = "Готов к работе!";
        }
        catch (Exception exception)
        {
            InfoTextBlock.Text = exception.Message;
        }
    }

    private void Stop_Click(object sender, RoutedEventArgs e)
    {
        _tcpClientLogic.Disconnect();

        StartButton.IsEnabled = true;
        StopButton.IsEnabled = false;
        SendButton.IsEnabled = false;

        InfoTextBlock.Text = "Соединение разорвано!";
        ErrorTextBlock.Text = "";
    }

    private async void Send_Click(object sender, RoutedEventArgs e)
    {      
        ErrorTextBlock.Text = "";
        SendButton.IsEnabled = false;

        try
        {
            ItemsControl.ItemsSource = await _tcpClientLogic.SendAsync<List<Recipe>>(RequestTextBox.Text);
            ResultTitleTextBlock.Text = "Список блюд, содержащих введенные ингредиенты:";
        }
        catch (Exception exception)
        {
            ErrorTextBlock.Text = exception.Message;
        }
        finally
        {
            SendButton.IsEnabled = true;
        }
    }
}