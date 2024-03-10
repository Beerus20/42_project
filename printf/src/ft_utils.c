/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:19:55 by beerus            #+#    #+#             */
/*   Updated: 2024/03/10 22:30:50 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pow(int nb, int pow)
{
	while (pow)
	{
		nb *= nb;
		pow--;
	}
	return (nb);
}

int	ft_count_nb(unsigned long nb, int base)
{
	int	count;

	count = 0;
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
}

char	ft_getnb_base(char type, unsigned int nb)
{
	if (type == 'x')
		return ("0123456789abcdef"[nb % 16]);
	if (type == 'X')
		return ("0123456789ABCDEF"[nb % 16]);
	return ("0123456789"[nb % 10]);
}

int	ft_uitos(char type, unsigned int nb)
{
	char	*value;
	int		len;
	int		i;
	int		base;

	i = 0;
	base = 16;
	if (type == 'u')
	{
		len = ft_count_nb(nb, 10);
		base = 10;
	}
	else
		len = ft_count_nb(nb, 16);
	value = (char *)malloc(sizeof(char) * len);
	if (!value)
		return (0);
	while (i < len)
	{
		value[i++] = ft_getnb_base(type, nb);
		nb /= base;
	}
	while (i--)
		ft_putchar_fd(value[i], 1);
	free(value);
	return (len);
}
