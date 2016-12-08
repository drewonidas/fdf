#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define BLK_SIZE 20
# define WIN_WID 400
# define WIN_HEI 400

typedef struct		e_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		e_image
{
	void			*img_ptr;
	char			**img_data;
	int				bpp;
	int				ln_len;
	int				endian;
}					t_image;

typedef struct		e_generator
{
	t_point			*points;
	t_image			*img;
	t_win			*win;
	t_map			*map;
}					t_generator;

t_generator			*init_generator(t_map *map);

t_generator			*kill_generator(t_generator *gen);

int					key_pressed(int key, void *gen);

t_point				*set_points(t_map *map);

void				reload(t_generator *gen);

void				draw_img(t_generator *gen);

#endif
