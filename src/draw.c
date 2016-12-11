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
	int				valx;
	int				valy;
	unsigned int	color;

	done = FALSE;
	color = mlx_get_color_value(gen->win->mlx, 0xFFFFFF);
	valx = (p1.x < p2.x ? 1 : -1);
	valy = (p1.y < p2.y ? 1 : -1);
	while (!done)
	{
		draw_point(p1, gen->img, color);
		done = TRUE;
		if ((int)p1.x != (int)p2.x)
		{
			done = FALSE;
			p1.x += valx;
		}
		if ((int)p1.y != (int)p2.y)
		{
			done = FALSE;
			p1.y += valy;
		}
	}	
}

void				draw_img(t_generator *gen)
{
	t_point			*p1;
	t_point			*p2;
	int				x;
	int				y;
	int				index;

	y = 0;
	index = 0;
	p1 = NULL;
	p2 = NULL;
	while (y < gen->map->rows)
	{
		x = 0;
		while (x < gen->map->cols)
		{
			index = (y * gen->map->cols) + (x);
			p1 = gen->points[y];
			p2 = gen->points[index + 1];
			if (p2 != NULL && ((index) < (gen->map->cols * gen->map->rows)))
				draw_line(*p1, *p2, gen);
			index = ((y) * gen->map->cols) + x;
			if (gen->points[index] != NULL)
				draw_line(*p1, *p2, gen);
			x++;
		}
		y++;
	}
}
