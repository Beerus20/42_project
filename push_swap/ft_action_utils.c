/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:17:07 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 14:38:48 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (value * (-1));
	return (value);
}

int	ft_nbmv(t_list *pile, int position)
{
	return (ft_abs(ft_position(pile, position)));
}

int	ft_select_mvl_v(t_pile *pile, t_list *sub_pile, t_action action)
{
	int	r_value;
	int	position_a;
	int	position_b;
	int	total;
	int	tmp;

	position_a = action.fa(*pile->a, sub_pile->content);
	position_b = action.fb(*pile->b, sub_pile->content);
	tmp = ft_nbmv(*pile->a, position_a) + ft_nbmv(*pile->b, position_b);
	r_value = sub_pile->content;
	while (sub_pile)
	{
		position_a = action.fa(*pile->a, sub_pile->content);
		position_b = action.fb(*pile->b, sub_pile->content);
		total = ft_nbmv(*pile->a, position_a) + ft_nbmv(*pile->b, position_b);
		if (total < tmp)
		{
			r_value = sub_pile->content;
			tmp = total;
		}
		sub_pile = sub_pile->next;
	}
	return (r_value);
}

int	ft_extra_moves(int *p_a, int *p_b)
{
	int	r_value;

	r_value = 0;
	if (*p_a >= 0 && *p_b >= 0)
	{
		r_value = *p_a;
		if (*p_a > *p_b)
			r_value = *p_b;
	}
	else if (*p_a < 0 && *p_b < 0)
	{
		r_value = *p_b + 1;
		if (*p_a > *p_b)
			r_value = *p_a + 1;
	}
	*p_b -= r_value;
	*p_a -= r_value;
	return (r_value);
}

t_action	ft_init_action(int type)
{
	t_action	action;

	if (!type)
	{
		action.end_action = "pb";
		action.fa = ft_get_index;
		action.fb = ft_get_position;
	}
	else
	{
		action.end_action = "pa";
		action.fa = ft_get_position_inv;
		action.fb = ft_get_index;
	}
	return (action);
}
