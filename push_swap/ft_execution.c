/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:18 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 19:49:31 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_count_char(char *str)
{
	int	i;

	i = 0;
	while (ft_isalpha(*(str++)))
		i++;
	return (i);
}

int	exec(t_pile *pile, char *action)
{
	int		nb;

	while (*action)
	{
		nb = ft_count_char(action);
		if (nb == 2)
		{
			if (*action == 's')
				ft_exec_swap(pile, *(action + 1));
			if (*action == 'p')
				ft_exec_push(pile, *(action + 1));
			if (*action == 'r')
				ft_exec_rotate(pile, *(action + 1));
		}
		else
			ft_exec_rev_rotate(pile, *(action + 2));
		ft_update_info(pile);
		action += nb;
		while (!ft_isalpha(*action) && *action)
			action++;
	}
	return (0);
}

void	loop_exec(t_pile *pile, int nb_iter, char *to_do)
{
	if (nb_iter >= 0)
	{
		while (nb_iter > 0)
		{
			exec(pile, to_do);
			nb_iter--;
		}
	}
	else
	{
		while (nb_iter < -1)
		{
			exec(pile, to_do);
			nb_iter++;
		}
	}
}
