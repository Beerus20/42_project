/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:45:38 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 19:49:33 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_splited_len(char const *s, const char c)
{
	int		count;
	int		*r_value;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	r_value = (int *)malloc(ft_count_char(s, c) + 1);
	while (i < ft_strlen(s))
	{
		if (s[i] == c || i == ft_strlen(s) - 1)
		{
			r_value[j] = count;
			count = 0;
			j++;
		}
		else
			count++;
		i++;
	}
	return (r_value);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		split_nb;
	int		*split_len;
	char	**r_value;

	i = 0;
	split_nb = ft_count_char(s, c) + 1;
	split_len = ft_splited_len(s, c);
	r_value = (char **)malloc(split_nb);
	while (i < split_nb)
	{
		j = 0;
		r_value[i] = (char *)malloc(split_len[i]);
		while (*s != c && *s != '\0')
		{
			r_value[i][j] = *s;
			j++;
			s++;
		}
		s++;
		i++;
	}
	return (r_value);
}
