#include "ft_shell.h"

void	ft_expr_delone(t_expr *expr)
{
	if (expr->strs)
	{
		ft_queue_destroy(expr->strs);
		free(expr->strs);
		expr->strs = NULL;
	}
}

void	ft_exprs_cleanup(t_queue *exprs)
{
	t_expr	*expr;

	while (!ft_queue_empty(exprs))
	{
		expr = (t_expr *)ft_queue_front(exprs);
		ft_expr_delone(expr);
		ft_queue_pop(exprs);
	}
}
