#include "push_swap.h"

t_list	*ft_upper_nb(t_list *pile, int value)
{
	t_list	*tmp;
	t_list	*tmp_value;
	t_list	*r_value;

	tmp = pile;
	r_value = ft_init_list(-1);
	tmp_value = r_value;
	while (tmp)
	{
		if (tmp->content >= value)
		{
			if (tmp_value->content != -1)
			{
				tmp_value->next = ft_init_list(-1);
				tmp_value = tmp_value->next;
			}
			tmp_value->content = tmp->content;
			tmp_value->next = NULL;
		}
		tmp = tmp->next;
	}
	return (r_value);
}
int	ft_get_maxv_tab(int *tab, int len)
{
	int	i;
	int	max;

	i = 0;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	*ft_init_ids(int nb)
{
	int	i;
	int	*r_ids;

	i = 0;
	r_ids = (int *)malloc(sizeof(int) * nb);
	if (!r_ids)
		exit(1);
	while (i < nb)
		r_ids[i++] = 1;
	return (r_ids);
}

int	*ft_init_tab(t_list *pile)
{
	t_list	*tmp;
	int		*r_tab;
	int		i;
	int		len;

	i = 0;
	tmp = pile;
	len = ft_get_list_len(pile);
	r_tab = (int *)malloc(sizeof(int) * len);
	if (!r_tab)
		exit(1);
	while (i < len)
	{
		r_tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (r_tab);
}

int	*ft_get_tab_ids(t_list *pile)
{
	int	*tmp;
	int	*ids;
	int	len;
	int	i;
	int	j;

	i = 1;
	len = ft_get_list_len(pile);
	ids = ft_init_ids(len);
	tmp = ft_init_tab(pile);
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (tmp[i] > tmp[j] && ids[i] < ids[j] + 1)
				ids[i] = ids[j] + 1;
			j++;
		}
		i++;
	}
	free(tmp);
	return (ids);
}
