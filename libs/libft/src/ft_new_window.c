#include "libft.h"

/**
 * creates a connection to mlx and creates a window
 * returns a struct containing mlx and window pointers
 **/
t_win		*ft_new_window(int wid, int hei, char *title)
{
	t_win	*win;

	win = (t_win *) malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, wid, hei, title);
	return (win);
}
