#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_list.h"

void	ft_list_create(t_list *l)
{
	l->head = malloc(sizeof(__t_list));
	if (!(l->head))
		ft_list_error(l, "list allocation error");
	__ft_lstinit(l->head);
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
	__ft_lstiter(l->head, f);
}

static void	*__ft_node_error(const char *errormsg)
{
	if (errormsg)
		write(STDERR_FILENO, errormsg, strlen(errormsg));
	return (NULL);
}

static __t_list	*__ft_node_make(void *content, size_t n)
{
	__t_list	*new;

	if (!content || !n)
		return (__ft_node_error("list content error"));
	new = __ft_lstnew(NULL);
	if (!new)
		return (__ft_node_error("list allocation error"));
	new->content = malloc(n);
	if (!(new->content))
	{
		free(new);
		return (__ft_node_error("list allocation error"));
	}
	memcpy(new->content, content, n);
	return (new);
}

void	ft_list_push_back(t_list *l, void *content, size_t n)
{
	__t_list	*new;

	new = __ft_node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	__ft_lstadd_back(l->head, new);
	l->size++;
}

void	ft_list_push_front(t_list *l, void *content, size_t n)
{
	__t_list	*new;

	new = __ft_node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	__ft_lstadd_front(l->head, new);
	l->size++;
}

void	ft_list_insert(t_list *l, size_t pos, void *content, size_t n)
{
	size_t		size;
	__t_list	*new;
	__t_list	*prev;

	size = ft_list_size(l);
	if (!(pos < size))
		ft_list_error(l, "list position error");
	new = __ft_node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	if (pos + 1 == size)
		__ft_lstadd_back(l->head, new);
	else if (pos == 0U)
		__ft_lstadd_front(l->head, new);
	else
	{
		prev = __ft_lstat(l->head, pos);
		__ft_lstadd(prev, new);
	}
	l->size++;
}

static void	__ft_content_del(void *content)
{
	free(content);
}

void	ft_list_pop_back(t_list *l)
{
	__t_list	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __ft_lstlast(l->head);
	__ft_lstdelone(node, __ft_content_del);
	l->size--;
}

void	ft_list_pop_front(t_list *l)
{
	__t_list	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __ft_lstfirst(l->head);
	__ft_lstdelone(node, __ft_content_del);
	l->size--;
}

void	ft_list_erase(t_list *l, size_t pos)
{
	size_t		size;
	__t_list	*node;

	size = ft_list_size(l);
	if (!(pos < size))
		ft_list_error(l, "list position error");
	if (pos + 1 == size)
		node = __ft_lstlast(l->head);
	else if (pos == 0U)
		node = __ft_lstfirst(l->head);
	else
		node = __ft_lstat(l->head, pos);
	__ft_lstdelone(node, __ft_content_del);
	l->size--;
}

void	*ft_list_back(t_list *l)
{
	__t_list	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __ft_lstlast(l->head);
	return (node->content);
}

void	*ft_list_front(t_list *l)
{
	__t_list	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = __ft_lstfirst(l->head);
	return (node->content);
}

void	*ft_list_at(t_list *l, size_t pos)
{
	size_t		size;
	__t_list	*node;

	size = ft_list_size(l);
	if (!(pos < size))
		ft_list_error(l, "list position error");
	if (pos + 1 == size)
		node = __ft_lstlast(l->head);
	else if (pos == 0U)
		node = __ft_lstfirst(l->head);
	else
		node = __ft_lstat(l->head, pos);
	return (node->content);
}
