using System.Windows;
using System.Windows.Controls;

namespace WPFHomework;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    /*     
     *          Урок №1 (Задание №1)
     *          
     * Необходимо разработать приложение содержащее набор кнопок, 
     * занимающих 2/3 ширины окна при любых его размерах.
     * Каждая кнопка должна в качестве содержимого отображать
     * название цвета и обладать наружным отступом равным 2.0.
     * Также соответствующий цвет должен использоваться в качестве
     * цвета переднего плана кнопки.
     * Необходимо использовать следующий набор цветов:
     * Navy, Blue, Aqua, Teal, Olive, Green, Lime, Yellow, Orange, 
     * Red, Maroon, Fuchsia, Purple, Black, Silver, Gray, White.
     * 
     */

    private void Button_Click(object sender, RoutedEventArgs e)
    {
        if (sender is not Button button)
            return;

        ChangingColor.Background = button.Foreground;
    }
}