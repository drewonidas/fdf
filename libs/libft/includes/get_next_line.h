#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUFF_SIZE 5000

typedef struct	s_file
{
	char		*curr_line;
	int			fd;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
