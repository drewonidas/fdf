#include "fdf.h"

t_matrix			*scale(int s)
{
	t_matrix		*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->a1 = s;
	matrix->b2 = s;
	matrix->c3 = s;
	matrix->d4 = 1;
	return (matrix);
}

void				scale_point(t_point *point, int s)
{
	t_scale_mtx		*matrix;

	matrix = (t_scale_mtx *)malloc(sizeof(t_scale_mtx));
	matrix->a1 = s;
	matrix->b2 = s;
	matrix->c3 = s;
	//matrix->d4 = 1;
	double tmp_x = matrix->a1 * point->x + matrix->a2 * point->x + matrix->a3 * point->x;
	double tmp_y = matrix->b1 * point->y + matrix->b2 * point->y + matrix->b3 * point->y;
	double tmp_z = matrix->c1 * point->z + matrix->c2 * point->z + matrix->c3 * point->z;
	point->x = tmp_x;
	point->y = tmp_y;
	point->z = tmp_z;
	free(matrix);
}

void				scale_map(t_map *map, int s_factor)
{
	//t_matrix		*tmp;

	//tmp = scale(s_factor);
	//transform_img(tmp, map);
	//free(tmp);
	t_line			**lines = map->lines;
	int				x = 0;
	int				y = 0;

	while (y < map->rows)
	{
		x = 0;
		while (x < lines[y]->cols)
		{
			scale_point(lines[y]->points[x], s_factor);
			x++;
		}
		y++;
	}
}
