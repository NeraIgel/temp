#include <string.h>
#include "ft_list.h"

void	ft_node_init(t_node *head)
{
	head->content = NULL;
	head->prev = head;
	head->next = head;
}

t_node	*ft_node_new(void *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_node	*ft_node_last(const t_node *head)
{
	if (head == head->prev)
		return (NULL);
	return (head->prev);
}

t_node	*ft_node_first(const t_node *head)
{
	if (head == head->next)
		return (NULL);
	return (head->next);
}

t_node	*ft_node_at(const t_node *head, size_t pos)
{
	t_node	*node;

	if (head == head->next)
		return (NULL);
	node = head->next;
	while (node != head && pos)
	{
		node = node->next;
		--pos;
	}
	return (pos > 0 ? NULL : node);
}

void	ft_node_add(t_node *prev, t_node *new)
{
	if (new)
	{
		new->prev = prev;
		new->next = prev->next;
		prev->next->prev = new;
		prev->next = new;
	}
}

void	ft_node_add_back(t_node *head, t_node *new)
{
	t_node	*tail;

	tail = head->prev;
	if (new)
	{
		new->prev = tail;
		new->next = tail->next;
		tail->next->prev = new;
		tail->next = new;
	}
}

void	ft_node_add_front(t_node *head, t_node *new)
{
	if (new)
	{
		new->prev = head;
		new->next = head->next;
		head->next->prev = new;
		head->next = new;
	}
}

void	ft_node_delone(t_node *node, void (*del)(void *))
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

void	ft_node_clear(t_node *head, void (*del)(void *))
{
	t_node	*node;
	t_node	*next;

	node = head->next;
	while (node != head)
	{
		next = node->next;
		ft_node_delone(node, del);
		node = next;
	}
}

void	ft_node_iter(t_node *head, void (*f)(void *))
{
	t_node	*node;

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

// ----------

void	ft_list_create(t_list *l)
{
	l->head = malloc(sizeof(t_node));
	if (!(l->head))
		ft_list_error(l, "list allocation error");
	ft_node_init(l->head);
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
	{
		write(STDERR_FILENO, errormsg, strlen(errormsg));
		write(STDERR_FILENO, "\n", 1);
	}
	if (l)
		ft_list_destroy(l);
	exit(EXIT_FAILURE);
}

size_t	ft_list_size(const t_list *l)
{
	return (l->size);
}

bool	ft_list_empty(const t_list *l)
{
	return (0U == l->size);
}

void	ft_list_iter(const t_list *l, void (*f)(void *))
{
	ft_node_iter(l->head, f);
}

static t_node	*ft_list_node_make(void *content, size_t n)
{
	t_node	*new;

	if (!content || !n)
		ft_list_error(NULL, "list content error");
	new = ft_node_new(NULL);
	if (!new)
		ft_list_error(NULL, "list allocation error");
	new->content = malloc(n);
	if (!(new->content))
	{
		free(new);
		ft_list_error(NULL, "list allocation error");
	}
	memcpy(new->content, content, n);
}

void	ft_list_push_back(t_list *l, void *content, size_t n)
{
	t_node	*new;

	new = ft_list_node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	ft_node_add_back(l->head, new);
	l->size++;
}

void	ft_list_push_front(t_list *l, void *content, size_t n)
{
	t_node	*new;

	new = ft_list_node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	ft_node_add_front(l->head, new);
	l->size++;
}

void	ft_list_insert(t_list *l, size_t pos, void *content, size_t n)
{
	t_node	*new;
	t_node	*prev;

	if (!(pos < ft_list_size(l)))
		ft_list_error(l, "list position error");
	new = ft_list_node_make(content, n);
	if (!new)
		ft_list_error(l, NULL);
	if (pos == 0U)
		ft_node_add_front(l->head, new);
	else if (pos + 1 == ft_list_size(l))
		ft_node_add_back(l->head, new);
	else
	{
		prev = ft_node_at(l->head, pos);
		ft_node_add(prev, new);		// review
	}
	l->size++;
}

static void	ft_content_del(void *content)
{
	free(content);
}

void	ft_list_pop_back(t_list *l)
{
	t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = ft_node_last(l->head);
	ft_node_delone(node, ft_content_del);
	l->size--;
}

void	ft_list_pop_front(t_list *l)
{
	t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = ft_node_first(l->head);
	ft_node_delone(node, ft_content_del);
	l->size--;
}

void	ft_list_erase(t_list *l, size_t pos)
{
	t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	if (!(pos < ft_list_size(l)))
		ft_list_error(l, "list position error");
	node = ft_node_at(l->head, pos);
	ft_node_delone(node, ft_content_del);
	l->size--;
}

void	*ft_list_back(t_list *l)
{
	t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = ft_node_last(l->head);
	return (node->content);
}

void	*ft_list_front(t_list *l)
{
	t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	node = ft_node_first(l->head);
	return (node->content);
}

void	*ft_list_at(t_list *l, size_t pos)
{
	t_node	*node;

	if (ft_list_empty(l))
		ft_list_error(l, "list empty");
	if (!(pos < ft_list_size(l)))
		ft_list_error(l, "list position error");
	node = ft_node_at(l->head, pos);
	return (node->content);
}
