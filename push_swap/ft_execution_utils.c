/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:40:55 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 10:40:56 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_swap(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("sa\n");
		ft_swap(pile->a);
	}
	else if (type == 'b')
	{
		ft_printf("sb\n");
		ft_swap(pile->b);
	}
	else if (type == 's')
	{
		ft_printf("ss\n");
		ft_swap(pile->a);
		ft_swap(pile->b);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_push(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("pa\n");
		ft_push(pile, 1);
	}
	else if (type == 'b')
	{
		ft_printf("pb\n");
		ft_push(pile, 0);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_rotate(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("ra\n");
		ft_rotate(pile->a);
	}
	else if (type == 'b')
	{
		ft_printf("rb\n");
		ft_rotate(pile->b);
	}
	else if (type == 'r')
	{
		ft_printf("rr\n");
		ft_rotate(pile->a);
		ft_rotate(pile->b);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_rev_rotate(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("rra\n");
		ft_rev_rotate(pile->a);
	}
	else if (type == 'b')
	{
		ft_printf("rrb\n");
		ft_rev_rotate(pile->b);
	}
	else if (type == 'r')
	{
		ft_printf("rrr\n");
		ft_rev_rotate(pile->a);
		ft_rev_rotate(pile->b);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}
