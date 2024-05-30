/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increase_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:05:48 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 12:07:31 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_nbmax_composition(t_list *pile)
{
	t_list	*tmp;
	int		*tab;
	int		len;
	int		max;

	tmp = ft_upper_nb(pile, pile->content);
	len = ft_get_list_len(tmp);
	tab = ft_get_tab_ids(tmp);
	max = ft_get_maxv_tab(tab, len);
	free(tab);
	ft_free_list(tmp);
	return (max);
}

int	ft_check_begin_max_increase(t_list *pile)
{
	int	value;
	int	max;
	int	result;
	int	r_value;

	max = 0;
	result = 0;
	r_value = 0;
	while (pile)
	{
		value = pile->content;
		max = ft_get_nbmax_composition(pile);
		if (max > result)
		{
			result = max;
			r_value = value;
		}
		pile = pile->next;
	}
	return (r_value);
}
