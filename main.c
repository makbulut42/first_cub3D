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
	double firstAngle[2];
	double secAngle[2];
	double thirdAngle[2];
	double	fourthAngle[2];
	int		wallSize;
	int		*wallLocationsX;
	int		*wallLocationsY;
}	t_data;


char map[10][10] = {
	"1111111111",
	"1010000001",
	"1010000001",
	"1000001001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1000000001",
	"1111111111",
};

int	wall_check(t_data data, int x, int y)
{
	int i;

	i = 0;
	while (data.wallSize > i)
	{
		if ((x < 0 || x > 700) || (y < 0 || y > 700))
			return (0);
		if (data.wallLocationsX[i] <= x && (data.wallLocationsX[i] + 70) >= x  && \
		( data.wallLocationsY[i] <= y && (data.wallLocationsY[i] + 70) >= y))
			return (1);
		i++;
	}	
	return (0);
}

// DDA Function for line generation
void drawLine(int X0, int Y0, int X1, int Y1, t_data *data)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, X, Y, 0x00ff00);
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
    }
}

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
				//drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
				break ;
			}
			k += 70;
		}
		k = 0;
		while (k <= 700) {
			checkPozY1 = data->y1 + (70 - ((int)data->x1 % 70) + k)*1/(-tan(data->val * (i)));
			checkPozX1 = data->x1 + k + 70 - ((int)data->x1) % 70;
			if (wall_check(*data, checkPozX1, checkPozY1)) {
				//drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
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
			drawLine(data->x1, data->y1, checkPozX, checkPozY, data);
		}
		else {
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX1, checkPozY1, 0x00ff00);
			drawLine(data->x1, data->y1, checkPozX1, checkPozY1, data);
		}
	}

/*	k = 0;
	i = data->secAngle[1];
	while (i++ < data->secAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozX = data->x1 + (((int)data->y1 % 70) + k)*(-tan(data->val * i));
			checkPozY = data->y1 - k - ((int)data->y1) % 70;
			if (wall_check(* data, checkPozX, checkPozY)) {
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0x00ff00);
				break ;
			}
			k += 70;
		}
	}*/

/*	k = 0;
	i = data->secAngle[1];
	while (i++ < data->secAngle[0] && i < 90)
	{
		k = 0;
		while (k <= 700) {
			checkPozY = data->y1 + (((int)data->x1 % 70) + k)*(1/(-tan(data->val * i)));
			checkPozX = data->x1 - k - ((int)data->x1) % 70;
			if (wall_check(*data, checkPozX, checkPozY)) {
				mlx_pixel_put(data->mlx_ptr, data->mlx_win, checkPozX, checkPozY, 0xff0f00);
				break ;
			}
			k += 70;
		}
	}
	}*/

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

	if (data->angle == 360 || data->angle == 1080) {
		data->angle = 720;
	}
	
	double checkAngle = abs((int)data->angle % 360);
	if (!(checkAngle > 60 && checkAngle < 210)) {
		if (checkAngle >= 210 && checkAngle < 330) {
			data->firstAngle[0] = 0;
			data->firstAngle[1] = fabs(210 - checkAngle);
		}
		else if (checkAngle >= 330) {
			data->firstAngle[0] = fabs(330 - checkAngle);
			data->firstAngle[1] = 90;
		}
		else if (checkAngle <= 60) {
			data->firstAngle[0] = fabs(30 + checkAngle);
			data->firstAngle[1] = 90;
		}
	}
	if (!(checkAngle > 330 && checkAngle < 120)) {
		if (checkAngle >= 120 && checkAngle < 240) {
			data->secAngle[0] = 90;
			if (checkAngle < 210)
				data->secAngle[1] = fabs(checkAngle - 120 - 90);
			else
				data->secAngle[1] = 0;
		}
		else if (checkAngle >= 240) {
			data->secAngle[0] = 90 - fabs(checkAngle - 240);
			data->secAngle[1] = 0;
		}
	}
	makeRay(data);
	return (0);

}

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
