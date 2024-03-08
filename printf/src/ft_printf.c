/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:34:40 by bruce             #+#    #+#             */
/*   Updated: 2024/03/08 21:17:46 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_value(t_descriptor *desc, va_list args)
{
	char	value;

	value = 0;
	if (desc->type == 's')
		ft_putstr_fd((char *)va_arg(args, char *), 1);
	if (desc->type == 'd')
	{
		value = (int)va_arg(args, int) + '0';
		ft_putchar_fd(value, 1);

	}
}

int	ft_check_specifier(char c)
{
	char	*check_list;

	check_list = "cspdiuxX%";
	while (*check_list)
	{
		if (c == *check_list)
			return (1);
		check_list++;
	}
	return (0);
}

char	*ft_check_type(char *str, t_descriptor *action)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_check_specifier(str[i]))
		{
			action->type = str[i];
			action->flags = ft_substr(str, 0, count);
			return (&str[i]);
		}
		i++;
		count++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	char			*tmp;
	t_descriptor	action;

	action = ft_init_descriptor();
	tmp = (char *)format;
	va_start(args, format);
	while (*tmp)
	{
		while (*tmp != '%' && *tmp)
			ft_putchar_fd(*(tmp++), 1);
		if (*(tmp++) == '\0')
			return (0);
		tmp = ft_check_type(tmp, &action);
		ft_print_value(&action, args);
		tmp++;
		printf("\nAto...\n");
	}
	va_end(args);
	return (0);
}
