/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:01:59 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 14:02:01 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	if (size < len_dst)
		return ((size_t)(size + len_src));
	else
	{
		while (i < size - 1)
		{
			dst[i] = *src;
			i++;
			src++;
		}
		dst[i] = '\0';
	}
	return ((size_t)(len_dst + len_src));
}
