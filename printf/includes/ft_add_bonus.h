#ifndef FT_ADD_BONUS_H
# define FT_ADD_BONUS_H

# include <stdarg.h>
# include "ft_dependencies_bonus.h"

// int		ft_add_str(char *text, char *str);
// int		ft_add_unb(char *text, unsigned long nb, char *base);
// int		ft_add_nb(char *text, long nb);
// int		ft_add_pointer(char *text, unsigned long nb);
void	ft_add(const char *format, char *text, va_list args);
#endif