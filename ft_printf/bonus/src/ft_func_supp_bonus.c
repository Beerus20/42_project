/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_supp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:07:32 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:50:00 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils_bonus.h"

int	ft_is_null_hex_value(char *content)
{
	while (*content)
	{
		if (*content != '0')
			return (0);
		content++;
	}
	return (1);
}
