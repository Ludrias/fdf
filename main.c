/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdoose <qdoose@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 05:37:04 by qdoose            #+#    #+#             */
/*   Updated: 2015/05/05 05:37:08 by qdoose           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	**read_file_map(char *file)
{
	int		fd;
	char	*content;
	char	*line;

	fd = open(file, O_RDONLY);
	content = ft_strjoin("", "");
	while (get_next_line(fd, &line) > 0)
	{
		content = ft_strjoin(content, line);
		content = ft_strjoin(content, "\n");
	}
	return (ft_strsplit(content, '\n'));
}

int		**ft_converttable_chartoint(char **table_temp, int *nbline, int *nbcol)
{
	int		i;
	int 	j;
	char	**table_temp2;
	int		**map;


	i = 0;
	while (table_temp[i])
		i++;
	map = (int **)malloc(sizeof(int *) * i);
	*nbline = i;
	i = 0;
	while (table_temp[i])
	{
		j = 0;
		table_temp2 = ft_strsplit(table_temp[i], ' ');
		while (table_temp2[j])
			j++;
		map[i] = (int *)malloc(sizeof(int) * j);
		*nbcol = j;
		j = 0;
		while (table_temp2[j])
		{
			map[i][j] = ft_atoi(table_temp2[j]);
			free(table_temp2[j]);
			j++;
		}
		i++;
		free(table_temp2);
		free(table_temp[i]);
	}
	free(table_temp);
	return (map);
}

void	draw(void *mlx, void *win, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	printf("%d\n", map->size_line);
	printf("%d\n", map->size_col);
	while(i < map->size_line)
	{
		j = 0;
		while(j < map->size_col)
		{
			mlx_pixel_put(mlx, win, map->size_line + i, map->size_col + j, 0xFF0000);
			mlx_pixel_put(mlx, win, map->size_line + i + 1, map->size_col + j, 0xFF0000);
			mlx_pixel_put(mlx, win, map->size_line + i, map->size_col + j + 1, 0xFF0000);
			mlx_pixel_put(mlx, win, map->size_line + i + 1, map->size_col + j + 1, 0xFF0000);
			j++;
		}
		i++;
	}
}

int 	key_hook(int keycode, t_env *e)
{
	if (e == NULL)
		exit(0);
	if (keycode == 53)
		exit(0);
	return(0);
}

int 	expose_hook(t_env *e)
{
	draw(e->mlx, e->win, e->map);
	return(0);
}

int		main(int argc, char **argv)
{
	char 	**table_tmpchar;
	int 	**table_tmpint;
	int		nbline;
	int		nbcol;
	t_map	map;

	t_env	e;

	if (argc < 2)
	{
		ft_putstr("No file!\n");
		return(0);
	}

	table_tmpchar = read_file_map(argv[1]);
	table_tmpint = ft_converttable_chartoint(table_tmpchar, &nbline, &nbcol);
	map.size_line = nbline;
	map.size_col = nbcol;
	map.nb_point = table_tmpint;
	e.map = &map;

	int 	i;
	int 	j;
	i = 0;
	while (i < map.size_line)
	{
		j = 0;
		while (j < map.size_col)
		{
			printf("%d ", map.nb_point[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, map.size_col * 32, map.size_line * 32, "Fil de fer");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);

	return (0);
}
