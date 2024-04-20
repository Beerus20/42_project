
int	ft_check(char c)
{
	int		i;
	char	*desc;

	i = 0;
	desc = "cspduixX%";
	while (desc[i])
	{
		if (desc[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
int	ft_get_with(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (!(str[i] >= '1' && str[i] <= '9') && !ft_check(str[i]))
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && !ft_check(str[i]))
	{
		width = (str[i] - 48) + (width * 10);
		i++;
	}
	return (width);
}
int	ft_get_precision(char *str)
{
	int	i;
	int	prec;

	i = 0;
	prec = 0;
	while (str[i++] != '.' && !ft_check(str[i]))
		;
	while ((str[i] >= '0' && str[i] <= '9') && !ft_check(str[i]))
	{
		prec = (str[i] - 48) + (prec * 10);
		i++;
	}
	return (prec);
}
