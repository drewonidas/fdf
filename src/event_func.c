#include "fdf.h"

/*
int		expose_win(void *game)
{
	draw((t_game) game);
}
*/
int		key_pressed(int key, void *window)
{
	if (key == 0xFF1B)
	{
		mlx_destroy_window(((t_win *)window)->mlx, ((t_win *)window)->win);
		exit(0);
	}
	return (0);
}
