#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define BLK_WID 20 
# define BLK_HEI 20
# define WIN_WID 800
# define WIN_HEI 600
# define BTN_LEFT 65361 //0xff51  /* Move left, left arrow */
# define BTN_UP 65362 //0xff52  /* Move up, up arrow */
# define BTN_RIGHT 65363 //0xff53  /* Move right, right arrow */
# define BTN_DOWN 65364 //0xff54  /* Move down, down arrow */
# define MOVE_ROT_X_U -M_PI / 64
# define MOVE_ROT_X_D M_PI / 64
# define MOVE_ROT_Y_U -M_PI / 64
# define MOVE_ROT_Y_D M_PI / 64
# define MOVE_ROT_Z_U -M_PI / 64
# define MOVE_ROT_Z_D M_PI / 64
/////////////////////
//TODO: delete these
#include <stdio.h>
/////////////////////

typedef struct		e_point
{
	double			x;
	double			y;
	double			z;
	double			s;
}					t_point;

typedef	struct		s_line
{
	t_point			**points;
	int				cols;
}					t_line;

typedef struct		s_map
{
	int				rows;
	t_point			*center;
	t_line			**lines;
}					t_map;

typedef struct		e_image
{
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				ln_len;
	int				endian;
}					t_image;

typedef struct		e_generator
{
	t_image			*img;
	t_map			*map;
	void			*mlx;
	void			*win;
}					t_generator;

typedef struct		e_matrix
{
	double			a1;
	double			a2;
	double			a3;
	double			a4;
	double			b1;
	double			b2;
	double			b3;
	double			b4;
	double			c1;
	double			c2;
	double			c3;
	double			c4;
	double			d1;
	double			d2;
	double			d3;
	double			d4;
}					t_matrix;

typedef struct		e_view
{
	t_point			**points;
	t_matrix		*matrix;
}					t_view;

t_generator			*init_generator(t_map *map);

void				kill_generator(t_generator *gen);

int					key_pressed(int key, void *gen);

t_point				**set_points(t_map *map);

void				reload(t_generator *gen);

void				draw_img(t_generator *gen);

/////////////////////
//TODO: delete these
void				draw_map(t_generator *e);
/////////////////////

t_map				*ft_save_map(int fd);

void				ft_print_map(t_map *map);

void				calc_center(t_map *map);

t_matrix			*translate(double tx, double ty, double tz);

t_matrix			*rotate_z(double angle);

t_matrix			*rotate_x(double angle);

t_matrix			*rotate_y(double angle);

t_matrix			*modal_projection();

void				transform_img(t_matrix *matrix, t_map *map);

void				rotate_map(t_map *map, double angle, char axis);

void				translate_map(t_map *map, double x, double y, double z);

void				scale_map(t_map *map, int s_factor);

#endif
