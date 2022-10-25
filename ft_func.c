
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>

#include "stdio.h"
void	ft_close_game(int keypress)
{
	if (keypress == 53)
		exit(1);
}
int func(int keypress, t_data *data) {
	t_degree degree;

	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ft_degree_direction_init(&degree, data);
	if (keypress == R) {
		data->tanAnglePoz -= 5;
		data->tanAngleNeg += 5;
		data->angle -= 5;
	}
	else if (keypress == L)
	{
		data->tanAnglePoz += 5;
		data->tanAngleNeg -= 5;
		data->angle += 5;
	}
	else if (keypress == 13 && (wall_check(*data, degree.ax, degree.ay) == 0))
	{
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
	ft_close_game(keypress);
	makeRay(data);
	return (0);
}