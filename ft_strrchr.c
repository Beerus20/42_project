#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i != 0 || (*s + i) != c)
		i--;
	return (s + i);
}
