#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

int	main(void)
{
	t_list	l;

	ft_list_create(&l);
	ft_list_push_back(&l, "a", 2);	printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_push_back(&l, "b", 2);	printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_push_front(&l, "2", 2);	printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_push_front(&l, "1", 2);	printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_pop_front(&l);			printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_pop_front(&l);			printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_pop_front(&l);			printf("%zd / %s\n", ft_list_size(&l), (char *)ft_list_at(&l, 0));
	ft_list_pop_front(&l);			printf("%zd\n", ft_list_size(&l));
	ft_list_destroy(&l);
	//system("leaks a.out");
	return (EXIT_SUCCESS);
}
