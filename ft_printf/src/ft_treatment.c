#include "../includes/ft_printf.h"
#include "../includes/ft_utils.h"
#include "../includes/ft_flags.h"

void	ft_apply_flags_str(t_value *value)
{
	if (ft_strchr(value->flags, 'l'))
		ft_len_flag_str(value);
	else if (!value->content)
		value->content = ft_strdup("(null)");
	value->l = ft_strlen(value->content);
	if (ft_strchr(value->flags, 'w'))
		ft_width_flag(value);
}

void	ft_apply_flags_pointer(t_value *value)
{
	if (!value->content)
		value->content = ft_strdup("(nil)");
	else
		ft_add_front_content_value(value, "0x");
	value->l = ft_strlen(value->content);
	if (ft_strchr(value->flags, 'w'))
		ft_width_flag(value);
}

void	ft_apply_flags_number(t_value *value)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(value->flags, 'l'))
	{
		tmp = ft_strdup(value->content);
		ft_len_flag_number(value, tmp);
		if (tmp[0] == '-' && value->content[0] != '-')
			ft_add_front_content_value(value, "-");
		free(tmp);
	}
	value->l = ft_strlen(value->content);
	if (ft_strchr(value->flags, 'w'))
		ft_width_flag(value);
}


void	ft_apply_flags(t_value *value)
{
	char	type;

	type = value->type;
	if (type == 's')
		ft_apply_flags_str(value);
	if (type == 'p')
		ft_apply_flags_pointer(value);
	if (ft_isnumber(type))
		ft_apply_flags_number(value);
}

void	ft_printc(t_value *value)
{
	int	i;

	i = 0;
	if (value->w == 0)
		ft_putchar_fd(value->content[0], 1);
	else
	{
		if (ft_strchr(value->flags, '-'))
		{
			ft_putchar_fd(value->content[0], 1);
			while (i < (value->w - 1))
			{
				write(1, " ", 1);
				i++;
			}
		}
		else
		{
			while (i < (value->w - 1))
			{
				write(1, " ", 1);
				i++;
			}
			ft_putchar_fd(value->content[0], 1);
		}
		value->l = value->w;
	}
}
