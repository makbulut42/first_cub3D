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

	data.new_img = mlx_new_image(data.mlx_ptr, 800, 800);
	data.new_img_data = mlx_get_data_addr(data.new_img, &data.bits_per_pixel, &data.size_line, &data.endian);

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
					while (y <= 70)
					{
						x = 0;
						while (x <= 70) 
						{
							char	*dst;
							dst = (data.new_img_data + (i * data.size_line * 70) + (y * data.size_line) + ((j * 70) * (data.bits_per_pixel / 8) + (x * (data.bits_per_pixel / 8))));
							*(unsigned int *)dst = 5353205;
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

t_data ft_put_wall2(t_data data) {


	int i = -1, j, x, y = 0;

	data.new_img = mlx_new_image(data.mlx_ptr, 1000, 1000);
	data.new_img_data = mlx_get_data_addr(data.new_img, &data.bits_per_pixel, &data.size_line, &data.endian);

	while (++i < 10) {
		j = -1;
		while (++j < 10) {
			if (map2[i][j] == '1') 
			{
					y = 0;
					while (y <= 70)
					{
						x = 0;
						while (x <= 70) 
						{
							char	*dst;
							dst = (data.new_img_data + (i * data.size_line * 70) + (y * data.size_line) + ((j * 70) * (data.bits_per_pixel / 8) + (x * (data.bits_per_pixel / 8))));
							*(unsigned int *)dst = 5353205;
							x++;
						}
						y++;
					}
				}
			}
		}
	return (data);
}