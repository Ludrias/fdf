/* Algo de tracage de segments */

void	tracage_segment (coordonne_x_gauche, coordonne_y_gauche, coordonne_x_droite, coordonne_y_droite)
{
	int 	coordonne_x;
	int		coordonne_y;
	int		coordonne_x_millieu;
	int		coordonne_y_millieu;
	int		mediane;

	coordonne_x = coordonne_x_gauche;
	coordonne_y = coordonne_y_gauche;
	coordonne_x_millieu = coordonne_x_droite - coordonne_x_gauche;
	coordonne_y_millieu = coordonne_y_droite - coordonne_y_gauche;
	mediane = coordonne_y_millieu / coordonne_x_millieu;

	while (coordonne_x <= coordonne_x_droite)
	{
		mlx_pixel_put(mlx, win, coordonne_x, coordonne_y , 0xFF0000);
		coordonne_y += mediane;
		coordonne_x++;
	}
}