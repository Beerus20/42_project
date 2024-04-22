/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:11:20 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 14:55:54 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_add_bonus.h"

int	ft_add_value(char *type, char *text, va_list args)
{
	int	flags[7];

	ft_init_flags(flags);
	ft_check_flags(type, flags);
	while (!ft_isdesc(*type))
		type++;
	if (*type == 'c')
		return (ft_add_char_value(text, flags, va_arg(args, int)));
	if (*type == 's')
		return (ft_add_str_value(text, flags, (char *)va_arg(args, char *)));
	if (*type == 'd' || *type == 'i')
		return (ft_add_nb_value(text, flags, (int)va_arg(args, int)));
	if (*type == 'p')
		return (ft_add_pval(text, flags, (unsigned long)va_arg(args, void *)));
	if (*type == 'x')
		return (ft_add_hex_value(text, flags, va_arg(args, unsigned int), 0));
	if (*type == 'X')
		return (ft_add_hex_value(text, flags, va_arg(args, unsigned int), 1));
	if (*type == 'u')
		return (ft_add_unb_value(text, flags, va_arg(args, unsigned int)));
	*(text++) = '%';
	return (1);
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
			text[j++] = format[i];
		else
		{
			j += ft_add_value(&((char *)format)[i + 1], &text[j], args);
			while (!ft_isdesc(format[++i]))
				;
		}
		i++;
	}
}
