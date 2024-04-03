/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:50:14 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
	va_end(args);
	return (ft_print_value(copy));
}
