#include "ft_shell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	s;

	if (argc > 1)
	{
		ft_shell_init(&s);
		ft_shell_setup(&s, argc, argv, envp);
		ft_shell_routine(&s);
		ft_shell_destroy(&s);
		system("leaks a.out");
	}
	return (EXIT_SUCCESS);
}
