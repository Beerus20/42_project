/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:18 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 10:40:03 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chr_action_type(char *str, int *index)
{
	int	i;

	i = 0;
	*index = 0;
	while (*str != 's' && *str != 'p' && *str != 'r' && *str)
	{
		str++;
		(*index)++;
	}
	while (*str != ' ' && *(str++))
		i++;
	return (i);
}

int	exec(t_pile *pile, char *action)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	while (*action)
	{
		nb = ft_chr_action_type(action, &index);
		if (nb == 2)
		{
			if (action[index] == 's')
				ft_exec_swap(pile, action[index + 1]);
			if (action[index] == 'p')
				ft_exec_push(pile, action[index + 1]);
			if (action[index] == 'r')
				ft_exec_rotate(pile, action[index + 1]);
		}
		else
			ft_exec_rev_rotate(pile, action[index + 2]);
		ft_update_info(pile);
		if (DEBUG)
			ft_debug(*pile);
		action += index + nb;
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
