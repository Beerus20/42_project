char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		s++;
	return (s);
}
