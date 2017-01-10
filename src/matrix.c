#include "projector.h"

t_vector			*vector_x_matrix(t_vector v, t_matrix m2)
{
	t_vector		*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (vector != NULL)
	{
		vector->x = (v.x * m2.v[0].x) + (v.y * m2.v[0].y) + (v.z * m2.v[0].z) + (v.h * m2.v[0].h);
		vector->y = (v.x * m2.v[1].x) + (v.y * m2.v[1].y) + (v.z * m2.v[1].z) + (v.h * m2.v[1].h);
		vector->z = (v.x * m2.v[2].x) + (v.y * m2.v[2].y) + (v.z * m2.v[2].z) + (v.h * m2.v[2].h);
		vector->h = (v.x * m2.v[3].x) + (v.y * m2.v[3].y) + (v.z * m2.v[3].z) + (v.h * m2.v[3].h);
	}
	return (vector);
}

matrix				*matrix_x_matrix(t_matrix m1, t_matrix m2)
{
	int				c;
	t_matrix		*result;

	c = 0;
	result = (t_matrix *)malloc(sizeof(t_matrix));
	while (c < 4 && result != NULL)
	{
		result->v[c] = (m1.v[c], m2);
		c++;
	}
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
