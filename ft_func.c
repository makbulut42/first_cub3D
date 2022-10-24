
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>

#include "stdio.h"

int func(int keypress, void *arg) {

	t_data *data;
	int ay;
	int ax;
	int by;
	int bx;
	int cy;
	int cx;
	int dy;
	int dx;

	data = (t_data *)arg;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	ay = data->y1 + (5 * sin((data->angle) * data->val));
	ax = data->x1 + (5 * cos((data->angle) * data->val));
	by = data->y1 - (5 * sin(data->angle * data->val));
	bx = data->x1 - (5 * cos(data->angle * data->val));
	cy = data->y1 - (5 * sin((data->angle + 90) * data->val));
	cx = data->x1 - (5 * cos((data->angle + 90) * data->val));
	dy = data->y1 + (5 * sin((data->angle + 90) * data->val));
	dx = data->x1 + (5 * cos((data->angle + 90) * data->val));
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
	else if (keypress == 13 && (wall_check(*data, ax, ay) == 0) /*  && (wall_check(*data, data->x1, data->y1 - 5) == 0) */) {
		data->y1 = data->y1 + (5 * sin(data->angle * data->val));
		data->x1 = data->x1 + (5 * cos(data->angle * data->val));
	}
	else if (keypress == 1 && wall_check(*data, bx, by) == 0 /* && (wall_check(*data, data->x1, data->y1 + 5) == 0) */){
		data->y1 = data->y1 - (5 * sin(data->angle * data->val));
		data->x1 = data->x1 - (5 * cos(data->angle * data->val));
	}
	else if (keypress == 0 && wall_check(*data, cx, cy) == 0 && (wall_check(*data, data->x1  - 5, data->y1) == 0)){
		data->y1 = data->y1 - (5 * sin((data->angle + 90) * data->val));
		data->x1 = data->x1 - (5 * cos((data->angle + 90) * data->val));
	}
	else if (keypress == 2 && wall_check(*data, dx, dy) == 0 && (wall_check(*data, data->x1 + 5, data->y1) == 0)){
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
		if (checkAngle >= 210 && checkAngle <= 300) {
			data->firstAngle[1] = 0;
			data->firstAngle[0] = fabs(210 - checkAngle);
		}
		else if (checkAngle >= 330) {
			data->firstAngle[1] = fabs(330 - checkAngle);
			data->firstAngle[0] = 90;
		}
		else if (checkAngle <= 60) {
			data->firstAngle[1] = fabs(30 + checkAngle);
			data->firstAngle[0] = 90;
		}
		// printf("f: %f, s: %f angle: %f\n", data->firstAngle[0], data->firstAngle[1], checkAngle);

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
	if ((checkAngle <= 240 && checkAngle >= 30)) {
		if (checkAngle >= 120 && checkAngle <= 240) {
			data->thirdAngle[0] = 90;
			if (checkAngle >= 150 && checkAngle <= 240)
				data->thirdAngle[1] = 90 - fabs(240 - checkAngle);
			else
				data->thirdAngle[1] = 0;
		}
		else if (checkAngle < 120) {
			data->thirdAngle[0] = 90 - fabs(120 - checkAngle);
			data->thirdAngle[1] = 0;
		}

	}
	if (!(checkAngle < 300 && checkAngle > 150)) {
        if (!(checkAngle < 300 && checkAngle > 60)) {
            data->fourthAngle[0] = 90;
            if (checkAngle >= 300 && checkAngle < 360)
                data->fourthAngle[1] = 90 - fabs(300 - checkAngle);
            else if (!(checkAngle > 30))
                data->fourthAngle[1] = 30 - checkAngle;
            else
                data->thirdAngle[1] = 0;
        }
        else if (checkAngle <= 150) {
            data->fourthAngle[0] = 90 - fabs(60 - checkAngle);
            data->fourthAngle[1] = 0;
        }
	}
	makeRay(data);
	return (0);
}