#include "fdf.h"

void				reload(t_generator *gen)
{
	t_image			*img;
	t_win			*win;

	img = gen->img;
	win = gen->win;
	img->img_ptr = mlx_new_image(win->mlx, WIN_WID, WIN_HEI);
	img->img_data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->ln_len), &(img->endian));
	draw_img(gen);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, 20, 20);
	ft_putendl("gosh:");
	mlx_destroy_image(win->mlx, img->img_ptr);
}

t_point				**set_points(t_map *map)
{
	t_point			**points;
	t_point			*tmp;
	int				r;
	int				c;
	int				index;

	r = 0;
	c = 0;
	index = 0;
	tmp = NULL;
	points = (t_point **)malloc(sizeof(t_point) * (map->cols * map->rows + 1));
	while (map->map[r])
	{
		while (map->map[r][c] != '\0')
		{
			tmp = (t_point *)malloc(sizeof(t_point));
			tmp->x = c * BLK_SIZE;
			tmp->y = r * BLK_SIZE;
			tmp->z = map->map[r][c];
			points[index++] = tmp;
		}
		r++;
		c = 0;
	}
	points[index] = NULL;
	return (points);
}

void				kill_generator(t_generator *gen)
{
	t_win			*win;
	int				c;

	win	= gen->win;
	c = 0;
	if (gen->points != NULL)
	{
		while (gen->points[c] != NULL)
			free(gen->points[c++]);
		free(gen->points);
	}
	mlx_destroy_window(win->mlx, win->win);
	free(gen->img);
	if (gen->map->map != NULL)
	{
		while (gen->map->map[c] != NULL)
			free(gen->map->map[c++]);
		free(gen->map);
	}
	free(gen);
}

t_generator			*init_generator(t_map *map)
{
	t_generator		*gen;

	gen = (t_generator *)malloc(sizeof(t_generator));
	gen->map = map;
	gen->points = set_points(gen->map);
	gen->img = (t_image *)malloc(sizeof(t_image));
	gen->win = ft_new_window(WIN_WID, WIN_HEI, "FDF");
	return (gen);
}
