#include "push_swap.h"

void	ft_exec_swap(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("sa\n");
		ft_swap(pile->a);
	}
	else if (type == 'b')
	{
		ft_printf("sb\n");
		ft_swap(pile->b);
	}
	else if (type == 's')
	{
		ft_printf("ss\n");
		ft_swap(pile->a);
		ft_swap(pile->b);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_push(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("pa\n");
		ft_push(pile, 1);
	}
	else if (type == 'b')
	{
		ft_printf("pb\n");
		ft_push(pile, 0);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_rotate(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("ra\n");
		ft_rotate(pile->a);
	}
	else if (type == 'b')
	{
		ft_printf("rb\n");
		ft_rotate(pile->b);
	}
	else if (type == 'r')
	{
		ft_printf("rr\n");
		ft_rotate(pile->a);
		ft_rotate(pile->b);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

void	ft_exec_rev_rotate(t_pile *pile, char type)
{
	if (type == 'a')
	{
		ft_printf("rra\n");
		ft_rev_rotate(pile->a);
	}
	else if (type == 'b')
	{
		ft_printf("rrb\n");
		ft_rev_rotate(pile->b);
	}
	else if (type == 'r')
	{
		ft_printf("rrr\n");
		ft_rev_rotate(pile->a);
		ft_rev_rotate(pile->b);
	}
	else
	{
		ft_printf("ERROR ACTION\n");
		exit(1);
	}
}

int	ft_chr_action_type(char *str, int *index)
{
	int	i;

	i = 0;
	*index = 0;
	while (*str != 's' && *str != 'p' && *str != 'r' && *str)
	{
		str++;
		(*index)++;
	}
	while (*str != ' ' && *(str++))
		i++;
	return (i);
}

int	exec(t_pile *pile, char *action)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	while (*action)
	{
		nb = ft_chr_action_type(action, &index);
		if (nb == 2)
		{
			if (action[index] == 's')
				ft_exec_swap(pile, action[index + 1]);
			if (action[index] == 'p')
				ft_exec_push(pile, action[index + 1]);
			if (action[index] == 'r')
				ft_exec_rotate(pile, action[index + 1]);
		}
		else
			ft_exec_rev_rotate(pile, action[index + 2]);
		ft_update_info(pile);
		if (DEBUG)
		{
			ft_show(*pile);
			ft_show_info(*pile);
		}
		action += index + nb;
	}
	return (0);
}

void	loop_exec(t_pile *pile, int nb_iter, char *to_do)
{
	while (nb_iter > 0)
	{
		exec(pile, to_do);
		nb_iter--;
	}
}
