/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:36:55 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 13:38:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_launch(t_pile *pile, t_pile *ref)
{
	ft_transform_value(pile);
	*ref->a = ft_get_max_increase(*pile->a);
	ft_get_info(ref->a, ref->ia);
	ft_check_additional_ref(*pile->a, *ref->a);
	ft_rectification_ref(*pile->a, *ref->a);
	if (pile->ia->len == 2 && ft_check_increas(*pile->a) == 1)
		exec(pile, "sa");
	else if (ft_check_increas(*pile->a) != pile->ia->len)
		ft_action(pile, ref);
}

int	main(int argc, const char **argv)
{
	t_pile	*pile;
	t_pile	*ref;

	pile = ft_init();
	ref = ft_init();
	if (ft_init_pile(argc, argv, pile->a))
	{
		ft_get_info(pile->a, pile->ia);
		ft_get_info(pile->b, pile->ib);
		ft_launch(pile, ref);
	}
	ft_free_pile(ref);
	ft_free_pile(pile);
	return (0);
}
