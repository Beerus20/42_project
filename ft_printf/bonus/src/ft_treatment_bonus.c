/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:34:57 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:07:01 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_utils_bonus.h"
#include "../includes/ft_flags_bonus.h"

void	ft_apply_flags_str(t_value *value)
{
	if (ft_strchr(value->flags, 'l'))
	{
		if (!value->content)
		{
			if (value->l < 6)
				value->content = ft_strdup("");
			else
				value->content = ft_strdup("(null)");
		}
		else
			ft_len_flag_str(value);
	}
	else if (!value->content)
		value->content = ft_strdup("(null)");
	value->l = ft_strlen(value->content);
}

void	ft_apply_flags_pointer(t_value *value)
{
	if (!value->content)
		value->content = ft_strdup("(nil)");
	else
		ft_add_front_content_value(value, "0x");
	value->l = ft_strlen(value->content);
}

void	ft_apply_extra_flags_number(t_value *value)
{
	if (ft_strchr(value->flags, '+') && value->content[0] != '-')
		ft_add_front_content_value(value, "+");
	else if (ft_strchr(value->flags, '#'))
	{
		if (!ft_is_null_hex_value(value->content) != 0)
		{
			if (value->type == 'x')
				ft_add_front_content_value(value, "0x");
			if (value->type == 'X')
				ft_add_front_content_value(value, "0X");
		}
	}
	else if (ft_strchr(value->flags, ' ') && value->content[0] != '-')
		ft_add_front_content_value(value, " ");
}

void	ft_apply_flags_number(t_value *value)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(value->flags, 'l'))
	{
		tmp = ft_strdup(value->content);
		free(value->content);
		if (value->l == 0 && tmp[0] == '0')
			value->content = ft_strdup("");
		else
		{
			ft_len_flag_number(value, tmp);
			if (tmp[0] == '-' && value->content[0] != '-')
				ft_add_front_content_value(value, "-");
		}
		free(tmp);
	}
	ft_apply_extra_flags_number(value);
	value->l = ft_strlen(value->content);
}

void	ft_apply_flags(t_value *value)
{
	char	type;

	type = value->type;
	if (type == 's')
		ft_apply_flags_str(value);
	if (type == 'p')
		ft_apply_flags_pointer(value);
	if (ft_isnumber(type))
		ft_apply_flags_number(value);
	if (ft_strchr(value->flags, 'w'))
		ft_width_flag(value);
	ft_putstr_fd(value->content, 1);
}
