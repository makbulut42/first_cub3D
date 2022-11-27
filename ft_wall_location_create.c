
void	ft_wall_location_create(int *wallLocationX, int *wallLocationY, int i, int j)
{
	static int a;

	wallLocationX[a] = (j * 70);
	wallLocationY[a] = (i * 70);
	a++;
	wallLocationX[a] = (j * 70 + 70);
	wallLocationY[a] = (i * 70);
	a++;
	wallLocationX[a] = (j * 70);
	wallLocationY[a] = (i * 70 + 70);
	a++;
	wallLocationX[a] = (j * 70 + 70);
	wallLocationY[a] = (i * 70 + 70);
	a++;
}
