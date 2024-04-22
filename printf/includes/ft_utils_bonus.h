/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:24 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 13:53:42 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

int		ft_add_blank(char *text, char c, int e);
int		ft_strlen(char *str);
int		ft_unblen(unsigned long nb, int base);
int		ft_put_nb(char *text, unsigned long nb, int prec, char *base);
void	ft_manage_precision(int flags[7], int sup);
#endif