/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:04:24 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:04:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_strlen(char *value)
{
	int	i;

	i = 0;
	if (!value)
		return (i);
	while (value[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*r_value;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (0);
	while (i < len)
	{
		r_value[i] = s[i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}

void	ft_printv(char type, char *value, int *len)
{
	if (type == 's' && !value)
	{
		*len += 6;
		write(1, "(null)", 6);
	}
	else if (type == 'p')
	{
		if (!value)
		{
			*len += 5;
			write(1, "(nil)", 5);
		}
		else
		{
			*len += 2;
			write(1, "0x", 2);
		}
	}
	else if (type == 'c' && ft_strlen(value) == 0)
		*len += 1;
	write(1, value, ft_strlen(value));
	*len += ft_strlen(value);
}

void	ft_printc(int value, int *len)
{
	write(1, &value, 1);
	*len += 1;
}
