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

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*r_value;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	r_value = (char *)malloc(len + 1);
	if (!r_value)
		return (0);
	while (i < len)
	{
		if (s[start + i] == '\0')
			break ;
		r_value[i] = s[start + i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
