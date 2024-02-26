/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:15:51 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 09:52:02 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*str_1;
	char		*str_2;

	i = 0;
	str_1 = (char *)s1;
	str_2 = (char *)s2;
	while (i < n)
	{
		if (str_1[i] != str_2[i])
		{
			if (ft_isascii(str_1[i]) && ft_isascii(str_2[i]))
				return (str_1[i] - str_2[i]);
			else
				return (1);
		}
		i++;
	}
	return (0);
}
