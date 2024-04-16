#ifndef FT_PRINTF_UTILS_BONUS_H
# define FT_PRINTF_UTILS_BONUS_H

# include <stdio.h>
# include <stdarg.h>
# include "ft_get_len.h"
# include "ft_utils_bonus.h"

int	ft_get_size(const char *format, va_list args);
int	ft_get_len(const char *format, va_list args);
#endif