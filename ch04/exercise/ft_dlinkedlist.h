#ifndef FT_DLINKEDLIST_H
# define FT_DLINKEDLIST_H

typedef struct s_dnode
{
	void			*content;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

typedef t_dnode	t_node;

t_node	*ft_create_node(void *content);
void	ft_insert_node(t_node **head, t_node *prev, t_node *new);
void	ft_remove_node(t_node **head, t_node *prev);
void	ft_iter_node(t_node *head, void (*f)(void *));

#endif
