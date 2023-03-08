#include <stdio.h>
#include <stdlib.h>
#include "ft_queue.h"

int	main(void)
{
	t_queue	q;

	ft_queue_create(&q);
	ft_queue_push(&q, "a", 2);	printf("%zd / %s\n", ft_queue_size(&q), (char *)ft_queue_front(&q));
	ft_queue_push(&q, "b", 2);	printf("%zd / %s\n", ft_queue_size(&q), (char *)ft_queue_front(&q));
	ft_queue_pop(&q);			printf("%zd / %s\n", ft_queue_size(&q), (char *)ft_queue_front(&q));
	ft_queue_pop(&q);			printf("%zd\n", ft_queue_size(&q));
	ft_queue_destroy(&q);
	//system("leaks a.out");
	return (EXIT_SUCCESS);
}
