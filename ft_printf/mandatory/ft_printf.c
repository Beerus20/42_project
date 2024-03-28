#include <stdio.h>
#include "ft_printf.h"

void	*ft_stoc(int c);
void	ft_write_value(char type, int *len, va_list args);
void	ft_printv(char type, char *value, int *len);
void	*ft_get_int_value(char type, int value);
char	*ft_get_uint_value(char type, va_list args);
void	*ft_get_str_value(char *value);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			len++;
		}
		else
			ft_write_value(format[++i], &len, args);
		i++;
	}
	printf("\nLEN	: [%d]\n", len);
	return (0);
}

void	*ft_stoc(int c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return ((void *)0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	ft_write_value(char type, int *len, va_list args)
{
	char	*r_value;

	r_value = NULL;
	if (ft_isint(type))
		r_value = ft_get_int_value(type, va_arg(args, int));
	else if (ft_isuint(type))
		r_value = ft_get_uint_value(type, args);
	else if (type == 's')
		r_value = ft_get_str_value(va_arg(args, char *));
	else
		r_value = ft_strdup("%");
	ft_printv(type, r_value, len);
}

void	ft_printv(char type, char *value, int *len)
{
	if (type == 's' && !value)
	{
		*len += 6;
		write(1, "(null)", 6);
	}
	else if (type == 'p')
	{
		if (!value)
		{
			*len += 5;
			write(1, "(nil)", 5);
		}
		else
		{
			*len += 2;
			write(1, "0x", 2);
		}
	}
	write(1, value, ft_strlen(value));
	*len += ft_strlen(value);
}

void	*ft_get_int_value(char type, int value)
{
	if (type == 'c')
		return (ft_stoc(value));
	return (ft_itoa(value));
}

char	*ft_get_uint_value(char type, va_list args)
{
	char			*value;
	int				len;
	unsigned long	nb;

	nb = 0;
	value = NULL;
	if (type == 'p')
	{
		nb = (unsigned long)(va_arg(args, void *));
		if (!nb)
			return ((char *)0);
	}
	else
		nb = (unsigned long)va_arg(args, unsigned long);
	len = ft_count_nb(type, nb);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (0);
	ft_uitos(type, nb, value);
	return (value);
}

void	*ft_get_str_value(char *value)
{
	if (!value)
		return ((char *)0);
	return (ft_strdup(value));
}
