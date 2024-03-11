/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:21:57 by beerus            #+#    #+#             */
/*   Updated: 2024/03/11 17:21:29 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdarg.h>
# include "libft.h"
# include "ft_check.h"

int		ft_uitos(char type, unsigned long nb);
int		ft_len_flags(const char *str);
void	ft_get_flags(char *flags, const char *str, int len);
#endif