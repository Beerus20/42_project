/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_supp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:07:32 by beerus            #+#    #+#             */
/*   Updated: 2024/03/18 14:07:55 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

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
