#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stdlib.h>
# include <stdbool.h>
# include "ft_list.h"

typedef struct s_queue
{
	t_list	*head;
	size_t	size;
}	t_queue;

void	ft_queue_create(t_queue *q);
void	ft_queue_destroy(t_queue *q);
void	ft_queue_clear(t_queue *q);
void	ft_queue_error(t_queue *q);
size_t	ft_queue_size(const t_queue *q);
bool	ft_queue_empty(const t_queue *q);
void	ft_queue_push(t_queue *q, void *content, size_t n);
void	ft_queue_pop(t_queue *q);
void	*ft_queue_front(t_queue *q);
void	*ft_queue_back(t_queue *q);

#endif
