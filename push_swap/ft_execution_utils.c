/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:40:55 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 20:27:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_cmd(char *cmd)
{
	if (!BONUS)
		ft_printf("%s", cmd);
}

void	ft_exec_swap(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_show_cmd("sa\n");
		ft_swap(pile->a);
	}
	else if (type == 'b')
	{
		ft_show_cmd("sb\n");
		ft_swap(pile->b);
	}
	else if (type == 's')
	{
		ft_show_cmd("ss\n");
		ft_swap(pile->a);
		ft_swap(pile->b);
	}
	else
	{
		ft_show_cmd("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_push(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_show_cmd("pa\n");
		ft_push(pile, 1);
	}
	else if (type == 'b')
	{
		ft_show_cmd("pb\n");
		ft_push(pile, 0);
	}
	else
	{
		ft_show_cmd("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_rotate(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_show_cmd("ra\n");
		ft_rotate(pile->a);
	}
	else if (type == 'b')
	{
		ft_show_cmd("rb\n");
		ft_rotate(pile->b);
	}
	else if (type == 'r')
	{
		ft_show_cmd("rr\n");
		ft_rotate(pile->a);
		ft_rotate(pile->b);
	}
	else
	{
		ft_show_cmd("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_rev_rotate(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_show_cmd("rra\n");
		ft_rev_rotate(pile->a);
	}
	else if (type == 'b')
	{
		ft_show_cmd("rrb\n");
		ft_rev_rotate(pile->b);
	}
	else if (type == 'r')
	{
		ft_show_cmd("rrr\n");
		ft_rev_rotate(pile->a);
		ft_rev_rotate(pile->b);
	}
	else
	{
		ft_show_cmd("ERROR ACTION\n");
		exit(1);
	}
}
