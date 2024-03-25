/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:03:36 by beerus            #+#    #+#             */
/*   Updated: 2024/03/25 15:40:17 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen( char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_zalloc(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (i < n)
		str[i++] = 0;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*r_value;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (0);
	while (i < len)
	{
		r_value[i] = s[i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}
