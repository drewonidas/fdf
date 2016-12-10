#include "fdf.h"

static void			draw_point(t_point point, t_image *img, int color)
{
	int				i;

	i = 0;
	i = (int) point.x + (point.y * img->ln_len);
	img->img_data[i] = color;
}

static void			draw_line(t_point p1, t_point p2, t_generator *gen)
{
	int				done;
	unsigned int	color;

	done = FALSE;
	color = mlx_get_color_value(gen->win->mlx, 0xFFFFFF);
	while (!done)
	{
		draw_point(p1, gen->img, color);
		done = TRUE;
		if (p1.x != p2.x)
		{
			done = FALSE;
			p1.x++;
		}
		if (p1.y != p2.y)
		{
			done = FALSE;
			p1.y++;
		}
	}	
}

void				draw_img(t_generator *gen)
{
	t_point			*tmp;
	int				x;
	int				y;
	int				index;

	y = 0;
	index = 0;
	tmp = NULL;
	while (y < gen->map->rows)
	{
		x = 0;
		while (x < gen->map->cols)
		{
			printf("green");
			index = (y * gen->map->cols) + (x + 1);
			tmp = gen->points[x];
			if (gen->points[index] != NULL)
				draw_line(*tmp, *(gen->points[index]), gen);
			index = ((y + 1) * gen->map->cols) + x;
			if (gen->points[index] != NULL)
				draw_line(*tmp, *(gen->points[index]), gen);
			x++;
		}
		y++;
	}
}
