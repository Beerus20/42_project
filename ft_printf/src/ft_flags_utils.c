/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:35:45 by beerus            #+#    #+#             */
/*   Updated: 2024/03/18 00:20:20 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_flags.h"

void	ft_len_flag_str(t_value *value)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!value->content)
	{
		if (value->l < 6)
			value->content = ft_strdup("");
		else
			value->content = ft_strdup("(null)");
	}
	else if (value->l < (int)ft_strlen(value->content))
	{
		tmp = ft_strdup(value->content);
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
		free(tmp);
	}
}

void	ft_len_flag_number(t_value *value, char *tmp)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(value->content);
	free(value->content);
	if (value->l == 0 && tmp[0] == '0')
	{
		value->content = ft_strdup("");
		return ;
	}
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
		while (tmp[j])
			value->content[i++] = tmp[j++];
		value->content[i] = '\0';
	}
	else
		value->content = ft_strdup(tmp);
}

void	ft_OAdot_flag(t_value *value, char *str, int apply_O)
{
	int		i;
	int		j;
	char	space_type;

	i = 0;
	j = 0;
	space_type = ' ';
	if (ft_strchr(value->flags, '0') && apply_O)
		space_type = '0';
	if (ft_strchr(value->flags, '-'))
	{
		while (i < value->l)
			value->content[i++] = str[j++];
		while (i < value->w)
			value->content[i++] = space_type;
	}
	else
	{
		while (i < (value->w - value->l))
			value->content[i++] = space_type;
		while (i < value->w)
			value->content[i++] = str[j++];
	}
	value->content[i] = '\0';
}

void	ft_width_flag(t_value *value)
{
	char	*tmp;
	int		len;

	len = value->l;
	tmp = ft_strdup(value->content);
	if (value->w > len)
	{
		free(value->content);
		value->content = (char *)malloc(sizeof(char) * (value->w + 1));
		if (!value->content)
			return ;
		if (ft_isnumber(value->type))
			ft_OAdot_flag(value, tmp, 1);
		else
			ft_OAdot_flag(value, tmp, 0);
		value->l = value->w;
	}
	free(tmp);
}