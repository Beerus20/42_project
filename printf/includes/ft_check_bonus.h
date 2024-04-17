#ifndef FT_CHECK_BONUS_H
# define FT_CHECK_BONUS_H

# include "ft_utils_bonus.h"

int		ft_check_desc(char c);
int		ft_check_value(char *str, char c);
int		ft_check_extra_len(char *str);
void	ft_check_flags(char *format, int flags[7]);
#endif