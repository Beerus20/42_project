/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:13:10 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 14:46:53 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils_bonus.h"

int	ft_add_blank(char *text, char c, int e)
{
	int	i;
	int	value;

	i = 0;
	if (!c)
		value = ' ';
	else
		value = c;
	while (i < e)
	{
		*(text++) = value;
		i++;
	}
	return (i);
}

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

int	ft_unblen(unsigned long nb, int base)
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

int	ft_put_nb(char *text, unsigned long nb, int prec, char *base)
{
	int	i;
	int	len;
	int	nb_base;

	i = 1;
	if (nb == 0)
	{
		if (prec == 0)
			return (0);
		*(text) = '0';
		return (1);
	}
	nb_base = ft_strlen(base);
	len = ft_unblen(nb, nb_base);
	while (nb)
	{
		text[len - (i++)] = base[nb % nb_base];
		nb /= nb_base;
	}
	return (len);
}

void	ft_manage_precision(int flags[7], int sup)
{
	if (flags[6] == -1 && flags[2])
	{
		flags[6] = flags[5] - sup;
		flags[5] = 0;
		flags[0] = 1;
	}
}
