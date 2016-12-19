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
		i = (int) point.x + (point.y * img->ln_len);
		img->img_data[i] = color;
	}
}
/*
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x32A862;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20 && z < 50)
		color = 0xFAECBE;
	else if (z >= 50 && z < 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xE0D3CC;
*/

void				draw_line(t_point p1, t_point p2, t_generator *gen)
{
	int				p;
	int				const1;
	int				const2;
	unsigned int	color;

   	p = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	const1 = 2 * (p2.y - p1.y);
	const2 = 2 * (p2.y - p1.y) - (p2.x - p1.x);
	if (p1.z > 0 || p2.z > 0)
		color = 0x0D6386;//mlx_get_color_value(gen->mlx, (0x55FFFF >> 8));
	else
		color = 0x000000;//mlx_get_color_value(gen->mlx, 0x55FFFF >> 8);
/*	while (p1.x < p2.x)
	{
		draw_point(p1, gen->img, color);
		p1.x++;
		if (p < 0)
			p = p + const1;
		else
		{ 
			p1.y++;
			p = p + const2;
		}
	}*/
	while (p1.y < p2.y)
	{
		draw_point(p1, gen->img, color);
		p1.y++;
		if (p < 0)
			p = p + const1;
		else
		{ 
			p1.y++;
			p = p + const2;
		}
	}
}
/*
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
}*/

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
