/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:07:26 by ballain           #+#    #+#             */
/*   Updated: 2024/03/17 23:37:56 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_get.h"
#include "../includes/ft_utils.h"

char	*ft_get_value(char type, va_list args)
{
	if (ft_isint(type))
		return (ft_get_int_value(type, va_arg(args, int)));
	if (ft_isuint(type))
		return (ft_get_uint_value(type, args));
	if (type == 's')
		return (ft_get_str_value(va_arg(args, char *)));
	return (ft_strdup("%"));
}

void	*ft_get_int_value(char type, int value)
{
	if (type == 'c')
		return (ft_stoc(value));
	return (ft_itoa(value));
}

char	*ft_get_uint_value(char type, va_list args)
{
	char			*value;
	int				len;
	unsigned long	nb;

	nb = 0;
	value = NULL;
	if (type == 'p')
	{
		nb = (unsigned long)(va_arg(args, void *));
		if (!nb)
			return ((char *)0);
	}
	else
		nb = (unsigned long)va_arg(args, unsigned long);
	len = ft_count_nb(type, nb);
	value = (char *)malloc(sizeof(char) * (len + 1));
	if (!value)
		return (0);
	ft_uitos(type, nb, value);
	return (value);
}

void	*ft_get_str_value(char *value)
{
	if (!value)
		return ((char *)0);
	return (ft_strdup(value));
}
