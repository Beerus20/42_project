/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:55:02 by ballain           #+#    #+#             */
/*   Updated: 2024/03/14 11:40:18 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	ft_get_desc(char *desc, const char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		desc[i++] = *(str++);
	desc[i] = '\0';
}

void	ft_get_width(char *desc, t_flags *flags)
{
	char	**w;
	int		min;
	int		max;

	min = 0;
	max = 0;
	w = (char **)malloc(sizeof(char *) * 3);
	ft_split_width(w, desc);
	if (ft_strlen(w[0]) == 0)
		min = 0;
	else
		min = ft_atoi(w[0]);
	if (ft_strlen(w[1]) == 0)
		max = 0;
	else
		max = ft_atoi(w[1]);
	ft_iflags(flags, flags->flag, min, max);
	free(w[2]);
	free(w[1]);
	free(w[0]);
	free(w);
}

void	ft_get_flags(char *desc, t_flags *flags)
{
	int		i;
	int		len_flag;

	i = 0;
	len_flag = ft_count_flags(desc);
	flags->flag = (char *)malloc(sizeof(char) * (len_flag + 1));
	if (ft_strchr(desc, '.'))
		flags->flag[i++] = '.';
	while (i < len_flag)
		flags->flag[i++] = *(desc++);
	ft_get_width(desc, flags);
	flags->flag[i] = '\0';
}

int	ft_len(char type, t_flags *flags, void *c)
{
	if (type == 'c')
		return (flags->min_w);
	else
	{
		if (flags->min_w <= (int)ft_strlen((char *)c))
			return (ft_strlen((char *)c));
		else
			return (flags->min_w);
	}
}

int	ft_apply_flags(char type, t_flags *flags, void *c)
{
	void	*value;
	void	*str;
	int		len;

	value = ft_treatment(type, flags, c);
	str = ft_init_to_printv(type, flags, value);
	len = ft_len(type, flags, str);
	if (ft_strchr(flags->flag, '-'))
		ft_dash_flag(type, 1, len, str);
	else
		ft_dash_flag(type, 0, len, str);
	free(value);
	free(str);
	return (len);
}
