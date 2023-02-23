#include <stdlib.h>
#include "__ft_list.h"

void	__ft_lstinit(__t_list *head)
{
	head->content = NULL;
	head->prev = head;
	head->next = head;
}

__t_list	*__ft_lstnew(void *content)
{
	__t_list	*new;

	new = malloc(sizeof(__t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

__t_list	*__ft_lstlast(const __t_list *head)
{
	if (head == head->prev)
		return (NULL);
	return (head->prev);
}

__t_list	*__ft_lstfirst(const __t_list *head)
{
	if (head == head->next)
		return (NULL);
	return (head->next);
}

__t_list	*__ft_lstat(const __t_list *head, size_t pos)
{
	__t_list	*node;

	node = head->next;
	while (node != head && pos)
	{
		node = node->next;
		--pos;
	}
	return (head == node ? NULL : node);
}

void	__ft_lstadd(__t_list *prev, __t_list *new)
{
	if (prev && new)
	{
		new->prev = prev;
		new->next = prev->next;
		prev->next->prev = new;
		prev->next = new;
	}
}

void	__ft_lstadd_back(__t_list *head, __t_list *new)
{
	__t_list	*tail;

	tail = head->prev;
	if (new)
	{
		new->prev = tail;
		new->next = tail->next;
		tail->next->prev = new;
		tail->next = new;
	}
}

void	__ft_lstadd_front(__t_list *head, __t_list *new)
{
	if (new)
	{
		new->prev = head;
		new->next = head->next;
		head->next->prev = new;
		head->next = new;
	}
}

void	__ft_lstdelone(__t_list *node, void (*del)(void *))
{
	if (node)
	{
		if (del)
			del(node->content);
		node->next->prev = node->prev;
		node->prev->next = node->next;
		free(node);
	}
}

void	__ft_lstclear(__t_list *head, void (*del)(void *))
{
	__t_list	*node;
	__t_list	*next;

	node = head->next;
	while (node != head)
	{
		next = node->next;
		__ft_lstdelone(node, del);
		node = next;
	}
}

void	__ft_lstiter(__t_list *head, void (*f)(void *))
{
	__t_list	*node;

	if (f)
	{
		node = head->next;
		while (node != head)
		{
			f(node->content);
			node = node->next;
		}
	}
}
