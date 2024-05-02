#include "push_swap.h"

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
	if (pile == NULL)
		return (0);
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
	second_nb = 0;
	while (i++ < first_nb)
	{
		if (tmp->next && ft_get_position(*pile->a, tmp->content, 1) != ft_position_of(*pile->a, tmp->next->content))
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
	return (0);
}

int	ft_second_node(t_pile *pile)
{
	int	question;

	if (*pile->b == NULL || *pile->ib->len == 1)
	{
		exec(pile, "pb");
		return (1);
	}
	ft_add_stack(pile);
	return (0);
}

int	action(t_pile *pile)
{
	int	question;

	question = *pile->ia->first == *pile->ia->second + 1;
	if (request(pile, question, "sa ra ra"))
		return (1);
	question = *pile->ia->first > *pile->ia->second;
	if (question)
	{
		ft_add_to_b(pile);
		return (1);
	}
	else
	{
		exec(pile, "ra");
	}
	return (0);
}

int	ft_action(t_pile *pile, int id_pile, int id_info)
{
	if (ft_check_isalign(*pile->a))
		return (1);
	action(pile);
	// if (ft_first_node(pile))
	// 	return (1);
	// if (ft_second_node(pile))
	// 	return (1);
	return (0);
}
