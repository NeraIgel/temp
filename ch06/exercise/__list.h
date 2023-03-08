#pragma once
#ifndef __LIST_H
# define __LIST_H

# include <stddef.h>

typedef struct __s_node
{
	void			*content;
	struct __s_node	*prev;
	struct __s_node	*next;
}	__t_node;

void		__lstinit(__t_node *head);
__t_node	*__lstnew(void *content);
__t_node	*__lstlast(const __t_node *head);
__t_node	*__lstfirst(const __t_node *head);
__t_node	*__lstat(const __t_node *head, size_t pos);
void		__lstadd(__t_node *prev, __t_node *new);
void		__lstadd_back(__t_node *head, __t_node *new);
void		__lstadd_front(__t_node *head, __t_node *new);
void		__lstdelone(__t_node *node, void (*del)(void *));
void		__lstclear(__t_node *head, void (*del)(void *));
void		__lstiter(const __t_node *head, void (*f)(void *));

#endif
