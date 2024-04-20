#include "../includes/ft_add_bonus.h"

void	ft_init_tab_flags(int flags[7])
{
	int	i;

	i = 0;
	while (i < 6)
		flags[i++] = 0;
	flags[i] = -1;
}

int	ft_add_value(char *format, char *text, va_list args)
{
	int	i;
	int	flags[7];

	i = 0;
	ft_init_tab_flags(flags);
	ft_check_flags(format, flags);
	while (!ft_check_desc(format[i]))
		i++;
	if (format[i] == 'c')
		return (ft_add_char_b(text, flags, va_arg(args, int)));
	// if (format[i] == 's')
	// 	return (ft_add_str(text, flags, (char *)va_arg(args, char *)));
	// if (format[i] == 'd' || format[i] == 'i')
	// 	return (ft_add_nb(text, flags, (long)va_arg(args, int)));
	// if (format[i] == 'p')
	// 	return (ft_add_pointer(text, (unsigned long)va_arg(args, void *)));
	// if (format[i] == 'x')
	// 	return (ft_add_unb(text, va_arg(args, unsigned int), "0123456789abcdef"));
	// if (format[i] == 'X')
	// 	return (ft_add_unb(text, va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (format[i] == 'u')
		return (ft_add_unb_b(text, flags, va_arg(args, unsigned int), "0123456789"));
	// else
	// {
	// 	ft_add_str(text, "%");
	// 	return (1);
	// }
	return (0);
}

void	ft_add(const char *format, char *text, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] != '%')
			text[j++] = format[i];
		else
		{
			j += ft_add_value(&((char *)format)[i + 1], &text[j], args);
			i++;
			while (!ft_check_desc(format[i]))
				i++;
		}
		i++;
	}
}
