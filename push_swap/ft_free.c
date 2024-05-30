/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:22 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 12:15:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_clean_list(t_list *list)
{
	t_list	*to_free;

	to_free = list;
	list = list->next;
	free(to_free);
	return (list);
}

void	ft_free_list(t_list *pile)
{
	t_list	*tmp;

	tmp = NULL;
	while (pile)
	{
		tmp = pile;
		pile = pile->next;
		free(tmp);
	}
}

void	ft_free(t_list **pile)
{
	ft_free_list(*pile);
	free(pile);
}

void	ft_free_pile(t_pile *pile)
{
	ft_free(pile->a);
	ft_free(pile->b);
	free(pile->ia);
	free(pile->ib);
	free(pile);
}
