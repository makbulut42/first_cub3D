#ifndef CUB3D_H
#define CUB3D_H

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

int	wall_check(t_data data, int x, int y);
void drawLine(int X0, int Y0, int X1, int Y1, t_data *data);
void makeRay(t_data *data);
int func(int keypress, void *arg);

#endif