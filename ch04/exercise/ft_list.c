#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_list.h"

void	ft_list_create(t_list *l)
{
	l->head = malloc(sizeof(__t_node));
	if (!(l->head))
		ft_list_error(l, "list allocation error");
	__lstinit(l->head);
	l->size = 0U;
}

void	ft_list_destroy(t_list *l)
{
	if (l->head)
	{
		ft_list_clear(l);
		free(l->head);
		l->head = NULL;
	}
}

void	ft_list_clear(t_list *l)
{
	while (!ft_list_empty(l))
		ft_list_pop_front(l);
}

void	ft_list_error(t_list *l, const char *errormsg)
{
	if (errormsg)
		write(STDERR_FILENO, errormsg, strlen(errormsg));
	ft_list_destroy(l);
	exit(EXIT_FAILURE);
}

size_t	ft_list_size(const t_list *l)
{
	return (l->size);
}

bool	ft_list_empty(const t_list *l)
{
	return (l->size == 0U);
}

void	ft_list_iter(const t_list *l, void (*f)(void *))
{
	__lstiter(l->head, f);
}

static void	*__node_error(const char *errormsg)
{
	if (errormsg)
		write(STDERR_FILENO, errormsg, strlen(errormsg));
	return (NULL);
}

static __t_node	*__node_make(void *content, size_t n)
{
	__t_node	*new;

	if (!content || !n)
		return (__node_error("list content error"));
	new = __lstnew(NULL);
	if (!new)
		return (__node_error("list allocation error"));
	new->content = malloc(n);
	if (!(new->content))
	{
		free(new);
		return (__node_error("list allocation error"));
	}
	memcpy(new->content, content, n);
	return (new);
}

void	ft_list_push_back(t_list *l, void *content, size_t n)
{
	__t_node	*new;

	new = __node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	__lstadd_back(l->head, new);
	l->size++;
}

void	ft_list_push_front(t_list *l, void *content, size_t n)
{
	__t_node	*new;

	new = __node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	__lstadd_front(l->head, new);
	l->size++;
}

void	ft_list_insert(t_list *l, size_t pos, void *content, size_t n)
{
	size_t		size;
	__t_node	*new;
	__t_node	*prev;

	size = ft_list_size(l);
	if (!(pos < size))
		ft_list_error(l, "list position error");
	new = __node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	if (pos + 1 == size)
		__lstadd_back(l->head, new);
	else if (pos == 0U)
		__lstadd_front(l->head, new);
	else
	{
		prev = __lstat(l->head, pos - 1);
		__lstadd(prev, new);
	}
	l->size++;
}

static void	__content_del(void *content)
{
	free(content);
}

void	ft_list_pop_back(t_list *l)
{
	__t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __lstlast(l->head);
	__lstdelone(node, __content_del);
	l->size--;
}

void	ft_list_pop_front(t_list *l)
{
	__t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __lstfirst(l->head);
	__lstdelone(node, __content_del);
	l->size--;
}

void	ft_list_erase(t_list *l, size_t pos)
{
	size_t		size;
	__t_node	*node;

	size = ft_list_size(l);
	if (!(pos < size))
		ft_list_error(l, "list position error");
	if (pos + 1 == size)
		node = __lstlast(l->head);
	else if (pos == 0U)
		node = __lstfirst(l->head);
	else
		node = __lstat(l->head, pos);
	__lstdelone(node, __content_del);
	l->size--;
}

void	*ft_list_back(t_list *l)
{
	__t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __lstlast(l->head);
	return (node->content);
}

void	*ft_list_front(t_list *l)
{
	__t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __lstfirst(l->head);
	return (node->content);
}

void	*ft_list_at(t_list *l, size_t pos)
{
	size_t		size;
	__t_node	*node;

	size = ft_list_size(l);
	if (!(pos < size))
		ft_list_error(l, "list position error");
	if (pos + 1 == size)
		node = __lstlast(l->head);
	else if (pos == 0U)
		node = __lstfirst(l->head);
	else
		node = __lstat(l->head, pos);
	return (node->content);
}
