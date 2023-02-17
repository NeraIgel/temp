#ifndef FT_LIST_TYPE_H
# define FT_LIST_TYPE_H

# include <stdlib.h>
# include <stdbool.h>
# include "ft_list.h"

typedef struct s_listType
{
	t_list	*head;
	size_t	size;
}	t_listType;

void	ft_list_create(t_listType *list);
void	ft_list_destroy(t_listType *list);
void	ft_list_clear(t_listType *list);
void	ft_list_error(t_listType *list, const char *errormsg);
size_t	ft_list_size(const t_listType *list);
bool	ft_list_empty(const t_listType *list);
void	ft_list_add(t_listType *list, size_t pos, void *content, size_t n);
void	ft_list_add_front(t_listType *list, void *content, size_t n);
void	ft_list_add_back(t_listType *list, void *content, size_t n);
void	ft_list_delete(t_listType *list, size_t pos);
void	*ft_list_at(t_listType *list, size_t pos);

#endif
