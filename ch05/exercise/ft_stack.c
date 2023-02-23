#include <stdlib.h>
#include "ft_stack.h"

t_stack	*ft_stack_create(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	if (!ft_stack_init(new))
		return (NULL);
	return (new);
}

bool	ft_stack_init(t_stack *s)
{
	t_stacknode	*head;

	head = (t_stacknode *)malloc(sizeof(t_stacknode));
	if (!head)
		return (false);
	head->content = NULL;
	head->next = NULL;
	s->top = head;
	s->size = 0;
	return (true);
}

void	ft_stack_clear(t_stack *s)
{
	while (ft_stack_pop(s))
		;
	free(s->top);
	free(s);
}

int	ft_stack_size(t_stack *s)
{
	return (s->size);
}

bool	ft_stack_isempty(t_stack *s)
{
	return (s->top->next == NULL);
}

void	ft_stack_push(t_stack *s, void *content)
{
	t_stacknode	*new;

	new = (t_stacknode *)malloc(sizeof(t_stacknode));
	if (!new)
		return ;
	new->content = content;
	new->next = s->top->next;
	s->top->next = new;
	s->size++;
}

void	*ft_stack_pop(t_stack *s)
{
	t_stacknode	*node;
	void		*content;

	if (ft_stack_isempty(s))
		return (NULL);
	node = s->top->next;
	content = node->content;
	s->top->next = node->next;
	s->size--;
	free(node);
	return (content);
}

void	*ft_stack_peek(t_stack *s)
{
	t_stacknode	*node;

	if (ft_stack_isempty(s))
		return (NULL);
	node = s->top->next;
	return (node->content);
}
