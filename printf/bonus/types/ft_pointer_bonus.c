/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:53:27 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 14:55:58 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_hex_bonus.h"

int	ft_get_len_pointer(int flags[7], unsigned long nb)
{
	int	len;

	len = ft_unblen(nb, 16) + 2;
	if (nb == 0)
		len = 5;
	if (flags[6] >= len)
		len = flags[6] + 2;
	if (flags[5] > len)
		len = flags[5];
	return (len);
}

int	ft_manage_pointerlen(unsigned long nb, int flags[7])
{
	int	len;

	len = ft_unblen(nb, 16) + 2;
	if (nb == 0)
		len = 5;
	if (flags[5] > flags[6])
	{
		if (flags[6] > len)
			flags[5] = flags[5] - flags[6] - 2;
		else
			flags[5] = flags[5] - len;
		if (flags[6] == -1 && flags[2])
		{
			flags[6] = flags[5] + 1;
			flags[5] = 0;
			flags[0] = 1;
		}
	}
	else
		flags[5] = 0;
	return (len);
}

char	*ft_manage_pvalue(char *text, unsigned long nb, int prec, char *base)
{
	if (nb == 0)
	{
		*(text++) = '(';
		*(text++) = 'n';
		*(text++) = 'i';
		*(text++) = 'l';
		*(text++) = ')';
		return (text);
	}
	else
	{
		text += ft_put_nb(text, nb, prec, base);
		return (text);
	}
}

char	*ft_add_front(char *text, unsigned long nb)
{
	if (nb)
	{
		*(text++) = '0';
		*(text++) = 'x';
	}
	return (text);
}

int	ft_add_pval(char *text, int flags[7], unsigned long nb)
{
	int		len;
	int		r_len;

	r_len = ft_get_len_pointer(flags, nb);
	len = ft_manage_pointerlen(nb, flags);
	if (flags[0])
	{
		text = ft_add_front(text, nb);
		text += ft_add_blank(text, '0', flags[6] - len);
		text = ft_manage_pvalue(text, nb, flags[6], "0123456789abcdef");
		ft_add_blank(text, ' ', flags[5]);
	}
	else
	{
		text += ft_add_blank(text, (flags[2] && flags[6] == -1), flags[5]);
		text = ft_add_front(text, nb);
		text += ft_add_blank(text, '0', flags[6] - len);
		ft_manage_pvalue(text, nb, flags[6], "0123456789abcdef");
	}
	return (r_len);
}
