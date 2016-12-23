#include "fdf.h"

static int			valid_point(t_point point)
{
	if (point.x > WIN_WID || point.x < 0 ||
			point.y > WIN_HEI || point.y < 0)
		return (0);
	else
		return (1);
}

static void			draw_point(t_point point, t_image *img, int color)
{
	int				i;

	i = 0;
	if (valid_point(point))
	{
		i = ((int) point.x * 4) + (point.y * img->ln_len);
		img->img_data[i] = color;
	}
}

/*void				draw_line(t_point p1, t_point p2, t_generator *gen)
{
	int				p;
	t_point			tmp;
	int				const1;
	int				const2;
	unsigned int	color;

	tmp.x = p1.x;
	tmp.y = p1.y;
   	p = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	const1 = 2 * (p2.y - p1.y);
	const2 = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	if (p1.z > 0 || p2.z > 0)
		color = 0xE0D3CC;//mlx_get_color_value(gen->mlx, (0x55FFFF >> 8));
	else
		color = 0x776386;//mlx_get_color_value(gen->mlx, 0x55FFFF >> 8);
	while (tmp.x < p2.x)
	{
		draw_point(tmp, gen->img, color);
		tmp.x++;
		if (p < 0)
			p = p + const1;
		else
		{ 
			tmp.y++;
			p = p + const2;
		}
	}
	tmp.x = p1.x;
	tmp.y = p1.y;
   	p = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	const1 = 2 * (p2.y - p1.y);
	const2 = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	while (tmp.y < p2.y)
	{
		draw_point(tmp, gen->img, color);
		p1.y++;
		if (p < 0)
			p = p + const1;
		else
		{ 
			tmp.y++;
			p = p + const2;
		}
	}
}
*/
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
		color = 0x00FF55;//mlx_get_color_value(gen->mlx, 0x55FFFF >> 8);
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
