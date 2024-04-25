#include "push_swap.h"

int	ft_check(t_list *pile, int	argc)
{
	if (!pile)
		return (1);
	if (ft_check_alignement(pile, 0) == argc)
		return (1);
	return (0);
}

int	ft_check_alignement(t_list *pile, int direction)
{
	int	to_compare;
	int	i;

	i = 1;
	to_compare = pile->content;
	if (pile->next)
	{
		pile = pile->next;
		i++;
		while (pile)
		{
			if (!direction)
			{
				if (to_compare > pile->content)
					return (0);
			}
			else
			{
				if (to_compare < pile->content)
					return (0);
			}
			to_compare = pile->content;
			pile = pile->next;
			i++;
		}
	}
	return (i);
}

int	ft_check_isgreater(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;

	tmp = *pile;
	if (tmp->next)
	{
		tmp = tmp->next;
		while (tmp)
		{
			if (tmp->content > *(ipile->first))
				return (0);
			tmp = tmp->next;
		}
		if (ft_check_alignement((*pile)->next, 0))
			return (1);
	}
	return (0);
}

int	ft_check_isgreater_inv(t_list **pile, t_ipile *ipile)
{
	t_list	*tmp;
	int		*last;

	last = NULL;
	if (ipile->last)
		last = ipile->last;
	else if (ipile->second)
		last = ipile->second;
	else if (ipile->first)
		last = ipile->first;
	else
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (tmp->content < *last)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_calcul_move(int position, int len)
{
	if (position <= (len / 2))
		return (position);
	else
		return (len - position);
}

int	ft_search_position(t_list *pile, int value)
{
	int	i;
	int up_value;

	i = 0;
	up_value = 0;
	if (pile->next)
	{
		up_value = pile->content;
		pile = pile->next;
		i++;
		while (pile)
		{
			if (up_value > value && value > pile->content)
				return (i);
			up_value = pile->content;
			pile = pile->next;
			i++;
		}
	}
	return (i);
}

int	*ft_count_move(t_list **pile, t_ipile *ia, t_ipile *ib)
{
	int	nb_mv_f;
	int	nb_mv_s;
	int	nb_mv_l;
	int	*r_value;

	r_value = (int *)malloc(sizeof(int) * 2);
	if (!r_value)
		exit(0);
	nb_mv_f = ft_calcul_move(ft_search_position(*pile, *(ia->first)), *(ib->len));
	nb_mv_s = ft_calcul_move(ft_search_position(*pile, *(ia->second)), *(ib->len));
	nb_mv_l = ft_calcul_move(ft_search_position(*pile, *(ia->last)), *(ib->len));
	r_value[0] = 0;
	r_value[1] = nb_mv_f;
	if ((nb_mv_s + 1) < nb_mv_f && nb_mv_s < nb_mv_l)
	{
		r_value[0] = 1;
		r_value[1] = nb_mv_s;
	}
	else if ((nb_mv_l + 1) < nb_mv_f && nb_mv_l < nb_mv_s)
	{
		r_value[0] = 2;
		r_value[1] = nb_mv_l;
	}
	return (r_value);
}
