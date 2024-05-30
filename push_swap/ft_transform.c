/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:59 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 14:36:05 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_tab(t_list *pile, int *tab)
{
	int	i;

	i = 0;
	while (pile)
	{
		tab[i] = pile->content;
		pile = pile->next;
		i++;
	}
}

int	ft_is_tab_align(int *tab, int len)
{
	int	i;
	int	to_compare;

	i = 1;
	to_compare = tab[0];
	while (i < len)
	{
		if (to_compare > tab[i])
			return (0);
		to_compare = tab[i];
		i++;
	}
	return (1);
}

void	ft_simple_arrange(int *tab, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (!ft_is_tab_align(tab, len))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_apply_change(t_list *pile, int *tab, int len)
{
	int	i;

	i = 0;
	while (pile)
	{
		while (i < len)
		{
			if (tab[i] == pile->content)
			{
				pile->content = i;
				i = 0;
				break ;
			}
			i++;
		}
		pile = pile->next;
	}
}

void	ft_transform_value(t_pile *pile)
{
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * (pile->ia->len));
	if (!tmp)
		exit(1);
	ft_add_to_tab(*pile->a, tmp);
	ft_simple_arrange(tmp, pile->ia->len);
	ft_apply_change(*pile->a, tmp, pile->ia->len);
	ft_update_info(pile);
	free(tmp);
}
