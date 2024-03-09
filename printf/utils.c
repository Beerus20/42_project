/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:39:38 by beerus            #+#    #+#             */
/*   Updated: 2024/03/09 09:34:31 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nblen(unsigned long nb, int base)
{
	int	r_count;

	r_count = 0;
	while (nb)
	{
		nb = nb / base;
		r_count++;
	}
	return (r_count);
}

char	*ft_rev_str(char *str)
{
	int		i;
	int		l_str;
	char	*r_value;

	i = 0;
	l_str = ft_strlen(str);
	r_value = (char *)malloc(sizeof(char) * (l_str + 1));
	str += l_str - 1;
	while (i < l_str)
		r_value[i++] = *(str--);
	r_value[i] = '\0';
	return (r_value);
}

int	ft_as_decimal_value(float nb)
{
	if ((nb - (int)nb) == 0)
		return (0);
	return (1);
}
