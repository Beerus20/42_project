/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:25 by ballain           #+#    #+#             */
/*   Updated: 2024/04/20 17:34:10 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"

int	ft_len_value(char *type, va_list args)
{
	int	flags[7];

	ft_init_flags(flags);
	ft_check_flags(type, flags);
	while (!ft_isdesc(*type))
		type++;
	if (*type == 'c')
		return (ft_get_len_char(flags, va_arg(args, int)));
	if (*type == 's')
		return (ft_get_len_str(flags, (char *)va_arg(args, char *)));
	// if (*type == 'd' || *type == 'i')
	// 	return (ft_nblen((int)va_arg(args, int)));
	// if (*type == 'p')
	// {
	// 	value = (unsigned long)va_arg(args, void *);
	// 	if (value == 0)
	// 		return (5);
	// 	return (2 + ft_u_nblen(value, 16));
	// }
	// if (*type == 'x' || *type == 'X')
	// 	return (ft_u_nblen((unsigned long)va_arg(args, unsigned int), 16));
	if (*type == 'u')
		return (ft_get_len_unb(flags, (unsigned long)va_arg(args, unsigned int)));
	else
		return (1);
}
