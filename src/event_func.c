#include "fdf.h"

/*
int		expose_win(void *game)
{
	draw((t_game) game);
}
*/
int		key_pressed(int key, void *gen)
{
	if (key == 0xFF1B)
	{
		kill_generator((t_generator *)gen);
		exit(0);
	}
	return (0);
}
