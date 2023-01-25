#include <string.h>
#include "ft_shell.h"
#include "ft_utils.h"

static void	ft_error(const char *errmsg)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	ft_dup2(int oldfd, int newfd)
{
	int	fd;

	if (oldfd != newfd)
	{
		fd = dup2(oldfd, newfd);
		close(oldfd);
		if (fd < 0)
			ft_error("error: fatal");
	}
}

static void	ft_tblclear(char ***tbl)
{
	char	**cp;

	if (*tbl)
	{
		cp = *tbl;
		while (*cp)
		{
			free(*cp);
			cp++;
		}
		tbl = NULL;
	}
}

static char	**ft_cmd_create(size_t size)
{
	char	**cmd;
	size_t	i;

	cmd = (char **)malloc(sizeof(char *) * (size + 1));
	if (!cmd)
		return (NULL);
	i = 0;
	while (i <= size)
		cmd[i++] = NULL;
	return (cmd);
}

static char	**ft_commandline_make(t_queue *strs)
{
	const size_t	size = ft_queue_size(strs);
	char			**cmd;
	size_t			i;

	cmd = ft_cmd_create(size);
	if (!cmd)
		return (NULL);
	i = 0;
	while (!ft_queue_empty(strs))
	{
		cmd[i] = ft_strdup((char *)ft_queue_front(strs));
		if (cmd[i] == NULL)
		{
			ft_tblclear(&cmd);
			return (NULL);
		}
		ft_queue_pop(strs);
		++i;
	}
	cmd[size] = NULL;
	return (cmd);
}

static void	ft_execve(char *argv[], char *envp[])
{
	if (execve(argv[0], argv, envp) < 0)
		ft_error("error: cannot execute executable_that_failed");
	exit(127);
}

static void	ft_process_redir(int pipein, int pipeout)
{
	ft_dup2(pipein, STDIN_FILENO);
	ft_dup2(pipeout, STDOUT_FILENO);
}

static void	ft_process_exec(t_queue *strs, char *envp[])
{
	char	**argv;

	if (strs && !ft_queue_empty(strs))
	{
		argv = ft_commandline_make(strs);
		if (!argv)
			ft_error("error: fatal");
		if (!strcmp(argv[0], "cd"))
			ft_execve(argv, envp);
		else
			ft_execve(argv, envp);
	}
	else
		exit(EXIT_SUCCESS);
}

static void	ft_shell_loop_process(t_expr *expr, int prev_pipe, int pipefd[], char *envp[])
{
	close(pipefd[0]);
	ft_process_redir(prev_pipe, pipefd[1]);
	ft_process_exec(expr->strs, envp);
}

static int	ft_shell_last_process(t_expr *expr, int prev_pipe, t_shell *s)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid < 0)
		ft_shell_error(s, "error: fatal");
	if (pid == 0)
	{
		ft_process_redir(prev_pipe, STDOUT_FILENO);
		ft_process_exec(expr->strs, s->environ);
	}
	if (prev_pipe != STDIN_FILENO)
		close(prev_pipe);
	if (waitpid(pid, &stat, 0) < 0)
		ft_shell_error(s, "error: fatal");
	return (WEXITSTATUS(stat));
}

void	ft_shell_routine(t_shell *s)
{
	pid_t	pid;
	int		stat;
	int		pipefd[2];
	int		prev_pipe;
	t_expr	*expr;

	prev_pipe = STDIN_FILENO;
	while (ft_queue_size(&(s->exprs)) > 1)
	{
		expr = (t_expr *)ft_queue_front(&(s->exprs));
		if (pipe(pipefd) < 0)
			ft_shell_error(s, "error: fatal");
		pid = fork();
		if (pid < 0)
			ft_shell_error(s, "error: fatal");
		if (pid == 0)
			ft_shell_loop_process(expr, prev_pipe, pipefd, s->environ);
		close(pipefd[1]);
		if (prev_pipe != STDIN_FILENO)
			close(prev_pipe);
		prev_pipe = pipefd[0];
		if (waitpid(pid, &stat, 0) < 0)
			ft_shell_error(s, "error: fatal");
		ft_expr_delone(expr);
		ft_queue_pop(&(s->exprs));
	}
	expr = (t_expr *)ft_queue_front(&(s->exprs));
	ft_shell_last_process(expr, prev_pipe, s);
}
