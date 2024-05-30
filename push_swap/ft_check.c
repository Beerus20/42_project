/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:15 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 14:37:36 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_increas(t_list *pile)
{
	int		i;
	int		to_compare;
	t_list	*tmp;

	i = 1;
	to_compare = 0;
	tmp = pile;
	if (tmp)
	{
		to_compare = tmp->content;
		if (tmp->next)
		{
			tmp = tmp->next;
			while (tmp)
			{
				if (to_compare < tmp->content)
					i++;
				else
					return (i);
				to_compare = tmp->content;
				tmp = tmp->next;
			}
		}
	}
	return (i);
}

int	ft_search(t_list *pile, int value)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (pile->content == value)
			return (i);
		i++;
		pile = pile->next;
	}
	return (-1);
}

int	ft_position(t_list *pile, int position)
{
	int	len;

	len = ft_get_list_len(pile);
	if (position <= len / 2)
		return (position);
	return (position - len);
}

int	ft_get_position(t_list *pile, int value)
{
	t_list	*tmp;
	int		max;
	int		min;

	max = ft_get_max_value(pile);
	if (max < value)
		return (ft_get_index(pile, max));
	min = ft_get_min_value(pile);
	if (min > value)
		return (ft_get_index(pile, min) + 1);
	tmp = ft_move_to(pile, max);
	while (tmp && tmp->content > value)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = pile;
		while (tmp && tmp->content != max && tmp->content > value)
			tmp = tmp->next;
	}
	if (tmp)
		return (ft_get_index(pile, tmp->content));
	return (0);
}

int	ft_get_position_inv(t_list *pile, int value)
{
	t_list	*tmp;
	t_list	*list;

	tmp = pile;
	list = NULL;
	while (tmp)
	{
		if (tmp->content > value)
			ft_add_back_content(&list, tmp->content);
		tmp = tmp->next;
	}
	if (!list)
		return (ft_get_index(pile, ft_get_max_value(pile)) + 1);
	return (ft_get_index(pile, ft_get_min_value(list)));
}
