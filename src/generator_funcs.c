#include "fdf.h"

void				reload(t_generator *gen)
{
	t_image			*img;

	img = gen->img;
	img->img_ptr = mlx_new_image(gen->mlx, WIN_WID, WIN_HEI);
	img->img_data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->ln_len), &(img->endian));
	//draw_img(gen);
	draw_map(gen);
	mlx_put_image_to_window(gen->mlx, gen->win, img->img_ptr, 0, 0);
	mlx_destroy_image(gen->mlx, img->img_ptr);
}

void				kill_generator(t_generator *gen)
{
	int				c;
	int				r;
	t_point			**tmp_p;
	t_line			**tmp_l;

	c = 0;
	r = 0;
	tmp_p = NULL;
	tmp_l = gen->map->lines;
	while (tmp_l[r] != NULL)
	{
		tmp_p = tmp_l[r]->points;
		c = 0;
		while (tmp_p[c] != NULL)
			free(tmp_p[c++]);
		free(tmp_p);
		free(tmp_l[r++]);
		tmp_p = NULL;
	}
	free(tmp_l);
	free(gen->map);
	mlx_destroy_window(gen->mlx, gen->win);
	free(gen->img);
	free(gen);
}

t_generator			*init_generator(t_map *map)
{
	t_generator		*gen;

	gen = (t_generator *)malloc(sizeof(t_generator));
	gen->map = map;
	gen->img = (t_image *)malloc(sizeof(t_image));
	gen->mlx = mlx_init();
	gen->win = mlx_new_window(gen->mlx, WIN_WID, WIN_HEI, "WTC fdf");
	return (gen);
}
