#include "projector.h"
#include <stdio.h>

static t_row	*set_row(char **line, int row_num)
{
	t_row		*row;
	int			index;
	int			size;

	size = 0;
	while (line[size] != NULL) 
		size++;
	row = (t_row *)malloc(sizeof(t_row));
	row->col_cnt = size;
	row->points = (t_point **)malloc(sizeof(t_point *) * (size + 1));
	index = 0;
	while (line[index] && index < size)
	{
		row->points[index] = (t_point *)malloc(sizeof(t_point));
		row->points[index]->x = index; //* BLK_WID;
		row->points[index]->y = row_num; //* BLK_HEI;
		row->points[index]->z = ft_atoi(line[index]);
		index++;
	}
	row->points[index] = NULL;
	ft_arrdel(&line);
	return (row);
}

/*
 * checks if the map is valid, return 1 on success
**/
static int		val_line(char *line)
{
	while (*line != '\0')
	{
		if (ft_isdigit(*line) || *line == ' ')
		{
			line++;
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
t_model			*read_model_data(int fd)
{
	char		*line;
	int			index;
	t_model		*model;

	index = 0;
	model = (t_model *)malloc(sizeof(t_model));
	model->rows = (t_row **)malloc(sizeof(t_row *) * 50);
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			break;
		if (val_line(line))
		{
			model->rows[index] = set_row(ft_strsplit(line, ' '), index);
			ft_strdel(&line);
			index++;
			continue;
		}
		else
			return (NULL);
	}
	model->rows[index] = NULL;
	model->row_cnt = index;
	return (model);
}
