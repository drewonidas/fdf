#include "libft.h"
#include <stdio.h>

void		ft_print_map(t_map *map)
{
	int		lvl1;
	int		lvl2;

	lvl1 = 0;
	lvl2 = 0;
	while (map->map[lvl1])
	{
		while (lvl2 < map->cols)
			ft_putnbr(map->map[lvl1][lvl2++]);
		ft_putchar('\n');
		lvl1++;
		lvl2 = 0;
	}
}
