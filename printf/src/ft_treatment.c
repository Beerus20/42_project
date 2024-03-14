/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:44:45 by ballain           #+#    #+#             */
/*   Updated: 2024/03/14 14:01:23 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	*ft_streatment(t_flags *flags, void *c)
{
	if (ft_strchr(flags->flag, '.'))
	{
		if ((char *)c == NULL)
		{
			if (flags->max_w < 6)
				return (ft_strdup(""));
		}
		else
			return (ft_substr(c, 0, flags->max_w));
	}
	if ((char *)c == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(c));
}

int	ft_count_digit(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '-')
			count++;
		i++;
	}
	return (count);
}

void	*ft_ntreatment(t_flags *flags, void *c)
{
	char	*r_value;
	int		i;
	int		len_c;
	int		len;

	i = 0;
	len_c = ft_count_digit(c);
	len = flags->max_w;
	if (len == 0 && ft_atoi(c) == 0)
		return (ft_strdup(""));
	if (len < len_c)
		len = len_c;
	if (ft_strchr(c, '-'))
		len++;
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (ft_strchr(c, '-'))
		r_value[i++] = '-';
	while (i < len - len_c )
		r_value[i++] = '0';
	while (*(char *)c)
	{
		if (*(char *)c != '-')
			r_value[i++] = *(char *)(c++);
		else
			c++;
	}
	r_value[i] = '\0';
	return (r_value);
}

void	*ft_treatment(char type, t_flags *flags, void *c)
{
	if (type == 's')
		return (ft_streatment(flags, c));
	if (ft_strchr(flags->flag, '.'))
	{
		if (type != 'c')
			return (ft_ntreatment(flags, c));
		return (ft_substr(c, 0, flags->max_w));
	}
	return (ft_strdup(c));
}
