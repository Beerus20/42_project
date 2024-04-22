/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:10:15 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:10:27 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_flags_bonus.h"

void	ft_init_flags(int flags[7])
{
	int	i;

	i = 0;
	while (i < 7)
		flags[i++] = 0;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_get_width(char *str)
{
	int	r_value;

	r_value = 0;
	while (!ft_isdigit(*str) || *str == '0')
	{
		if (*str == '.' || ft_isdesc(*str))
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		r_value = (*str - 48) + (r_value * 10);
		str++;
	}
	return (r_value);
}

int	ft_get_prec(char *str)
{
	int	r_value;

	r_value = 0;
	while (!ft_isdesc(*str) && *str != '.')
		str++;
	if (*(str++) != '.')
		return (-1);
	while (!ft_isdesc(*str))
	{
		r_value = (*str - 48) + (r_value * 10);
		str++;
	}
	return (r_value);
}

void	ft_check_flags(char *str, int flags[7])
{
	while (!ft_isdesc(*str) && (!ft_isdigit(*str) || *str == '0'))
	{
		if (*str == '-')
			flags[0] = 1;
		if (*str == '+')
			flags[1] = 1;
		if (*str == '0')
			flags[2] = 1;
		if (*str == ' ')
			flags[3] = 1;
		if (*str == '#')
			flags[4] = 2;
		if (*str == '.')
			break ;
		str++;
	}
	flags[5] = ft_get_width(str);
	flags[6] = ft_get_prec(str);
}
