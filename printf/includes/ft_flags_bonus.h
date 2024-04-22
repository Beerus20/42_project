/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:15:49 by ballain           #+#    #+#             */
/*   Updated: 2024/04/22 15:18:38 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_BONUS_H
# define FT_FLAGS_BONUS_H

# include <stdarg.h>

void	ft_init_flags(int flags[7]);
int		ft_isdesc(int c);
int		ft_isdigit(int c);
int		ft_get_prec(char *str);
int		ft_get_width(char *str);
void	ft_check_flags(char *str, int flags[7]);
#endif