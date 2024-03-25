/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/25 17:12:07 by ballain          ###   ########.fr       */
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

char	*ft_get_line(t_list *value)
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
		ft_add_value(&r_value[i], value->content, '\n');
	return (r_value);
}

char	*ft_get_rest(t_list *value)
{
	char	*r_value;
	int		i;

	i = 0;
	r_value = NULL;
	while (!ft_strchr(value->content, '\n') && value->next)
		value = value->next;
	if (ft_strchr(value->content, '\n'))
	{
		while (value->content[i++] != '\n')
			;
		r_value = ft_zalloc(ft_strlen(value->content) - i);
		if (!r_value)
			return (NULL);
		ft_add_value(r_value, &value->content[i], '\0');
	}
	return (r_value);
}

void	ft_add_front(t_list **list, char *rest)
{
	t_list	*_rest;

	_rest = (t_list *)malloc(sizeof(t_list));
	if (!_rest)
		return ;
	_rest->content = ft_strdup(rest);
	_rest->next = *list;
	*list = _rest;
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
	static char	*rest;
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
	if (!rest || !ft_strchr(rest, '\n'))
		ft_get_file_content(fd, &value);
	if (rest)
	{
		if (ft_strchr(rest, '\n'))
			value->content = ft_strdup(rest);
		else
			ft_add_front(&value, rest);
		free(rest);
	}
	line = ft_get_line(value);
	rest = ft_get_rest(value);
	ft_free(value);
	return (line);
}
/*
*	faire en sorte que le rest soit static mais que la list ne le soit pas
 */
