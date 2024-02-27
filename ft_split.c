/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:45:38 by ballain           #+#    #+#             */
/*   Updated: 2024/02/21 19:49:33 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_alloc_rvalue(char const *s, char c, int *nb_w)
{
	int		i;
	int		can_count_word;
	char	**r_value;

	i = 0;
	can_count_word = 1;
	r_value = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c && can_count_word)
		{
			can_count_word = 0;
			*nb_w += 1;
		}
		if (s[i] == c)
			can_count_word = 1;
		i++;
	}
	r_value = (char **)malloc(sizeof(char *) * (*nb_w + 1));
	if (!r_value)
		return (0);
	return (r_value);
}

int	ft_alloc_content(char **r_value, char const *s, char c)
{
	int		i;
	int		j;
	int		id_word;
	int		nb_c;
	int		can_write;

	i = 0;
	j = 0;
	id_word = 0;
	nb_c = 0;
	can_write = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			can_write = 1;
			if (s[i - 1] != c)
				r_value[j] = ft_substr(s, id_word, nb_c);
		}
		if (s[i] != c)
		{
			if (can_write)
			{
				printf("ATO ...\n");
				id_word = i;
				j++;
				nb_c = 0;
			}
			can_write = 0;
			nb_c++;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nb_w;
	char	**r_value;

	nb_w = 0;
	r_value = ft_alloc_rvalue(s, c, &nb_w);
	if (nb_w == 0)
	{
		r_value[0] = NULL;
		return (r_value);
	}
	ft_alloc_content(r_value, s, c);
	return (r_value);
}

int	main(void)
{
	char	*str = " lorem    ipsum    dolor     sit    met    ";
	char	**result = ft_split(str, ' ');

	while (*result)
	{
		printf("result : [%s]\n", *result);
		result++;
	}
	return (0);
}
