#include "../libft.h"
#include "ft_lstnew_bonus.c"


void	*ft_test(void *element)
{
	t_list	*e;

	e = (t_list*)element;
	return ((void *)e);
}

int	main(void)
{
	t_list	**tab;
	t_list	*list3;
	t_list	*list2;
	t_list	*list1;;
	t_list	new = {"new value", NULL};
	
	tab = (t_list **)malloc(sizeof(t_list *) * 3);
	if (!tab)
	{
		printf("ALLOCATION ERROR ...");
		return (0);
	}
	list3 = (t_list *)malloc(sizeof(t_list));
	list3 -> content = "c";
	list3 -> next = NULL; 
	list2 = (t_list *)malloc(sizeof(t_list));
	list2 -> content = "b";
	list2 -> next = list3;
	list1 = (t_list *)malloc(sizeof(t_list));
	list1 -> content = "a";
	list1 -> next = list2;
	tab[0] = list1;
	tab[1] = list2;
	tab[2] = list3;
	printf("VALUE INIT 1 : %s ,%p\n", (char *)list1 -> content, list1 -> next);
	printf("VALUE INIT 2 : %s ,%p\n", (char *)list2 -> content, list2 -> next);
	printf("VALUE INIT 3 : %s ,%p\n\n", (char *)list3 -> content, list3 -> next);
	ft_lstmap(list1, ft_test, ft_del);
	ft_show(list1);
	free(tab);
	return (0);
}
