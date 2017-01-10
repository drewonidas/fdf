/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:15:11 by ybarbier          #+#    #+#             */
/*   Updated: 2014/12/13 15:15:13 by ybarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projector.h"

int		point_out_window(t_point *point1)
{
	if (!(point1->x > WIN_WID + 100 || point1->x <= 0 ||
		point1->y > WIN_HEI + 100 || point1->y <= 0))
		return (1);
	else
		return (0);
}

static void		draw_line_params(t_point *point1, t_point *point2, double *tab)
{
	tab[0] = fabs(point1->x - point2->x);
	tab[1] = point1->x < point2->x ? 1 : -1;
	tab[2] = fabs(point1->y - point2->y);
	tab[3] = point1->y < point2->y ? 1 : -1;
	tab[4] = (tab[0] > tab[2] ? tab[0] : -tab[2]) * 0.5;
}

static void		draw_point(t_point *point, t_projector *e, int color)
{
	int i;

	i = ((int)point->x * 4) + ((int)point->y * e->img->ln_len);
	e->img->img_data[i] = color;
	e->img->img_data[++i] = color >> 8;
	e->img->img_data[++i] = color >> 16;
}

static void		draw_line(t_point p1, t_point p2, t_projector *e)
{
	double	tab[6];
	int		state;

	if (!point_out_window(&p1) && !point_out_window(&p2))
		return ;
	draw_line_params(&p1, &p2, tab);
	state = 1;
	while (state == 1 && !((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		if (point_out_window(&p1) == 1)
			draw_point(&p1, e, 0xE0D3CC);
		tab[5] = tab[4];
		state = 0;
		if (tab[5] > -tab[0] && (int)p1.x != (int)p2.x)
		{
			tab[4] -= tab[2];
			p1.x += tab[1];
			state = 1;
		}
		if (tab[5] < tab[2] && (int)p1.y != (int)p2.y)
		{
			tab[4] += tab[0];
			p1.y += tab[3];
			state = 1;
		}
	}
}

void			draw_map(t_projector *e)
{
	int			x;
	int			y;
	t_point		p1;

	y = 0;
	while (y < e->model->row_cnt)
	{
		x = 0;
		while (x < (e->model->rows[y]->col_cnt))
		{
			p1 = (*e->model->rows[y]->points[x]);
			if (e->model->rows[y]->points[x + 1])
				draw_line(p1, (*e->model->rows[y]->points[x + 1]), e);
			if (e->model->rows[y + 1])
				if (e->model->rows[y + 1]->points[x] &&
					x <= e->model->rows[y + 1]->col_cnt)
					draw_line(p1, (*e->model->rows[y + 1]->points[x]), e);
			x++;
		}
		y++;
	}
}
