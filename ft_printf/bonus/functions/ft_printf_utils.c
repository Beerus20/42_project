/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:41 by ballain           #+#    #+#             */
/*   Updated: 2024/04/15 16:34:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"

int	ft_len_value(char type, va_list args)
{
	unsigned long	value;

	value = 0;
	if (type == 'c')
	{
		va_arg(args, int);
		return (1);
	}
	if (type == 's')
		return (ft_strlen((char *)va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_nblen((int)va_arg(args, int)));
	if (type == 'p')
	{
		value = (unsigned long)va_arg(args, void *);
		if (value == 0)
			return (5);
		return (2 + ft_u_nblen(value, 16));
	}
	if (type == 'x' || type == 'X')
		return (ft_u_nblen((unsigned long)va_arg(args, unsigned int), 16));
	if (type == 'u')
		return (ft_u_nblen((unsigned long)va_arg(args, unsigned int), 10));
	else
		return (1);
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
