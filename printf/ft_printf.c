/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:34:40 by bruce             #+#    #+#             */
/*   Updated: 2024/03/09 10:48:53 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_print_value(char type, va_list arg)
{
	if (type == 'c')
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	char			*tmp;
	void			*r_value;
	int				count;

	count = 0;
	tmp = (char *)format;
	va_start(args, format);
	while (*tmp)
	{
		while (*tmp != '%' && *tmp)
		{
			ft_putchar_fd(*tmp, 1);
			tmp++;
			count++;
		}
		if (*(tmp++) == '\0')
			return (count);
		if (*tmp == 'c')
		{
			r_value = (int)va_arg(args, int);
			write(1, &r_value, 1);
			count++;
		}
		if (*tmp == 's')
		{
			r_value = (char *)va_arg(args, char *);
			ft_putstr_fd(r_value, 1);
			count++;
		}
		tmp++;
	}
	va_end(args);
	return (count);
}
