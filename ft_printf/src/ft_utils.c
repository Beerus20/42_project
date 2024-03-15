/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:32 by ballain           #+#    #+#             */
/*   Updated: 2024/03/15 15:40:52 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	*ft_stoc(int c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return ((void *)0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
