#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdbool.h>

typedef struct s_stacknode
{
	void				*content;
	struct s_stacknode	*next;
}	t_stacknode;

typedef struct s_stack
{
	t_stacknode	*top;
	int			size;
}	t_stack;

t_stack	*ft_stack_create(void);
bool	ft_stack_init(t_stack *s);
void	ft_stack_clear(t_stack *s);
int		ft_stack_size(t_stack *s);
bool	ft_stack_isempty(t_stack *s);
void	ft_stack_push(t_stack *s, void *content);
void	*ft_stack_pop(t_stack *s);
void	*ft_stack_peek(t_stack *s);

#endif
