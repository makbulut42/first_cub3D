
#include "cub3D.h"
#include <stdio.h>

void	ft_wall_location_create(t_data *data, int i, int j)
{
	static int a;

	if (a <= data->wallSize){
		data->wallLocationsX4[a] = (j * 70);
		data->wallLocationsY4[a] = (i * 70);
		a++;
		data->wallLocationsX4[a] = (j * 70 + 70);
		data->wallLocationsY4[a] = (i * 70);
		a++;
		data->wallLocationsX4[a] = (j * 70);
		data->wallLocationsY4[a] = (i * 70 + 70);
		a++;
		data->wallLocationsX4[a] = (j * 70 + 70);
		data->wallLocationsY4[a] = (i * 70 + 70);
		a++;
	}
}
