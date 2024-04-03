/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:59:58 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:01:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

int	ft_isflag(int c)
{
	if (ft_strchr("-0# +", c))
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
