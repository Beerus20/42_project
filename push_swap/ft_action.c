/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:40:07 by ballain           #+#    #+#             */
/*   Updated: 2024/06/29 16:10:23 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_action(t_pile *pile, t_pile *ref, t_action action, int stop)
{
	t_list	*tmp;

	if (stop)
	{
		if ((pile->ia->len - ref->ia->len) < (pile->ia->len / 2))
			return ;
		stop = pile->ia->len - (pile->ia->len / 4);
		while (pile->ia->len >= stop)
		{
			tmp = ft_get_extra(*pile->a, *ref->a);
			if (ft_search(*ref->a, pile->ia->first) == -1)
				ft_move_element(pile, tmp, action);
			else
				exec(pile, "ra");
		}
	}
}

t_list	*ft_second_action(t_pile *pile, t_pile *ref, int stop)
{
	t_list	*tmp;

	tmp = NULL;
	if (stop)
	{
		while (!ft_verify(pile, ref))
		{
			if (ft_search(*ref->a, pile->ia->first) == -1)
			{
				ft_add_back_content(&tmp, pile->ia->first);
				exec(pile, "pb");
			}
			else
				exec(pile, "ra");
		}
	}
	return (tmp);
}

void	ft_three_action(t_pile *pile)
{
	int	p_max;
	int	p_min;
	int	max;
	int	min;

	if (ft_check_increas(*pile->a) != pile->ia->len)
	{
		max = ft_get_max_value(*pile->a);
		min = ft_get_min_value(*pile->a);
		p_max = ft_get_index(*pile->a, max);
		p_min = ft_get_index(*pile->a, min);
		request(pile, p_min == 1 && p_max == 2, "sa");
		request(pile, p_min == 0 && p_max == 1, "sa ra");
		request(pile, p_min == 1 && p_max == 0, "ra");
		request(pile, p_min == 2 && p_max == 0, "sa rra");
		request(pile, p_min == 2 && p_max == 1, "rra");
	}
}

void	ft_five_action(t_pile *pile, t_action action)
{
	int	stop;
	int	i_max;

	request(pile, pile->ia->first > pile->ia->second, "sa");
	if (ft_check_increas(*pile->a) != pile->ia->len)
	{
		loop_exec(pile, 2, "pb");
		ft_three_action(pile);
		ft_move_element(pile, ft_copy_list(*pile->b), action);
		i_max = ft_get_index(*pile->a, ft_get_max_value(*pile->a));
		stop = ft_position(*pile->a, i_max);
		request_loop(pile, stop >= 0, stop + 1, "ra");
		request_loop(pile, stop < 0, stop, "rra");
	}
}

int	ft_action(t_pile *pile, t_pile *ref)
{
	t_list		*tmp;
	t_action	action_1;
	t_action	action_2;
	int			stop;
	int			i_max;

	action_1 = ft_init_action(0);
	action_2 = ft_init_action(1);
	if (pile->ia->len == 3)
		ft_three_action(pile);
	else if (pile->ia->len == 5)
		ft_five_action(pile, action_2);
	else
	{
		stop = pile->ia->len != ref->ia->len;
		ft_first_action(pile, ref, action_1, stop);
		tmp = ft_second_action(pile, ref, stop);
		ft_move_element(pile, tmp, action_2);
		ft_move_element(pile, ft_copy_list(*pile->b), action_2);
		i_max = ft_get_index(*pile->a, ft_get_max_value(*pile->a));
		stop = ft_position(*pile->a, i_max);
		request_loop(pile, stop >= 0, stop + 1, "ra");
		request_loop(pile, stop < 0, stop, "rra");
	}
	return (0);
}
