#include "ft_slinkedlist.h"
#include <stdlib.h>

t_node	*ft_create_node(void *content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_insert_node(t_node **head, t_node *prev, t_node *new)
{
	if (!(*head))
	{
		*head = new;
	}
	else if (!prev)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = prev->next;
		prev->next = new;
	}
}

void	ft_remove_node(t_node **head, t_node *prev)
{
	t_node	*removed;

	if (!prev)
	{
		removed = *head;
		*head = removed->next;
	}
	else
	{
		removed = prev->next;
		prev->next = removed->next;
	}
	free(removed);
	removed = NULL;
}

void	ft_iter_node(t_node *head, void (*f)(void *))
{
	t_node	*node;

	node = head;
	while (node)
	{
		f(node->content);
		node = node->next;
	}
}
