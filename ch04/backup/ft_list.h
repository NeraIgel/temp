#ifndef FT_LIST_H
# define FT_LIST_H

//# include "ft_slinkedlist.h"
# include "ft_dlinkedlist.h"
# include <stdbool.h>

typedef struct s_list
{
	t_node	*head;
	int		size;
}	t_list;

t_list	*ft_lstcreate(void);
void	ft_lstinit(t_list *lst);
void	ft_lstclear(t_list **lst);

int		ft_lstsize(t_list *lst);
bool	ft_lstisempty(t_list *lst);

void	ft_lstadd_last(t_list *lst, void *content);
void	ft_lstadd_first(t_list *lst, void *content);
void	ft_lstadd(t_list *lst, int pos, void *content);

void	ft_lstdel_last(t_list *lst);
void	ft_lstdel_first(t_list *lst);
void	ft_lstdel(t_list *lst, int pos);

t_node	*ft_lstget_last(t_list *lst);
t_node	*ft_lstget_first(t_list *lst);
t_node	*ft_lstget(t_list *lst, int pos);

void	ft_lstset_last(t_list *lst, void *content);
void	ft_lstset_first(t_list *lst, void *content);
void	ft_lstset(t_list *lst, int pos, void *content);

void	ft_lstiter(t_list *lst, void (*f)(void *));

#endif
