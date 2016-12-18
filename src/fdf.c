#include "fdf.h"

void				calc_center(t_map *map)
{
	t_point			*center;
	int				x_len;
	int				y_len;

	x_len = map->lines[0]->cols - 1;
	y_len = map->rows - 1;
	center = (t_point *)malloc(sizeof(t_point));
	center->x = (map->lines[y_len]->points[x_len]->x + map->lines[0]->points[0]->x) / 2;
	center->y = (map->lines[y_len]->points[x_len]->y + map->lines[0]->points[0]->y) / 2;
	map->center = center;
}

int					play(t_generator *gen)
{
	reload(gen);
	return (0);
}
/*
void	adapt_map(t_env *e)
{
	int		w;
	int		h;
	double	s;

	w = (WINDOW_SIZE_W + 100) / 2;
	h = (WINDOW_SIZE_H + 100) / 2;
	e->center.x == 0 ? e->center.x = 10 : e->center.x;
	s = (w - 600) / (e->center.x);
	ft_cal_translat(e, -e->center.x + w, -e->center.y + h, 0);
	ft_cal_scale(e, s);
}
*/
int 				main(int ac, char **av)
{
	int				fd;
	t_map			*map;
	t_generator		*gen;

	fd = 0;
	gen = NULL;
	map = NULL;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if ((map = ft_save_map(fd)) != NULL)
		{
			gen = init_generator(map);
			calc_center(gen->map);
			int w = (WIN_WID + 100) / 2;
			int h = (WIN_HEI + 100) / 2;
			//double s = (w - 600) / (gen->map->center->x);
			//translate_map(gen->map, 300, 300, 0);
			rotate_map(gen->map, 45, 'y');
			rotate_map(gen->map, -35.264, 'x');
			//rotate_map(gen->map, -15, 'z');
			scale_map(gen->map, 1);
			translate_map(gen->map, -gen->map->center->y + w, -gen->map->center->y + h, 0);
			mlx_expose_hook(gen->win, play, gen);
			mlx_key_hook(gen->win, key_pressed, gen);
			mlx_loop(gen->mlx);
		}
		else
			ft_putendl("bad map file");
	}
	else
		ft_putendl("No map file specified");
	return (0);
}
