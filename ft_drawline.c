#include "cub3D.h"
#include <math.h>
#include <stdlib.h>

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
