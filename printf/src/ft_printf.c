/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:20:17 by ballain           #+#    #+#             */
/*   Updated: 2024/03/10 22:05:29 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_int_value(char type, int nb)
{
	char	*p_value;
	int		len;

	p_value = "";
	len = 0;
	if (type == 'c')
	{
		ft_putchar_fd(nb, 1);
		return (1);
	}
	p_value = ft_itoa(nb);
	len = ft_strlen(p_value);
	ft_putstr_fd(p_value, 1);
	free(p_value);
	return (len);
}

int	ft_print_uint_value(char type, unsigned int nb)
{
	int		r_len;

	r_len = 0;
	if (nb == 0)
	{
		ft_putstr_fd("0", 1);
		return (r_len + 1);
	}
	r_len = ft_uitos(type, nb);
	return (r_len);
}

int	ft_printv(char type, va_list args)
{
	char	*p_value;
	int		len;

	len = 0;
	p_value = NULL;
	if (ft_isint(type))
		return (ft_print_int_value(type, va_arg(args, int)));
	if (ft_isuint(type))
		return (ft_print_uint_value(type, va_arg(args, unsigned int)));
	if (type == 's')
	{
		p_value = va_arg(args, char *);
		if (!p_value)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(p_value, 1);
		len = ft_strlen(p_value);
		return (len);
	}
	return (len);
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
			len += ft_printv(str[++i], args);
		i++;
	}
	va_end(args);
	return (len);
}
