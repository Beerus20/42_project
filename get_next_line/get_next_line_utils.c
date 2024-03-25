/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:03:36 by beerus            #+#    #+#             */
/*   Updated: 2024/03/25 08:09:23 by beerus           ###   ########.fr       */
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
	r_value = ft_zalloc(len);
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

char	*ft_strjoin(char  *s1, char  *s2)
{
	int		i;
	char	*r_value;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	r_value = ft_zalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_value)
		return (NULL);
	while (*s1)
		r_value[i++] = *(s1++);
	while (*s2 != '\0')
		r_value[i++] = *(s2++);
	r_value[i] = '\0';
	return (r_value);
}

int	ft_size(char  *s, unsigned int start, size_t len)
{
	size_t	r_value;
	size_t	len_s;
	size_t	len_r;

	r_value = 0;
	len_s = ft_strlen(s);
	len_r = start + len;
	if (len_r >= len_s)
		r_value = len_s - start + 1;
	else
		r_value = len + 1;
	if (start >= len_s)
		r_value = (int)(sizeof(char));
	return (r_value);
}

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*r_value;

	i = 0;
	len_s = ft_strlen(s);
	r_value = ft_zalloc(ft_size(s, start, len));
	if (!r_value)
		return (0);
	if (start >= len_s)
	{
		r_value[i] = '\0';
		return (r_value);
	}
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

