/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:15:51 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 09:16:38 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;

	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while ((*str_1 == *str_2) && n-- && ++str_1 && ++str_2)
	{
		printf("%c - %c\n", *str_1, *str_2);
	}
	return (*str_1 - *str_2);
}
