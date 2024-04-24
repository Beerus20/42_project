/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:25 by ballain           #+#    #+#             */
/*   Updated: 2024/04/24 09:30:49 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_value(char *type, va_list args)
{
	int	fgs[7];

	ft_init_flags(fgs);
	ft_check_flags(type, fgs);
	while (!ft_isdesc(*type))
		type++;
	if (*type == 'c')
		return (ft_get_len_char(fgs, va_arg(args, int)));
	if (*type == 's')
		return (ft_get_len_str(fgs, (char *)va_arg(args, char *)));
	if (*type == 'd' || *type == 'i')
		return (ft_get_len_nb(fgs, (int)va_arg(args, int)));
	if (*type == 'p')
		return (ft_get_len_pointer(fgs, (unsigned long)va_arg(args, void *)));
	if (*type == 'x' || *type == 'X')
		return (ft_get_len_hex(fgs, (unsigned long)va_arg(args, unsigned int)));
	if (*type == 'u')
		return (ft_get_len_unb(fgs, (unsigned long)va_arg(args, unsigned int)));
	else
		return (1);
}
