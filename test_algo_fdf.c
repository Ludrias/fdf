/* Algo de tracage de segments 

		Merci : http://morpheo.inrialpes.fr/people/Boyer/Teaching/RICM/c2.pdf */

void	tracage_segment_simple (coordonne_x_gauche, coordonne_y_gauche, coordonne_x_droite, coordonne_y_droite)
{
	int 	coordonne_x;
	int		coordonne_y;
	int		coordonne_x_millieu;
	int		coordonne_y_millieu;
	int		moyenne_coordonne;

	coordonne_x = coordonne_x_gauche;
	coordonne_y = coordonne_y_gauche;
	coordonne_x_millieu = coordonne_x_droite - coordonne_x_gauche;
	coordonne_y_millieu = coordonne_y_droite - coordonne_y_gauche;
	moyenne_coordonne = coordonne_y_millieu / coordonne_x_millieu;

	while (coordonne_x <= coordonne_x_droite)
	{
		mlx_pixel_put(mlx, win, coordonne_x, coordonne_y , 0xFF0000);
		coordonne_y += moyenne_coordonne;
		coordonne_x++;
	}
	return;
}

void	tracage_segment_Bresenham_entier(coordonne_x_gauche, coordonne_y_gauche, coordonne_x_droite, coordonne_y_droite)
{
	int 	coordonne_x;
	int		coordonne_y;
	int		coordonne_x_millieu;
	int		coordonne_y_millieu;
	int 	incrementation_est;
	int 	incrementation_nordest;
	int 	moyenne_coordonne_double;

	coordonne_x = coordonne_x_gauche;
	coordonne_y = coordonne_y_gauche;
	coordonne_x_millieu = coordonne_x_droite - coordonne_x_gauche;
	coordonne_y_millieu = coordonne_y_droite - coordonne_y_gauche;
	incrementation_est = coordonne_y_millieu << 1;
	incrementation_nordest = (coordonne_y_millieu - coordonne_x_millieu) << 1;
	moyenne_coordonne_double = (coordonne_y_millieu << 1) - coordonne_x_millieu;

	while (coordonne_x <= coordonne_x_droite)
	{
		mlx_pixel_put(mlx, win, coordonne_x, coordonne_y , 0xFF0000);
		if (moyenne_coordonne_double >= 0)
		{
			coordonne_y += 1;
			moyenne_coordonne_double += incrementation_nordest;
		}
		else
			moyenne_coordonne_double += incrementation_est;
		coordonne_x++;
	}
}

