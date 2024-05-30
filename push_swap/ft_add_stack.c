/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:12 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 14:39:27 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_additional_ref(t_list *pile, t_list *ref)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*add_ref;
	int		last;
	int		len;

	len = ft_get_list_len(pile);
	list = ft_sub_list(pile, pile->content, ref->content);
	last = ft_get_last(ref)->content;
	tmp = ft_sub_list_between(list, last, len - 1);
	add_ref = ft_get_max_increase(tmp);
	ft_free_list(tmp);
	tmp = ft_move_to(ref, last);
	ft_free_list(list);
	if (add_ref)
	{
		tmp->next = add_ref;
		return (1);
	}
	return (0);
}

int	ft_rectification_ref(t_list	*pile, t_list *ref)
{
	t_list	*list;
	t_list	*max_increase;
	t_list	*tmp;
	int		len;
	int		i;

	i = 0;
	list = ft_sub_list(pile, pile->content, ref->content);
	max_increase = ft_get_max_increase(list);
	ft_free_list(list);
	len = ft_get_list_len(max_increase);
	tmp = ref;
	while (len && tmp && tmp->content < max_increase->content)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp && ft_get_list_len(ref) < len + i)
	{
		ft_concat_list(&ref, &max_increase, tmp, NULL);
		return (1);
	}
	ft_free_list(max_increase);
	return (0);
}

t_list	*ft_get_extra(t_list *pile, t_list *ref)
{
	t_list	*tmp;
	t_list	*r_value;

	tmp = NULL;
	r_value = NULL;
	ft_add_back(&r_value, ft_get_portion(pile, ref));
	while (pile)
	{
		if (ft_search(ref, pile->content) != -1)
			tmp = pile;
		pile = pile->next;
	}
	if (tmp && tmp->next)
		ft_add_back(&r_value, ft_get_portion(tmp->next, ref));
	return (r_value);
}

void	ft_move(t_pile *pile, int p_a, int p_b)
{
	int	extra_move;

	extra_move = ft_extra_moves(&p_a, &p_b);
	if (p_a >= 0)
	{
		loop_exec(pile, extra_move, "rr");
		loop_exec(pile, p_a, "ra");
	}
	else
	{
		loop_exec(pile, -extra_move, "rrr");
		loop_exec(pile, -p_a, "rra");
	}
	if (p_b >= 0)
		loop_exec(pile, p_b, "rb");
	else
	{
		if (*pile->b)
			loop_exec(pile, -p_b, "rrb");
	}
}

void	ft_move_element(t_pile *pile, t_list *sub_pile, t_action action)
{
	int		position_a;
	int		position_b;
	int		value;

	while (sub_pile)
	{
		value = ft_select_mvl_v(pile, sub_pile, action);
		position_a = ft_position(*pile->a, action.fa(*pile->a, value));
		position_b = ft_position(*pile->b, action.fb(*pile->b, value));
		ft_move(pile, position_a, position_b);
		ft_del_list_value(&sub_pile, value);
		exec(pile, action.end_action);
	}
}
