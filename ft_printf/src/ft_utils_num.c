/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:04 by ballain           #+#    #+#             */
/*   Updated: 2024/03/15 16:11:45 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils_num.h"

int	ft_pow(int nb, int pow)
{
	while (pow)
	{
		nb *= nb;
		pow--;
	}
	return (nb);
}

int	ft_count_nb(char type, unsigned long nb)
{
	int	count;
	int	base;

	count = 0;
	base = 16;
	if (type == 'u')
		base = 10;
	if (nb == 0)
		return (1);
	while (nb && ++count)
		nb /= base;
	return (count);
}

char	ft_getnb_base(char type, unsigned long *nb)
{
	char	r_value;

	r_value = 0;
	if (type == 'x' || type == 'p')
		r_value = "0123456789abcdef"[*nb % 16];
	if (type == 'X')
		r_value = "0123456789ABCDEF"[*nb % 16];
	if (type == 'u')
	{
		r_value = "0123456789"[*nb % 10];
		*nb /= 10;
	}
	else
		*nb /= 16;
	return (r_value);
}

void	ft_reverse(char *str)
{
	char	tmp;
	int		tmp_i;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	tmp = 0;
	while (i < len / 2)
	{
		tmp_i = len - (i + 1);
		tmp = str[i];
		str[i] = str[tmp_i];
		str[tmp_i] = tmp;
		i++;
	}
}

void	ft_uitos(char type, unsigned long nb, char *value)
{
	int		len;
	int		i;

	i = 0;
	len = ft_count_nb(type, nb);
	while (i < len)
		value[i++] = ft_getnb_base(type, &nb);
	value[i] = '\0';
	ft_reverse(value);
}
