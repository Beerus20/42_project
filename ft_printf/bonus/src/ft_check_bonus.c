/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:23:10 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:49:44 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_check_bonus.h"

int	ft_isflag(int c)
{
	if (ft_strchr("-0# +", c))
		return (1);
	return (0);
}

int	ft_check_type(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	ft_isint(char type)
{
	if (ft_strchr("cdi", type))
		return (1);
	return (0);
}

int	ft_isuint(char type)
{
	if (ft_strchr("upxX", type))
		return (1);
	return (0);
}

int	ft_isnumber(char type)
{
	if (ft_strchr("diuxX", type))
		return (1);
	return (0);
}
