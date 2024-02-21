/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:40:05 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 19:53:02 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(const char *s, const char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_count_chars(char const *s1, char const *set)
{
	int			count;
	size_t		i;

	count = 0;
	i = 0;
	while (i < ft_strlen(set))
	{
		if (ft_strchr(s1, set[i]))
			count++;
		i++;
	}
	return (count);
}

int	ft_pow(int nb, int pow)
{
	int	r_value;

	r_value = 1;
	while (pow)
	{
		r_value *= nb;
		pow--;
	}
	return (r_value);
}
