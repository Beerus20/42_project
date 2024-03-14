/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:42:51 by beerus            #+#    #+#             */
/*   Updated: 2024/03/14 11:45:37 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	*ft_init_to_printv(char type, t_flags *flags, void *str)
{
	if (ft_strchr(flags->flag, '#') || type == 'p')
	{
		if (type == 'p' && *(int *)str == '0')
			return (ft_strdup("(nil)"));
		if (type == 'p' || type == 'x')
			return (ft_strjoin("0x", (char *)str));
		if (type == 'X')
			return (ft_strjoin("0X", (char *)str));
	}
	return (ft_strdup(str));
}

int	ft_plen(char type, int len, void *c)
{
	if (type == 'c')
		return (len - 1);
	else
	{
		if (len <= (int)ft_strlen((char *)c))
			return ((int)ft_strlen((char *)c));
		else
			return (len - (int)ft_strlen((char *)c));
	}
}

void	ft_dash_flag(char type, int apply, int len, void *c)
{
	if (apply)
	{
		if (type == 'c')
			ft_putchar_fd(*(char *)c, 1);
		else
			ft_putstr_fd((char *)c, 1);
		ft_rprintc(' ', ft_plen(type, len, c));
	}
	else
	{
		if (len != (int)ft_strlen((char *)c))
			ft_rprintc(' ', ft_plen(type, len, c));
		if (type == 'c')
			ft_putchar_fd(*(char *)c, 1);
		else
			ft_putstr_fd((char *)c, 1);
	}
}
