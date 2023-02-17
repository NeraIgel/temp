#include <stdio.h>
#include "ft_listType.h"

int	main(void)
{
	t_listType	list;

	ft_list_create(&list);
	ft_list_add_back(&list, "a", 2);
	printf("%zd / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0));
	ft_list_add_back(&list, "b", 2);
	printf("%zd / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0));
	ft_list_add_front(&list, "1", 2);
	printf("%zd / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0));
	ft_list_add_front(&list, 1, "2", 2);
	printf("%zd / %s / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0), (char *)ft_list_at(&list, 1));
	ft_list_delete(&list, 0);
	printf("%zd / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0));
	ft_list_delete(&list, 0);
	printf("%zd / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0));
	ft_list_delete(&list, 0);
	printf("%zd / %s\n", ft_list_size(&list), (char *)ft_list_at(&list, 0));
	ft_list_delete(&list, 0);
	printf("%zd\n", ft_list_size(&list);
	ft_list_destroy(&list);
	return (EXIT_SUCCESS);
}
