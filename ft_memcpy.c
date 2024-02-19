/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:22:30 by ballain           #+#    #+#             */
/*   Updated: 2024/02/19 18:40:41 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)dest;
	while (n-- > 0)
	{
		*str = *(unsigned char *)src;
		src++;
		str++;
	}
	return (dest);
}
