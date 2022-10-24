#include "cub3D.h"

char map2[10][10] = {
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

t_data	ft_put_wall(t_data data)
{
	int x;
	int y = 0;
	int i = -1;
	int j;
	int *tmp;
	int *tmp2;

	tmp = data.wallLocationsX;
	tmp2 = data.wallLocationsY;
	while (++i < 10) {
		j = -1;
		while (++j < 10) {
			if (map2[i][j] == '1') 
			{
					ft_wall_location_create(data.wallLocationsX4, data.wallLocationsY4, i, j);
					*data.wallLocationsX = (j * 70);
					*data.wallLocationsY = (i * 70);
					data.wallLocationsX++;
					data.wallLocationsY++;
					y = 0;
					while (y <= 68)
					{
						x = 0;
						while (x <= 68) 
						{
							data.new_img_data[(i * 800 * 70) + (j * 70) + (x + (y * 800))] = 5353205;
							x++;
						}
						y++;
					}
				}
			} 
		}
	data.wallLocationsX = tmp;
	data.wallLocationsY = tmp2;
	return (data);
}