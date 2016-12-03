#include "libft.h"

void		ft_print_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->map[i])
		ft_putendl(ft_itoa((int)map->map[i++]));
}
