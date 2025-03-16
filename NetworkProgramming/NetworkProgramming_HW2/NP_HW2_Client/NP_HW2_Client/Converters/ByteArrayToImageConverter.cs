using System.Globalization;
using System.Windows.Data;
using System.Windows.Media.Imaging;

namespace NP_HW2_Client.Converters;

public class ByteArrayToImageConverter : IValueConverter
{
    public object? Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        if (value is byte[] imageBytes && imageBytes.Length > 0)
        {
            var bitmapImage = new BitmapImage();
            using (var stream = new System.IO.MemoryStream(imageBytes))
            {
                bitmapImage.BeginInit();
                bitmapImage.CacheOption = BitmapCacheOption.OnLoad;
                bitmapImage.StreamSource = stream;
                bitmapImage.EndInit();
            }
            return bitmapImage;
        }

        return null;
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}