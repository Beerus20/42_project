/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:19 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 19:52:16 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*r_value;

	i = 0;
	r_value = (char *)malloc(len);
	if (!r_value)
		return (0);
	while (i < len || s[start + i] == '\0')
	{
		r_value[i] = s[start + i];
		i++;
	}
	return (r_value);
}
