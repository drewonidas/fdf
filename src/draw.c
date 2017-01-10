#include "projector.h"

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

static int			valid_point(t_point p)
{
	if (p.x > WIN_WID || p.x < 0 || p.y > WIN_HEI || p.y < 0)
		return (0);
	else
		return (1);
}

static void			draw_point(t_point point, t_model_img *img, int color)
{
	int				i;

	i = 0;
	if (valid_point(point))
	{
		i = ((int) point.x * 4) + (point.y * img->ln_len);
		img->img_data[i] = color;
		img->img_data[i++] = color >> 8;
		img->img_data[i++] = color >> 16;
	}
}

static void			draw_line(t_point p1, t_point p2, t_projector *proj)
{
	int				done;
	int				valx;
	int				valy;
	unsigned int	color;

	done = FALSE;
	//if (p1.z > 0 || p2.z > 0)
	//	color = 0xCCFF22;//mlx_get_color_value(gen->mlx, (0x55FFFF >> 8));
	//else
		color = 0x00FF55;//mlx_get_color_value(gen->mlx, 0x55FFFF >> 8);
	valx = (p1.x < p2.x ? 1 : -1);
	valy = (p1.y < p2.y ? 1 : -1);
	while (!done)
	{
		draw_point(p1, proj->img, color);
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

void				rastarize_model(t_projector *proj)
{
	t_point			*p1;
	t_point			*p2;
	int				x;
	int				y;

	y = 0;
	p1 = NULL;
	p2 = NULL;
	while (y < proj->model->row_cnt)
	{
		x = 0;
		while (x < proj->model->rows[y]->col_cnt && proj->model->rows[y]->points[x])
		{
			p1 = proj->model->rows[y]->points[x];
			if (proj->model->rows[y]->points[x + 1] != NULL)
			{
				p2 = proj->model->rows[y]->points[x + 1];
				draw_line(*p1, *p2, proj);
			}
			if (proj->model->rows[y + 1] != NULL)
			{
				p2 = proj->model->rows[y + 1]->points[x];
				draw_line(*p1, *p2, proj);
			}
			x++;
		}
		y++;
	}
}
