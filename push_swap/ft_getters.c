/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:25 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 09:40:26 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_value(t_list *pile)
{
	int	max;

	max = 0;
	if (pile)
		max = pile->content;
	while (pile)
	{
		if (pile->content < max)
			max = pile->content;
		pile = pile->next;
	}
	return (max);
}

int	ft_get_max_value(t_list *pile)
{
	int	max;

	max = 0;
	if (pile)
		max = pile->content;
	while (pile)
	{
		if (pile->content > max)
			max = pile->content;
		pile = pile->next;
	}
	return (max);
}

int	ft_get_index(t_list *pile, int value)
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

int	ft_get_value(t_list *pile, int index)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (i == index)
			return (pile->content);
		i++;
		pile = pile->next;
	}
	return (-1);
}

int	ft_get_list_len(t_list *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}
