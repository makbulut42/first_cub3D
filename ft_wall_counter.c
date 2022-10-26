#include "cub3D.h"

char map1[10][10] = {
	"1111111111",
	"1010000001",
	"1010000001",
	"1000001001",
	"1000000001",
	"1010010001",
	"1001000001",
	"1010010001",
	"1000000001",
	"1111111111",
};

void	ft_wall_counter(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->wallSize = 0;
	while (i < 10 && map1[i]){
		j = 0;
		while (j < 10 && map1[i][j])
		{
			if (map1[i][j] == '1'){
				data->wallSize++;
				j++;
			}
			else
				j++;
		}
		i++;
	}
}