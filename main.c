/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:32 by ballain           #+#    #+#             */
/*   Updated: 2024/02/20 13:36:00 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <ctype.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	str_1[7] = "makes ";
	char	*str_2 = "the world easy";
	char	*result;

	//strlcat(str_1, str_2, 4);
	printf("lenght : %zu %zu\n", ft_strlen(str_1), ft_strlen(str_2));
	printf("SOURCE : \n %s\n %zu\n", str_1, strlcat(str_1, str_2, 1));
	printf("lenght result : %zu\n", ft_strlen(str_1));
	//printf("COPY   : %d\n", ft_atoi("-4e567"));
	return (0);
}
