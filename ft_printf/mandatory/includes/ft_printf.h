/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:59:39 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 14:11:11 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_utils_num.h"

void	ft_printc(int value, int *len);
void	ft_printv(char type, char *value, int *len);
char	*ft_strdup(char *s);
char	*ft_itoa(int n);
int		ft_pow(int nb, int pow);
int		ft_strlen(char *value);
int		ft_isint(char type);
int		ft_isuint(char type);
int		ft_isflag(int c);
int		ft_printf(const char *format, ...);
#endif