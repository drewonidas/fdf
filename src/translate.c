#include "projector.h"

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

void				translate_model(t_model *model, double x, double y, double z)
{
	/*t_matrix		*tmp;

	tmp = translate(x, y, z);
	transform_img(tmp, map);
	calc_center(map);
	free(tmp);
	*/
	t_row			**rows = model->rows;
	int				c = 0;
	int				r = 0;

	while (r < model->row_cnt)
	{
		c = 0;
		while (c < rows[r]->col_cnt)
		{
			rows[r]->points[c]->x += x;
			rows[r]->points[c]->y += y;
			rows[r]->points[c]->z += z;
			c++;
		}
		r++;
	}
	calc_center(model);
}
