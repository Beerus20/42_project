/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:06 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 10:20:35 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_add.h"

int	ft_add_value(char type, char *text, va_list args)
{
	if (type == 'c')
		return (ft_add_char(text, va_arg(args, int)));
	if (type == 's')
		return (ft_add_str(text, (char *)va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_add_nb(text, (int)va_arg(args, int)));
	if (type == 'p')
		return (ft_add_pointer(text, (unsigned long)va_arg(args, void *)));
	if (type == 'x')
		return (ft_add_unb(text, va_arg(args, unsigned int), 1));
	if (type == 'X')
		return (ft_add_unb(text, va_arg(args, unsigned int), 2));
	if (type == 'u')
		return (ft_add_unb(text, va_arg(args, unsigned int), 0));
	else
	{
		ft_add_str(text, "%");
		return (1);
	}
}

void	ft_add(const char *format, char *text, va_list args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] != '%')
			text[j++] = format[i++];
		else
		{
			j += ft_add_value(format[i + 1], &text[j], args);
			i += 2;
		}
	}
}
