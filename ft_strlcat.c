/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:01:59 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 14:02:01 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if ((int)size >= 0 && size < len_dst)
	{
		
		return (size + len_src);
	}
	else
	{
		if ((int)size < 0)
		{
			ft_strlcpy(&dst[len_dst], src, len_src + 1);
		}
		else
		{
			printf("\n\nato......\n\n");
			ft_strlcpy(ft_strchr(dst, '\0'), src, size - 1);
		}
	}
	return (len_dst + len_src);
}

int	main(void)
{
	char	*str = "lorem ipsum dolor sit amet";
	char	dest[16];
	size_t	size = 15;
	
	dest[12] = 'a';
	dest[13] = 'b';
	dest[14] = 'c';
	printf("LEN : %p %lu\n", strchr(dest, '\0'), strlen(dest));
	printf("CPY : %p %lu\n\n", ft_strchr(dest, '\0'), ft_strlen(dest));
	int	i = 0;
	while (!isalpha(dest[i]))
	{
		printf("%d : [%d] - [%c]\n", i, isprint(dest[i]), dest[i]);
		i++;
	}
	printf("%d : [%d] - [%c]\n", i, isprint(dest[i]), dest[i]);
	//printf("\nORIG	: %zu\n", strlcat(dest, str, size));
	//printf("COPY	: %zu\n", ft_strlcat(dest, str, size));
	printf("TEST : %c %d %s, %p, %p", dest[6], dest[6], dest, ft_strchr(dest, '\0'), dest + 14);
	return (0);
}
