/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:38:03 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 10:43:23 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_portion(t_list *pile, t_list *ref)
{
	t_list	*r_value;

	r_value = NULL;
	while (pile && ft_search(ref, pile->content) == -1)
	{
		ft_add_back_content(&r_value, pile->content);
		pile = pile->next;
	}
	return (r_value);
}

t_list	*ft_sub_list(t_list *list, int begin, int end)
{
	t_list	*r_value;
	int		subst;

	r_value = NULL;
	if (ft_get_index(list, end) < ft_get_index(list, begin))
	{
		subst = end;
		end = begin;
		begin = subst;
	}
	list = ft_move_to(list, begin);
	while (list && list->content != end)
	{
		ft_add_back_content(&r_value, list->content);
		list = list->next;
	}
	if (list && list->content == end)
		ft_add_back_content(&r_value, list->content);
	return (r_value);
}

t_list	*ft_sub_list_between(t_list *list, int a, int b)
{
	t_list	*r_value;
	int		tmp;

	r_value = NULL;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (list)
	{
		if (list->content >= a && list->content <= b)
			ft_add_back_content(&r_value, list->content);
		list = list->next;
	}
	return (r_value);
}

int	request(t_pile *pile, int question, char *to_do)
{
	if (question)
	{
		exec(pile, to_do);
		return (1);
	}
	return (0);
}

int	request_loop(t_pile *pile, int question, int nb_iter, char *to_do)
{
	if (question)
	{
		loop_exec(pile, nb_iter, to_do);
		return (1);
	}
	return (0);
}
