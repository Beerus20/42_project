/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:09:56 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:50:21 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_utils_bonus.h"
#include "../includes/ft_flags_bonus.h"

void	ft_printc(t_value *value)
{
	int	i;

	i = 0;
	if (value->w == 0)
	{
		ft_putchar_fd(value->content[0], 1);
		value->l = 1;
	}
	else
	{
		if (ft_strchr(value->flags, '-'))
		{
			ft_putchar_fd(value->content[0], 1);
			while (i++ < (value->w - 1))
				write(1, " ", 1);
		}
		else
		{
			while (i++ < (value->w - 1))
				write(1, " ", 1);
			ft_putchar_fd(value->content[0], 1);
		}
		value->l = value->w;
	}
}

t_value	*ft_fill_text_value(t_value *value, char *str, int *len)
{
	char	*tmp;

	tmp = str;
	while (*str != '%' && *(str++))
		*len = *len + 1;
	if (*len != 0)
	{
		value->type = 't';
		value->flags = ft_strdup("");
		value->content = ft_substr(tmp, 0, *len);
		value->w = 0;
		value->l = ft_strlen(value->content);
		if (*(str - 1) != '\0')
		{
			value->next = (t_value *)malloc(sizeof(t_value));
			if (!value->next)
				return (NULL);
		}
		else
			value->next = NULL;
		return (value->next);
	}
	return (value);
}

t_value	*ft_fill_arg_value(t_value *value, char *str, va_list args, int *len)
{
	char	*desc;
	int		i;

	i = 0;
	desc = NULL;
	while (!ft_check_type(str[i]))
	{
		i++;
		*len += 1;
	}
	desc = ft_substr(str, 0, i);
	value->type = str[i];
	value->content = ft_get_value(str[i], args);
	value->next = NULL;
	ft_get_flags(value, desc);
	free(desc);
	if (str[i + 1] != '\0')
	{
		value->next = (t_value *)malloc(sizeof(t_value));
		if (!value->next)
			return (NULL);
		return (value->next);
	}
	else
		return (value);
}

int	ft_print_value(t_value *value)
{
	t_value	*to_free;
	int		len;

	len = 0;
	to_free = NULL;
	while (value)
	{
		if (value->type == 'c')
			ft_printc(value);
		else
			ft_apply_flags(value);
		to_free = value;
		len += value->l;
		value = value->next;
		ft_free_value(to_free);
	}
	return (len);
}

void	ft_free_value(t_value *value)
{
	free(value->flags);
	free(value->content);
	free(value);
}
