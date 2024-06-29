/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:36:55 by ballain           #+#    #+#             */
/*   Updated: 2024/06/28 17:48:54 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_strlen_split(const char *str, char c)
// {
// 	int	r_count;

// 	r_count = 0;
// 	while (*str)
// 	{
// 		while (*str == c && *str)
// 			str++;
// 		while (*str != c && *str)
// 		{
// 			r_count++;
// 			str++;
// 		}
// 		if (*str)
// 		{

// 			str++;
// 		}
// 	}
// 	return (r_count);
// }

// int	ft_count_wd(const char *str, const char sep)
// {
// 	int	i;
// 	int	len;
// 	int	r_count;

// 	i = 0;
// 	len = ft_strlen(str);
// 	r_count = 0;
// 	while (i < len)
// 	{
// 		while (str[i] == sep && str[i])
// 			i++;
// 		if (str[i])
// 			r_count++;
// 		while (str[i] != sep && str[i])
// 			i++;
// 	}
// 	return (r_count);
// }

// char	*ft_strdup(const char *str)
// {
// 	int		len;
// 	char	*r_value;
// 	char	*tmp;

// 	len = ft_strlen(str) + 1;
// 	if (len == 1)
// 		return (NULL);
// 	r_value = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!r_value)
// 		return (NULL);
// 	tmp = r_value;
// 	while (*str)
// 		*(tmp++) = *(str++);
// 	*tmp = '\0';
// 	return (r_value);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	char	**r_value;
// 	char	*tmp;

// 	i = 0;
// 	while (*s == c && *s)
// 		s++;
// 	tmp = ft_strdup(s);
// 	if (!tmp)
// 		return (NULL);
// 	r_value = (char **)malloc(sizeof(char *) * (ft_count_wd(s, c) + 1));
// 	if (!r_value)
// 		return (NULL);
// 	while (*tmp)
// 	{
// 		while (*tmp == c && *tmp)
// 			*(tmp++) = '\0';
// 		if (*tmp)
// 			r_value[i++] = tmp;
// 		while (*tmp != c && *tmp)
// 			tmp++;
// 	}
// 	r_value[i] = NULL;
// 	return (r_value);
// }

// 9 8 5 2 1 4

void	ft_launch(t_pile *pile, t_pile *ref)
{
	ft_transform_value(pile);
	*ref->a = ft_get_max_increase(*pile->a);
	ft_get_info(ref->a, ref->ia);
	ft_check_additional_ref(*pile->a, *ref->a);
	ft_rectification_ref(*pile->a, *ref->a);
	if (ft_check_increas(*pile->a) != pile->ia->len)
		ft_action(pile, ref);
}

int	main(int argc, const char **argv)
{
	t_pile	*pile;
	t_pile	*ref;

	pile = ft_init();
	ref = ft_init();
	ft_init_pile(argc, argv, pile->a);
	ft_get_info(pile->a, pile->ia);
	ft_get_info(pile->b, pile->ib);
	ft_launch(pile, ref);
	ft_free_pile(ref);
	ft_free_pile(pile);
	return (0);
}
