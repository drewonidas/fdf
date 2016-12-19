#include "fdf.h"
#include <stdio.h>

static t_line	*ft_to_array(char **line, int row_num)
{
	t_line		*map_line;
	int			index;
	int			size;

	size = 0;
	while (line[size] != NULL) 
		size++;
	map_line = (t_line *)malloc(sizeof(t_line));
	map_line->cols = size;
	map_line->points = (t_point **)malloc(sizeof(t_point *) * (size + 1));
	index = 0;
	while (line[index] && index < size)
	{
		map_line->points[index] = (t_point *)malloc(sizeof(t_point));
		map_line->points[index]->x = index;// * BLK_WID;
		map_line->points[index]->y = row_num;// * BLK_HEI;
		map_line->points[index]->z = ft_atoi(line[index]);
		index++;
	}
	map_line->points[index] = NULL;
	ft_arrdel(&line);
	return (map_line);
}

/*
 * checks if the map is valid, return 1 on success
**/
static int		ft_val_map(char *map)
{
	while (*map != '\0')
	{
		if (ft_isdigit(*map) || *map == ' ')
		{
			map++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}

/*
 * gets the lines from the map and stores it in a 2d array
 * returns 1 on succes, -1 if invalid map, and 0 if invalid fd
**/
t_map			*ft_save_map(int fd)
{
	char		*line;
	int			index;
	t_map		*map;

	index = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->lines = (t_line **)malloc(sizeof(t_line *) * 50);
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			break;
		if (ft_val_map(line))
		{
			map->lines[index] = ft_to_array(ft_strsplit(line, ' '), index);
			ft_strdel(&line);
			index++;
			continue;
		}
		else
			return (NULL);
	}
	map->lines[index] = NULL;
	map->rows = index;
	return (map);
}
