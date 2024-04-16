/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:04:41 by ballain           #+#    #+#             */
/*   Updated: 2024/04/16 16:05:44 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_utils.h"

int	ft_get_len(const char *format, va_list args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len++;
		else
		{
			len += ft_len_value(&((char *)format)[i + 1], args);
			i++;
		}
		i++;
	}
	return (len);
}
