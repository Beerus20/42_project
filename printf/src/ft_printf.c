/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/11 17:28:28 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printv(const char *type, va_list args)
{
	char	*flags;
	int		len_flags;

	len_flags = ft_len_flags((char *)type);
	flags = (char *)malloc(sizeof(char) * (len_flags + 1));
	if (!flags)
		return (0);
	ft_get_flags(flags, type, len_flags);
	printf("\n\tFLAGS	: [%d]\n", len_flags);
	type += len_flags;
	if (ft_isint(*type))
		return (ft_print_int(*type, va_arg(args, int)));
	if (ft_isuint(*type))
		return (ft_print_u(*type, args));
	if (*type == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (*type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	free(flags);
	return (0);
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
			len += ft_printv(&str[++i], args);
		i++;
	}
	va_end(args);
	return (len);
}
