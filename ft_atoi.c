/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:05:17 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 12:15:03 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	counter_sign;
	int				sign;
	int				result;

	sign = -1;
	counter_sign = 0;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	while ((*nptr == '-' || *nptr == '+') && nptr++ && counter_sign++)
	{
		if (*nptr == '+')
			sign *= sign;
		if (counter_sign > 1)
			return (0);
	}
	while (*nptr != '\0')
	{
		if (ft_isalpha(*nptr))
			break ;
		result = result * 10 + (*nptr - 48);
		nptr++;
	}
	return (sign * result);
}
