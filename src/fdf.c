#include "fdf.h"

int					play(t_generator *gen)
{
	reload(gen);
	return (0);
}

int 				main(int ac, char **av)
{
	int				fd;
	t_map			map;
	t_generator		*gen;

	fd = 0;
	gen = NULL;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (ft_save_map(fd, &map))
		{
			gen = init_generator(&map);
			play(gen);
			mlx_expose_hook(gen->win->win, play, gen);
			mlx_key_hook(gen->win->win, key_pressed, gen);
			mlx_loop(gen->win->mlx);
		}
	}
	else
		ft_putendl("No map file specified");
	return (0);
}
