#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	size_t	size;
}	t_list;

void	ft_node_init(t_node *head);
t_node	*ft_node_new(void *content);
t_node	*ft_node_last(const t_node *head);
t_node	*ft_node_first(const t_node *head);
t_node	*ft_node_at(const t_node *head, size_t pos);
void	ft_node_add(t_node *prev, t_node *new);
void	ft_node_add_back(t_node *head, t_node *new);
void	ft_node_add_front(t_node *head, t_node *new);
void	ft_node_delone(t_node *node, void (*del)(void *));
void	ft_node_clear(t_node *head, void (*del)(void *));
void	ft_node_iter(t_node *head, void (*f)(void *));

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
