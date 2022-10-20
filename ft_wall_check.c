#include "cub3D.h"

int	wall_check(t_data data, int x, int y)
{
	int i;

	i = 0;
	while (data.wallSize > i)
	{
		if ((x < 0 || x > 700) || (y < 0 || y > 700))
			return (0);
		if (data.wallLocationsX[i] <= x && (data.wallLocationsX[i] + 70) >= x  && \
		( data.wallLocationsY[i] <= y && (data.wallLocationsY[i] + 70) >= y))
			return (1);
		i++;
	}	
	return (0);
}
