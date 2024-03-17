/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:51:03 by beerus            #+#    #+#             */
/*   Updated: 2024/03/17 15:43:18 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_flags.h"

int	ft_count_flags(char *desc)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (ft_strchr(desc, '.'))
		count += 2;
	if (ft_strlen(desc))
	{
		while (ft_isflag(desc[i]))
		{
			count++;
			i++;
		}
	}
	if (desc[i] != '\0')
		count++;
	return (count);
}

void	ft_get_lenght(t_value *value, char *desc)
{
	char	type;
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = desc;
	type = value->type;
	if (!ft_strlen(desc))
	{
		if (type == 'c')
			value->l = 1;
		else
		{
			if (ft_strchr(value->flags, 'l'))
				value->l = 0;
			else if (value->content)
				value->l = ft_strlen(value->content);
			else
				value->l = ft_strlen("(null)");
		}
		return ;
	}
	while (*tmp)
		tmp++;
	str = ft_substr(desc, 0, tmp - desc);
	value->l = ft_atoi(str);
	free(str);
}

void	ft_get_size(t_value *value, char *desc)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = NULL;
	if (ft_strchr(desc, '.'))
	{
		tmp = ft_strchr(desc, '.');
		str = ft_substr(desc, 0, tmp - desc);
		value->w = ft_atoi(str);
		free(str);
		ft_get_lenght(value, ++tmp);
	}
	else if (*desc != '\0')
	{
		tmp = desc;
		while (*tmp)
			tmp++;
		str = ft_substr(desc, 0, tmp - desc);
		value->w = ft_atoi(str);
		free(str);
		ft_get_lenght(value, tmp);
	}
	else
		ft_get_lenght(value, desc);
}

void	ft_get_flags(t_value *value, char *desc)
{
	int		nb_flags;
	int		i;

	i = 0;
	nb_flags = ft_count_flags(desc);
	value->flags = (char *)malloc(sizeof(char) * (nb_flags + 1));
	if (!value->flags)
		return ;
	while (ft_isflag(*desc))
		value->flags[i++] = *(desc++);
	if (ft_strchr(desc, '.'))
	{
		value->flags[i++] = 'l';
		value->flags[i++] = '.';
	}
	if (*desc != '\0')
		value->flags[i++] = 'w';
	value->flags[i] = '\0';
	ft_get_size(value, desc);
}
