#ifndef FT_UTILS_NUM_H
# define FT_UTILS_NUM_H

int		ft_pow(int nb, int pow);
int		ft_count_nb(char type, unsigned long nb);
char	ft_getnb_base(char type, unsigned long *nb);
void	ft_reverse(char *str);
void	ft_uitos(char type, unsigned long nb, char *value);
#endif