#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_display(void *content)
{
	printf("%d\n", (int)content);
}

static void	do_test1(void)
{
	t_node	*head;

	head = NULL;
	ft_insert_node(&head, NULL, ft_create_node((void *)1));
	ft_insert_node(&head, NULL, ft_create_node((void *)2));
	ft_insert_node(&head, NULL, ft_create_node((void *)3));
	ft_iter_node(head, ft_display);
	ft_remove_node(&head, NULL);
	ft_remove_node(&head, NULL);
	ft_remove_node(&head, NULL);
	printf("\n");
}

static void	do_test2(void)
{
	t_list	*lst;

	lst = ft_lstcreate();
	ft_lstadd_first(lst, (void *)10);
	ft_lstadd_first(lst, (void *)20);
	ft_lstadd_first(lst, (void *)30);
	ft_lstiter(lst, ft_display);
	ft_lstset_first(lst, (void *)3);
	ft_lstiter(lst, ft_display);
	ft_lstclear(&lst);
	printf("\n");
	lst = ft_lstcreate();
	ft_lstadd_last(lst, (void *)10);
	ft_lstadd_last(lst, (void *)20);
	ft_lstadd_last(lst, (void *)30);
	ft_lstiter(lst, ft_display);
	ft_lstset_last(lst, (void *)3);
	ft_lstiter(lst, ft_display);
	ft_lstdel_last(lst);
	ft_lstdel_last(lst);
	ft_lstdel_last(lst);
	ft_lstclear(&lst);
}

int	main(void)
{
	do_test1();
	do_test2();
	return (0);
}
