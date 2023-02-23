#pragma once
#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>
# include <stdbool.h>
# include "__ft_list.h"

typedef struct s_list
{
	__t_list	*head;
	size_t		size;
}	t_list;

void	ft_list_create(t_list *l);
void	ft_list_destroy(t_list *l);
void	ft_list_clear(t_list *l);
void	ft_list_error(t_list *l, const char *errormsg);
size_t	ft_list_size(const t_list *l);
bool	ft_list_empty(const t_list *l);
void	ft_list_iter(const t_list *l, void (*f)(void *));
void	ft_list_push_back(t_list *l, void *content, size_t n);
void	ft_list_push_front(t_list *l, void *content, size_t n);
void	ft_list_insert(t_list *l, size_t pos, void *content, size_t n);
void	ft_list_pop_back(t_list *l);
void	ft_list_pop_front(t_list *l);
void	ft_list_erase(t_list *l, size_t pos);
void	*ft_list_back(t_list *l);
void	*ft_list_front(t_list *l);
void	*ft_list_at(t_list *l, size_t pos);

#endif
