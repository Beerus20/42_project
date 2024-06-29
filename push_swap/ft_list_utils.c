/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:48 by ballain           #+#    #+#             */
/*   Updated: 2024/06/29 14:31:14 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_move_to(t_list *pile, int value)
{
	if (pile && ft_search(pile, value) != -1)
	{
		while (pile->content != value)
			pile = pile->next;
		return (pile);
	}
	return (NULL);
}

void	ft_del_list_value(t_list **list, int value)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*to_free;

	prev = NULL;
	to_free = NULL;
	tmp = *list;
	while (tmp && tmp->content != value)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	to_free = tmp;
	if (prev == NULL)
		*list = tmp->next;
	else
		prev->next = tmp->next;
	free(to_free);
}

void	ft_add_list_value(t_list **list, int index, int value)
{
	int		i;
	t_list	*prev;
	t_list	*tmp;
	t_list	*iter;

	prev = NULL;
	tmp = NULL;
	iter = *list;
	i = 0;
	while (i < index)
	{
		prev = iter;
		iter = iter->next;
		i++;
	}
	if (prev)
	{
		tmp = prev->next;
		prev->next = ft_init_list(value);
		prev->next->next = tmp;
	}
	else
		ft_add_front(list, ft_init_list(value));
}

void	ft_add_back_content(t_list **pile, long value)
{
	t_list	*tmp_list;
	t_list	*tmp;

	tmp = ft_init_list(-1);
	tmp_list = *pile;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp->content = value;
		tmp_list->next = tmp;
	}
	else
	{
		tmp->content = value;
		*pile = tmp;
	}
}

void	ft_concat_list(t_list **a, t_list **b, t_list *s_a, t_list *s_b)
{
	t_list	*prev;
	t_list	*tmp;

	prev = NULL;
	tmp = *a;
	while (tmp && tmp != s_a)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	ft_free_list(tmp);
	if (prev)
		prev->next = *b;
	else
		*a = *b;
	prev = NULL;
	tmp = *b;
	while (tmp && tmp != s_b)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev->next)
		prev->next = NULL;
	ft_free_list(tmp);
}
