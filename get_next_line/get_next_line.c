/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/26 09:10:37 by beerus           ###   ########.fr       */
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

int	ft_add_value(char *receiver, char *to_add, char stop)
{
	int	i;

	i = 0;
	while (to_add[i] != stop && to_add[i])
	{
		receiver[i] = to_add[i];
		i++;
	}
	if (stop == '\n')
	{
		receiver[i] = to_add[i];
		i++;
	}
	return (i);
}

int	ft_get_file_content(int fd, t_list **list)
{
	t_list	*value;
	char	*buffer;
	int		size;

	size = 0;
	value = *list;
	if ((*list)->content)
		value = (*list)->next;
	buffer = ft_zalloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || size == 0)
		{
			free(buffer);
			return (size);
		}
		buffer[size] = '\0';
		value->content = ft_strdup(buffer);
		value->next = malloc(sizeof(t_list));
		value = value->next;
		value->content = NULL;
		value->next = NULL;
	}
	free(buffer);
	return (1);
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

char	*ft_get_line(t_list *value, char **rest)
{
	char	*r_value;
	int		i;

	i = 0;
	r_value = ft_zalloc(ft_get_len(value));
	if (!r_value)
		return (NULL);
	i = 0;
	while (!ft_strchr(value->content, '\n') && value->next)
	{
		i += ft_add_value(&r_value[i], value->content, '\0');
		value = value->next;
	}
	if (ft_strchr(value->content, '\n'))
	{
		i = ft_add_value(&r_value[i], value->content, '\n');
		if ((ft_strlen(value->content) - i) != 0)
		{
			*rest = ft_zalloc(ft_strlen(value->content) - i);
			if (!(*rest))
				return (NULL);
			ft_add_value((*rest), &value->content[i], '\0');
		}
	}
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

int	ft_init(t_list *value, char **rest)
{
	if (*rest && ft_strlen(*rest))
	{
		value->content = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
		if (ft_strchr(value->content, '\n'))
			return (0);
		value->next = (t_list *)malloc(sizeof(t_list));
		if (!value->next)
			return (0);
		value->next->content = NULL;
		value->next->next = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	t_list		*value;
	char		*line;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	value = (t_list *)malloc(sizeof(t_list));
	if (!value)
		return (0);
	value->content = NULL;
	value->next = NULL;
	if (ft_init(value, &rest))
	{
		if (ft_get_file_content(fd, &value) <= 0 && value->content == NULL)
		{
			free(value);
			return (NULL);
		}
	}
	line = ft_get_line(value, &rest);
	ft_free(value);
	if (!ft_strlen(line))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
*	faire en sorte que le rest soit static mais que la list ne le soit pas
 */
