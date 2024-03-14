/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/14 17:18:25 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_value(t_value *value);
char	*ft_get_value(char type, va_list args);
char	*ft_get_str_value(char *value);
char	*ft_get_int_value(char type, int value);
char	*ft_get_uint_value(char type, va_list args);
char	*ft_fill_text_value(t_value *value, const char *str);
char	*ft_fill_arg_value(t_value *value, const char *str, va_list args);
void	ft_show_value(t_value *value);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_value	*value;
	t_value	*copy;
	char	*c_str;

	c_str = (char *)str;
	value = (t_value *)malloc(sizeof(t_value));
	copy = value;
	if (!value)
		return (0);
	va_start(args, str);
	while (*c_str)
	{
		if (ft_strchr(c_str, '%'))
		{
			c_str = ft_fill_text_value(value, c_str);
			value = value->next;
			c_str = ft_fill_arg_value(value, c_str, args);
			value = value->next;
		}
		else
			ft_fill_text_value(value, c_str);
	}
	value->next = NULL;
	ft_print_value(copy);
	//ft_show_value(copy);
	va_end(args);
	return (0);
}

char	*ft_fill_text_value(t_value *value, const char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '%');
	value->type = 't';
	value->flags = ft_strdup("");
	value->content = ft_substr(str, 0, tmp - str);
	value->w = 0;
	value->l = ft_strlen(value->content);
	value->next = (t_value *)malloc(sizeof(t_value));
	if (!value->next)
		return (NULL);
	return (tmp + 1);
}

char	*ft_fill_arg_value(t_value *value, const char *str, va_list args)
{
	int	i;

	i = 0;
	while (!ft_check_type(str[i]))
		i++;
	value->type = str[i];
	value->flags = ft_substr(str, 0, i);
	value->content = ft_get_value(str[i], args);
	value->w = 0;
	value->l = ft_strlen(value->content);
	value->next = (t_value *)malloc(sizeof(t_value));
	if (!value->next)
		return (NULL);
	return ((char *)(str + ++i));
}

char	*ft_get_value(char type, va_list args)
{
	if (ft_isint(type))
		return (ft_get_int_value(type, va_arg(args, int)));
	if (ft_isuint(type))
		return (ft_get_uint_value(type, args));
 	if (type == 's')
		return (ft_get_str_value(va_arg(args, char *)));
	return (ft_strdup("%"));
}

char	*ft_get_int_value(char type, int value)
{
	if (type == 'c')
		return (ft_stoc(value));
	return (ft_itoa(value));
}

char	*ft_get_uint_value(char type, va_list args)
{
	char			*value;
	int				len;
	unsigned long	nb;

	nb = 0;
	value = NULL;
	if (type == 'p')
		nb = (unsigned long)(va_arg(args, void *));
	else
		nb = (unsigned long)va_arg(args, unsigned long);
	len = ft_count_nb(type, nb);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (0);
	ft_uitos(type, nb, value);
	return (value);
}

char	*ft_get_str_value(char *value)
{
	if (!value)
		return (ft_strdup("(null)"));
	return (ft_strdup(value));
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

void	ft_print_value(t_value *value)
{
	while (value->next)
	{
		ft_putstr_fd(value->content, 1);
		value = value->next;
	}
	ft_putchar_fd('\n', 1);
}
