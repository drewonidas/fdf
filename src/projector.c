#include "projector.h"

void				calc_center(t_model *model)
{
	int				x_len;
	int				y_len;

	x_len = model->rows[0]->col_cnt - 1;
	y_len = model->row_cnt - 1;
	if (model != NULL)
	{
		model->center->x = (model->rows[y_len]->points[x_len]->x + model->rows[0]->points[0]->x) / 2;
		model->center->y = (model->rows[y_len]->points[x_len]->y + model->rows[0]->points[0]->y) / 2;
	}
}

void				set_projection(t_model *model)
{
	t_matrix		*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	matrix->a1 = -1;
	matrix->b2 = -1;
	matrix->d4 = 1;
	transform_model(matrix, model);
}

void				isometric(t_model *model)
{
	int w = (WIN_WID) / 2;
	int h = (WIN_HEI) / 2;
	
	w = (WIN_WID) / 2;
	h = (WIN_HEI) / 2;
	translate_model(model, -model->center->x, -model->center->y, 0);
	scale_model(model, 5);
	rotate_model(model, 35.264, 'z');
	rotate_model(model, 45, 'x');
	project(model);
	translate_model(model, model->center->x + w, model->center->y + h, 0);
}

