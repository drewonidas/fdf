#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		int g = ft_strcmp("", "john");
		char **q = ft_strtrim("john\n\n");
		while (q[i])
		printf("%-18s:g = %+-7irazor\n", q, g);
		//printf("%-18s:%+-7irazor\n", av[1], 2000);
		ft_strdel(&q);
	}
	return (0);
}
