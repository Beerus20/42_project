#include "../printf.h"

int	ft_count_char(const char *str, const char c)
{
	unsigned int	i;
	unsigned int	count;	

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}