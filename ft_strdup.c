/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:33:14 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 16:33:15 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r_value;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	r_value = (char *)malloc(size);
	if (!r_value)
		return (0);
	while (i < size)
	{
		r_value[i] = s[i];
		i++;
	}
	return (r_value);
}
