/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/23 18:19:27 by ballain          ###   ########.fr       */
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


	value = (t_list *)malloc(sizeof(t_list));
	if (!value)
		return (NULL);
	value->content = NULL;
	value->next = NULL;
	if (list && list->content)
		list->next = value;
	else
	{
		if (list)
			free(list);
		list = value;
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

int	ft_get_len(t_list *value)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (!ft_strchr(value->content, '\n') && value)
	{
		len += ft_strlen(value->content);
		value = value->next;
	}
	if (ft_strchr(value->content, '\n'))
	{
		while (value->content[i] != '\n')
			i++;
		len += i;
	}
	return (len);
}

void	ft_free(t_list *value)
{
	t_list	*to_free;
	t_list	*copy;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	to_free = NULL;
	copy = value;
	printf(".....................FREE.....................\n");
	if (copy->next)
	{
		copy = copy->next;
		while (copy->next)
		{
			to_free = copy;
			copy = copy->next;
			free(to_free->content);
			free(to_free);
		}
	}
	if (ft_strchr(copy->content, '\n'))
	{
		while (copy->content[i++] != '\n')
			;
		tmp = ft_zalloc(ft_strlen(copy->content) - i);
		if (!tmp)
			return ;
		while (copy->content[i])
			tmp[j++] = copy->content[i++];
		tmp[j] = '\0';
	}
	free(value->content);
	if (tmp && ft_strlen(tmp))
		value->content = ft_strdup(tmp);
	else
		value->content = NULL;
	printf("REST	: [%s]\n", value->content);
	value->next = NULL;
	printf("...................end FREE...................\n");
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
	printf("TAFIDITRA ATO 1: [%p]====================================\n", value);
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
