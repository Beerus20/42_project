#include "push_swap.h"

int	ft_get_list_len(t_list *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

void	ft_get_fpile(t_list **pile, t_info *info)
{
	t_list	*tmp;

	tmp = *pile;
	if (tmp)
	{
		info->first = (int *)malloc(sizeof(int));
		if (!info->first)
			exit(1);
		*(info->first) = tmp->content;
	}
}

t_list	*ft_get_last(t_list *pile)
{
	t_list	*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_get_salpile(t_list **pile, t_info *info)
{
	t_list	*tmp;
	t_list	*to_verify;

	tmp = *pile;
	if (tmp)
	{
		if (tmp->next)
		{
			tmp = tmp->next;
			info->second = (int *)malloc(sizeof(int));
			if (!info->second)
				exit(1);
			*(info->second) = tmp->content;
			to_verify = tmp;
			tmp = ft_get_last(tmp);
			if (to_verify != tmp)
			{
				info->last = (int *)malloc(sizeof(int));
				if (!info->last)
					exit(1);
				*(info->last) = tmp->content;
			}
		}
	}
}

void	ft_init_info(t_info *pile)
{
	pile->first = NULL;
	pile->second = NULL;
	pile->last = NULL;
	pile->len = (int *)malloc(sizeof(int));
	if (!pile->len)
		exit(1);
	*(pile->len) = 0;
}

void	ft_get_info(t_list **pile, t_info *info)
{
	ft_init_info(info);
	ft_get_fpile(pile, info);
	ft_get_salpile(pile, info);
	*(info->len) = ft_get_list_len(*pile);
}

void	ft_update_info(t_pile *pile)
{
	ft_get_info(pile->a, pile->ia);
	ft_get_info(pile->b, pile->ib);
}

int	ft_info(t_info info, int id)
{
	if (id == 0 && info.first)
		return (*info.first);
	if (id == 1 && info.second)
		return (*info.second);
	if (id == 2 && info.last)
		return (*info.last);
	if (info.len)
		return (*info.len);
	return (0);
}