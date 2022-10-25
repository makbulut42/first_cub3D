#include <stdlib.h>
#include <stdio.h> //silinebilir
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

	ft_init_data(&data);
	data.lastDistances = calloc(sizeof(int), 1500);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.new_img, 0, 0);
	mlx_hook(data.win2, 2, 0, func, (void *)&data);
	mlx_hook(data.mlx_win, 2, 0, func, (void *)&data);
	data = ft_put_wall(data);
	makeRay(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
