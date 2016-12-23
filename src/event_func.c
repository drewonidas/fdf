#include "fdf.h"

/*
int		expose_win(void *game)
{
	draw((t_game) game);
}
*/

void	rotate_model(int key, t_generator *gen)
{
	if (key == BTN_UP)
		rotate_map(gen->map, MOVE_ROT_X_U, 'z');
	if (key == BTN_DOWN)
		rotate_map(gen->map, MOVE_ROT_X_D, 'z');
	if (key == BTN_LEFT)
		rotate_map(gen->map, MOVE_ROT_X_U, 'y');
	if (key == BTN_RIGHT)
		rotate_map(gen->map, MOVE_ROT_X_D, 'y');
	reload(gen);
}

int		key_pressed(int key, void *gen)
{
	if (key == 0xFF1B)
	{
		kill_generator((t_generator *)gen);
		exit(0);
	}
	rotate_model(key, (t_generator *)gen);
	return (0);
}
