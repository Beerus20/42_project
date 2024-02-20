#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	i;
	char	*r_value;

	i = 0;
	r_value = (char *)malloc(len);
	if (!r_value)
		return (0);
	while (i < len && s[start + i] == '\0')
	{
		r_value[i] = s[start + i]; 
		i++;
	}
	return (r_value);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	char	*r_value;

	i = 0;
	r_value = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!r_value)
		return (0);
	while (*s1 != '\0')
	{
		r_value[i] = *s1;
		i++;
	}
	while (*s2 != '\0')
	{
		r_value[i] = *s2;
		i++;
	}
	return (r_value);
}

char	*ft_strtrim(char const *s1, char const *set)
{

}

int	ft_count_char(const char *s, const char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_size_sepw()
{

}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	count;
	int	split_nb;
	char	**r_value;

	i = 0;
	count = 0;
	split_nb = ft_count_char(s, c) + 1;
	r_value = (char **)malloc(split_nb);
	while (i < split_nb)
	{
		while ()
		*r_value = (char *)malloc(ft_strlen());
		i++;
	}
}
