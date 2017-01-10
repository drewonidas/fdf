#include "projector.h"
//TODO: delete
#include <stdio.h>

void	scale_view(int key, t_projector *proj)
{
	if (key == BTN_PGUP)
		scale_model(proj->model, 2);
	if (key == BTN_PGDW)
		scale_model(proj->model, -5);
}

static void		pvt_rot(t_model *model, double angle, char axis)
{
	//int w = (WIN_WID) / 2;
	//int h = (WIN_HEI) / 2;

	int cx = model->center->x;
	int cy = model->center->x;
	translate_model(model, -cx, -cy, 0);
	rotate_model(model, angle, axis);
	translate_model(model, cx, cy, 0);
}

void	rotate_view(int key, t_projector *proj)
{
	if (key == BTN_UP)
		pvt_rot(proj->model, (double)MOVE_ROT_X_U, 'x');
	if (key == BTN_DOWN)
		pvt_rot(proj->model, (double)MOVE_ROT_X_D, 'x');
	if (key == BTN_LEFT)
		pvt_rot(proj->model, (double)MOVE_ROT_Y_U, 'y');
	if (key == BTN_RIGHT)
		pvt_rot(proj->model, (double)MOVE_ROT_Y_D, 'y');
	if (key == BTN_MIN)
		pvt_rot(proj->model, (double)MOVE_ROT_Z_U, 'z');
	if (key == BTN_PLS)
		pvt_rot(proj->model, (double)MOVE_ROT_Z_D, 'z');
}

int		key_pressed(int key, void *proj)
{
	if (key == 0xFF1B)
	{
		kill_projector((t_projector *)proj);
		exit(0);
	}
	rotate_view(key, (t_projector *)proj);
	//scale_view(key, (t_projector *)proj);
	refresh(proj);
	return (0);
}
