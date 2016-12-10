#include "libft.h"
#include <stdio.h>

static int	*ft_to_array(char **line, int size)
{
	int		*map_line;
	int		m_index;
	int		s_index;
	int		c_index;

	map_line = (int *) malloc(sizeof(int) * (size + 1));
	m_index = 0;
	s_index = 0;
	c_index = 0;
	while (line[s_index] && m_index < size)
	{
		if (ft_isdigit(line[s_index][c_index]))
		{
			map_line[m_index] = ft_atoi(line[s_index]);
			m_index++;
		}
		s_index++;
	}
	map_line[m_index] = (int)'\0';
	return (map_line);
}

/*
 * checks if the map is valid, return 1 on success
**/
static int	ft_val_map(char *map)
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
int			ft_save_map(int fd, t_map **map)
{
	char	**tmp;
	char	*line;
	int		index;
	int		cnt;
	t_map	*tmp_map;

	cnt = 0;
	tmp = NULL;
	index = 0;
	tmp_map = (t_map *)malloc(sizeof(t_map));
	tmp_map->map = (int **)malloc(sizeof(int *) * 50);
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			break;
		if (ft_val_map(line))
		{
			tmp = ft_strsplit(line, ' ');
			cnt = 0;
			while (tmp[cnt] != NULL)
				cnt++;
			tmp_map->map[index++] = ft_to_array(tmp, cnt);
			ft_arrdel(&tmp);
			ft_strdel(&line);
			continue;
		}
		else
			return (-1);
	}
	tmp_map->map[index] = NULL;
	tmp_map->cols = cnt;
	tmp_map->rows = index;
	if (*map == NULL)
		*map = tmp_map;
	if (line != NULL)
		ft_strdel(&line);
	return (1);
}
