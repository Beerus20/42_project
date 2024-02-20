/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:58:16 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 19:42:02 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_value;

	dest_value = (unsigned char *)dest;
	while (n-- > 0)
		*dest_value++ = *(unsigned char *)src++;
	return (dest);
}
