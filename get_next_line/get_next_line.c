#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*r_value;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (0);
	while (i < len)
	{
		r_value[i] = s[i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*r_value;

	i = 0;
	r_value = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_value)
		return (0);
	while (*s1 != '\0')
	{
		r_value[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		r_value[i++] = *s2;
		s2++;
	}
	r_value[i] = '\0';
	return (r_value);
}

int	ft_size(char const *s, unsigned int start, size_t len)
{
	size_t	r_value;
	size_t	len_s;
	size_t	len_r;

	r_value = 0;
	len_s = ft_strlen(s);
	len_r = start + len;
	if (len_r >= len_s)
		r_value = len_s - start + 1;
	else
		r_value = len + 1;
	if (start >= len_s)
		r_value = (int)(sizeof(char) * 1);
	return (r_value);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*r_value;

	i = 0;
	len_s = ft_strlen(s);
	r_value = (char *)malloc(ft_size(s, start, len));
	if (!r_value)
		return (0);
	if (start >= len_s)
	{
		r_value[i] = '\0';
		return (r_value);
	}
	while (i < len)
	{
		if (s[start + i] == '\0')
			break ;
		r_value[i] = s[start + i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buffer_tmp;
	char		*r_value;
	int			stop_reading;
	int			size;
	int			i;

	i = 0;
	size = 0;
	stop_reading = 0;
	buffer_tmp = NULL;
	r_value = (char *)malloc(sizeof(char));
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer && !r_value && !fd)
			return (0);
	}
	while (!stop_reading)
	{
		if (!ft_strlen(buffer))
		{
			buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!buffer && !r_value && !fd)
				return (0);
			size = read(fd, buffer, BUFFER_SIZE);
			if (!size)
				return (NULL);
			buffer[size] = '\0';
		}
		i = 0;
		while (buffer[i] != '\n' && buffer[i])
			i++;
		if (buffer[i] == '\n')
		{
			r_value = ft_strjoin(r_value, ft_substr(buffer, 0, ++i));
			buffer_tmp = ft_substr(buffer, i, ft_strlen(buffer));
			free(buffer);
			buffer = ft_strdup(buffer_tmp);
			printf("____BUFFER	: [\n%s]\n", buffer);
			stop_reading = 1;
		}
		else
		{
			r_value = ft_strjoin(r_value, ft_substr(buffer, 0, i));
			buffer = ft_strdup("");
		}
	}
	return (r_value);
}