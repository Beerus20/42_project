/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruce <bruce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:25 by bruce             #+#    #+#             */
/*   Updated: 2024/03/04 19:59:54 by bruce            ###   ########.fr       */
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

void	ft_show_value(t_in_value *lst)
{
	while (lst)
	{
		if (lst->type == INT)
			printf("VALUE : [%d]\n", *(int *)lst->content);
		if (lst->type == TEXT)
			printf("VALUE : [%s]\n", (char *)lst->content);
		lst = (t_in_value *)lst->next;
	}
}