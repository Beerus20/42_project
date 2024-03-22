/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/22 21:15:02 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (1);
	return (0);
}

char	*ft_read_file(int fd)
{
	char	*buffer;
	int		size;

	size = 0;
	buffer = ft_zalloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[size] = '\0';
	return (buffer);
}

t_list	*ft_get_file_content(int fd, t_list *list)
{
	t_list	*value;
	char	*buffer;

	value = list;
	if (value->content)
	{
		while (value->next)
			value = value->next;
		if (!ft_strchr(value->content, '\n'))
		{
			value->next = (t_list *)malloc(sizeof(t_list));
			if (!value->next)
				return (NULL);
			value = value->next;
			value->content = NULL;
			value->next = NULL;
		}
		else
			return (NULL);
	}
	while (1)
	{
		buffer = ft_read_file(fd);
		value->content = ft_strdup(buffer);
		if (ft_strchr(value->content, '\n'))
			break ;
		value->next = (t_list *)malloc(sizeof(t_list));
		if (!value->next)
			return (NULL);
		value = value->next;
		value->content = NULL;
		value->next = NULL;
	}
	return (list);
}

int	ft_check_content(t_list *value)
{
	if (!value->content)
		return (0);
	while (ft_strchr(value->content, '\n') && value)
		value = value->next;
	if (ft_strchr(value->content, '\n'))
		return (1);
	return (0);
}

void	ft_show(t_list *value)
{
	t_list	*copy;

	copy = NULL;
	if (!value)
		return ;
	copy = value;
	printf("VALUE	: [%p] ------------------------------\n", value);
	while (copy)
	{
		printf("content	: [%s]\n", copy->content);
		copy = copy->next;
	}
	printf("---------------------------------------------\n");
}

void	ft_free(t_list *value)
{
	t_list	*to_free;
	t_list	*copy;

	to_free = NULL;
	copy = value;
	if (!value)
		return ;
	if (copy->next)
		copy = copy->next;
	while (copy)
	{
		to_free = copy;
		copy = copy->next;
		free(to_free->content);
		free(to_free);
	}
	value->content = NULL;
}

char	*get_next_line(int fd)
{
	static t_list	*value;
	t_list			*copy;

	copy = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!value)
	{
		value = (t_list *)malloc(sizeof(t_list));
		if (!value)
			return (NULL);
		value->content = NULL;
		value->next = NULL;
	}
	printf("TAFIDITRA ATO 1: [%p]..........\n", value);
	if ((value && !ft_check_content(value)))
	{
		value = ft_get_file_content(fd, value);
		if (!value)
			return (NULL);
		copy = value;
		ft_show(copy);
		ft_free(copy);
	}
	return (0);
}
