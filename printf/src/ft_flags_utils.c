/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:51:47 by beerus            #+#    #+#             */
/*   Updated: 2024/03/13 23:28:31 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

int	ft_count(const char *str, int (*f)(char))
{
	int	count;

	count = 0;
	while ((*f)(*(str++)) != 1)
		count++;
	return (count);
}

int	ft_count_flags(char *desc)
{
	int	count;

	count = 0;
	if (ft_strchr(desc, '.'))
		count++;
	while (ft_isflag(*(desc++)))
		count++;
	return (count);
}

void	ft_iflags(t_flags *flags, char *flag, int min, int max)
{
	flags->flag = flag;
	flags->min_w = min;
	flags->max_w = max;
}

void	ft_split_width(char **w, char *desc)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(desc, '.'))
	{
		tmp = ft_strchr(desc, '.');
		w[0] = ft_substr(desc, 0, (tmp - desc));
		desc = tmp + 1;
		w[1] = ft_strdup(desc);
	}
	else
	{
		w[0] = ft_strdup(desc);
		w[1] = ft_strdup("");
	}
	w[2] = NULL;
}
