#include "projector.h"

t_vector			*point_x_point(t_vector p1, t_vector p2)
{
	t_vector		*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (vector != NULL)
	{
		vector->x = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.h * v2.h);
		vector->y = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.h * v2.h);
		vector->z = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.h * v2.h);
		vector->h = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.h * v2.h);
	}
	return (vector);
}

matrix				*matrix_x_matrix(t_matrix m1, t_matrix m2)
{
	int				c;
	t_matrix		*result;

	c = 0;
	result = (t_matrix *)malloc(sizeof(t_matrix));
	transpose(&m2);
	while (c < 4)
	{
		result->v[c].x = (m2.v[c].x * m1.v[c].x) + (m1.v[c].x * m2.v[c + 1]) +
	}
}

void				matrix_x_point(t_vector *point, t_matrix m)
{
	double			tmp_x;
	double			tmp_y;
	double			tmp_z;
	double			tmp_h;

	tmp_x = (m->a1 * point->x) + (m->a2 * point->y) + (m->a3 * point->z) + (m->a4 * point->h);
	tmp_y = (m->b1 * point->x) + (m->b2 * point->y) + (m->b3 * point->z) + (m->b4 * point->h);
	tmp_z = (m->c1 * point->x) + (m->c2 * point->y) + (m->c3 * point->z) + (m->c4 * point->h);
	tmp_h = (m->d1 * point->x) + (m->d2 * point->y) + (m->d3 * point->z) + (m->d4 * point->h);
	point->x = tmp_x;
	point->y = tmp_y;
	point->z = tmp_z;
	point->h = tmp_h;
}

void				transform_model(t_matrix *transf_mtx, t_model *model)
{
	int				c;
	int				r;

	r = 0;
	while (r < model->row_cnt)
	{
		c = 0;
		while (c < model->rows[r]->col_cnt)
			matrix_x_point(model->rows[r]->points[c++], transf_mtx);
		r++;
	}
}
