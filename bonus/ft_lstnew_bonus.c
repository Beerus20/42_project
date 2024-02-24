#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r_value;

	r_value = (t_list *)malloc(sizeof(t_list));
	if (!r_value)
		return (0);
	r_value -> content = content;
	r_value -> next = NULL;
	return (r_value);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	printf("\nyou are");
	(**lst).content = "test test test ok ok ok";
	(**lst).next = NULL;	
	//lst = &new;
}
