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

static int	ft_count_chars(char const *s1, char const *set)
{
	int		count;
	size_t	i;
	size_t	len_set;
	size_t	len_str;

	count = 0;
	i = 0;
	len_set = ft_strlen(set);
	len_str = ft_strlen(s1);
	if (!len_set)
		return (0);
	while (s1[i])
	{
		if (!ft_strncmp(&s1[i], set, len_set))
			count++;
		i++;
	}
	return (int)len_str - (count * len_set) + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		t_len;
	char	*r_value;
	size_t	len_set;
	size_t	len_s1;

	i = 0;
	len_set = ft_strlen(set);
	len_s1 = ft_strlen(s1);
	t_len = (int)len_s1 - (ft_count_chars(s1, set) * len_set) + 1;
	r_value = (char *)malloc(t_len);
	if (!r_value)
		return (0);
	if (!len_set)
	{
		ft_strlcpy(r_value, s1, len_s1 + 1);
		return (r_value);
	}
	while (*s1 != '\0')
	{
		if (!ft_strncmp(s1, set, len_set))
			s1 += len_set;
		else
			*(r_value + (i++)) = *(s1++);
	}
	r_value[i] = '\0';
	return (r_value);
}
