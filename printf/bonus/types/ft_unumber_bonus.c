/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumber_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:15:11 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:15:11 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_unumber_bonus.h"

int	ft_get_len_unb(int flags[7], unsigned long nb)
{
	int	len;

	len = ft_unblen(nb, 10);
	if (nb == 0 && flags[6] == 0)
		len = 0;
	if (flags[6] >= len)
		len = flags[6];
	if (flags[5] > len)
		len = flags[5];
	return (len);
}

int	ft_manage_unblen(unsigned long nb, int flags[7])
{
	int	len;

	len = ft_unblen(nb, 10);
	if (nb == 0 && flags[6] == 0)
		len = 0;
	if (flags[5] > flags[6])
	{
		if (flags[6] > len)
			flags[5] = flags[5] - flags[6];
		else
			flags[5] = flags[5] - len;
	}
	else
		flags[5] = 0;
	return (len);
}

int	ft_add_unb_value(char *text, int flags[7], unsigned long nb)
{
	int	len;
	int	r_len;

	r_len = ft_get_len_unb(flags, nb);
	len = ft_manage_unblen(nb, flags);
	if (flags[0])
	{
		text += ft_add_blank(text, '0', flags[6] - len);
		text += ft_put_nb(text, nb, flags[6], "0123456789");
		ft_add_blank(text, ' ', flags[5]);
	}
	else
	{
		if (flags[2] && flags[6] == -1)
			text += ft_add_blank(text, '0', flags[5]);
		else
			text += ft_add_blank(text, ' ', flags[5]);
		text += ft_add_blank(text, '0', flags[6] - len);
		ft_put_nb(text, nb, flags[6], "0123456789");
	}
	return (r_len);
}
