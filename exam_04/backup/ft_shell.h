#ifndef FT_SHELL_H
# define FT_SHELL_H

# include "ft_queue.h"

typedef enum s_type
{
	TYPE_NONE,
	TYPE_PIPE,
	TYPE_SEMICOLON
}	t_type;

typedef struct s_expr
{
	t_type	type;
	t_queue	*strs;
}	t_expr;

typedef struct s_shell
{
	t_queue	exprs;
	char	**environ;
}	t_shell;

void	ft_shell_init(t_shell *s);
void	ft_shell_destroy(t_shell *s);
void	ft_shell_error(t_shell *s, const char *errmsg);
void	ft_shell_setup(t_shell *s, int argc, char *argv[], char *envp[]);
void	ft_shell_routine(t_shell *s);

void	ft_expr_delone(t_expr *expr);
void	ft_exprs_cleanup(t_queue *exprs);

#endif
