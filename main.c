/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:32 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 19:55:07 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	*hello;
	char	*str;
	int		fd;

	hello = "hello world!";
	str = " How are you stud?";
	fd = open("text.txt", O_RDWR);
	write(fd, hello, ft_strlen(hello));
	write(fd, str, ft_strlen(str));
	close(fd);
	return (0);
}
