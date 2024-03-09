/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/09 16:02:44 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	char	*tmp;
	char	*r_value;
	int		i;

	i = 0;
	r_value = "";
	str = (char *)format;
	tmp = str;
	va_start(args, format);
	while (str[i])
	{
		tmp = ft_strchr(&str[i], '%');
		r_value = ft_strjoin(r_value, ft_substr(&str[i], 0, (tmp - &str[i])));
		i += tmp - &str[i];
		if(str[i++] == '%')
		{
			if (str[i] == 'c')
			{
				r_value = ft_strjoin(r_value, "^^");
			}
		}
		if (*tmp == '\0')
			break ;
		i++;
	}
	ft_putstr_fd(r_value, 1);
	va_end(args);
	return (0);
}
