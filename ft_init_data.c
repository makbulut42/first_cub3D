#include "cub3D.h"
#include "mlx.h"

void	ft_init_data_game_values(t_data *data)
{
	data->val = PI / 180;
	data->angle = 630;
	data->x1 =  210.187407;
	data->y1 = 309.354930;
	data->tanAnglePoz = 60;
	data->tanAngleNeg = 60;
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
	data->win2 = mlx_new_window(data->mlx_ptr, 2000, 2000, "2.pencere");
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1000, 1000, "377266");
 	data->new_img = mlx_new_image(data->mlx_ptr, 800, 800);
	data->img2 = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->new_img_data = (int *)mlx_get_data_addr(data->new_img, &data->bits_per_pixel, &data->size_line, &data->endian);
	data->new_img_data2 = (int *)mlx_get_data_addr(data->img2, &data->bits_per_pixel2, &data->size_line2, &data->endian2);
	ft_wall_counter(data);
	ft_malloc_allocat(data);
	ft_init_data_game_values(data);
}
