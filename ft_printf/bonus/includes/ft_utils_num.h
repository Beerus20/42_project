/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_num.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beerus <beerus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:09 by ballain           #+#    #+#             */
/*   Updated: 2024/03/18 14:29:29 by beerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_NUM_H
# define FT_UTILS_NUM_H

# include "function.h"

int		ft_pow(int nb, int pow);
int		ft_count_nb(char type, unsigned long nb);
char	ft_getnb_base(char type, unsigned long *nb);
void	ft_reverse(char *str);
void	ft_uitos(char type, unsigned long nb, char *value);
#endif