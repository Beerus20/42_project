/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:15:14 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 08:57:51 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			if (ft_isascii(s1[i]) && ft_isascii(s2[i]))
				return ((int)s1[i] - (int)s2[i]);
			else
				return (1);
		}
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
