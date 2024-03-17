/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:32 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 00:12:05 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	*ft_stoc(int c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return ((void *)0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	ft_add_front_content_value(t_value *value, char *str)
{
	char	*tmp;

	tmp = ft_strdup(value->content);
	free(value->content);
	value->content = ft_strjoin(str, tmp);
	free(tmp);
}

int	ft_hasflag(char *flag)
{
	if (ft_strlen(flag))
		return (1);
	return (0);
}

void	ft_show_test(t_value *value)
{
	printf("CONTENT	: \n");
	printf("\tTYPE	: [%c]\n", value->type);
	printf("\tFALGS	: [%s]\n", value->flags);
	printf("\tVALUE	: [%s]\n", (char *)value->content);
	printf("\tWIDTH	: [%d]\n", value->w);
	printf("\tLEN	: [%d]\n", value->l);
}

void	ft_show_value(t_value *value)
{
	int	i;

	i = 0;
	while (value)
	{
		printf("CONTENT	: [%i]\n", i++);
		printf("\tTYPE	: [%c]\n", value->type);
		printf("\tFALGS	: [%s]\n", value->flags);
		printf("\tVALUE	: [%s]\n", (char *)value->content);
		printf("\tWIDTH	: [%d]\n", value->w);
		printf("\tLEN	: [%d]\n", value->l);
		value = value->next;
	}
}
