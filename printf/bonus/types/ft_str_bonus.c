/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:14:50 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:14:51 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_str_bonus.h"

int	ft_manage_strlen(char *str, int prec)
{
	int	len;

	len = ft_strlen(str);
	if (!str)
	{
		if (prec != -1 && prec < 6)
			len = 0;
		else
			len = 6;
	}
	if (prec != -1 && prec < len)
		len = prec;
	return (len);
}

int	ft_get_len_str(int flags[7], char *str)
{
	int	len;

	len = ft_manage_strlen(str, flags[6]);
	if (flags[5] > len)
		len = flags[5];
	return (len);
}

int	ft_put_str(char *text, char *str, int len)
{
	int		i;

	i = 0;
	if (!str)
	{
		if (len < 6)
			str = "";
		else
			str = "(null)";
	}
	while (*str && i < len)
	{
		*(text++) = *(str++);
		i++;
	}
	return (i);
}

int	ft_add_str_value(char *text, int flags[7], char *str)
{
	int	len;

	len = ft_manage_strlen(str, flags[6]);
	if (flags[0])
	{
		text += ft_put_str(text, str, len);
		ft_add_blank(text, ' ', flags[5] - len);
	}
	else
	{
		text += ft_add_blank(text, ' ', flags[5] - len);
		ft_put_str(text, str, len);
	}
	return (ft_get_len_str(flags, str));
}
