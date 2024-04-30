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

int	ft_count_move(t_list *pile, int value)
{
	int	i;
	int	sub;

	i = 0;
	sub = 1;
	if (value == 0)
		sub = 0;
	while (!ft_search(pile, value - sub))
		sub++;
	while (pile)
	{
		if (pile->content == (value - sub))
			return (i);
		pile = pile->next;
		i++;
	}
	return (0);
}

int	ft_b_action(t_pile *pile)
{
	int	nb_move;

	if (*pile->b == NULL)
	{
		exec(pile, "pb");
		return (1);
	}
	nb_move = ft_count_move(*pile->b, *pile->ia->first);
	if (*pile->ib->len > 1)
	{
		if (pile->ib->last)
		{
			if (nb_move >= (*pile->ib->len / 2))
			{
				nb_move = *pile->ib->len - nb_move;
				loop_exec(pile, nb_move, "rrb");
			}
			else
				loop_exec(pile, nb_move, "rb");
			exec(pile, "pb");
		}
		else
			request(pile, *pile->ib->second < *pile->ia->first, "sb pb");
		return (1);
	}
	else
	{
		exec(pile, "pb");
		return (1);
	}
	return (0);
}

int	ft_move_to_a(t_pile *pile)
{
	if (ft_check_percent(pile, ft_check_increas, 0) >= 30)
	{
		while (*(pile->ib->len) != 0 && *pile->ia->first == *pile->ib->first + 1)
			exec(pile, "pa");
		return (1);
	}
	return (0);
}

int	ft_move_to_b(t_pile *pile)
{
	int	move;
	int	nb_move;
	int	percent;

	move = ft_count_move(*pile->a, (*pile->a)->content);
	nb_move = ft_check_increas(*pile->a);
	percent = ft_check_percent(pile, ft_check_increas, 0);
	if (percent <= 40)
	{
		while (nb_move-- && *pile->ia->first != (*pile->ia->last - 1))
			ft_b_action(pile);
		exec(pile, "rra");
		return (1);
	}
	else
	{
		exec(pile, "rra");
		return (1);
	}
	return (0);
}

int	ft_action(t_pile *pile, int id_pile, int id_info)
{
	t_list	*tmp;
	t_info	*info;
	int		question;

	question = 0;
	tmp = *(pile->a);
	info = pile->ia;
	if (id_pile)
		tmp = *(pile->b);
	if (id_info)
		info = pile->ib;
	question = *info->first == (*info->len - 1) && ft_check_isalign(tmp->next);
	if (request(pile, question, "ra"))
		return (1);
	question = *info->first == (*info->second + 1);
	if (request(pile, question, "sa"))
		return (1);
	question = info->last && *info->first == (*info->last - 1);
	if (request(pile, question, "rra sa"))
		return (1);
	question = info->last && *info->first == (*info->last + 1);
	if (request(pile, question, "rra"))
		return (1);
	if (ft_move_to_b(pile))
		return (1);
	return (0);
}
