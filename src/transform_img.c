#include "fdf.h"

static void			calc_new_points(t_point *point, t_matrix *m, t_point center)
{
	double		tmp_x;
	double		tmp_y;
	double		tmp_z;

	point->x -= center.x;
	point->y -= center.y;
	tmp_x = point->x * m->a1 + point->y * m->a2 + point->z * m->a3 + point->s * m->a4;
	tmp_y = point->x * m->b1 + point->y * m->b2 + point->z * m->b3 + point->s * m->b4;
	tmp_z = point->x * m->c1 + point->y * m->c2 + point->z * m->c3 + point->s * m->c4;
	point->z = tmp_z;
	point->y = tmp_y;
	point->x = tmp_x;
	point->x += center.x;
	point->y += center.y;
}

void			tranform_img(t_matrix *matrix, t_map *map)
{
	int			c;
	int			r;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->lines[r]->cols)
			calc_new_points(map->lines[r]->points[c++], matrix, *(map->center));
		r++;
	}
}
