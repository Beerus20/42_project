/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:44:01 by ballain           #+#    #+#             */
/*   Updated: 2024/07/01 15:12:09 by ballain          ###   ########.fr       */
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

void	ft_show_cmds(t_cmd *cmds)
{
	while (cmds)
	{
		ft_printf("test	: [%s]\n", cmds->content);
		cmds = cmds->next;
	}
}

t_cmd	*ft_get_cmd(void)
{
	char	*cmd;
	t_cmd	*cmds;

	cmds = NULL;
	while (1)
	{
		cmd = get_next_line(1);
		ft_printf("CMD	: %s", cmd);
		if (ft_strlen(cmd) == 1)
		{
			free(cmd);
			break ;
		}
		ft_add_cmd(&cmds, cmd);
	}
	ft_show_cmds(cmds);
	return (cmds);
}

int	main(int argc, char const *argv[])
{
	t_pile	*pile;
	t_cmd	*cmds;

	cmds = NULL;
	pile = ft_init();
	if (ft_init_pile(argc, argv, pile->a))
	{
		ft_get_info(pile->a, pile->ia);
		ft_get_info(pile->b, pile->ib);
		cmds = ft_get_cmd();
		// while (cmds)
		// {
		// 	ft_printf("CMD	: [%s]\n", cmds->content);
		// 	cmds = cmds->next;
		// }
	}
	ft_free_pile(pile);
	return (0);
}
