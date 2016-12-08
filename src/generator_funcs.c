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
	mlx_put_image_to_window(win->mlx, win->win, img, 0, 0);
	mlx_destroy_image(win->mlx, img);
}

t_point			*set_points(t_map *map)
{
	t_point		*points;
	int			r;
	int			c;
	int			index;

	r = 0;
	c = 0;
	index = 0;
	points = (t_point *)malloc(sizeof(t_point) * (map->cols * map->rows + 1));
	while (map->map[r])
	{
		while (map->map[r][c] != '\0')
		{
			points[index].x = c * BLK_SIZE;
			points[index].y = r * BLK_SIZE;
			points[index].z = map->map[r][c];
			index++;
		}
		r++;
		c = 0;
	}
	return (points);
}

void				kill_generator(t_generator *gen)
{
	t_win			*win;

	win	= gen->win;
	if (gen->points != NULL)
		free(gen->points);
	mlx_destroy_window(win->mlx, win->win);
	free(gen);
}

t_generator			*init_generator(t_map *map)
{
	t_generator		*gen;

	gen = (t_generator *)malloc(sizeof(t_generator));
	gen->map = map;
	gen->points = set_points(gen->map);
	gen->img = NULL;
	gen->win = ft_new_window(WIN_WID, WIN_HEI, "FDF");
	return (gen);
}
