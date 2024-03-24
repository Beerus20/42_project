/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/24 06:45:57 by beerus           ###   ########.fr       */
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
		printf("content added 2	: [%p] [%s]..........\n", value, value->content);
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

void	ft_free(t_list **value)
{
	t_list	*to_free;

	to_free = NULL;
	printf("...................start FREE...................\n");
	while (!ft_strchr((*value)->content, '\n') && (*value))
	{
		to_free = *value;
		*value = (*value)->next;
		free(to_free->content);
		free(to_free);
	}
	if ((*value)->next)
		value = &((*value)->next);
	free((*value)->content);
	free((*value));
	printf("...................end FREE...................\n");
}

/* void	ft_get_rvalue(t_list **value)
{

}
 */
char	*get_next_line(int fd)
{
	static t_list	*value;

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
	ft_show(value);
	ft_free(&value);
	return (0);
}
