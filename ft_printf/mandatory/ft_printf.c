/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:00:09 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:04:03 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_write_value(char type, int *len, va_list args);
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
	return (len);
}

void	ft_write_value(char type, int *len, va_list args)
{
	char	*r_value;

	r_value = NULL;
	if (type == 'c')
	{
		ft_printc(va_arg(args, int), len);
		return ;
	}
	else if (ft_isint(type))
		r_value = ft_itoa(va_arg(args, int));
	else if (ft_isuint(type))
		r_value = ft_get_uint_value(type, args);
	else if (type == 's')
		r_value = ft_get_str_value(va_arg(args, char *));
	else
		r_value = ft_strdup("%");
	ft_printv(type, r_value, len);
	free(r_value);
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
