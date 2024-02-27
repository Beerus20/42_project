/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:14:42 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 14:14:57 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_init_count_rvalue(char const *s1, char const *set)
{
	
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*r_value;
	char	*str;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(s1);
	str = ft_strdup(s1);
	if (!str)
		return (0);
	while (1)
	{
		if (ft_str)
	}
	return (r_value);
}

int	main(void)
{
	char	*str = "lorem \n ipsum \t dolor \n sit \t amet";
	printf("RETURN VALUE : [%s]\n", str);
	return (0);
}
