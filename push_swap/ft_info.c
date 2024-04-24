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

void	ft_init_ipile(t_ipile *ipile)
{
	ipile->first = NULL;
	ipile->second = NULL;
	ipile->last = NULL;
	ipile->len = (int *)malloc(sizeof(int));
	if (!ipile->len)
		exit(0);
}

void	ft_get_fpile(t_list **pile, t_ipile *info)
{
	if (*pile)
	{
		if ((*pile)->content)
		{
			info->first = (int *)malloc(sizeof(int));
			if (!info->first)
				exit(0);
			*(info->first) = (*pile)->content;
		}
	}
}

void	ft_get_salpile(t_list **pile, t_ipile *info)
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
				exit(0);
			*(info->second) = tmp->content;
			to_verify = tmp;
			tmp = ft_get_last(tmp);
			if (to_verify != tmp)
			{
				info->last = (int *)malloc(sizeof(int));
				if (!info->last)
					exit(0);
				*(info->last) = tmp->content;
			}
		}
	}
}

void	ft_get_info(t_list **pile, t_ipile *info)
{
	ft_init_ipile(info);
	ft_get_fpile(pile, info);
	ft_get_salpile(pile, info);
	*(info->len) = ft_get_list_len(*pile);		
}