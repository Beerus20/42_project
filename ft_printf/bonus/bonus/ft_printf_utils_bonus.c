#include "../includes/ft_printf_utils.h"

int	ft_get_width(const char *format, va_list args)
{
	int	i;
	int	len;
	int	width;
	int	prec;

	i = 0;
	width = ft_get_width(format[i]);
	prec = ft_get_precision(format[i]);
	len = ft_len_value(format[i]);
}

int	ft_get_len(const char *format, va_list args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len++;
		else
		{
			len += ft_len_value(format[i + 1], args);
			i++;
		}
		i++;
	}
	return (len);
}