#include <string.h>
#include <unistd.h>
#include "ft_listType.h"

void	ft_list_create(t_listType *list)
{
	list->head = malloc(sizeof(t_list));
	if (!(list->head))
		ft_list_error(list, "list allocation error");
	ft_listinit(list->head);
	list->size = 0Ul
}

void	ft_list_destroy(t_listType *list)
{
	if (list->head)
	{
		ft_list_clear(list);
		free(list->head);
		list->head = NULL;
	}
}

void	ft_list_clear(t_listType *list)
{
	while (!ft_list_empty(list))
		ft_list_delete_front(list);
}

void	ft_list_error(t_listType *list, const char *errormsg)
{
	if (errormsg)
	{
		write(STDERR_FILENO, errormsg);
		write(STDERR_FILENO, "\n", 1);
	}
	ft_list_destroy(list);
	exit(EXIT_FAILURE);
}

size_t	ft_list_size(const t_listType *list)
{
	return (list->size);
}

bool	ft_list_empty(const t_listType *list)
{
	return (0U == list->size);
}

static t_list	*ft_list_node_create(t_listType *list, void *content, size_t n)
{
	t_list	*new;

	if (!content || !n)
		ft_list_error(list, "list content error");
	new = ft_lstnew(NULL);
	if (!new)
		ft_list_error(list, "list allocation error");
	new->content = malloc(n);
	if (!(new->content))
	{
		free(new);
		ft_list_error(list, "list allocation error");
	}
	memcpy(new->content, content, n);
	return (new);
}

void	ft_list_add(t_listType *list, size_t pos, void *content, size_t n)
{
	t_list	*new;
	t_list	*prev;

	if (!(pos < ft_list_size(list)))
		ft_list_error(list, "list position error");
	new = ft_list_node_create(list, content, n);
	if (pos == 0U)
		ft_lstadd_front(list->head, new);
	else if (pos + 1 == ft_list_size(list))
		ft_lstadd_back(list->head, new);
	else
	{
		prev = ft_lstat(list->head, pos - 1);
		ft_lstadd(list->head, prev, new);
	}
	list->size++;
}

void	ft_list_add_front(t_listType *list, void *content, size_t n)
{
	t_list	*new;

	new = ft_list_node_create(list, content, n);
	ft_lstadd_front(list->head, new);
	list->size++;
}

void	ft_list_add_back(t_listType *list, void *content, size_t n)
{
	t_list	*new;

	new = ft_list_node_create(list, content, n);
	ft_lstadd_back(list->head, new);
	list->size++;
}

static void	ft_content_del(void *content)
{
	free(content);
}

void	ft_list_delete(t_listType *list, size_t pos)
{
	t_list	*node;

	if (!(pos < ft_list_size(list)))
		ft_list_error(list, "list position error");
	node = ft_lstat(list->head, pos);
	ft_lstdelone(node, ft_content_del);
	list->size--;
}

void	*ft_list_at(t_listType *list, size_t pos)
{
	t_list	*node;

	if (!(pos < ft_list_size(list)))
		ft_list_error(list, "list position error");
	node = ft_lstat(list->head, pos);
	return (node->content);
}
