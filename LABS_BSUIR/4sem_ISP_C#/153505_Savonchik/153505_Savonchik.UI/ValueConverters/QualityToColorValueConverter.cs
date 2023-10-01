using System.Globalization;

namespace _153505_Malihtorovich.UI.ValueConverters
{
    public class QualityToColorValueConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if ((int)value < 4)
                return Colors.LightPink;

            return Colors.WhiteSmoke;
        }
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
