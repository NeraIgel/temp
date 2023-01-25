#include "ft_shell.h"
#include "ft_utils.h"

void	ft_shell_init(t_shell *s)
{
	ft_queue_create(&(s->exprs));
	s->environ = NULL;
}

void	ft_shell_destroy(t_shell *s)
{
	ft_exprs_cleanup(&(s->exprs));
	ft_queue_destroy(&(s->exprs));
	s->environ = NULL;
}

void	ft_shell_error(t_shell *s, const char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	ft_shell_destroy(s);
	exit(EXIT_FAILURE);
}
