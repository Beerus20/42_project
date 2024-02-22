/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:46 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 19:42:41 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*r_value;
	size_t		i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (0);
	r_value = (char *)malloc(nmemb * size);
	if (r_value == 0)
		return (0);
	while (i < nmemb)
		r_value[i++] = 0;
	return ((void *)r_value);
}
