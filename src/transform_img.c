#include "fdf.h"

static void			calc_new_points(t_point *point, t_matrix *m, t_point center)
{
	double		tmp_x;
	double		tmp_y;
	double		tmp_z;

	point->x -= 150;
	point->y -= 150;
	tmp_x = center.x;
	tmp_x = m->a1 * point->x + m->a2 * point->y + m->a3 * point->z + m->a4 * point->s;
	tmp_y = m->b1 * point->x + m->b2 * point->y + m->b3 * point->z + m->b4 * point->s;
	tmp_z = m->c1 * point->x + m->c2 * point->y + m->c3 * point->z + m->c4 * point->s;
	point->z = tmp_z;
	point->y = tmp_y;
	point->x = tmp_x;
	point->x += 150;
	point->y += 150;
}

void			transform_img(t_matrix *matrix, t_map *map)
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
