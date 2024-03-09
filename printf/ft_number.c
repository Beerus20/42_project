/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 07:59:21 by beerus            #+#    #+#             */
/*   Updated: 2024/03/09 09:49:46 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nb_to_str(char type, va_list arg)
{
	double	s_value;

	s_value = (double)va_arg(arg, double);
	if (!s_value || type == 'i')
		s_value = (int)va_arg(arg, int);
	if (type == 'd' || type == 'i')
		ft_decimal_to_str(s_value);
	if (type == 'u' && s_value > 0)
		ft_decimal_to_str(s_value);
	if (type == 'x' || type == 'X')
		ft_base_tth(s_value, type);
}
