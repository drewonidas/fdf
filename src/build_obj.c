#include "fdf.h"

//void			exit_gen(t_)

t_point			*set_points(t_map *map)
{
	t_point		*points;
	int			r;
	int			c;
	int			index;

	r = 0;
	c = 0;
	index = 0;
	points = (t_point *)malloc(sizeof(t_point) * (map->cols * map->rows + 1));
	while (map->map[r])
	{
		while (map->map[r][c] != '\0')
		{
			points[index].x = c;
			points[index].y = r;
			points[index].z = map->map[r][c];
			index++;
		}
		r++;
		c = 0;
	}
	return (points);
}
