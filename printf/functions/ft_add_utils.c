/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:03:58 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 14:13:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_add.h"

int	ft_add_char(char *text, char c)
{
	*text = c;
	return (1);
}

int	ft_add_str(char *text, char *str)
{
	int		len;

	if (!str)
		str = "(null)\0";
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	while (*str)
		*(text++) = *(str++);
	return (len);
}

int	ft_add_unb(char *text, unsigned long nb, int type)
{
	int		i;
	int		len;
	int		nb_base;
	char	*base[3];

	i = 1;
	base[0] = "0123456789";
	base[1] = "0123456789abcdef";
	base[2] = "0123456789ABCDEF";
	if (nb == 0)
		return (ft_add_str(text, "0"));
	nb_base = ft_strlen(base[type]);
	len = ft_u_nblen(nb, nb_base);
	while (nb)
	{
		text[len - (i++)] = base[type][nb % nb_base];
		nb /= nb_base;
	}
	return (len);
}

int	ft_add_nb(char *text, long nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (ft_add_str(text, "0"));
	if (nb < 0)
	{
		*(text++) = '-';
		len++;
		nb = -nb;
	}
	len += ft_add_unb(text, nb, 0);
	return (len);
}

int	ft_add_pointer(char *text, unsigned long nb)
{
	int		len;

	len = 0;
	if (!nb)
		return (ft_add_str(text, "(nil)"));
	*(text++) = '0';
	*(text++) = 'x';
	len = ft_add_unb(text, nb, 1);
	return (len + 2);
}
