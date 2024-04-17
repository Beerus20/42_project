#ifndef FT_ADD_BONUS_H
# define FT_ADD_BONUS_H

# include <stdio.h>
# include <stdarg.h>
# include "ft_get_len.h"
# include "ft_utils_bonus.h"

int		ft_add_char(char *text, int flags[7], char c);
int		ft_add_str(char *text, int flags[7], char *str);
int		ft_add_unb(char *text, int flags[7], unsigned long nb, char *base);
int		ft_add_nb(char *text, int flags[7], long nb);
int		ft_add_pointer(char *text, int flags[7], unsigned long nb);
void	ft_add(const char *format, char *text, va_list args);
#endif