/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:07:58 by ballain           #+#    #+#             */
/*   Updated: 2024/03/13 23:03:04 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_flags(char type, char *desc, void *str)
{
	t_flags	*flags;
	int		r_len;

	r_len = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	ft_get_flags(desc, flags);
	r_len = ft_apply_flags(type, flags, str);
	free(flags->flag);
	free(flags);
	return (r_len);
}

int	ft_print_int(char type, char *desc, int nb)
{
	char	*p_value;
	int		len;

	p_value = "";
	len = 0;
	if (type == 'c')
	{
		if (ft_strlen(desc) != 0)
			return (ft_print_flags(type, desc, &nb));
		ft_putchar_fd(nb, 1);
		return (1);
	}
	p_value = ft_itoa(nb);
	len = ft_print_flags(type, desc, p_value);
	free(p_value);
	return (len);
}

int	ft_print_u(char type, char *desc, va_list args)
{
	char			*value;
	int				len;
	unsigned long	nb;

	nb = 0;
	value = NULL;
	if (type == 'p')
		nb = (unsigned long)(va_arg(args, void *));
	else
		nb = (unsigned long)va_arg(args, unsigned long);
	len = ft_count_nb(type, nb);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (0);
	ft_uitos(type, nb, value);
	len = ft_print_flags(type, desc, value);
	free(value);
	return (len);
}

int	ft_print_str(char type, char *desc, char *str)
{
	if (!str)
		return (ft_print_flags(type, desc, "(null)"));
	return (ft_print_flags(type, desc, str));
}
