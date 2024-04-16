/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:25 by ballain           #+#    #+#             */
/*   Updated: 2024/04/16 16:27:50 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_get_len.h"

int	ft_strlen(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	while (str[i++])
		len++;
	return (len);
}

int	ft_string_len(char *text, char *str)
{
	int	i;
	int	len;
	int	prec;

	i = 0;
	len = 0;
	while (*text != '%' && *text != '.')
		text--;
	prec = ft_get_precision(text);
	if (!str)
	{
		if (*text == '.' && prec < 6)
			return (0);
		return (6);
	}
	if (*text == '.')
		return (prec);
	while (str[i++])
		len++;
	return (len);
}

int	ft_u_nblen(unsigned long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int	ft_nblen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_len_value(char *type, va_list args)
{
	unsigned long	value;

	value = 0;
	if (*type == 'c')
	{
		va_arg(args, int);
		return (1);
	}
	if (*type == 's')
		return (ft_string_len(type, (char *)va_arg(args, char *)));
	if (*type == 'd' || *type == 'i')
		return (ft_nblen((int)va_arg(args, int)));
	if (*type == 'p')
	{
		value = (unsigned long)va_arg(args, void *);
		if (value == 0)
			return (5);
		return (2 + ft_u_nblen(value, 16));
	}
	if (*type == 'x' || *type == 'X')
		return (ft_u_nblen((unsigned long)va_arg(args, unsigned int), 16));
	if (*type == 'u')
		return (ft_u_nblen((unsigned long)va_arg(args, unsigned int), 10));
	else
		return (1);
}
