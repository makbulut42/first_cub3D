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

void	ft_init_data_game_values(t_data *data)
{
	data->val = PI / 180;
	data->angle = 630;
	data->x1 =  420;
	data->y1 = 180;
	data->firstAngle[1] = 0;
	data->firstAngle[0] = 0;
	data->secAngle[1] = 0;
	data->secAngle[0] = 0;
	data->thirdAngle[1] = 0;
	data->thirdAngle[0] = 0;
	data->fourthAngle[1] = 0;
	data->fourthAngle[0] = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win2 = mlx_new_window(data->mlx_ptr, 1920, 1080, "2.Pencere");
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1000, 1000, "377266");


	
	ft_wall_counter(data);
	ft_malloc_allocat(data);
	*data = ft_put_wall(*data);
	ft_init_data_game_values(data);
}

int main() {
	t_data data;

	ft_init_data(&data);

	data.lastDistances = calloc(sizeof(int), TOTALRAYS);
	data.wall_faces = calloc(sizeof(char), TOTALRAYS + 1);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.new_img, 0, 0);
	data.begin =0;
	//makeRay(&data);
	mlx_hook(data.mlx_win, 2, 0, func, (void *)&data);
	mlx_hook(data.win2, 2, 0, func, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
