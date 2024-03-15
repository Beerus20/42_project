/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/15 16:52:59 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_value(t_value *value);
t_value	*ft_fill_text_value(t_value *value, char *str, int len);
int		ft_fill_arg_value(t_value *value, char *str, va_list args);
void	ft_show_value(t_value *value);
void	ft_free_value(t_value *value);

t_value	*ft_add_next(t_value *value)
{
	value->next = (t_value *)malloc(sizeof(t_value));
	if (!value->next)
		return (NULL);
	return (value->next);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_value	*value;
	t_value	*copy;
	char	*str;
	char	*tmp;

	tmp = NULL;
	str = (char *)format;
	value = (t_value *)malloc(sizeof(t_value));
	copy = value;
	if (!value)
		return (0);
	va_start(args, format);
	while (*str)
	{
		tmp = str;
		while (*str != '%' && *str)
			str++;
		if ((str - tmp) != 0)
			value = ft_fill_text_value(value, tmp, (str - tmp));
		if (*(str++) == '\0')
			break ;
		str += ft_fill_arg_value(value, str, args);
		if (*(++str) == '\0')
			break ;
		value = ft_add_next(value);
	}
	va_end(args);
	return (ft_print_value(copy));
}

t_value	*ft_fill_text_value(t_value *value, char *str, int len)
{
	value->type = 't';
	value->flags = ft_strdup("");
	value->content = ft_substr(str, 0, len);
	value->w = 0;
	value->l = ft_strlen(value->content);
	if (*(str + len) != '\0')
	{
		value->next = (t_value *)malloc(sizeof(t_value));
		if (!value->next)
			return (NULL);
	}
	else
		value->next = NULL;
	return (value->next);
}

int	ft_fill_arg_value(t_value *value, char *str, va_list args)
{
	int	i;

	i = 0;
	while (!ft_check_type(str[i]))
		i++;
	value->type = str[i];
	value->flags = ft_substr(str, 0, i);
	value->content = ft_get_value(str[i], args);
	value->w = 0;
	if (value->type == 'c')
		value->l = 1;
	else
		value->l = ft_strlen(value->content);
	value->next = NULL;
	return (i);
}

void	ft_show_value(t_value *value)
{
	int	i;

	i = 0;
	while (value)
	{
		printf("CONTENT	: %d\n", i++);
		printf("\tType	: %c\n", value->type);
		printf("\tflags	: %s\n", value->flags);
		printf("\tlen	: %d\n", value->l);
		printf("\tval	: [%s]\n\n", value->content);
		value = value->next;
	}
}

int	ft_print_value(t_value *value)
{
	t_value	*to_free;
	int		len;
	int		c;

	c = 0;
	len = 0;
	to_free = NULL;
	while (value)
	{
		to_free = value;
		if (value->type == 'c')
		{
			c = ((int *)value->content)[0];
			write(1, &c, 1);
		}
		else
			ft_putstr_fd(value->content, 1);
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
