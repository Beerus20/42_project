/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_num.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:59:45 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 13:59:45 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_NUM_H
# define FT_UTILS_NUM_H

int		ft_pow(int nb, int pow);
int		ft_count_nb(char type, unsigned long nb);
char	ft_getnb_base(char type, unsigned long *nb);
void	ft_reverse(char *str);
void	ft_uitos(char type, unsigned long nb, char *value);
#endif