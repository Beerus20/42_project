/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:36:46 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 09:43:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_front(t_list **pile, t_list *new)
{
	new->next = *pile;
	*pile = new;
}

void	ft_del_front(t_list **pile)
{
	t_list	*tmp;

	tmp = *pile;
	*pile = tmp->next;
	free(tmp);
}

t_list	*ft_init_list(int value)
{
	t_list	*r_list;

	r_list = (t_list *)malloc(sizeof(t_list));
	if (!r_list)
		exit(1);
	r_list->content = value;
	r_list->next = NULL;
	return (r_list);
}

void	ft_add_back(t_list **pile, t_list *new)
{
	t_list	*tmp_list;

	tmp_list = *pile;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp_list->next = new;
	}
	else
		*pile = new;
}

t_list	*ft_copy_list(t_list *list)
{
	t_list	*r_value;

	r_value = NULL;
	while (list)
	{
		ft_add_back_content(&r_value, list->content);
		list = list->next;
	}
	return (r_value);
}
