#ifndef FT_SLINKEDLIST_H
# define FT_SLINKEDLIST_H

typedef struct s_snode
{
	void			*content;
	struct s_snode	*next;
}	t_snode;

typedef t_snode	t_node;

t_node	*ft_create_node(void *content);
void	ft_insert_node(t_node **head, t_node *prev, t_node *new);
void	ft_remove_node(t_node **head, t_node *prev);
void	ft_iter_node(t_node *head, void (*f)(void *));

#endif
