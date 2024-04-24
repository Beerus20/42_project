#include <stdio.h>
#include "push_swap.h"

void	ft_exec(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib);

int	main(int argc, char **argv)
{
	t_list 	**pile_a;
	t_list 	**pile_b;
	t_ipile	*ipile_a;
	t_ipile	*ipile_b;
	int		i;

	i = 0;
	pile_a = (t_list **)malloc(sizeof(t_list *));
	pile_b = (t_list **)malloc(sizeof(t_list *));
	ipile_a = (t_ipile *)malloc(sizeof(t_ipile));
	ipile_b = (t_ipile *)malloc(sizeof(t_ipile));
	if (!pile_a || !pile_b || !ipile_a || !ipile_b)
		return (0);
	*pile_b = NULL;
	ft_init_pile(argc, argv, pile_a);
	ft_get_info(pile_a, ipile_a);
	ft_get_info(pile_b, ipile_b);
	ft_show("A", *pile_a, *pile_b);
	// ft_printf("TEST	: [%d]\n", ft_search_position(*pile_a, 5));
	while (i < 10/* !ft_check(*pile_a, argc) && *pile_a && */)
	{
		ft_exec(pile_a, pile_b, ipile_a, ipile_b);
		ft_show("test", *pile_a, *pile_b);
		ft_show_ipile( *ipile_a, *ipile_b);
		i++;
	}
	ft_free_info(ipile_a);
	ft_free_info(ipile_b);
	free(ipile_a);
	free(ipile_b);
	ft_free(pile_a);
	ft_free(pile_b);
	return (0);
}

void	ft_exec(t_list **pile_a, t_list **pile_b, t_ipile *ia, t_ipile *ib)
{
	ft_printf("#_____________________EXEC_____________________#\n");
	if (ft_action_isgreater(pile_a, ia))
	{
		ft_printf("====> CHECK GREATER\n");
		return ;
	}
	if (*(ib->len) == 0 && ft_arrange_pile(pile_a, ia))
	{
		ft_printf("====> CHECK ALIGNEMENT\n");
		return ;
	}
	if (ft_is_both_aligned(pile_a, pile_b, ia, ib))
	{
		ft_printf("====> CHECK BOTH ALIGNEMENT\n");
		return ;
	}
	if ((ia->first && ia->second) && *(ia->first) > *(ia->second))
	{
		ft_printf("====> SWAP\n");
		ft_swap(pile_a, ia);
	}
	else if ((ia->first && ia->last) && *(ia->first) > *(ia->last))
	{
		ft_printf("====> REV ROTATE\n");
		ft_rev_rotate(pile_a, ia);
	}
	else
	{
		ft_printf("====> PUSH\n");
		ft_push(pile_a, pile_b, ia, ib);
	}
	ft_printf("#_____________________FIN EXEC_____________________#\n");
}
