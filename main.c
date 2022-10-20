#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cub3D.h"

char map[10][10] = {
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


int main() {
	t_data data;


	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 1000, 1000, "377266");

 	data.new_img = mlx_new_image(data.mlx_ptr, 800, 800);

	int bits_per_pixel;
	int size_line;
	int endian;
	data.new_img_data = (int *)mlx_get_data_addr(data.new_img, &bits_per_pixel, &size_line, &endian);
int l, L;

	data.wallSize = 0;
	l = 0;
	L = 0;
	while (l < 10 && map[l]){
		L = 0;
		while (L < 10 && map[l][L])
		{
			if (map[l][L] == '1'){
				data.wallSize++;
				L++;
			}
			else
				L++;
		}
		l++;
	}
	data.wallLocationsX = (int *)malloc(sizeof(int) * data.wallSize);
	data.wallLocationsY = (int *)malloc(sizeof(int) * data.wallSize);
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
			if (map[i][j] == '1') {
				*data.wallLocationsX = (j * 70);
				*data.wallLocationsY = (i * 70);
				data.wallLocationsX++;
				data.wallLocationsY++;
				y = 0;
				while (y <= 68) {
					x = 0;
					while (x <= 68) {
						data.new_img_data[(i * 800 * 70) + (j * 70) + (x + (y * 800))] = 5353205;
						x++;
					}
					y++;
				}
			}
			/* else {
				for (int ks = 0; ks < 70; ks++)
					data.new_img_data[(i * 800 * 70) + (j * 70) + (x + (y * 799)) + ks] = 0xff8000;
			} */
			} 
		}
	data.wallLocationsX = tmp;
	data.wallLocationsY = tmp2;
	double angle, val, x1, x2, y1, y2;
	data.val = PI / 180;
	data.angle = 630;
	data.x1 =  210.187407;
	data.y1 = 309.354930;
	data.tanAnglePoz = 60;
	data.tanAngleNeg = 60;

	float asd = 10.54f;

	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.new_img, 0, 0);
	mlx_hook(data.mlx_win, 2, 0, func, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
