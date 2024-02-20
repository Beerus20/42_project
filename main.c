/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:32 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 16:35:48 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	char	*str_1;
	char	*str_2;
	int		i;

	i = 0;
	str_1 = strdup("Hello");
	str_2 = ft_strdup(" world");
	printf("ORIGINAL : %s\n", str_1);
	printf("COPY     : %s\n", str_2);
	free(str_1);
	free(str_2);
	return (0);
}
