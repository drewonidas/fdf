#include "fdf.h"

void			play()//t_map *map)
{
	t_win		*window;
			//t_vector	v1, v2;
			//void		*img;

	window = ft_new_window(400, 400, "brick");
	//img = mlx_new_image(window->mlx, 200, 200);
	//v1.x = 4;
	//v1.y = 4;
	//v2.x = 300;
	//mlx_pixel_put(window->mlx, window->win, v1);
	//v2.y = 300;
//	init_player(game->player);
//	draw(game);
//	mlx_expose_hook(game->win, expose_win, game)i;
	mlx_key_hook(window->win, key_pressed, window);
//  mlx_mouse_hook(win2,mouse_win2,0);
 // mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);
	mlx_loop(window->mlx);
//	ft_print_map(gam->map);
//	return (0);
}

int 			main(int ac, char **av)
{
	int			fd;
	t_map		map;

	fd = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (ft_save_map(fd, &map))
		{
			//ft_putendl("brom");
			set_points(&map);
			play();//&map);
		}
	}
	else
		ft_putendl("No map file specified");
	return (0);
}
