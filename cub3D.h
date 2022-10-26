#ifndef CUB3D_H
#define CUB3D_H

#include "mlx.h"

#define PI 3.14159265
#define W 13
#define A 0
#define S 1
#define D 2
#define R 123
#define L 124

typedef	struct s_degree
{
	int ay;
	int ax;
	int by;
	int bx;
	int cy;
	int cx;
	int dy;
	int dx;
}			t_degree;

typedef struct s_data
{
	int bits_per_pixel;
	int bits_per_pixel2;
	int size_line;
	int size_line2;
	int endian;
	int endian2;
	void *new_img;
	int *new_img_data;
	int *new_img_data2;
	void	*img2;
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
	int		*wallLocationsX4;
	int		*wallLocationsY;
	int		*wallLocationsY4;
	void	*win2;
	float	*lastDistances;
}	t_data;

int		wall_check(t_data data, int x, int y);
void	drawLine(int X0, int Y0, int X1, int Y1, t_data *data);
void	makeRay(t_data *data);
int		func(int keypress, t_data *data) ;
char	wall_face(t_data data, int x, int y);
void	ft_wall_location_create(t_data *data, int i, int j);
void	ft_malloc_allocat(t_data *data);
void	ft_wall_counter(t_data *data);
void	ft_put_wall(t_data data);
void	ft_degree_direction_init(t_degree *degree, t_data *data);
void	ft_init_data(t_data *data);
void	ft_render(t_data data);

#endif