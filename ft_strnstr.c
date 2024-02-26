/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:39:23 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 10:39:26 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	unsigned int	j;
	unsigned int	len_little;

	i = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (*big && len)
	{
		j = 0;
		if (*big == *little)
		{
			i = len;
			while (big[j] == little[j] && i--)
				j++;
			if (little[j] == '\0')
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
