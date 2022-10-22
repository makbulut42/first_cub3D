#include "cub3D.h"
#include <stdio.h> //silinecek
#include <stdlib.h>
#include "mlx.h"

char wall_face(t_data data, int x, int y)
{
	int i;
	i = 0;
	while (i < (data.wallSize - 1) * 4)
	{
		if ((data.wallLocationsX70[i] < x && ((data.wallLocationsX70[i + 1] > x && data.wallLocationsY70[i] == y )&& data.wallLocationsY70[i + 1] == y)))
			return ('S');
		else if ((data.wallLocationsX70[i + 2]) < x && ((data.wallLocationsX70[i + 3])) > (x) && ((data.wallLocationsY70[i + 2]) == ((data.wallLocationsY70[i + 3])) && data.wallLocationsY70[i + 3] == y))
		  return ('N');
		else if (data.wallLocationsY70[i + 1] < y && data.wallLocationsY70[i + 3] > y && data.wallLocationsX70[i + 1] == x && data.wallLocationsX70[i + 3] == x)
			return ('W');
		else if (data.wallLocationsY70[i] < y && data.wallLocationsY70[i + 2] > y && data.wallLocationsX70[i] == x && data.wallLocationsX70[i + 2] == x)
			return('E');
		i += 4;
	}
	return (0);
}