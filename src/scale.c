#include "projector.h"

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

void				scale_model(t_model *model, int s_factor)
{
	t_matrix		*tmp;

	tmp = scale(s_factor);
	transform_model(tmp, model);
	free(tmp);
}
