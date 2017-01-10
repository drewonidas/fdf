#ifndef MATRIX_H
# define MATRIX_H

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			h;
}					t_vector;

typedef struct		e_matrix
{
	t_vector		rows[4];
}					t_matrix;

typedef struct		s_row
{
	t_vector		**points;
	int				col_cnt;
}					t_row;

typedef struct		s_model
{
	t_row			**rows;
	t_vector		center;
	int				row_cnt;
}					t_model;

t_matrix			*get_translate_matrix(double tx, double ty, double tz);

t_matrix			*get_x_rot_matrix(double angle);

t_matrix			*get_y_rot_matrix(double angle);

t_matrix			*get_z_rot_matrix(double angle);

t_matrix			*matrix_x_matrix(t_matrix *matrix, t_matrix *matrix);

void				transform_model(t_matrix *matrix, t_model *model);

void				translate_model(t_model *model, double x, double y, double z);

void				scale_model(t_model *model, int s_factor);

void				rotate_model(t_model *model, double angle, char axis);

#endif
