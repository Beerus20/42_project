/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:32 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 19:33:04 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	char	str_1[19] = "alightechs";
	char	str_2[10];
	char	str_3[4];

	//i = strlcpy(str_2, str_1, 2);
	memmove(str_1 + 5, str_1, 14);
//	printf("ORIGINAL : %s, %zu\n", str_1, i);
//	printf("COPY     : %s\n", str_2);
	printf("ORIGINAL : %s\n", str_1);
//	printf("COPY     : %s\n", str_2);
	return (0);
}
