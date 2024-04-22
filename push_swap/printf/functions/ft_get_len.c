/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:25 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 14:21:36 by ballain          ###   ########.fr       */
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

int	ft_get_strlen(char *str)
{
	if (!str)
		return (6);
	return (ft_strlen(str));
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

int	ft_nblen(long nb)
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
		return (ft_get_strlen((char *)va_arg(args, char *)));
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
