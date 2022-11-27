#ifndef CUB3D_H
#define CUB3D_H

#include "mlx.h"

#define PI 3.14159265
#define RAYS 0.03125
#define TOTALRAYS ((1 / RAYS) * 60)

typedef struct s_img
{
	void	*imgRender;
	char	*imgRenger_data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}	t_img;


typedef struct s_data
{
	int bits_per_pixel;
	int size_line;
	int endian;
	void *new_img;
	char *new_img_data;
	void *mlx_ptr;
	void *mlx_win;
	double angle;
	double val;
	double x1;
	double y1;
	double firstAngle[2];
	double secAngle[2];
	double thirdAngle[2];
	double	fourthAngle[2];
	char	*wall_faces;
	int		wallSize;
	int		*wallLocationsX;
	int		*wallLocationsX4;
	int		*wallLocationsY;
	int		*wallLocationsY4;
	void	*win2;
	float	*lastDistances;
	int		begin;
	double	angle_distance;

	t_img	renderImg;
}	t_data;

int	wall_check(t_data data, int x, int y);
void drawLine(int X0, int Y0, int X1, int Y1, t_data *data);
void makeRay(t_data *data);
int func(int keypress, void *arg);
char wall_face(t_data data, int x, int y);
void	ft_wall_location_create(int *wallLocationX, int *wallLocationY, int i, int j);
void	ft_malloc_allocat(t_data *data);
void	ft_wall_counter(t_data *data);
t_data	ft_put_wall(t_data data);
char	ft_pozitionCheck(t_data *data, int l);
void	img_put_pix(t_data *data, int x, int y, int color);
void	img_put_pix2(t_data *data, int x, int y, int color);
t_data ft_put_wall2(t_data data);



#endif