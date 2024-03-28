#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_utils_num.h"

char	*ft_strdup(char *s);
char	*ft_itoa(int n);
int		ft_pow(int nb, int pow);
int		ft_strlen(char *value);
int		ft_isint(char type);
int		ft_isuint(char type);
int		ft_isflag(int c);
int		ft_printf(const char *format, ...);
#endif