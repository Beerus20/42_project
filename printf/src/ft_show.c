/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:07:58 by ballain           #+#    #+#             */
/*   Updated: 2024/03/11 16:36:02 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_int(char type, int nb)
{
	char	*p_value;
	int		len;

	p_value = "";
	len = 0;
	if (type == 'c')
	{
		ft_putchar_fd(nb, 1);
		return (1);
	}
	p_value = ft_itoa(nb);
	len = ft_strlen(p_value);
	ft_putstr_fd(p_value, 1);
	free(p_value);
	return (len);
}

int	ft_print_u(char type, va_list args)
{
	unsigned long	value;

	value = 0;
	if (type == 'p')
	{
		value = (unsigned long)(va_arg(args, void *));
		if (!value)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		return (2 + ft_uitos('x', value));
	}
	else
		return (ft_uitos(type, (unsigned long)va_arg(args, unsigned long)));
	return (0);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
