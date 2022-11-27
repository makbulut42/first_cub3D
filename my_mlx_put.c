#include "cub3D.h"
#include "stdio.h"

void	img_put_pix(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->new_img_data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

void	img_put_pix2(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->renderImg.imgRenger_data + (y * data->renderImg.size_line + x * (data->renderImg.bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}