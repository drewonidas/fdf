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
	if (p1.z > 0 || p2.z > 0)
		color = 0xCCFF22;//mlx_get_color_value(gen->mlx, (0x55FFFF >> 8));
	else
		color = 0xFFFFFF;//mlx_get_color_value(gen->mlx, 0x55FFFF >> 8);
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

	y = 0;
	p1 = NULL;
	p2 = NULL;
	while (y < gen->map->rows)
	{
		x = 0;
		while (x < gen->map->lines[y]->cols && gen->map->lines[y]->points[x])
		{
			p1 = gen->map->lines[y]->points[x];
			if (gen->map->lines[y]->points[x + 1] != NULL)
			{
				p2 = gen->map->lines[y]->points[x + 1];
				draw_line(*p1, *p2, gen);
			}
			if (gen->map->lines[y + 1] != NULL)
			{
				p2 = gen->map->lines[y + 1]->points[x];
				draw_line(*p1, *p2, gen);
			}
			x++;
		}
		y++;
	}
}
