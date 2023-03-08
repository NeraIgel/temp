#pragma once
#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stddef.h>
# include <stdbool.h>
# include "__list.h"

typedef struct s_queue
{
	__t_node	*head;
	size_t		size;
}	t_queue;

void	ft_queue_create(t_queue *q);
void	ft_queue_destroy(t_queue *q);
void	ft_queue_clear(t_queue *q);
void	ft_queue_error(t_queue *q, const char *errormsg);
size_t	ft_queue_size(const t_queue *q);
bool	ft_queue_empty(const t_queue *q);
void	ft_queue_push(t_queue *q, void *content, size_t n);
void	ft_queue_pop(t_queue *q);
void	*ft_queue_back(t_queue *q);
void	*ft_queue_front(t_queue *q);

#endif
