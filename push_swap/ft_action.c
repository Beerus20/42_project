#include "push_swap.h"

int	request(t_pile *pile, int question, char *to_do)
{
	if (question)
	{
		exec(pile, to_do);
		return (1);
	}
	return (0);
}

int	request_loop(t_pile *pile, int question, int nb_iter ,char *to_do)
{
	if (question)
	{
		loop_exec(pile, nb_iter, to_do);
		return (1);
	}
	return (0);
}

int	ft_search(t_list *pile, int value)
{
	if (ft_check_issmaller(pile, value))
		return (1);
	while (pile)
	{
		if (pile->content == value)
			return (1);
		pile = pile->next;
	}
	return (0);
}

int	ft_position_of(t_list *pile, int value)
{
	int	i;

	i = 0;
	while (pile)
	{
		if (pile->content == value)
			return (i);
		i++;
		pile = pile->next;
	}
	return (-1);
}

int	ft_get_position(t_list *pile, int value, int behind)
{
	if (behind)
	{
		if (value >= ft_get_max_value(pile))
			value = ft_get_min_value(pile);
		else
			value++;
	}
	else
	{
		if (value <= ft_get_min_value(pile))
			value = ft_get_max_value(pile);
		else
			value--;
	}
	while (!ft_search(pile, value))
	{
		if (behind)
			value++;
		else
			value--;
	}
	return (ft_position_of(pile, value));
}

int	ft_arrange(t_pile *pile)
{
	int		i;
	int		first_nb;
	int 	second_nb;
	int 	question;
	t_list	*tmp;

	i = 0;
	tmp = *pile->a;
	first_nb = ft_check_increas(tmp);
	while (i++ < first_nb)
	{
		if (ft_get_position(*pile->a, tmp->content, 1) != ft_position_of(*pile->a, tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	second_nb = ft_check_increas(tmp);
	question = *pile->b == NULL && (first_nb + second_nb) == *pile->ia->len;
	if (question)
	{
		request_loop(pile, first_nb <= second_nb, first_nb , "ra");
		request_loop(pile, first_nb > second_nb, second_nb , "rra");
		return (1);
	}
	return (0);
}

void	ft_add_to_b(t_pile *pile)
{
	int	front;
	int	behind;
	int	question;
	int	value;

	if (*pile->b == NULL || *pile->ib->len == 1)
	{
		exec(pile, "pb");
		return ;
	}
	front = ft_get_position(*pile->b, *pile->ia->first, 0);
	behind = ft_get_position(*pile->b, *pile->ia->first, 1);
	question = *pile->ib->len == 2 && front == 1;
	if (request(pile, question, "sb pb"))
		return ;
	value = ft_get_value(*pile->b, front);
	while (*pile->ib->first != value)
	{
		if (front <= *pile->ib->len / 2)
			exec(pile, "rb");
		else
			exec(pile, "rrb");
	}
	exec(pile, "pb");
}

void	ft_add_to_a(t_pile *pile)
{
	int	behind;
	int	question;
	int	value;

	behind = ft_get_position(*pile->a, *pile->ib->first, 1);
	value = ft_get_value(*pile->a, behind);
	while (*pile->ia->first != value)
	{
		if (behind <= *pile->ia->len / 2)
			exec(pile, "ra");
		else
			exec(pile, "rra");
	}
	exec(pile, "pa");
}

int	ft_first_node(t_pile *pile)
{
	int	front;
	int	position;
	int	behind;
	int	question;
	int	value;

	value = *pile->ia->first;
	front = ft_get_position(*pile->a, value, 0);
	position = ft_position_of(*pile->a, value);
	behind = ft_get_position(*pile->a, value, 1);
	if (ft_arrange(pile))
		return (1);
	question = position == 0 && front == 1;
	if (request(pile, question, "sa"))
		return (1);
	question = position == 0 \
				&& (front == (*pile->ia->len - 1) || behind == (*pile->ia->len - 1));
	if (request(pile, question, "rra"))
		return (1);
	if (position == 0 && behind != 1)
	{
		ft_add_to_b(pile);
		return (1);
	}
	return (0);
}

int	ft_second_node(t_pile *pile)
{
	t_list	*tmp;
	int		position;
	int		behind;

	tmp = *pile->a;
	position = ft_position_of(*pile->a, *pile->ia->second);
	behind = ft_get_position(*pile->a, *pile->ia->second, 1);
	if (position != behind - 1)
	{
		ft_add_to_b(pile);
		ft_add_to_b(pile);
		return (1);
	}
	if (!ft_check_isalign(*pile->a))
	{
		exec(pile, "rra");
		return (1);
	}
	return (0);
}

int	ft_action(t_pile *pile, int id_pile, int id_info)
{
	if (ft_check_isalign(*pile->a))
	{
		// if (*pile->b)
		// 	ft_add_to_a(pile);
		return (1);
	}
	if (ft_first_node(pile))
		return (1);
	if (ft_second_node(pile))
		return (1);
	// ft_printf("ADD TO PILE A\n");
	// ft_printf("NO MOVE POSSIBLE ...\n");
	return (0);
}
