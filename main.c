/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:32 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 14:09:28 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <ctype.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	str_1[50] = "makes ";
	char	*str_2 = "the world easy";
	char	str_3[50] = "makes ";
	char	*str_4 = "the world easy";
	char	*result;
	size_t	size = 0;

	printf("SOURCE L : %zu\n", strlcpy(str_1, str_2, size));
	printf("RESULT S : %s\n\n", str_1);
	printf("SORTIE L : %zu\n", ft_strlcpy(str_3, str_4, size));
	printf("RESULT S : %s\n", str_3);
	return (0);
}
