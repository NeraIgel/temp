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
t_list	*ft_lstfirst(const t_list *head);
t_list	*ft_lstlast(const t_list *head);
t_list	*ft_lstat(const t_list *head, size_t pos);
void	ft_lstadd_front(t_list *head, t_list *new);
void	ft_lstadd_back(t_list *head, t_list *new);
void	ft_lstadd(t_list *head, t_list *prev, t_list *new);
void	ft_lstdelone(t_list *node, void (*del)(void *));
void	ft_lstclear(t_list *head, void (*del)(void *));

#endif
