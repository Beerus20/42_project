/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/13 11:24:47 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printv(const char *type, va_list args, int *i)
{
	char	*desc;
	int		len_desc;
	int		r_len;

	r_len = 0;
	len_desc = ft_count(type, ft_check_type);
	desc = (char *)malloc(sizeof(char) * (len_desc + 1));
	if (!desc)
		return (0);
	ft_get_desc(desc, type, len_desc);
	type += len_desc;
	*i += len_desc;
	if (ft_isint(*type))
		r_len = ft_print_int(*type, desc, va_arg(args, int));
	if (ft_isuint(*type))
		r_len = ft_print_u(*type, desc, args);
	if (*type == 's')
		r_len = ft_print_str(*type, desc, va_arg(args, char *));
	if (*type == '%')
	{
		ft_putchar_fd('%', 1);
		r_len = (1);
	}
	free(desc);
	return (r_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%' && str[i] != '\0' && ++len)
			ft_putchar_fd(str[i], 1);
		else
			len += ft_printv(&str[++i], args, &i);
		i++;
	}
	va_end(args);
	return (len);
}
