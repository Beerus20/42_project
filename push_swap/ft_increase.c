#include "push_swap.h"

int	ft_get_nbmax_composition(t_list *pile)
{
	t_list	*tmp;
	int		*tab;
	int		len;
	int		max;

	tmp = ft_upper_nb(pile, pile->content);
	len = ft_get_list_len(tmp);
	tab = ft_get_tab_ids(tmp);
	max = ft_get_maxv_tab(tab, len);
	free(tab);
	ft_free_list(tmp);
	return (max);
}

int	ft_check_begin_max_increase(t_list *pile)
{
	int	value;
	int	max;
	int	result;
	int	r_value;

	max = 0;
	result = 0;
	r_value = 0;
	while (pile)
	{
		value = pile->content;
		max = ft_get_nbmax_composition(pile);
		if ( max > result)
		{
			result = max;
			r_value = value;
		}
		pile = pile->next;
	}
	return (r_value);
}

int	ft_get_tab_index(int *tab, int len, int value)
{
	int	i;
	int	r_i;

	i = 0;
	r_i = 0;
	while (i < len)
	{
		if (tab[i] == value)
			r_i = i;
		i++;
	}
	return (r_i);
}

void	ft_clean_tab(t_list *pile, int *tab, int len, int value)
{
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = pile;
	while (i < len)
	{
		if (pile->content > value)
		{
			pile->content = -1;
			tab[i] = -1;
		}
		pile = pile->next;
		i++;
	}
	while (pile)
	{
		if (pile->content < value)
		{
			pile->content = -1;
			tab[i] = -1;
		}
		pile = pile->next;
		i++;
	}
}

t_list	*ft_get_cleaned_list(t_list *pile)
{
	t_list	*r_value;
	t_list	*to_free;
	t_list	*tmp;

	r_value = pile;
	tmp = NULL;
	while (pile)
	{
		while (pile && pile->content == -1)
		{
			to_free = pile;
			pile = pile->next;
			free(to_free);
		}
		if (tmp == NULL)
			tmp = pile;
		else
		{
			tmp->next = pile;
			tmp = tmp->next;
		}
		if (!pile)
			break ;
		pile = pile->next;
		tmp->next = NULL;
	}
	return (r_value);
}

t_list	*ft_get_increase_list(t_list *pile)
{
	int	begin;
	int	end;
	int	len;
	int	index;
	int	*tab;

	begin = ft_check_begin_max_increase(pile);
	while (pile->content != begin)
		pile = pile->next;
	pile = ft_upper_nb(pile, begin);
	len = ft_get_list_len(pile);
	tab = ft_get_tab_ids(pile);
	end = ft_get_maxv_tab(tab, len);
	while (end)
	{
		index = ft_get_tab_index(tab, len, end);
		ft_clean_tab(pile, tab, index, ft_get_value(pile, index));
		end--;
	}
	// ft_show_pile(pile);
	free(tab);
	return (ft_get_cleaned_list(pile));
}
