/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:58:16 by ballain           #+#    #+#             */
/*   Updated: 2024/02/22 09:03:24 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_value;
	unsigned const char	*src_value;

	dest_value = (unsigned char *)dest;
	src_value = (unsigned const char *)src;
	if (src_value <= dest_value)
	{
		dest_value += n - 1;
		src_value += n - 1;
		while (n--)
			*dest_value-- = *src_value--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
