/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruce <bruce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:34:40 by bruce             #+#    #+#             */
/*   Updated: 2024/03/04 21:29:17 by bruce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/printf.h"

int	ft_count_words(char *str)
{
	char	*tmp;
	int		count_words;

	tmp = (char *)str;
	count_words = 0;
	while (1)
	{
		while (*tmp != '%' && *tmp)
			tmp++;
		if (*tmp == '\0' && count_words++)
			return (count_words);
		str = tmp;
		count_words++;
		while (ft_strchr("cspdiuxX%", *tmp) && *tmp)
			tmp++;
		if (*tmp == '\0' && count_words++)
			return (count_words);
		str = tmp;
		count_words++;
	}
	return (0);
}

int	ft_analyse(const char *str)
{
	const char	*tmp;

	tmp = ft_strchr(str, '%');
	printf("LENGHT : [%ld] [%p] [%p]\n", (tmp - str), str, tmp);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			nb_word;
	t_in_value	**value;

	nb_word = ft_count_words((char *)str) + 1;
	value = (t_in_value **)malloc(sizeof(t_in_value *) * nb_word);
	ft_analyse(str);
	printf("words : [%d]\n", ft_count_words((char *)str));
	free(value);
	return (0);
}

int	main(void)
{
	int i;

	i = 0;
	printf("%s\n", TYPE(i));
	return (0);
}
