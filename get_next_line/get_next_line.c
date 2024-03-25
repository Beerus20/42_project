/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/25 09:27:08 by beerus           ###   ########.fr       */
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
	ft_free(value);
	return (line);
}

/*
*	faire en sorte que le rest soit static mais que la list ne le soit pas
 */
