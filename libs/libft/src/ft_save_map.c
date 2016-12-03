#include "libft.h"

static int	*ft_to_array(char **line, int size)
{
	int		*map_line;
	int		m_index;
	int		s_index;
	int		c_index;

	map_line = (int *) malloc(sizeof(int *) * size);
	m_index = 0;
	s_index = 0;
	c_index = 0;
	while (line[s_index])
	{
		if (ft_isdigit(line[s_index][c_index]))
		{
			map_line[m_index] = ft_atoi(line[s_index]);
			m_index++;
		}
		s_index++;
	}
	return (map_line);
}

/*
 * checks if the map is valid, return 1 on success
**/
static int	ft_val_map(char *map)
{
	while (*map)
	{
		if (ft_isdigit(*map) || *map == ',')
			continue;
		else
			return (0);
	}
	return (1);
}

/*
 * gets the lines from the map and stores it in a 2d array
 * returns 1 on succes, -1 if invalid map, and 0 if invalid fd
**/
int			ft_save_map(int fd, t_map *map)
{
	char	**tmp;
	char	*line;
	int		index;

	index = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_val_map(line))
		{
			tmp = ft_strsplit(line, ',');
			map->map[index++] = ft_to_array(tmp, ft_strlen(line));
			continue;
		}
		else
			return (-1);
		return (1);
	}
	return (0);
}
