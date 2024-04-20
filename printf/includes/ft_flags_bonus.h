#ifndef FT_FLAGS_BONUS_H
# define FT_FLAGS_BONUS_H

# include <stdarg.h>

// int	ft_get_len(const char *format, va_list args);
void	ft_init_flags(int flags[7]);
int		ft_isdesc(int c);
int		ft_isdigit(int c);
int		ft_get_prec(char *str);
int		ft_get_width(char *str);
void	ft_check_flags(char *str, int flags[7]);
#endif