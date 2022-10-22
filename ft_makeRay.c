#include "cub3D.h"
#include <math.h>
#include <stdlib.h>
#include "unistd.h"

#include "stdio.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n-- > 0)
		*dest++ = '\0';
}

void firstArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->firstAngle[1];
	while (i < data->firstAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (((int)data->y1 % 70) + k)*tan(data->val * i);
			checkPozY = data->y1 - (((int)data->y1 % 70) + k);
			if (wall_check(*data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 - (70 - ((int)data->x1 % 70) + k)*(1/tan(data->val * i));
			checkPozX1 = data->x1 + (70 - ((int)data->x1 % 70) + k);
			 if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX < checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
		}
		i += 5;
	}
}
void secArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->secAngle[0];
	while (i >= data->secAngle[1])
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 - (((int)data->y1 % 70) + k)*(tan(data->val * i));
			checkPozY = data->y1 - (((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 - (((int)data->x1 % 70) + k)*((1/tan(data->val * i)));
			checkPozX1 = data->x1 - (((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
		}
		i -= 5;
	}	
}

void thirdArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->thirdAngle[1];
	while (i < data->thirdAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 - (70 - ((int)data->y1 % 70) + k)*(tan(data->val * i));
			checkPozY = data->y1 + (70 - ((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 + (((int)data->x1 % 70) + k)*((1/tan(data->val * i)));
			checkPozX1 = data->x1 - (((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
		}
		i += 5;
	}
}

void fourtArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->fourthAngle[0];
	while (i >= data->fourthAngle[1])
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (70 - ((int)data->y1 % 70) + k)*((tan(data->val * i)));
			checkPozY = data->y1 + (70 - ((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
 		while (k <= 700) {
			checkPozY1 = data->y1 + (70 - ((int)data->x1 % 70) + k)*(1/(tan(data->val * i)));
			checkPozX1 = data->x1 + (70 - ((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
 		}
		if (checkPozX1 > checkPozX) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
		}
		else if (checkPozX1 < checkPozX){
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
		}
		i -= 5;
	}
}

void makeRay(t_data *data) {
	double i;
	double x2;
	double y2;
	double tmp;

	int d_idx = -1;


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

	ft_bzero(data->lastDistances, 34);


	if (((int)data->angle % 360) >= 60 && ((int)data->angle % 360) <= 330) {
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
		secArea(data, &d_idx);
		firstArea(data, &d_idx);
	}
	else {
		secArea(data, &d_idx);
		firstArea(data, &d_idx);
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
	}

	int j = -1;
	while (++j < 24)
		printf("%d: %d\n", j, data->lastDistances[j]);



	//----------------------



/* 	printf("fir1: %f, fir2: %f\n sec1: %f, sec2: %f\n thi1: %f, thi2: %f\n for1: %f, for2: %f\n", \
	data->firstAngle[1], data->firstAngle[0], data->secAngle[1], data->secAngle[0], data->thirdAngle[1], data->thirdAngle[0], \
	data->fourthAngle[1], data->fourthAngle[0]); */
/* 	d_idx = -1;
	i = data->firstAngle[1];
	while (i < data->firstAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (((int)data->y1 % 70) + k)*tan(data->val * i);
			checkPozY = data->y1 - (((int)data->y1 % 70) + k);
			if (wall_check(*data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 - (70 - ((int)data->x1 % 70) + k)*(1/tan(data->val * i));
			checkPozX1 = data->x1 + (70 - ((int)data->x1 % 70) + k);
			 if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX < checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->distances[0][++d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
			//drawLine(data->x1, data->y1, checkPozX , checkPozY , data);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->distances[0][++d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
			//drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		}
		i += 5;
	} */
/* 	d_idx = -1;
	while (++d_idx < 24)
		printf("%d: %d\n", d_idx, data->distances[0][d_idx]);  */

/* 	d_idx = (data->secAngle[0] - data->secAngle[1]) / 5;
	i = data->secAngle[1];
	while (i < data->secAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 - (((int)data->y1 % 70) + k)*(tan(data->val * i));
			checkPozY = data->y1 - (((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 - (((int)data->x1 % 70) + k)*((1/tan(data->val * i)));
			checkPozX1 = data->x1 - (((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->distances[1][--d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
			//drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->distances[1][--d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
			//drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		}
		i += 5;
	} */
/* 	d_idx = -1;
	while (++d_idx < 24)
		printf("%d: %d\n", d_idx, data->distances[1][d_idx]);  */


/* 	d_idx = -1;
	i = data->thirdAngle[1];
	while (i < data->thirdAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 - (70 - ((int)data->y1 % 70) + k)*(tan(data->val * i));
			checkPozY = data->y1 + (70 - ((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 + (((int)data->x1 % 70) + k)*((1/tan(data->val * i)));
			checkPozX1 = data->x1 - (((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70;
		}
		if (checkPozX > checkPozX1) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->distances[2][++d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
			//drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->distances[2][++d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
			//drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		}
		i += 5;
	} */
/* 	d_idx = -1;
	while (++d_idx < 24)
		printf("%d: %d\n", d_idx, data->distances[2][d_idx]);  */

/* 	d_idx = (data->fourthAngle[0] - data->fourthAngle[1]) / 5;
	i = data->fourthAngle[1];
	while (i < data->fourthAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (70 - ((int)data->y1 % 70) + k)*((tan(data->val * i)));
			checkPozY = data->y1 + (70 - ((int)data->y1 % 70) + k);
			if (wall_check(* data, checkPozX, checkPozY)) {
				break ;
			}
			k += 70;
		}
		k = 0;
 		while (k <= 700) {
			checkPozY1 = data->y1 + (70 - ((int)data->x1 % 70) + k)*(1/(tan(data->val * i)));
			checkPozX1 = data->x1 + (70 - ((int)data->x1 % 70) + k);
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				break ;
			}
			k += 70; 
 		}
		if (checkPozX1 > checkPozX) {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->distances[3][--d_idx] = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)));
			//drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
		}
		else if (checkPozX1 < checkPozX){
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->distances[3][--d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)));
			//drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		} 
		i+= 5;
	} */
/* 	d_idx = -1;
	while (++d_idx < 24)
		printf("%d: %d\n", d_idx, data->distances[3][d_idx]); */
	
/* 	int k_idx;
	int l_idx = -1;

	printf("---------------%d\n", (int)data->angle % 360);
	d_idx = 4;
	if (((int)data->angle % 360) >= 60 && ((int)data->angle % 360) <= 330) {
		while (--d_idx >= 0) {
			k_idx = -1;
			while (++k_idx < 24) {
				if (data->distances[d_idx][k_idx])
				{
					data->lastDistances[++l_idx] = data->distances[d_idx][k_idx];
				}
			}
		}
	} */
	/* else {
		d_idx = 2;
		while (--d_idx >= 0) {
			k_idx = -1;
			while (++k_idx < 24) {
				if (data->distances[d_idx][k_idx])
					data->lastDistances[++l_idx] = data->distances[d_idx][k_idx];
			}
		}
		d_idx = 4;
		while (--d_idx >= 2) {
			k_idx = -1;
			while (++k_idx < 24) {
				if (data->distances[d_idx][k_idx])
					data->lastDistances[++l_idx] = data->distances[d_idx][k_idx];
			}
		}
	} */

/* 	d_idx = -1;
	while (++d_idx < 24)
		printf("%d: %d\n", d_idx, data->lastDistances[d_idx]); */
}
