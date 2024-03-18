/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:32 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 09:56:41 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	*ft_stoc(int c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return ((void *)0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	ft_add_front_content_value(t_value *value, char *str)
{
	char	*tmp;

	tmp = ft_strdup(value->content);
	free(value->content);
	value->content = ft_strjoin(str, tmp);
	free(tmp);
}

int	ft_hasflag(char *flag)
{
	if (ft_strlen(flag))
		return (1);
	return (0);
}

int	ft_zero_flag_condition(t_value *value)
{
	int	is_true;

	is_true = 1;
	if (!ft_strchr(value->flags, '0'))
		is_true = 0;
	if (ft_strchr(value->flags, 'l'))
		is_true = 0;
	if (!ft_isnumber(value->type))
		is_true = 0;
	return (is_true);
}

int	ft_has_extra_flags(char *flags, char *str)
{
	int	has_extra;

	has_extra = 0;
	if (str[0] == '-')
		has_extra = 1;
	if (str[0] == '+')
		has_extra = 1;
	if (str[0] == ' ')
		has_extra = 1;
	if (ft_strchr(flags, '#'))
		has_extra = 1;
	return (has_extra);
}
