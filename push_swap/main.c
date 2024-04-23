#include <stdio.h>
#include "./printf/includes/ft_printf.h"
#include "push_swap.h"

void	ft_exec(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib);

int	main(int argc, char **argv)
{
	t_list 	**pile_a;
	t_list 	**pile_b;
	t_ipile	ipile_a;
	t_ipile	ipile_b;
	int		i;

	i = 0;
	pile_a = (t_list **)malloc(sizeof(t_list *));
	pile_b = (t_list **)malloc(sizeof(t_list *));
	if (!pile_a || !pile_b)
		return (0);
	*pile_b = NULL;
	ft_init_pile(argc, argv, pile_a);
	ft_get_info(pile_a, &ipile_a);
	ft_get_info(pile_b, &ipile_b);
	ft_show("A", *pile_a, *pile_b);
	while (!ft_check(*pile_a, argc) && *pile_a)
	{
		ft_exec(pile_a, pile_b, &ipile_a, &ipile_b);
		ft_show("test", *pile_a, *pile_b);
		ft_show_ipile(ipile_a);
		ft_show_ipile(ipile_b);
		i++;
	}
	ft_free(pile_a);
	ft_free(pile_b);
	return (0);
}

void	ft_exec(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib)
{
	if ((ia->first && ia->second) && *(ia->first) > *(ia->second))
	{
		ft_swap(pile_a);
		ft_get_info(pile_a, ia);
	}
	else if ((ia->first && ia->last) && *(ia->first) > *(ia->last))
	{
		ft_rev_rotate(pile_a);
		ft_get_info(pile_a, ia);
	}
	else
	{
		ft_push(pile_a, pile_b);
		ft_get_info(pile_a, ia);
		ft_get_info(pile_b, ib);
	}
}