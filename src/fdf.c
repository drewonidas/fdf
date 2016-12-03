#include "fdf.h"

void		play(char *title)
{
	t_win	*window;

	window = ft_new_window(400, 400, title);
//	init_player(game->player);
//	draw(game);
//	mlx_expose_hook(game->win, expose_win, game);
	mlx_key_hook(window->win, key_pressed, window);
//  mlx_mouse_hook(win2,mouse_win2,0);
 // mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);
	mlx_loop(window->mlx);
//	ft_print_map(gam->map);
//	return (0);
}

int 		main(int ac, char **av)
{
//	int		fd;

//	fd = 0;
	if (ac > 1)
	{
		//fd = open(av[1], O_RDONLY);
		//if (ft_save_map(fd, game.map))
			play(av[ac]);
	}
	else
		ft_putendl("No map file specified");
	ft_putendl("done!!");
	return (0);
}
