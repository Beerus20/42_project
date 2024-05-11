#include "push_swap.h"

t_list	*ft_upper_nb(t_list *pile, int value)
{
	t_list	*tmp;
	t_list	*tmp_value;
	t_list	*r_value;
	int		count;

	count = 0;
	tmp = pile;
	r_value = (t_list *)malloc(sizeof(t_list));
	if (!tmp_value)
		exit(1);
	r_value->content = -1;
	tmp_value = r_value;
	while (tmp)
	{
		if (tmp->content > value)
		{
			if (tmp_value->content != -1)
			{
				tmp_value->next = (t_list *)malloc(sizeof(t_list));
				if (!tmp_value->next)
					exit(1);
				tmp_value = tmp_value->next;
			}
			tmp_value->content = tmp->content;
			tmp_value->next = NULL;
		}
		tmp = tmp->next;
	}
	return (r_value);
}

void	ft_check_max_increase(t_list *pile)
{
	t_list	*tmp;
	t_list	*result;

	result = NULL;
	tmp = ft_upper_nb(pile, pile->content);
	if (pile->next)
	{
		pile = pile->next;
	}
}

void	ft_analysies(t_pile *pile)
{
	int		value;
	t_list	*tmp;
	t_list	*tmp_value;
	t_list	*result;

	tmp_value = NULL;
	result = NULL;
	tmp = *pile->a;
	while (tmp->content != *pile->ia->last)
	{
		while (tmp_value && ft_get_last(tmp_value)->content > tmp->content)
			ft_pop(tmp_value);
		ft_add_back(tmp_value, tmp);
		ft_show_pile(tmp_value);
		if (ft_get_pile_len(tmp_value) > ft_get_pile_len(result))
		{
			ft_printf("TEST\n");
			result = tmp_value;
		}
		tmp = tmp->next;
	}
	if (ft_get_pile_len(tmp_value) > ft_get_pile_len(result))
	{
		ft_printf("TEST\n");
		result = tmp_value;
	}
	ft_show_pile(result);
}

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;

	i = 0;
	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	// ft_show(*pile);
	ft_show_pile(*pile->a);
	ft_analysies(pile);
	ft_show_pile(*pile->a);
	ft_free_pile(pile);
	return (0);
}

// int	verify(t_list *pile, int min, int max)
// {
// 	t_list	*tmp;

// 	tmp = pile;
// 	while (tmp)
// 	{
// 		if (tmp->content >= min && tmp->content < max)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }


// void	launch(t_pile *pile, int len)
// {
// 	int	id_max;
// 	int	max;

// 	while (verify(*pile->a, 0, 20))
// 		ft_action(pile, 0, 20);

// 	while (verify(*pile->a, 20, 40))
// 		ft_action(pile, 20, 40);

// 	while (verify(*pile->a, 40, 60))
// 		ft_action(pile, 40, 60);

// 	while (verify(*pile->a, 60, 80))
// 		ft_action(pile, 60, 80);

// 	while (verify(*pile->a, 80, 95))
// 		ft_action(pile, 80, 95);

// 	max = ft_get_max_value(*pile->a);
// 	id_max = ft_get_index(*pile->a, max);
// 	if (id_max > *pile->ia->len / 2)
// 	{
// 		while (*pile->ia->first != max)
// 			exec(pile, "rra");
// 	}
// 	else
// 	{
// 		while (*pile->ia->first != max)
// 			exec(pile, "ra");
// 	}
// 	// // ft_arrange(pile);
// 	while (*pile->ib->len != 0)
// 		ft_add_to_a(pile);
// 	ft_arrange(pile);
// }


// while (verify(*pile->a, 0, 20))
// 		ft_action(pile, 0, 20);

// 	while (verify(*pile->a, 20, 40))
// 		ft_action(pile, 20, 40);

// 	while (verify(*pile->a, 40, 60))
// 		ft_action(pile, 40, 60);

// 	while (verify(*pile->a, 60, 80))
// 		ft_action(pile, 60, 80);

// 	while (verify(*pile->a, 80, 95))
// 		ft_action(pile, 80, 95);