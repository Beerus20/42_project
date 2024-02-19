int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;

	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while ((*str_1++ && *str_2) || n--)
		;
	return (*str_1 - *str_2);
}
