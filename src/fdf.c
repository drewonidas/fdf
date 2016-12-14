#include "fdf.h"

int					play(t_generator *gen)
{
	reload(gen);
	return (0);
}

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
