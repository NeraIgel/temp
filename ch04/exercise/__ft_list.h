#pragma once
#ifndef __FT_LIST_H
# define __FT_LIST_H

# include <stddef.h>

typedef struct __s_list
{
	void			*content;
	struct __s_list	*prev;
	struct __s_list	*next;
}	__t_list;

void		__ft_lstinit(__t_list *head);
__t_list	*__ft_lstnew(void *content);
__t_list	*__ft_lstlast(const __t_list *head);
__t_list	*__ft_lstfirst(const __t_list *head);
__t_list	*__ft_lstat(const __t_list *head, size_t pos);
void		__ft_lstadd(__t_list *prev, __t_list *new);
void		__ft_lstadd_back(__t_list *head, __t_list *new);
void		__ft_lstadd_front(__t_list *head, __t_list *new);
void		__ft_lstdelone(__t_list *node, void (*del)(void *));
void		__ft_lstclear(__t_list *head, void (*del)(void *));
void		__ft_lstiter(__t_list *head, void (*f)(void *));

#endif
