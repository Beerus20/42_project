/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:03:36 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 12:23:40 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	ft_gnl_strlen( char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_gnl_get_len(t_cmd *value)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (!ft_strchr(value->content, '\n') && value->next)
	{
		len += ft_gnl_strlen(value->content);
		value = value->next;
	}
	if (ft_strchr(value->content, '\n'))
	{
		while (value->content[i++] != '\n')
			;
		len += i;
	}
	else
		len += ft_gnl_strlen(value->content);
	return (len);
}

char	*ft_alloc(char *s, int len)
{
	char	*r_value;
	int		i;

	i = 0;
	if (s)
		len = ft_gnl_strlen(s);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (0);
	if (s)
	{
		while (i < len)
		{
			r_value[i] = s[i];
			i++;
		}
	}
	else
	{
		while (i < len)
			r_value[i++] = 0;
	}
	r_value[i] = '\0';
	return (r_value);
}

void	ft_gnl_free(t_cmd *value)
{
	t_cmd	*to_free;

	to_free = NULL;
	while (value)
	{
		to_free = value;
		value = value->next;
		free(to_free->content);
		free(to_free);
	}
}
