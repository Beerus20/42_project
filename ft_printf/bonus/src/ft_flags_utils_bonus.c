/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:35:45 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:49:55 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_flags_bonus.h"
#include "../includes/ft_utils_bonus.h"

void	ft_len_flag_str(t_value *value)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(value->content);
	if (value->l < (int)ft_strlen(value->content))
	{
		free(value->content);
		value->content = (char *)malloc(sizeof(char) * (value->l + 1));
		if (!value->content)
			return ;
		while (i < value->l)
		{
			value->content[i] = tmp[i];
			i++;
		}
		value->content[i] = '\0';
	}
	free(tmp);
}

void	ft_len_flag_number(t_value *value, char *tmp)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(tmp);
	if (tmp[0] == '-')
	{
		len--;
		j++;
	}
	if (value->l > len)
	{
		value->content = (char *)malloc(sizeof(char) * (value->l + 1));
		if (!value->content)
			return ;
		while (i < (value->l - len))
			value->content[i++] = '0';
		while (i < value->l)
			value->content[i++] = tmp[j++];
		value->content[i] = '\0';
	}
	else
		value->content = ft_strdup(tmp);
}

void	ft_zero_flag(t_value *value, char *str, int i, int w)
{
	char	space_type;
	int		j;

	j = 0;
	space_type = ' ';
	if (ft_zero_flag_condition(value))
		space_type = '0';
	if (ft_strchr(value->flags, '-'))
	{
		while (i < value->l)
			value->content[i++] = str[j++];
		while (i < w)
			value->content[i++] = space_type;
	}
	else
	{
		while (i < (w - value->l))
			value->content[i++] = space_type;
		while (i < w)
			value->content[i++] = str[j++];
	}
	value->content[i] = '\0';
}

void	ft_dot_flag(t_value *value, char *str)
{
	int		i;
	int		w;

	i = 0;
	w = value->w;
	if (ft_has_extra_flags(value->flags, str) && ft_zero_flag_condition(value))
	{
		if (ft_strchr(value->flags, '#'))
		{
			value->content[i++] = '0';
			value->content[i++] = value->type;
			str += 2;
			w += 2;
		}
		else
		{
			value->content[i++] = str[0];
			str++;
			w++;
		}
	}
	ft_zero_flag(value, str, i, w);
}

void	ft_width_flag(t_value *value)
{
	char	*tmp;
	int		len;

	len = value->l;
	tmp = NULL;
	if (value->w > len)
	{
		tmp = ft_strdup(value->content);
		free(value->content);
		value->content = (char *)malloc(sizeof(char) * (value->w + 1));
		if (!value->content)
			return ;
		ft_dot_flag(value, tmp);
		value->l = value->w;
		free(tmp);
	}
}
