/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 13:33:53 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_gnl_add_value(char *receiver, char *to_add, char stop)
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

int	ft_get_file_content(int fd, t_cmd **list)
{
	t_cmd	*value;
	char	*buffer;
	int		size;

	size = 0;
	value = *list;
	buffer = ft_alloc(NULL, BUFFER_SIZE);
	if (!buffer)
		return (0);
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1 || size == 0)
			break ;
		buffer[size] = '\0';
		value->content = ft_alloc(buffer, 0);
		value->next = malloc(sizeof(t_cmd));
		if (!value->next)
			return (0);
		value->next->content = NULL;
		value->next->next = NULL;
		value = value->next;
	}
	free(buffer);
	return (size);
}

char	*ft_get_line(t_cmd *value, char **rest)
{
	char	*r_value;
	int		i;

	i = 0;
	r_value = ft_alloc(NULL, ft_gnl_get_len(value));
	if (!r_value)
		return (NULL);
	i = 0;
	while (!ft_strchr(value->content, '\n') && value->next)
	{
		i += ft_gnl_add_value(&r_value[i], value->content, '\0');
		value = value->next;
	}
	if (ft_strchr(value->content, '\n'))
	{
		i = ft_gnl_add_value(&r_value[i], value->content, '\n');
		if ((ft_gnl_strlen(value->content) - i) != 0)
		{
			*rest = ft_alloc(NULL, ft_gnl_strlen(value->content) - i);
			if (!(*rest))
				return (NULL);
			ft_gnl_add_value((*rest), &value->content[i], '\0');
		}
	}
	return (r_value);
}

int	ft_gnl_init(t_cmd **value, char **rest)
{
	(*value) = (t_cmd *)malloc(sizeof(t_cmd));
	if (!(*value))
		return (0);
	(*value)->content = NULL;
	(*value)->next = NULL;
	if (*rest && ft_gnl_strlen(*rest))
	{
		(*value)->content = ft_alloc(*rest, 0);
		free(*rest);
		*rest = NULL;
		if (ft_strchr((*value)->content, '\n'))
			return (0);
		(*value)->next = (t_cmd *)malloc(sizeof(t_cmd));
		if (!(*value)->next)
			return (0);
		(*value)->next->content = NULL;
		(*value)->next->next = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	t_cmd		*value;
	char		*line;
	int			size;

	line = NULL;
	value = NULL;
	size = 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_gnl_init(&value, &rest))
	{
		if (!value->content)
			size = ft_get_file_content(fd, &value);
		else
			size = ft_get_file_content(fd, &value->next);
		if (size == -1 || (size == 0 && value->content == NULL))
		{
			ft_gnl_free(value);
			return (NULL);
		}
	}
	line = ft_get_line(value, &rest);
	ft_gnl_free(value);
	return (line);
}
/*
*	faire en sorte que le rest soit static mais que la list ne le soit pas
 */
