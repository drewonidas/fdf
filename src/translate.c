#include "fdf.h"

t_matrix			*translate(double tx, double ty, double tz)
{
	t_matrix		*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->a4 = tx;
	matrix->b4 = ty;
	matrix->c4 = tz;
	matrix->a1 = 1;
	matrix->b2 = 1;
	matrix->c3 = 1;
	matrix->d4 = 1;
	return (matrix);
}

void				translate_map(t_map *map, double x, double y, double z)
{
	/*t_matrix		*tmp;

	tmp = translate(x, y, z);
	transform_img(tmp, map);
	calc_center(map);
	free(tmp);*/
	t_line			**lines = map->lines;
	int				c = 0;
	int				r = 0;

	while (r < map->rows)
	{
		c = 0;
		while (c < lines[r]->cols)
		{
			lines[r]->points[c]->x += x;
			lines[r]->points[c]->y += y;
			lines[r]->points[c]->z += z;
			c++;
		}
		r++;
	}
}
