/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:07:58 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 18:50:37 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_wd(const char *str, const char sep)
{
	int	i;
	int	len;
	int	r_count;

	i = 0;
	len = ft_strlen((char *)str);
	r_count = 0;
	while (i < len)
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i])
			r_count++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (r_count);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*r_value;
	char	*tmp;

	len = ft_strlen((char *)str) + 1;
	if (len == 1)
		return (NULL);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	tmp = r_value;
	while (*str)
		*(tmp++) = *(str++);
	*tmp = '\0';
	return (r_value);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**r_value;
	char	*tmp;

	i = 0;
	while (*s == c && *s)
		s++;
	tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	r_value = (char **)malloc(sizeof(char *) * (ft_count_wd(s, c) + 1));
	if (!r_value)
		return (NULL);
	while (*tmp)
	{
		while (*tmp == c && *tmp)
			*(tmp++) = '\0';
		if (*tmp)
			r_value[i++] = tmp;
		while (*tmp != c && *tmp)
			tmp++;
	}
	r_value[i] = NULL;
	return (r_value);
}

int	ft_params_is_valid(int argc, const char **argv)
{
	int		i;
	char	*param;

	i = 0;
	while (++i < argc)
	{
		param = (char *)argv[i];
		while (*param)
		{
			while (*param == ' ' && *param)
				param++;
			if (*param == '-')
				param++;
			while (*param != ' ' && *param)
			{
				if (!(*param >= '0' && *param <= '9'))
				{
					ft_printf("Error\n");
					return (0);
				}
				param++;
			}
		}
	}
	return (1);
}

int	ft_check_error(t_list *pile)
{
	while (pile)
	{
		if (pile->content > 2147483647 || pile->content < -2147483648)
		{
			ft_printf("Error\n");
			return (1);
		}
		if (ft_search(pile->next, pile->content) != -1)
		{
			ft_printf("Error\n");
			return (1);
		}
		pile = pile->next;
	}
	return (0);
}
