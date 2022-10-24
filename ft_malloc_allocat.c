#include "cub3D.h"
#include <stdlib.h>

void	ft_malloc_allocat(t_data *data)
{
	data->wallLocationsX = (int *)malloc(sizeof(int) * data->wallSize);
	data->wallLocationsY = (int *)malloc(sizeof(int) * data->wallSize);
    data->wallLocationsX4 = (int *)malloc(sizeof(int) * data->wallSize * 4);
    data->wallLocationsY4 = (int *)malloc(sizeof(int) * data->wallSize * 4);
}