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
	if (*pile)
	{
		if ((*pile)->content)
		{
			info->first = (int *)malloc(sizeof(int));
			if (!info->first)
				exit(1);
			*(info->first) = (*pile)->content;
		}
	}
}

t_list	*ft_get_last(t_list *pile)
{
	while (pile->next)
		pile = pile->next;
	return (pile);
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