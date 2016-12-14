#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define BLK_WID 60
# define BLK_HEI 40
# define WIN_WID 800
# define WIN_HEI 600

/////////////////////
//TODO: delete these
#include <stdio.h>
/////////////////////

typedef struct		e_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef	struct		s_line
{
	t_point			**points;
	int				cols;
}					t_line;

typedef struct		s_map
{
	int				rows;
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

typedef struct		e_matrice
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
}					t_matrice;

t_generator			*init_generator(t_map *map);

void				kill_generator(t_generator *gen);

int					key_pressed(int key, void *gen);

t_point				**set_points(t_map *map);

void				reload(t_generator *gen);

void				draw_img(t_generator *gen);

t_map				*ft_save_map(int fd);

void				ft_print_map(t_map *map);

#endif
