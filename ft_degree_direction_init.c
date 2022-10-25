
#include "cub3D.h"
#include <math.h>

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