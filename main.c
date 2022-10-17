#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "mlx.h"

#define PI 3.14159265

typedef struct s_data
{
	void *new_img;
	int *new_img_data;
	void *mlx_ptr;
	void *mlx_win;
	double angle;
	double val;
	double x1;
	double y1;
	double tanAnglePoz;
	double tanAngleNeg;
}	t_data;


char map[10][10] = {
	"1111111111",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1111111111",
};


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
	i = 0;
	int k = 0, j = 10;
	if ((data->tanAngleNeg >= 30 && data->tanAngleNeg <= 90) && (data->tanAnglePoz >= 30 && data->tanAnglePoz <= 90))
	{
		while (j--)
		{
			i = -1;
			while (i++ < data->tanAnglePoz)
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x1 + (((int)data->y1 % 70) + k)*tan(data->val * i), data->y1 - k - ((int)data->y1) % 70, 0x00ff00);
			k += 70;
		}
		i,j = 10;
		k = 0;
		while (j--)
		{
			i = 0;
			while (i++ < data->tanAngleNeg)
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x1 + (((int)data->y1 % 70) + k) * (-tan(data->val * i)), data->y1 - k - ((int)data->y1) % 70, 0x00ff00);
			k += 70;
		}}
	// printf("x1: %f, y1: %f, xa1: %f, xb1: %f\n", data->x1, data->y1, tan(data->val * data->angle)*data->x1, tan(data->val * data->angle)*data->y1);

}

int func(int keypress, void *arg) {

	t_data *data;

	data = (t_data *)arg;

	mlx_clear_window(data->mlx_ptr, data->mlx_win);

	if (keypress == 123) {
		data->tanAnglePoz -= 5;
		data->tanAngleNeg += 5;
		data->angle -= 5;
	}
	else if (keypress == 124)
	{
		data->tanAnglePoz += 5;
		data->tanAngleNeg -= 5;
		data->angle += 5;
	}
	else if (keypress == 13) {
		data->y1 = data->y1 + (5 * sin(data->angle * data->val));
		data->x1 = data->x1 + (5 * cos(data->angle * data->val));
	}
	else if (keypress == 1){
		data->y1 = data->y1 - (5 * sin(data->angle * data->val));
		data->x1 = data->x1 - (5 * cos(data->angle * data->val));
	}
	else if (keypress == 0){
		data->y1 = data->y1 - (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 - (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 2){
		data->y1 = data->y1 + (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 + (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 53)
		exit(1);
	if (data->angle == 365)
		data->angle = 5;
	if (data->angle == -5)
		data->angle = 355;
	if ( data->tanAngleNeg == 360 || data->tanAngleNeg == -360)
	{
	data->tanAngleNeg = 0;
	}	
		
	if ( data->tanAnglePoz == 360 || data->tanAnglePoz == -360)
		data->tanAnglePoz = 0;
	makeRay(data);
	//if (data->tanAnglePoz + data->tanAngleNeg == 120){
		printf("val : %f, angle: %f\n x1 %f, y1 %f\npoz : %f, neg: %f\n", data->val, data->angle, data->x1, data->y1, data->tanAnglePoz, data->tanAngleNeg);
	//}
	if (data->tanAnglePoz == 0 && data->tanAngleNeg == -240)
	{
		data->tanAnglePoz = 0;
		data->tanAngleNeg = 120;
	}
	if (data->tanAngleNeg == 0 && data->tanAnglePoz == -240)
	{
		data->tanAnglePoz = 120;
		data->tanAngleNeg = 0;
	}
	return (0);
}

int main() {
	t_data data;


	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 700, 700, "377266");

 	data.new_img = mlx_new_image(data.mlx_ptr, 800, 800);

	int bits_per_pixel;
	int size_line;
	int endian;
	data.new_img_data = (int *)mlx_get_data_addr(data.new_img, &bits_per_pixel, &size_line, &endian);
	int x;
	int y = 0;
	int i = -1;
	int j;

	while (++i < 10) {
		j = -1;
		while (++j < 10) {
			if (map[i][j] == '1') {
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
			else {
				for (int ks = 0; ks < 70; ks++)
					data.new_img_data[(i * 800 * 70) + (j * 70) + (x + (y * 799)) + ks] = 0xff8000;
			}
		}
	}
	double angle, val, x1, x2, y1, y2;
	data.val = PI / 180;
	data.angle = 270;
	data.x1 =  210.187407;
	data.y1 = 309.354930;
	data.tanAnglePoz = 60;
	data.tanAngleNeg = 60;

	float asd = 10.54f;
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.new_img, 0, 0);
	mlx_hook(data.mlx_win, 2, 0, func, (void *)&data);
	makeRay(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
