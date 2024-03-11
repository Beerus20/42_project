/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 08:23:10 by beerus            #+#    #+#             */
/*   Updated: 2024/03/11 16:09:32 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_check.h"

int	ft_check_type(char c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	ft_isint(char type)
{
	if (ft_strchr("cdi", type))
		return (1);
	return (0);
}

int	ft_isuint(char type)
{
	if (ft_strchr("upxX", type))
		return (1);
	return (0);
}
