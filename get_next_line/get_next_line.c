/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/19 22:05:30 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
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

char	*ft_strdup(const char *s)
{
	char	*r_value;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	r_value = ft_zalloc((len + 1));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*r_value;

	i = 0;
	r_value = ft_zalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_value)
		return (NULL);
	while (*s1 != '\0')
		r_value[i++] = *(s1++);
	while (*s2 != '\0')
		r_value[i++] = *(s2++);
	r_value[i] = '\0';
	return (r_value);
}

int	ft_size(char const *s, unsigned int start, size_t len)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*ft_get_value(char *buffer, char *r_value, char *content)
{
	int		i;
	char	*tmp;
	char	*copy;

	i = 0;
	tmp = NULL;
	copy = NULL;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i++] == '\n')
	{
		copy = ft_strdup(r_value);
		tmp = ft_substr(buffer, 0, i);
		free(r_value);
		r_value = ft_strjoin(copy, tmp);
		free(tmp);
		free(copy);

		tmp = ft_substr(content, i, ft_strlen(content));
		free(content);
		content = ft_strdup(tmp);
		free(tmp);
		free(copy);
	}
	else
	{
		copy = ft_strdup(r_value);
		tmp = ft_substr(buffer, 0, i);
		free(r_value);
		r_value = ft_strjoin(copy, tmp);
		free(tmp);
		free(copy);
	}
	return (r_value);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*buffer;
	char		*tmp;
	char		*r_value;
	int			size;

	size = 0;
	r_value = ft_zalloc(1);
	if (fd == -1 || !r_value)
		return (NULL);
	while (1)
	{
		buffer = ft_zalloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || size == 0)
			return (NULL);
		buffer[size] = '\0';
		tmp = ft_strdup(r_value);
		free(r_value);
		r_value = ft_get_value(buffer, tmp, content);
		if (ft_check(r_value, '\n'))
			break ;
	}
	return (r_value);
}
