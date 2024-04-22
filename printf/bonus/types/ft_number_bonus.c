/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:14:32 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 13:35:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_number_bonus.h"

int	ft_get_len_nb(int flags[7], long nb)
{
	int	len;
	int	sup;

	sup = 0;
	if (nb < 0 || flags[1] || (flags[3] && !flags[1]))
		sup = 1;
	if (nb < 0)
		nb = -nb;
	len = ft_unblen(nb, 10) + sup;
	if (nb == 0 && flags[6] == 0)
		len = 0;
	if (flags[6] >= len)
		len = flags[6] + sup;
	if (flags[5] > len)
		len = flags[5];
	return (len);
}

int	ft_manage_nblen(long nb, int flags[7])
{
	int	len;
	int	sup;

	sup = 0;
	if (nb < 0)
	{
		sup = 1;
		nb = -nb;
	}
	len = ft_unblen(nb, 10);
	if (nb == 0 && flags[6] == 0)
		len = 0;
	ft_manage_precision(flags, sup);
	if (flags[5] > flags[6])
	{
		if (flags[6] > len)
			flags[5] = (flags[5] - flags[6]) - sup;
		else
			flags[5] = (flags[5] - len) - sup;
	}
	else
		flags[5] = 0;
	return (len);
}

int	ft_manage_sign(long *nb, int flags[7])
{
	int	sign;

	sign = 0;
	if (*nb < 0)
	{
		sign = '-';
		*nb *= -1;
	}
	else
	{
		if (flags[1])
			sign = '+';
		if (flags[3] && !flags[1])
			sign = ' ';
	}
	return (sign);
}

char	*ft_apply_flags_nb(char *text, int flags[7], long nb, int len)
{
	int	sign;

	sign = ft_manage_sign(&nb, flags);
	if (sign)
		*(text++) = sign;
	text += ft_add_blank(text, '0', flags[6] - len);
	text += ft_put_nb(text, nb, flags[6], "0123456789");
	return (text);
}

int	ft_add_nb_value(char *text, int flags[7], long nb)
{
	int	len;
	int	r_len;

	r_len = ft_get_len_nb(flags, nb);
	len = ft_manage_nblen(nb, flags);
	if (flags[0])
	{
		text = ft_apply_flags_nb(text, flags, nb, len);
		ft_add_blank(text, ' ', flags[5]);
	}
	else
	{
		if (flags[2] && flags[6] == -1)
			text += ft_add_blank(text, '0', flags[5]);
		else
			text += ft_add_blank(text, ' ', flags[5]);
		ft_apply_flags_nb(text, flags, nb, len);
	}
	return (r_len);
}
