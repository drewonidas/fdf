#include "projector.h"

void				init_projector(t_projector *projector)
{
	projector->img = (t_model_img *)malloc(sizeof(t_model_img));
	projector->mlx = mlx_init();
	projector->win = mlx_new_window(projector->mlx, WIN_WID, WIN_HEI, "WTC fdf");
}

void				kill_projector(t_projector *proj)
{
	int				c;
	int				r;
	t_point			**tmp_p;
	t_row			**tmp_r;

	c = 0;
	r = 0;
	tmp_p = NULL;
	tmp_r = proj->model->rows;
	while (tmp_r[r] != NULL)
	{
		tmp_p = tmp_r[r]->points;
		c = 0;
		while (tmp_p[c] != NULL)
			free(tmp_p[c++]);
		free(tmp_p);
		free(tmp_r[r++]);
		tmp_p = NULL;
	}
	free(tmp_r);
	free(proj->model);
	mlx_destroy_window(proj->mlx, proj->win);
	free(proj->img);
}

void				refresh(t_projector *proj)

{
	t_model_img		*img;

	img = proj->img;
	img->img_ptr = mlx_new_image(proj->mlx, WIN_WID, WIN_HEI);
	img->img_data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->ln_len), &(img->endian));
	draw_map(proj);
	//rastarize_model(proj);
	mlx_put_image_to_window(proj->mlx, proj->win, img->img_ptr, 0, 0);
	mlx_destroy_image(proj->mlx, img->img_ptr);
}

int 				main(int ac, char **av)
{
	int				fd;
	t_projector		projector;

	fd = 0;
	projector.model = NULL;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if ((projector.model = read_model_data(fd)) != NULL)
		{
			init_projector(&projector);
			calc_center(projectorodel);
			isometric(projector.model);
			mlx_expose_hook(projector.win, play, (void*)&projector);
			mlx_key_hook(projector.win, key_pressed, (void*)&projector);
			mlx_loop(projector.mlx);
		}
		else
			ft_putendl("bad map file");
	}
	else
		ft_putendl("No map file specified");
	return (0);
}
