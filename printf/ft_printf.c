/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruce <bruce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:34:40 by bruce             #+#    #+#             */
/*   Updated: 2024/03/05 17:11:16 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/printf.h"

int	ft_cspdiuxX(char c)
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

char	*ft_check_type(char *str, t_action *action)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_cspdiuxX(str[i]))
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
	va_list		args;
	void		*in_value;
	char		*tmp;
	t_action	action;

	action = ft_init_action();
	tmp = (char *)format;
	va_start(args, format);
	while (*tmp)
	{
		while (*tmp != '%' && *tmp)
			ft_putchar_fd(*(tmp++), 1);
		if (*(tmp++) == '\0')
			return (0);
		tmp = ft_check_type(tmp, &action);
		ft_show_value(&action);
		if (*(tmp++) == 's')
		{
			in_value = (char *)va_arg(args, char *);
			ft_putstr_fd((char *)in_value, 1);
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	int	i;

	i = 2;
	printf("ORG	: [%s]\n", "HELLO");
	ft_printf("CPY	: [%0.12s] [%#.45d]\n", "HELLO");
	return (0);
}
