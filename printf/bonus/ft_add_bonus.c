#include "../includes/ft_add_bonus.h"

int	ft_add_value(char *type, char *text, va_list args)
{
	int	flags[7];

	ft_init_flags(flags);
	ft_check_flags(type, flags);
	while (!ft_isdesc(*type))
		type++;
	if (*type == 'c')
		return (ft_add_char_value(text, flags, va_arg(args, int)));
	if (*type == 's')
		return (ft_add_str_value(text, flags, (char *)va_arg(args, char *)));
	// if (type == 'd' || type == 'i')
	// 	return (ft_add_nb(text, (int)va_arg(args, int)));
	// if (type == 'p')
	// 	return (ft_add_pointer(text, (unsigned long)va_arg(args, void *)));
	// if (type == 'x')
	// 	return (ft_add_unb(text, va_arg(args, unsigned int), "0123456789abcdef"));
	// if (type == 'X')
	// 	return (ft_add_unb(text, va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*type == 'u')
		return (ft_add_unb_value(text, flags, va_arg(args, unsigned int)));
	// else
	// {
	// 	ft_add_str(text, "%");
	return (1);
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
			while (!ft_isdesc(format[++i]))
				;
		}
		i++;
	}
}