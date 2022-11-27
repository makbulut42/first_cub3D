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
	int l, L;
	data->wallSize = 0;
	l = 0;
	L = 0;
	while (l < 10 && map1[l]){
		L = 0;
		while (L < 10 && map1[l][L])
		{
			if (map1[l][L] == '1'){
				data->wallSize++;
				L++;
			}
			else
				L++;
		}
		l++;
	}
}