#include "push_swap.h"

int	ft_search(t_list *pile, int value)
{
	// if (ft_check_issmaller(pile, value))
	// 	return (1);
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

int	ft_get_min_up(t_pile *pile, int min, int max)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *pile->a;
	while (tmp)
	{
		if (tmp->content >= min && tmp->content < max)
			return (tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	ft_get_min_down(t_pile *pile, int min, int max)
{
	int		i;
	int		value;
	t_list	*tmp;

	i = 1;
	tmp = *pile->a;
	value = 0;
	while (i < *pile->ia->len)
	{
		value = ft_get_value(*pile->a, *pile->ia->len - i);
		if (value >= min && value < max)
			return (value);
		i++;
	}
	return (-1);
}

int	ft_action(t_pile *pile, int min, int max)
{
	int	value;
	int	min_up;
	int	min_down;
	int	p_up;
	int	p_down;

	request(pile, *pile->ia->first == *pile->ia->second - 1, "sa");
	min_up = ft_get_min_up(pile, min, max);
	min_down = ft_get_min_down(pile, min, max);
	p_up = ft_get_index(*pile->a, min_up);
	p_down = ft_get_index(*pile->a, min_down);
	if (p_up == -1 && p_down == -1)
		return (0);
	if (p_down != -1)
		p_down = *pile->ia->len - p_down;
	if (p_up != -1 && p_up <= p_down || p_down == -1)
	{
		while (*pile->ia->first != min_up)
			exec(pile, "ra");
		exec(pile, "pb");
		return (1);
	}
	else if (p_down != -1 && p_up > p_down || p_up == -1)
	{
		while (*pile->ia->first != min_down)
			exec(pile, "rra");
		exec(pile, "pb");
		return (1);
	}
	else
		exec(pile, "rra");
	return (0);
}


// int	ft_action(t_pile *pile, int id_pile, int id_info)
// {
// 	if (ft_check_isalign(*pile->a))
// 		return (1);
	// if (*pile->ia->len == 3)
	// 	return (1);
	// if (ft_first_node(pile))
	// 	return (1);
	// if (ft_second_node(pile))
	// 	return (1);
// 	return (0);
// }
