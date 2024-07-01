/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:44:01 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 21:17:59 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_cmd	*ft_init_cmd(char *value)
{
	t_cmd	*r_cmd;

	r_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!r_cmd)
		exit(1);
	r_cmd->content = value;
	r_cmd->next = NULL;
	return (r_cmd);
}

void	ft_add_cmd(t_cmd **cmds, char *value)
{
	t_cmd	*tmp_list;
	t_cmd	*tmp;

	tmp = ft_init_cmd(value);
	tmp_list = *cmds;
	if (tmp_list)
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp_list->next = tmp;
	}
	else
		*cmds = tmp;
}

int	ft_strcmp(char *a, char *b)
{
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (*a && *b)
	{
		if (*a != *b)
			return (0);
		a++;
		b++;
	}
	return (1);
}

t_cmd	*ft_get_cmd(void)
{
	char	*cmd;
	t_cmd	*cmds;

	cmds = NULL;
	while (1)
	{
		cmd = get_next_line(1);
		if (ft_strcmp(cmd, "\n"))
		{
			free(cmd);
			break ;
		}
		ft_add_cmd(&cmds, cmd);
	}
	return (cmds);
}

int	main(int argc, char const *argv[])
{
	t_pile	*pile;
	t_cmd	*cmds;
	t_cmd	*to_f;
	int		nb_inc;

	cmds = NULL;
	pile = ft_init();
	nb_inc = 0;
	if (ft_init_pile(argc, argv, pile->a))
	{
		ft_get_info(pile->a, pile->ia);
		ft_get_info(pile->b, pile->ib);
		nb_inc = pile->ia->len;
		cmds = ft_get_cmd();
		to_f = cmds;
		while (cmds)
		{
			exec(pile, cmds->content);
			cmds = cmds->next;
		}
		free(to_f->content);
		free(to_f);
	}
	if (ft_check_increas(*pile->a) == nb_inc)
		ft_printf("\033[0;32mOK\033[0;0m\n");
	else
		ft_printf("\033[0;31mKO\033[0;0m\n");
	ft_free_pile(pile);
	return (0);
}
