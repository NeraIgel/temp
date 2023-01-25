#include "ft_queue.h"
#include "ft_utils.h"

void	ft_queue_create(t_queue *q)
{
	q->head = malloc(sizeof(t_list));
	if (!(q->head))
		ft_queue_error(q);
	ft_lstinit(q->head);
	q->size = 0;
}

void	ft_queue_destroy(t_queue *q)
{
	if (q->head)
	{
		ft_queue_clear(q);
		free(q->head);
		q->head = NULL;
	}
}

void	ft_queue_clear(t_queue *q)
{
	while (!ft_queue_empty(q))
		ft_queue_pop(q);
}

void	ft_queue_error(t_queue *q)
{
	ft_putendl_fd("error: fatal", STDERR_FILENO);
	ft_queue_destroy(q);
	exit(EXIT_FAILURE);
}

size_t	ft_queue_size(const t_queue *q)
{
	return (q->size);
}

bool	ft_queue_empty(const t_queue *q)
{
	return (0 == q->size);
}

void	ft_queue_push(t_queue *q, void *content, size_t n)
{
	t_list	*node;

	if (!content || !n)
		ft_queue_error(q);
	node = ft_lstnew(content);
	if (!node)
		ft_queue_error(q);
	node->content = malloc(n);
	if (!(node->content))
	{
		free(node);
		ft_queue_error(q);
	}
	ft_memcpy(node->content, content, n);
	ft_lstadd_back(q->head, node);
	q->size++;
}

static void	ft_content_del(void *content)
{
	free(content);
}

void	ft_queue_pop(t_queue *q)
{
	t_list	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q);
	node = ft_lstfirst(q->head);
	ft_lstdelone(node, ft_content_del);
	q->size--;
}

void	*ft_queue_front(t_queue *q)
{
	t_list	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q);
	node = ft_lstfirst(q->head);
	return (node->content);
}

void	*ft_queue_back(t_queue *q)
{
	t_list	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q);
	node = ft_lstlast(q->head);
	return (node->content);
}
