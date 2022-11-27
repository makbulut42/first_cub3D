#include "cub3D.h"
#include "math.h"

#include "stdio.h"

char	ft_pozitionCheck(t_data *data, int l) {
	int i, j;
	float distanceLeft = 0, distanceRight = 0;


	// printf("idx--> %d\n", l);


	i = 1;
	j = 1;
	if ((l + i) < TOTALRAYS) {
		while ((l + i) < TOTALRAYS - 1 && data->wall_faces[l + i] == 0)
			i++;
		distanceRight = fabs(data->lastDistances[l] - data->lastDistances[l + i]);
	}
	if (l - j > 1) {
		while (l - j > 0 && data->wall_faces[l - j] == 0)
			j++;
		distanceLeft = fabs(data->lastDistances[l] - data->lastDistances[l - j]);
	}

	// printf("left: %d\n", i);
	// printf("Right: %d\n", j);

	if (l - j >= 0 && distanceLeft < distanceRight) {
		// printf("1--> %d\n", data->wall_faces[l - j]);
		return (data->wall_faces[l - j]);
	}
	else if (l + i <= TOTALRAYS) {
		// printf("2--> %d\n", data->wall_faces[l + i]);
		return (data->wall_faces[l + i]);
	}
	return (0);
}