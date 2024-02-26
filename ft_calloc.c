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
#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*r_value;
	size_t	i;

	i = 0;
	r_value = malloc(nmemb * size);
	if (!r_value)
		return ((void *)0);
	while (i < nmemb)
		r_value[i++] = 0;
	return ((void *)r_value);
}
