#ifndef FDF_H
#define FDF_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		e_vector
{
	int				x;
	int				y;
	int				z;
}					t_vector;

int		key_pressed(int key, void *game);

#endif
