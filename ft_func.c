
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>

#include "stdio.h"

typedef	struct s_degree
{
	int ay;
	int ax;
	int by;
	int bx;
	int cy;
	int cx;
	int dy;
	int dx;
}			t_degree;

void	ft_degree_direction_init(t_degree *degree, t_data *data)
{
	degree->ay = data->y1 + (5 * sin((data->angle) * data->val));
	degree->ax = data->x1 + (5 * cos((data->angle) * data->val));
	degree->by = data->y1 - (5 * sin(data->angle * data->val));
	degree->bx = data->x1 - (5 * cos(data->angle * data->val));
	degree->cy = data->y1 - (5 * sin((data->angle + 90) * data->val));
	degree->cx = data->x1 - (5 * cos((data->angle + 90) * data->val));
	degree->dy = data->y1 + (5 * sin((data->angle + 90) * data->val));
	degree->dx = data->x1 + (5 * cos((data->angle + 90) * data->val));
}

int func(int keypress, void *arg) {

	t_data *data;
	t_degree degree;

	data = (t_data *)arg;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_degree_direction_init(&degree, data);
	if (keypress == 123) {
		data->tanAnglePoz -= 5;
		data->tanAngleNeg += 5;
		data->angle -= 5;
	}
	else if (keypress == 124)
	{
		data->tanAnglePoz += 5;
		data->tanAngleNeg -= 5;
		data->angle += 5;
	}
	else if (keypress == 13 && (wall_check(*data, degree.ax, degree.ay) == 0)) {
		data->y1 = data->y1 + (5 * sin(data->angle * data->val));
		data->x1 = data->x1 + (5 * cos(data->angle * data->val));
	}
	else if (keypress == 1 && (wall_check(*data, degree.bx, degree.by) == 0)){
		data->y1 = data->y1 - (5 * sin(data->angle * data->val));
		data->x1 = data->x1 - (5 * cos(data->angle * data->val));
	}
	else if (keypress == 0 && wall_check(*data, degree.cx, degree.cy) == 0 \
	&& (wall_check(*data, data->x1  - 5, data->y1) == 0)){
		data->y1 = data->y1 - (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 - (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 2 && wall_check(*data, degree.dx, degree.dy) == 0 \
	&& (wall_check(*data, data->x1 + 5, data->y1) == 0)){
		data->y1 = data->y1 + (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 + (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 53)
		exit(1);
	makeRay(data);
	return (0);
}