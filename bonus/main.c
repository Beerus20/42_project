#include "../libft.h"
#include "ft_lstnew_bonus.c"


int	main(void)
{
	t_list	**tab;
	t_list	list3 = {"test3", NULL};
	t_list	list2 = {"test2", &list3};
	t_list	list1 = {"test1", &list2};

	tab = (t_list **)malloc(sizeof(t_list *) * 3);
	tab[0] = &list1;
	tab[1] = &list2;
	tab[2] = &list3;
	printf("RESULT : %s\n", (char *)list.content);
	return (0);
}
