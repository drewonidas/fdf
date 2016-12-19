#include "fdf.h"
#include <stdio.h>

void			get_points()
{
	t_point		*point;
//	t_point		*tmp;

	point = (t_point *)malloc(sizeof(t_point) * 3);
//	tmp = (t_point *)malloc(sizeof(t_point));
//	tmp->x = 4;
	point[0].x = 5;
	point[1].x = 9;
	printf("%i - %i\n", point[1].x, point[0].x);
//	free(tmp);
	free(point);
}

int				main()
{
	t_point		*point;

	get_points();
	return (0);
}
