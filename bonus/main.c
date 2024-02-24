#include "../libft.h"
#include "ft_lstnew_bonus.c"
#include <string.h>

char	*ft_toupper_content(char *str)
{
	int	i;
	int	len;
	char	*r_value;

	i = 0;
	len = strlen(str);
	r_value = (char *)malloc(len);
	while (i < len)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			r_value[i] = str[i] - 32;
		else
			r_value[i] = str[i];
		i++;
	}
	return (r_value);
}


void	*ft_test(void *element)
{
	t_list	*e;

	e = (t_list*)element;
	e -> content = (char *)ft_toupper_content((char *)e -> content);
	return ((void *)e);
}

void	delete(void *e)
{
	
}

int	main(void)
{
	t_list	list1;
	t_list	*list2;
	t_list	list3;
	
	list3.content = "item 3 content";
	list3.next = NULL;
	list2 = (t_list *)malloc(sizeof(t_list));
	list2 -> content = "hello world";
	list2 -> next = &list3;
	list1.content = "test 1 to see";
	list1.next = list2;
	ft_show(&list1);
	ft_lstdelone(list2, ft_del);
	ft_show(&list1);
	return (0);
}
