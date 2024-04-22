#include <stdio.h>
#include "./printf/includes/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list **pile_a;
	t_list **pile_b;

	pile_a = (t_list **)malloc(sizeof(t_list *));
	pile_b = (t_list **)malloc(sizeof(t_list *));
	if (!pile_a || !pile_b)
		return (0);
	*pile_b = NULL;
	ft_init_pile(argc, argv, pile_a);
	ft_push(pile_a, pile_b);
	// ft_rev_rotate(pile_a);
	ft_show("A", *pile_a);
	ft_show("B", *pile_b);
	ft_free(pile_a);
	ft_free(pile_b);
	// ft_printf("NUMBER	: [%s]\n", argv[0]);
	return (0);
}

// int	ft_check(t_list **pile)
// {
// 	while ((*pile)->next)
// 	{
// 		if ((*pile)->content > (*pile)->next->content)
// 			return (0);

// 	}
// }