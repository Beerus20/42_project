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
	while (n > 0)
	{
		if (*s1 == *s2)
			return (0);
		if (*s1 > *s2)
			return (1);
		if (*s1 < *s2)
			return (-1);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
