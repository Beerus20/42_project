/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:03:58 by ballain           #+#    #+#             */
/*   Updated: 2024/04/15 16:34:03 by ballain          ###   ########.fr       */
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
		str = "(null)";
	len = ft_strlen(str);
	while (*str)
		*(text++) = *(str++);
	return (len);
}

int	ft_add_unb(char *text, unsigned long nb, char *base)
{
	int	i;
	int	len;
	int	nb_base;

	i = 1;
	if (nb == 0)
		return (ft_add_str(text, "0"));
	nb_base = ft_strlen(base);
	len = ft_u_nblen(nb, nb_base);
	while (nb)
	{
		text[len - (i++)] = base[nb % nb_base];
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
	len += ft_add_unb(text, nb, "0123456789");
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
	len = ft_add_unb(text, nb, "0123456789abcdef");
	return (len + 2);
}
