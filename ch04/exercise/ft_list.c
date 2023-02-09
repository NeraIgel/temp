#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_lstcreate(void)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	ft_lstinit(lst);
	return (lst);
}

void	ft_lstinit(t_list *lst)
{
	if (lst)
	{
		lst->head = NULL;
		lst->size = 0;
	}
}

void	ft_lstclear(t_list **lst)
{
	int		i;

	for (i = 0; i < ft_lstsize(*lst); i++)
		ft_lstdel(*lst, i);
	free(*lst);
	*lst = NULL;
}

// --------------------------------

int	ft_lstsize(t_list *lst)
{
	return (lst ? lst->size : -1);
}

bool	ft_lstisempty(t_list *lst)
{
	return (lst ? !(lst->head) : true);
}

// --------------------------------

void	ft_lstadd_last(t_list *lst, void *content)
{
	ft_lstadd(lst, ft_lstsize(lst), content);
}

void	ft_lstadd_first(t_list *lst, void *content)
{
	ft_lstadd(lst, 0, content);
}

void	ft_lstadd(t_list *lst, int pos, void *content)
{
	t_node	*new;

	if (!lst || pos < 0 || pos > lst->size)
		return ;
	new = ft_create_node(content);
	if (!new)
		return ;
	ft_insert_node(&(lst->head), ft_lstget(lst, pos - 1), new);
	(lst->size)++;
}

// --------------------------------

void	ft_lstdel_last(t_list *lst)
{
	ft_lstdel(lst, ft_lstsize(lst) - 1);
}

void	ft_lstdel_first(t_list *lst)
{
	ft_lstdel(lst, 0);
}

void	ft_lstdel(t_list *lst, int pos)
{
	if (ft_lstisempty(lst) || pos < 0 || pos > lst->size)
		return ;
	ft_remove_node(&(lst->head), ft_lstget(lst, pos - 1));
	(lst->size)--;
}

// --------------------------------

t_node	*ft_lstget_last(t_list *lst)
{
	return (ft_lstget(lst, ft_lstsize(lst) - 1));
}

t_node	*ft_lstget_first(t_list *lst)
{
	return (ft_lstget(lst, 0));
}

t_node	*ft_lstget(t_list *lst, int pos)
{
	t_node	*node;
	int		i;

	if (ft_lstisempty(lst) || pos < 0 || pos > lst->size)
		return (NULL);
	for (node = lst->head, i = 0; i < pos; i++)
		node = node->next;
	return (node);
}

// --------------------------------

void	ft_lstset_last(t_list *lst, void *content)
{
	ft_lstset(lst, ft_lstsize(lst) - 1, content);
}

void	ft_lstset_first(t_list *lst, void *content)
{
	ft_lstset(lst, 0, content);
}

void	ft_lstset(t_list *lst, int pos, void *content)
{
	t_node	*node;

	node = ft_lstget(lst, pos);
	if (!node)
		return ;
	node->content = content;
}

// --------------------------------

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
		ft_iter_node(lst->head, f);
}
