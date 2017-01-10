#ifndef PROJECTOR_H
# define PROJECTOR_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "transform.h"

# define BLK_WID 20 
# define BLK_HEI 20
# define WIN_WID 800
# define WIN_HEI 600

typedef struct	e_model_img
{
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			ln_len;
	int			endian;
}				t_model_img;

typedef struct	s_projector
{
	t_model_img	*img;
	t_model		*model;
	void		*mlx;
	void		*win;
	t_matrix	*plane;
}				t_projector;

void			calc_center(t_model *model);

void			set_projection(t_model *model);

void			rastarize_model(t_projector *proj);

//////////
//TODO: delete
void			draw_map(t_projector *e);
/////////

#endif
