#include "cub3D.h"
#include <math.h>
#include <stdlib.h>
#include "unistd.h"

#include "stdio.h"
#include "string.h"

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

	//printf("<-------->\n");


	i = data->firstAngle[1];
	while (i < data->firstAngle[0])
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
		float res1, res2;
		res1 = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
		res2 = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
		//printf("x: %d, y: %d, res1: %f, x1: %d, y1: %d, res2: %f\n", checkPozX, checkPozY, res1 , checkPozX1, checkPozY1, res2);

		if (res1 == res2){
			(*d_idx)++;
			data->lastDistances[*d_idx] = res1;
		}
		else if (res1 < res2) {
				img_put_pix(data, checkPozX, checkPozY, 0x00ff00);
				// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = res1;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);
		}
		else{
			img_put_pix(data, checkPozX1, checkPozY1, 0xff0000);

				// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = res2;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
		}
		i += RAYS;
		data->angle_distance -= RAYS;
	}
}
void secArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->secAngle[0];
	while (i > data->secAngle[1])
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
		float res1, res2;
		res1 = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
		res2 = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
		if (res1 == res2){
			(*d_idx)++;
			data->lastDistances[*d_idx] = res1;
		}
		else if (res1 < res2) {
				img_put_pix(data, checkPozX, checkPozY, 0x00ff00);

				// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = res1;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);
		}
		else {
			img_put_pix(data, checkPozX1, checkPozY1, 0xff0000);

				// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = res2;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
		}
		i -= RAYS;
		data->angle_distance -= RAYS;
	}	
}

void thirdArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->thirdAngle[1];
	while (i < data->thirdAngle[0])
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
		float res1, res2;
		res1 = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
		res2 = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
		if (res1 == res2){
			(*d_idx)++;
			data->lastDistances[*d_idx] = res1;
		}
		else if (res1 < res2) {
				img_put_pix(data, checkPozX, checkPozY, 0x00ff00);

			// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = res1;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);

		}
		else {
			img_put_pix(data, checkPozX1, checkPozY1, 0xff0000);

			// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = res2;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
		}
		i += RAYS;
		data->angle_distance -= RAYS;
	}
}

void fourtArea(t_data *data, int *d_idx) {
	int k;
	float i;
	int checkPozX, checkPozY, checkPozX1, checkPozY1;

	i = data->fourthAngle[0];
	while (i > data->fourthAngle[1])
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
		float res1, res2;
		res1 = sqrt(((data->x1 - checkPozX) * (data->x1 - checkPozX)) + \
			((data->y1 - checkPozY) * (data->y1 - checkPozY)))*cos(data->val * (data->angle_distance));
		res2 = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
			((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
		if (res1 == res2){
			(*d_idx)++;
			data->lastDistances[*d_idx] = res1;
		}
		else if (res2 > res1 && i != 90) {
				img_put_pix(data, checkPozX, checkPozY, 0x00ff00);

			// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
			data->lastDistances[++*d_idx] = res1;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX, checkPozY);

		}
		else if (i != 90){
			img_put_pix(data, checkPozX1, checkPozY1, 0xff0000);

			// mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0xff0000);
			data->lastDistances[++*d_idx] = res2;
			data->wall_faces[*d_idx] = wall_face(*data, checkPozX1, checkPozY1);
		}
		if (i == 90) {
			k = 0;
			while (k <= 700) {
				checkPozX1 = 70 - ((int)data->x1 % 70) + data->x1 + k;
				if (wall_check(*data, checkPozX1, data->y1)) {
					data->lastDistances[++*d_idx] = sqrt(((data->x1 - checkPozX1) * (data->x1 - checkPozX1)) + \
					((data->y1 - checkPozY1) * (data->y1 - checkPozY1)))*cos(data->val * (data->angle_distance));
					break ;
				}
				k += 70;
			}
		}
		i -= RAYS;
		data->angle_distance -= RAYS;
	}
}

void makeRay(t_data *data) {
	double i;
	double x2;
	double y2;
	double tmp;

	int d_idx = -1;

	data->angle_distance = 30;
	// data->renderImg.imgRenger_data = mlx_get_data_addr(data->renderImg.imgRender, &data->bits_per_pixel, &data->size_line, &data->endian);
	// printf(">>>%p\n", data->renderImg.imgRenger_data);

	// mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x1, data->y1, 0xff0000);
	

	img_put_pix(data, data->x1, data->y1, 0xff0000);

	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle - 30)));
		tmp = x2 - (int)x2;
		if (tmp > (double)0.5)
			x2 += 1;
		y2 = data->y1 + (i * sin(data->val * (data->angle - 30)));
		tmp = y2 - (int)y2;
		if (tmp > (double)0.5)
			y2 += 1;
		img_put_pix(data, x2, y2, 0xff0000);
		// mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle + 30)));
		y2 = data->y1 + (i * sin(data->val * (data->angle + 30)));
		img_put_pix(data, x2, y2, 0xff0000);
		// mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}
	i = 0;
	while (++i < 100) {
		x2 = data->x1 + (i * cos(data->val * (data->angle)));
		y2 = data->y1 + (i * sin(data->val * (data->angle)));
		img_put_pix(data, x2, y2, 0xff0000);
		// mlx_pixel_put(data->mlx_ptr, data->mlx_win, x2, y2, 0xff0000);
	}

	ft_bzero(data->wall_faces, TOTALRAYS);
	if (((int)data->angle % 360) > 300 && ((int)data->angle % 360) < 330){ 
		secArea(data, &d_idx);
		firstArea(data, &d_idx);
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
	}
	else if (((int)data->angle % 360) > 60 && ((int)data->angle % 360) < 330) {
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
		secArea(data, &d_idx);
		firstArea(data, &d_idx);
	}
	else{
		firstArea(data, &d_idx);
		fourtArea(data, &d_idx);
		thirdArea(data, &d_idx);
		secArea(data, &d_idx);
	}


	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->new_img, 0, 0);


	mlx_clear_window(data->mlx_ptr, data->win2);

	data->renderImg.imgRender = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->renderImg.imgRenger_data = mlx_get_data_addr(data->renderImg.imgRender, &data->renderImg.bits_per_pixel, &data->renderImg.size_line, &data->renderImg.endian);

	int	k;
	int l = 0;
	double angle = 30;
	while (l < TOTALRAYS)
	{
		if (data->lastDistances[l] < 1)
			data->lastDistances[l] =1;
		float	pixel_length = 120000.0f/((data->lastDistances[l]));
		if (pixel_length > 1080)
			pixel_length = 1080;
		int begining_y = 540 - (pixel_length/2);
		k = 0;
		while(k < pixel_length){
			if (data->wall_faces[l] == 'N' || data->wall_faces[l] == 'S')
				img_put_pix2(data, l, begining_y, 0x0ffff0);
			else if (data->wall_faces[l] == 'W' || data->wall_faces[l] == 'E')
				img_put_pix2(data, l, begining_y, 0xfff000);
			else {
				if (ft_pozitionCheck(data, l) == 'S' || ft_pozitionCheck(data, l) == 'N')
					img_put_pix2(data, l, begining_y, 0x0ffff0);
				else
					img_put_pix2(data, l, begining_y, 0xfff000);
			}
			begining_y += 1;
			k+= 1;
		}
		l += 1;
		angle -= RAYS;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win2, data->renderImg.imgRender, 0, 0);
}

/* void	img_put_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	take_texture(t_data *data, int x, int y, int color, int which_wall)
{
	char	*dst;
	dst = data->new_img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	

	*(unsigned int*)dst = color;
} */