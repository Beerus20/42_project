/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruce <bruce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:25 by bruce             #+#    #+#             */
/*   Updated: 2024/03/05 17:10:00 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

int	ft_count_char(const char *str, const char c)
{
	unsigned int	i;
	unsigned int	count;	

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

t_action	ft_init_action(void)
{
	t_action	r_value;

	r_value.type = 0;
	r_value.flags = (void *)0;
	return (r_value);
}

void	ft_show_value(t_action *action)
{
	printf("\nAction : \n\t--type : [%c]\n\t--flags : [%s]\n\n", action->type, action->flags);
}
