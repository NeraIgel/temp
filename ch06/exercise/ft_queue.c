#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_queue.h"

void	ft_queue_create(t_queue *q)
{
	q->head = malloc(sizeof(__t_node));
	if (!(q->head))
		ft_queue_error(q, "queue allocation error");
	__lstinit(q->head);
	q->size = 0U;
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

void	ft_queue_error(t_queue *q, const char *errormsg)
{
	if (errormsg)
		write(STDERR_FILENO, errormsg, strlen(errormsg));
	ft_queue_destroy(q);
	exit(EXIT_FAILURE);
}

size_t	ft_queue_size(const t_queue *q)
{
	return (q->size);
}

bool	ft_queue_empty(const t_queue *q)
{
	return (0U == q->size);
}

void	ft_queue_push(t_queue *q, const void *content, size_t n)
{
	__t_node	*new;

	if (!content || !n)
		ft_queue_error(q, "queue content error");
	new = __lstnew(NULL);
	if (!new)
		ft_queue_error(q, "queue allocation error");
	new->content = malloc(n);
	if (!(new->content))
	{
		free(new);
		ft_queue_error(q, "queue allocation error");
	}
	memcpy(new->content, content, n);
	__lstadd_back(q->head, new);
	q->size++;
}

static void	__content_del(void *content)
{
	free(content);
}

void	ft_queue_pop(t_queue *q)
{
	__t_node	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q, "queue empty");
	node = __lstfirst(q->head);
	__lstdelone(node, __content_del);
	q->size--;
}

void	*ft_queue_back(t_queue *q)
{
	__t_node	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q, "queue empty");
	node = __lstlast(q->head);
	return (node->content);
}

void	*ft_queue_front(t_queue *q)
{
	__t_node	*node;

	if (ft_queue_empty(q))
		ft_queue_error(q, "queue empty");
	node = __lstfirst(q->head);
	return (node->content);
}
