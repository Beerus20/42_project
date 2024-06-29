/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:43 by ballain           #+#    #+#             */
/*   Updated: 2024/06/29 15:12:36 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		len;
	int		mul;
	long	nb;

	i = 0;
	nb = 0;
	len = ft_strlen((char *)str);
	mul = 1;
	if (str[0] == '-')
	{
		mul = -1;
		i++;
	}
	while (i < len)
		nb = (str[i++] - 48) + (nb * 10);
	return (nb * mul);
}

int	ft_init_pile(int argc, const char **argv, t_list **pile)
{
	int		i;
	char	**s_params;
	char	**tmp;

	i = 0;
	s_params = NULL;
	if (!ft_params_is_valid(argc, argv))
		return (0);
	while (++i < argc)
	{
		s_params = ft_split(argv[i], ' ');
		tmp = s_params;
		while (tmp && *tmp)
			ft_add_back_content(pile, ft_atoi(*(tmp++)));
		free(*s_params);
		free(s_params);
	}
	if (ft_check_error(*pile))
		return (0);
	return (1);
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
