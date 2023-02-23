#include <stdio.h>
#include "ft_stack.h"

int	main(void)
{
	t_stack	*s;

	s = ft_stack_create();
	if (s)
	{
		ft_stack_push(s, (void *)1);
		ft_stack_push(s, (void *)2);
		printf("%d(%d)\n", (int)ft_stack_peek(s), ft_stack_size(s));
		printf("%d(%d)\n", (int)ft_stack_pop(s), ft_stack_size(s));
		printf("%d(%d)\n", (int)ft_stack_pop(s), ft_stack_size(s));
		ft_stack_clear(s);
	}
	return (0);
}
