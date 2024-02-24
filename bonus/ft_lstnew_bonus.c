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
	(*lst) -> content = new -> content;	
}

int	ft_lstsize(t_list *lst)
{
	int	count;
	t_list	*list;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int	last_id;

	while ((*lst) -> next)
		(*lst) = (*lst) -> next;
	(*lst) -> content = new -> content;
}

void	ft_del(void *element)
{
	free(element);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*next;

	next = lst -> next;
	(*del)(lst);
	lst -> next = next;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))	
{
	t_list	*stock;
	t_list	*i;

	stock = *lst;
	i = stock;
	while (i)
	{
		i = stock -> next;
		(*del)(stock);
		stock = i;
	}
	(*lst) -> next = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*element;

	element = lst;
	while (element)
	{
		(*f)(element);
		element = element -> next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	int		len_list;
	t_list	*r_value;

	i = 0;
	len_list = ft_lstsize(lst);
	r_value = (t_list *)malloc(sizeof(t_list) * len_list);;
	while (i < len_list)
	{
		r_value[i] = *(t_list *)(*f)(lst);
		printf("POINTEUR : %p\n", r_value);
		(*del)(r_value + i);
		lst = lst -> next;
		i++;
	}
	return (r_value);
}

void	ft_show(t_list *e)
{
	int	len_e;

	while(e)
	{
		printf("content : %s - pointeur : %p\n", (char *)e -> content, e -> next);
		e = e -> next;
	}	
}


