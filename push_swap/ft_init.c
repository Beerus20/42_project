/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:43 by ballain           #+#    #+#             */
/*   Updated: 2024/05/30 09:44:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	len;
	int	mul;

	i = 0;
	nb = 0;
	len = ft_getlen(str);
	mul = 1;
	if (len >= 2 && str[0] == '-')
	{
		mul = -1;
		i = 1;
	}
	while (i < len)
	{
		nb = (str[i] - 48) + (nb * 10);
		i++;
	}
	return (nb * mul);
}

void	ft_init_pile(int argc, const char **argv, t_list **pile)
{
	int		i;
	t_list	*tmp;

	i = 1;
	*pile = (t_list *)malloc(sizeof(t_list));
	if (!(*pile))
		return ;
	if (argc < 2)
		return ;
	tmp = (*pile);
	while (i < argc)
	{
		tmp->content = ft_atoi(argv[i]);
		if ((i + 1) < argc)
		{
			tmp->next = (t_list *)malloc(sizeof(t_list));
			if (!tmp)
				return ;
		}
		else
			tmp->next = 0;
		tmp = tmp->next;
		i++;
	}
}

t_pile	*ft_init(void)
{
	t_pile	*pile;

	pile = (t_pile *)malloc(sizeof(t_pile));
	pile->a = (t_list **)malloc(sizeof(t_list *));
	pile->b = (t_list **)malloc(sizeof(t_list *));
	pile->ia = (t_info *)malloc(sizeof(t_info));
	pile->ib = (t_info *)malloc(sizeof(t_info));
	if (!pile || !pile->a || !pile->b || !pile->ia || !pile->ib)
		exit(1);
	*(pile->a) = NULL;
	*(pile->b) = NULL;
	return (pile);
}
