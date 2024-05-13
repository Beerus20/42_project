#include "push_swap.h"

t_list	*ft_get_last(t_list *pile)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_get_info(t_list **pile, t_info *info)
{
	t_list	*tmp;

	tmp = *pile;
	if (tmp)
	{
		info->first = tmp->content;
		if (tmp->next)
			info->second = tmp->next->content;
		else
		{
			info->second = -1;
			info->last = -1;
		}
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->content == info->second)
			info->last = -1;
		else
			info->last = tmp->content;
	}
	else
	{
		info->first = -1;
		info->second = -1;
		info->last = -1;
	}
	info->len = ft_get_list_len(*pile);
}

void	ft_update_info(t_pile *pile)
{
	ft_get_info(pile->a, pile->ia);
	ft_get_info(pile->b, pile->ib);
}

int	ft_info(t_info info, int id)
{
	if (id == 0 && info.first)
		return (info.first);
	if (id == 1 && info.second)
		return (info.second);
	if (id == 2 && info.last)
		return (info.last);
	if (info.len)
		return (info.len);
	return (0);
}