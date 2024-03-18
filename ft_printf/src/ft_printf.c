/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 14:12:07 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
