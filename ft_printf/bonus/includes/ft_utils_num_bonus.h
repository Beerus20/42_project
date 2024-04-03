/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_num_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:33:09 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:06:27 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_NUM_BONUS_H
# define FT_UTILS_NUM_BONUS_H

# include "function.h"

int		ft_pow(int nb, int pow);
int		ft_count_nb(char type, unsigned long nb);
char	ft_getnb_base(char type, unsigned long *nb);
void	ft_reverse(char *str);
void	ft_uitos(char type, unsigned long nb, char *value);
#endif