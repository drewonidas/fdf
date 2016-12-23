#include "fdf.h"

static void			calc_new_points(t_point *point, t_matrix *m, t_point center)
{
	double			tmp_x;
	double			tmp_y;
	double			tmp_z;
//	double			tmp_s;

	//point->x -= center.x;
	//point->y -= center.y;
	tmp_x = (m->a1 * point->x) + (m->a2 * point->y) + (m->a3 * point->z) ;//+ (m->a4 * point->s);
	tmp_y = (m->b1 * point->x) + (m->b2 * point->y) + (m->b3 * point->z) ;//+ (m->b4 * point->s);
	tmp_z = (m->c1 * point->x) + (m->c2 * point->y) + (m->c3 * point->z) ;//+ (m->c4 * point->s);
//	tmp_s = (m->d1 * point->x) + (m->d2 * point->y) + (m->d3 * point->z) + (m->d4 * point->s);
	point->x = center.x;
	point->z = tmp_z;
	point->y = tmp_y;
	point->x = tmp_x;
//	point->s = tmp_s;
	//point->x += center.x;
	//point->y += center.y;
}

t_matrix			*get_projection_mtx(int axis)
{
	t_matrix		*mtx;

	mtx = (t_matrix *)malloc(sizeof(t_matrix));
	if (axis == 'z')
	{
		mtx->a1 = 1;
		mtx->b2 = 1;
	}
	return (mtx);
}

t_matrix			*modal_projection()
{
	t_matrix		*mtx_transform;
	t_matrix		*mtx_project;
	t_matrix		*rot_y;
	t_matrix		*rot_x;

	mtx_transform = (t_matrix *)malloc(sizeof(t_matrix));
	mtx_project = get_projection_mtx('z');
	rot_y = rotate_y(45);
	rot_x = rotate_x(35);
	
	mtx_transform->a1 = rot_y->a1 * rot_x->a1 * mtx_project->a1;
	mtx_transform->a2 = rot_y->a2 * rot_x->a2 * mtx_project->a2;
	mtx_transform->a3 = rot_y->a3 * rot_x->a3 * mtx_project->a3;
//	mtx_tranform->a4 = rot_y->a4 * rot_x->a4;
	
	mtx_transform->b1 = rot_y->b1 * rot_x->b1 * mtx_project->b1;
	mtx_transform->b2 = rot_y->b2 * rot_x->b2 * mtx_project->b2;
	mtx_transform->b3 = rot_y->b3 * rot_x->b3 * mtx_project->b3;
//	mtx_tranform->b4 = rot_y->b4 * rot_x->b4;
	
	mtx_transform->c1 = rot_y->c1 * rot_x->c1 * mtx_project->c1;
	mtx_transform->c2 = rot_y->c2 * rot_x->c2 * mtx_project->c2;
	mtx_transform->c3 = rot_y->c3 * rot_x->c3 * mtx_project->c3;
//	mtx_tranform->c4 = rot_y->c4 * rot_x->c4;
	
//	mtx_tranform->d1 = rot_y->d1 * rot_x->d1 * mtx_project->a1;
//	mtx_tranform->d2 = rot_y->d2 * rot_x->d2 * mtx_project->a1;
//	mtx_tranform->d3 = rot_y->d3 * rot_x->d3 * mtx_project->a1;
//	mtx_tranform->d4 = rot_y->d4 * rot_x->d4;
	free(mtx_project);
	free(rot_y);
	free(rot_x);
	return (mtx_transform);
}

void				transform_img(t_matrix *matrix, t_map *map)
{
	int				c;
	int				r;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->lines[r]->cols)
			calc_new_points(map->lines[r]->points[c++], matrix, *(map->center));
		r++;
	}
}
