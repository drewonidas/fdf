#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "matrix.h"

void				init_projector(t_projector *proj);

t_model				*read_model_data(int fd);

int					key_pressed(int key, void *proj);

void				refresh(t_projector *proj);

void				kill_projector(t_projector *proj);

#endif
