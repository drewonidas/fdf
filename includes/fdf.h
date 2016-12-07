#ifndef FDF_H
#define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		e_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		e_gen
{
	t_point			*point;
}					t_gen;

int					key_pressed(int key, void *game);

t_point				*set_points(t_map *map);

#endif
