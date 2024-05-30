/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:32 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 16:07:45 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_tab_index(int *tab, int len, int value)
{
	int	i;
	int	r_i;

	i = 0;
	r_i = 0;
	while (i < len)
	{
		if (tab[i] == value)
			r_i = i;
		i++;
	}
	return (r_i);
}

void	ft_clean_tab(t_list *pile, int *tab, int len, int value)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (pile->content > value)
		{
			pile->content = -1;
			tab[i] = -1;
		}
		pile = pile->next;
		i++;
	}
	while (pile)
	{
		if (pile->content < value)
		{
			pile->content = -1;
			tab[i] = -1;
		}
		pile = pile->next;
		i++;
	}
}

t_list	*ft_get_cleaned_list(t_list *pile)
{
	t_list	*r_value;
	t_list	*tmp;

	r_value = pile;
	tmp = NULL;
	while (pile)
	{
		while (pile && pile->content == -1)
			pile = ft_clean_list(pile);
		if (tmp == NULL)
			tmp = pile;
		else
		{
			tmp->next = pile;
			tmp = tmp->next;
		}
		if (!pile)
			break ;
		pile = pile->next;
		tmp->next = NULL;
	}
	return (r_value);
}

t_list	*ft_get_increase(t_list *pile)
{
	int	end;
	int	len;
	int	index;
	int	*tab;

	len = ft_get_list_len(pile);
	tab = ft_get_tab_ids(pile);
	end = ft_get_maxv_tab(tab, len);
	while (end)
	{
		index = ft_get_tab_index(tab, len, end);
		ft_clean_tab(pile, tab, index, ft_get_value(pile, index));
		end--;
	}
	free(tab);
	return (ft_get_cleaned_list(pile));
}

t_list	*ft_get_max_increase(t_list *pile)
{
	int	begin;

	if (pile)
	{
		begin = ft_check_begin_max_increase(pile);
		while (pile->content != begin)
			pile = pile->next;
		pile = ft_upper_nb(pile, begin);
		return (ft_get_increase(pile));
	}
	return (NULL);
}
