/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:25 by bruce             #+#    #+#             */
/*   Updated: 2024/03/09 09:34:55 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_descriptor	ft_init_descriptor(void)
{
	t_descriptor	r_value;

	r_value.type = 0;
	r_value.flags = (void *)0;
	return (r_value);
}

void	ft_decimal_to_str(double nb)
{
	long	i;
	long	entier;
	double	decimal;

	i = 0;
	entier = (long)nb;
	decimal = nb - (long)nb;
	printf("VALUE	:[%f]\n", nb);
	ft_putstr_fd(ft_itoa((int)entier), 1);
	if (decimal != 0.0)
	{
		while (i < 6)
		{
			decimal *= 10;
			i++;
		}
		ft_putchar_fd('.', 1);
		ft_putstr_fd(ft_itoa(decimal), 1);
	}
}

char	*ft_get_address(void *p)
{
	unsigned long	tmp;
	int				len;
	int				i;
	char			*r_value;

	i = 0;
	tmp = *((unsigned long *) &p);
	len = ft_nblen(tmp, 16);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	while (tmp)
	{
		r_value[i++] = "0123456789abcdef"[tmp % 16];
		tmp /= 16;
	}
	r_value[i] = '\0';
	return (ft_rev_str(r_value));
}

void	ft_base_tth(int n, char type)
{
	char	tmp;

	tmp = 0;
	if (n == 0)
		return ;
	else
	{
		if (type == 'X')
			tmp = "0123456789ABCDEF"[n % 16];
		else
			tmp = "0123456789abcdef"[n % 16];
		n /= 16;
		ft_base_tth(n, type);
	}
	ft_putchar_fd(tmp, 1);
}
