/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdoose <qdoose@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 05:48:50 by qdoose            #+#    #+#             */
/*   Updated: 2015/05/05 05:48:53 by qdoose           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_map
{
	int			size_line;
	int			size_col;
	int			**nb_point;
}				t_map;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	t_map		*map;
}				t_env;

#endif
