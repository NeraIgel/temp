#include <stdlib.h>
#include "__list.h"

void	__lstinit(__t_node *head)
{
	head->content = NULL;
	head->prev = head;
	head->next = head;
}

__t_node	*__lstnew(void *content)
{
	__t_node	*new;

	new = malloc(sizeof(__t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

__t_node	*__lstlast(const __t_node *head)
{
	if (head == head->prev)
		return (NULL);
	return (head->prev);
}

__t_node	*__lstfirst(const __t_node *head)
{
	if (head == head->next)
		return (NULL);
	return (head->next);
}

__t_node	*__lstat(const __t_node *head, size_t pos)
{
	__t_node	*node;

	node = head->next;
	while (node != head && pos)
	{
		node = node->next;
		--pos;
	}
	return (head == node || pos ? NULL : node);
}

void	__lstadd(__t_node *prev, __t_node *new)
{
	if (prev && new)
	{
		new->prev = prev;
		new->next = prev->next;
		prev->next->prev = new;
		prev->next = new;
	}
}

void	__lstadd_back(__t_node *head, __t_node *new)
{
	__t_node	*tail;

	tail = head->prev;
	if (new)
	{
		new->prev = tail;
		new->next = tail->next;
		tail->next->prev = new;
		tail->next = new;
	}
}

void	__lstadd_front(__t_node *head, __t_node *new)
{
	if (new)
	{
		new->prev = head;
		new->next = head->next;
		head->next->prev = new;
		head->next = new;
	}
}

void	__lstdelone(__t_node *node, void (*del)(void *))
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

void	__lstclear(__t_node *head, void (*del)(void *))
{
	__t_node	*node;
	__t_node	*next;

	node = head->next;
	while (node != head)
	{
		next = node->next;
		__lstdelone(node, del);
		node = next;
	}
}

void	__lstiter(const __t_node *head, void (*f)(void *))
{
	__t_node	*node;

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
