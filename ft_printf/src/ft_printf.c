/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/17 23:42:10 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_utils.h"
#include "../includes/ft_flags.h"

int		ft_print_value(t_value *value);
t_value	*ft_fill_text_value(t_value *value, char *str, int *len);
t_value	*ft_fill_arg_value(t_value *value, char *str, va_list args, int *len);
void	ft_free_value(t_value *value);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_value	*value;
	t_value	*copy;
	int		len;

	len = 0;
	value = (t_value *)malloc(sizeof(t_value));
	copy = value;
	if (!value)
		return (0);
	va_start(args, format);
	while (*format)
	{
		len = 0;
		value = ft_fill_text_value(value, (char *)format, &len);
		format += len;
		if (*(format++) == '\0')
			break ;
		len = 0;
		value = ft_fill_arg_value(value, (char *)format, args, &len);
		format += len + 1;
	}
	//ft_show_value(copy);
	va_end(args);
	return (ft_print_value(copy));
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
		{
			ft_apply_flags(value);
			ft_putstr_fd(value->content, 1);
		}
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
