/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:02:37 by beerus            #+#    #+#             */
/*   Updated: 2024/03/24 08:40:25 by beerus           ###   ########.fr       */
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

void	ft_add_last(t_list *value)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (value->content[i++] != '\n')
		;
	len = ft_strlen(value->content) - i;
	if (len <= 0)
		return ;
	value->next = (t_list *)malloc(sizeof(t_list));
	if (!value->next)
		return ;
	printf("LEN AT ADD LAST	=========> : [%d] [%s]\n", len, value->content);
	value->next->content = ft_zalloc(len);
	value->next->next = NULL;
	while (value->content[i])
		value->next->content[j++] = value->content[i++];
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
		{
			ft_add_last(value);
			break ;
		}
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

/* int	ft_check_content(t_list *value)
{
	if (!value->content)
	{
		printf("............... VALUE CONTENT NULL ERROR \n");
		return (0);
	}
	if (ft_strchr(value->content, '\n'))
		return (1);
	return (0);
} */

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

t_list	*ft_free(t_list *value)
{
	t_list	*to_free;

	to_free = NULL;
	printf("...................start FREE...................\n");
	while (!ft_strchr(value->content, '\n') && value)
	{
		to_free = value;
		value = value->next;
		free(to_free->content);
		free(to_free);
	}
	printf("...................end FREE...................\n");
	if (ft_strchr(value->content, '\n'))
		return (value);
	return (NULL);
}

char	*ft_get_rvalue(t_list *value)
{
	char	*r_value;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_get_len(value);
	r_value = ft_zalloc(len + 1);
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
	printf("RESULTAT	==============================> [%d] [%s]\n", len, r_value);
	return (r_value);
}

char	*get_next_line(int fd)
{
	static t_list	*value;
	char			*r_value;

	r_value = NULL;
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
	if (value && !ft_strchr(value->content, '\n'))
	{
		printf("############# CALL READ FILE TO ADD CONTENT #############\n");
		value = ft_get_file_content(fd, value);
		if (!value->content)
			return (NULL);
		printf("########### END CALL READ FILE TO ADD CONTENT ###########\n");
	}
	//printf("============	: [%p] [%s]..........\n", value, value->content);
	ft_show(value);
	r_value = ft_get_rvalue(value);
	value = ft_free(value);
	return (r_value);
}
