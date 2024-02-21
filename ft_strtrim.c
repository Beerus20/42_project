/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:14:42 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 14:14:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*r_value;

	i = 0;
	r_value = (char *)malloc((int)ft_strlen(s1) - ft_count_chars(s1, set));
	if (!r_value)
		return (0);
	while (*s1 != '\0')
	{
		if (!ft_strchr(set, *s1))
		{
			*(r_value + i) = *s1;
			i++;
		}
		s1++;
	}
	return (r_value);
}
