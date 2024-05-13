#include "push_swap.h"

t_list	*ft_upper_nb(t_list *pile, int value)
{
	t_list	*tmp;
	t_list	*tmp_value;
	t_list	*r_value;

	tmp = pile;
	r_value = ft_init_list();
	tmp_value = r_value;
	while (tmp)
	{
		if (tmp->content >= value)
		{
			if (tmp_value->content != -1)
			{
				tmp_value->next = ft_init_list();
				tmp_value = tmp_value->next;
			}
			tmp_value->content = tmp->content;
			tmp_value->next = NULL;
		}
		tmp = tmp->next;
	}
	return (r_value);
}

t_list	*ft_get_max_increase(t_list *list)
{
	t_list	*result;
	t_list	**tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_get_pile_len(list);
	result = NULL;
	tmp = (t_list **)malloc(sizeof(t_list *));
	if (!tmp)
		exit(1);
	while (i++ < len)
	{
		while (*tmp && ft_get_last(*tmp)->content > list->content)
			ft_pop(tmp);
		ft_add_back(tmp, list);
		if (ft_get_pile_len(*tmp) > ft_get_pile_len(result))
		{
			ft_show_pile(*tmp);
			result = *tmp;
		}
		list = list->next;
	}
	ft_show_pile(result);
	return (result);
}

t_list	*ft_analysies(t_pile *pile)
{
	int		i;
	int		value;
	t_list	*tmp;
	t_list	*tmp_value;
	t_list	*result;

	i = 0;
	value = -1;
	result = NULL;
	tmp_value = NULL;
	tmp = *pile->a;
	while (i++ < *pile->ia->len)
	{
		value = tmp->content;
		tmp_value = ft_get_max_increase(ft_upper_nb(tmp, value));
		ft_show_pile(tmp_value);
		if (ft_get_pile_len(tmp_value) > ft_get_pile_len(result))
			result = tmp_value;
		while (i++ < *pile->ia->len && tmp->content >= value)
			tmp = tmp->next;
	}
	// ft_show_pile(result);
	return (result);
}

int	main(int argc, const char **argv)
{
	int		i;
	t_pile	*pile;
	t_list	*result;

	i = 0;
	pile = ft_init_piles(argc, argv);
	ft_transform_value(pile);
	ft_show(*pile);
	// ft_show_pile(*pile->a);
	// ft_upper_nb(*pile->a, *pile->ia->first);
	// result = ft_analysies(pile);
	ft_get_max_increase(ft_upper_nb(*pile->a, *pile->ia->first));
	// ft_show_diff(*pile->a, result);
	// ft_show_pile(*pile->a);
	ft_free_pile(pile);
	return (0);
}
