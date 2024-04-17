/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:22:01 by ballain           #+#    #+#             */
/*   Updated: 2024/04/17 09:50:10 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	cp_args;
	int		i;
	int		len;
	char	*text;

	i = 0;
	va_start(args, format);
	va_copy(cp_args, args);
	len = ft_get_len(format, args);
	text = (char *)malloc(sizeof(char) * (len + 1));
	if (!text)
		return (0);
	while (i < len)
		text[i++] = 0;
	text[i] = '\0';
	ft_add(format, text, cp_args);
	write(1, text, len);
	free(text);
	return (len);
}
