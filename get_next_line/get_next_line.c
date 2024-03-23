/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/23 08:58:06 by beerus           ###   ########.fr       */
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
		printf("buffer got _________	: [%s]..........\n", buffer);
		if (!buffer)
		{
			printf("NULL BUFFER	: [%s]..........\n", buffer);
			free(buffer);
			break ;
		}
		value->content = ft_strdup(buffer);
		printf("content added 2	: [%p] [%s]..........\n\n", value, value->content);
		if (ft_strchr(value->content, '\n'))
			break ;
		if (ft_strlen(value->content) != BUFFER_SIZE)
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
	{
		printf("............... VALUE CONTENT NULL ERROR \n");
		return (0);
	}
	while (!ft_strchr(value->content, '\n') && value)
		value = value->next;
	if (ft_strchr(value->content, '\n'))
		return (1);
	return (0);
}

void	ft_show(t_list *value)
{
	t_list	*copy;

	printf("####################### SHOW CALL #######################\n");
	copy = value;
	printf("VALUE	: [%p] ------------------------------\n", value);
	while (copy)
	{
		printf("content	: [%s] \n", copy->content);
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
	if (copy->next)
		copy = copy->next;
	printf(".....................FREE.....................\n");
	while (copy)
	{
		to_free = copy;
		copy = copy->next;
		free(to_free->content);
		free(to_free);
	}
	printf("...................end FREE...................\n");
	value->content = NULL;
	value->next = NULL;
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
	ft_show(value);
	if (value && !ft_check_content(value))
	{
		printf("############# CALL READ FILE TO ADD CONTENT #############\n");
		printf("_______ check result	: [%d]\n", ft_check_content(value));
		value = ft_get_file_content(fd, value);
	}
	//printf("============	: [%p] [%s]..........\n", value, value->content);
	copy = value;
	ft_show(copy);
	ft_free(copy);
	return (0);
}
