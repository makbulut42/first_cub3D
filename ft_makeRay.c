#include "cub3D.h"
#include <math.h>
#include <stdlib.h>

void makeRay(t_data *data) {
	double i;
	double x2;
	double y2;
	double tmp;
	
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->new_img, 0, 0);
	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x1, data->y1, 0xff0000);
	i = 0;
	while (++i < 500) {
		x2 = data->x1 + (i * cos(data->val * (data->angle - 60)));
		tmp = x2 - (int)x2;
		if (tmp > (double)0.5)
			x2 += 1;
		y2 = data->y1 + (i * sin(data->val * (data->angle - 60)));
		tmp = y2 - (int)y2;
		if (tmp > (double)0.5)
			y2 += 1;
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 500) {
		x2 = data->x1 + (i * cos(data->val * (data->angle + 60)));
		y2 = data->y1 + (i * sin(data->val * (data->angle + 60)));
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle)));
		y2 = data->y1 + (i * sin(data->val * (data->angle)));
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}

	int checkPozX;
	int checkPozY;
	int checkPozX1;
	int checkPozY1;

	i = 0;
	int k;
	i = data->firstAngle[0];
	while (i++ < data->firstAngle[1] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (((int)data->y1 % 70) + k)*tan(data->val * i);
			checkPozY = data->y1 - k - ((int)data->y1) % 70;
			if (wall_check(*data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 + (70 - ((int)data->x1 % 70) + k)*1/(-tan(data->val * (i)));
			checkPozX1 = data->x1 + k + 70 - ((int)data->x1) % 70;
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX < checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0x00ff00);
			drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		}

	}

	i = data->secAngle[1];
	while (i++ < data->secAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (((int)data->y1 % 70) + k)*(-tan(data->val * i));
			checkPozY = data->y1 - k - ((int)data->y1) % 70;
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 + (((int)data->x1 % 70) + k)*(1/(-tan(data->val * i)));
			checkPozX1 = data->x1 - k - ((int)data->x1) % 70;
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			//drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0x00ff00);
			//drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		}
	}
}
