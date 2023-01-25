#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	ft_lstinit(t_list *head);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstfirst(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list *head, t_list *new);
void	ft_lstdelone(t_list *node, void (*del)(void *));
void	ft_lstclear(t_list *head, void (*del)(void *));

#endif
