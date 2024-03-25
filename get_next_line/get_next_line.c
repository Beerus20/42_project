/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/25 13:48:30 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

void	ft_get_file_content(int fd, t_list **list)
{
	t_list	*value;
	char	*buffer;
	int		size;

	size = 0;
	value = *list;
	buffer = ft_zalloc(BUFFER_SIZE);
	if (!buffer)
		return ;
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || size == 0)
			break ;
		buffer[size] = '\0';
		value->content = ft_strdup(buffer);
		value->next = malloc(sizeof(t_list));
		if (!value->next)
			return ;
		value = value->next;
		value->content = NULL;
		value->next = NULL;
	}
	free(buffer);
}

int	ft_get_len(t_list *value)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (!ft_strchr(value->content, '\n') && value->next)
	{
		len += ft_strlen(value->content);
		value = value->next;
	}
	if (ft_strchr(value->content, '\n'))
	{
		while (value->content[i++] != '\n')
			;
		len += i;
	}
	else
		len += ft_strlen(value->content);
	return (len);
}

char	*ft_get_line(t_list *value)
{
	char	*r_value;
	int		i;
	int		j;

	i = 0;
	r_value = ft_zalloc(ft_get_len(value));
	if (!r_value)
		return (NULL);
	while (!ft_strchr(value->content, '\n') && value->next)
	{
		j = 0;
		while (value->content[j])
			r_value[i++] = value->content[j++];
		value = value->next;
	}
	if (ft_strchr(value->content, '\n'))
	{
		j = 0;
		while (value->content[j] != '\n')
			r_value[i++] = value->content[j++];
		r_value[i++] = value->content[j];
	}
	printf("\nLEN	: [%d] [%s]\n", ft_get_len(value), r_value);
	return (r_value);
}

void	ft_free(t_list *value)
{
	t_list	*to_free;

	to_free = NULL;
	while (value)
	{
		to_free = value;
		value = value->next;
		free(to_free->content);
		free(to_free);
	}
}

char	*get_next_line(int fd)
{
	//static char	*rest;
	t_list		*value;
	char		*line;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	value = (t_list *)malloc(sizeof(t_list));
	if (!value)
		return (NULL);
	value->content = NULL;
	value->next = NULL;
	ft_get_file_content(fd, &value);
	line = ft_get_line(value);
	ft_free(value);
	return (line);
}
/*
*	faire en sorte que le rest soit static mais que la list ne le soit pas
 */
