/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:55:02 by ballain           #+#    #+#             */
/*   Updated: 2024/03/11 17:28:16 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

int	ft_len_flags(char *str)
{
	int	count;

	count = 0;
	while (ft_check_type(*(str++)) != 1)
		count++;
	return (count);
}

void	ft_get_flags(char *flags,const char *str, int len)
{
	int	i;

	i = 0;
	printf("\nTESTSETSTEET : [%d]\n", len);
	while (i < len)
	{
		flags[i++] = *(str++);
		printf("\n\tTEST : [%c]\n", flags[i - 1]);
	}
}
