/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:32 by ballain           #+#    #+#             */
/*   Updated: 2024/02/19 18:41:30 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	str[] = "makes";
	char	dest[] = "";
	char	dest_0[] = "";

	//strlcpy(dest, str, sizeof(str));
	ft_strlcpy(dest_0, str, 4);
	//printf("CPY : %s\n", dest);
	printf("FT_CPY : %s\n", dest_0);
	return (0);
}
