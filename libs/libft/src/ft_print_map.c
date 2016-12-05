#include "libft.h"
#include <stdio.h>

void		ft_print_map(t_map *map)
{
	int		lvl1;
	int		lvl2;

	lvl1 = 0;
	lvl2 = 0;
			//printf("%i \n", map->map[0][0]);
	while (map->map[lvl1])
	{
		ft_putendl("bru");
		while (map->map[lvl1][lvl2])
			printf("%i \n", map->map[lvl1][lvl2++]);
		//ft_putendl(ft_itoa((int)map->map[lvl1][lvl2++]));
		lvl1++;
		lvl2 = 0;
	}
}
