#include "fdf.h"

static t_matrix		rotate_x(double angle)
{
	t_matrix		*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->a1 = 1;
	matrix->b2 = cos(beta);
	matrix->b3 = -sin(beta);
	matrix->c2 = sin(beta);
	matrix->c3 = cos(beta);
	matrix->d4 = 1;
	return (matrix);
}

static t_matrix		rotate_y(double angle)
{
	t_matrix		*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->a1 = cos(beta);
	matrix->a3 = sin(beta);
	matrix->c1 = -sin(beta);
	matrix->c3 = cos(beta);
	matrix->b2 = 1;
	matrix->d4 = 1;
	return (matrix);
}

static t_matrix		rotate_z(double angle)
{
	t_matrix		*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->a1 = cos(beta);
	matrix->a2 = -sin(beta);
	matrix->b1 = sin(beta);
	matrix->b2 = cos(beta);
	matrix->c3 = 1;
	matrix->d4 = 1;
	return (matrix);
}

void				rotate(t_point center, double angle, char axis);
{
	t_matrix		*tmp;

	tmp = NULL;
	if (axis == 'x')
		tmp = rotate_x(angle);
	else if (axis == 'y')
		tmp = rotate_y(angle);
	else if (axis == 'z')
		tmp = rotate_z(angle);
	transform_img(tmp, center);
	free(tmp);
}
