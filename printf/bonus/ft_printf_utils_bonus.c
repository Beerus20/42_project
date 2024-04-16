#include <stdio.h>
#include "../includes/ft_printf_utils.h"
#include "../includes/ft_utils_bonus.h"

int	ft_get_size(const char *format, va_list args)
{
	int	i;
	int	len;
	int	width;
	int	prec;
	int	r_value;

	i = 0;
	width = ft_get_width((char *)format);
	prec = ft_get_precision((char *)format);
	r_value = width;
	while (!ft_check_desc(format[i]))
		i++;
	len = ft_len_value(&((char *)format)[i], args);
	len += ft_check_extra_len((char *)format);
	if ((width < prec) && !ft_strchr("csp", format[i]))
		r_value = prec;
	if (len >= width)
		r_value = len;
	return (r_value);
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
			len += ft_get_size(&format[i + 1], args);
			i++;
			while (!ft_check_desc(format[i]))
				i++;
		}
		i++;
	}
	return (len);
}
