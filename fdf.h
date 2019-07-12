/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:23:22 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 02:51:31 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>

# define SPACE ' '
# define OK 0
# define NOT_OK 1

# define ISO_ANGLE -0.46373398

# define OFFSET_X 400
# define OFFSET_Y 400
# define WINX 1000
# define WINY 1000
# define DISTANCE 25

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_win
{
	void	*id;
	void	*win_ptr;
	void	*mlx_img;
	char	*buff;
	int		projection;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_win;

typedef struct	s_map
{
	int		x;
	int		y;
	int		**tab;
}				t_map;

void			parsing(char *file, t_map *map);
void			initialisation_window(t_win *w);
void			affichage(t_win *w);
void			fill_img_buffer(t_win *w, int x, int y, int color);
void			get_coordinates(t_win *win, t_map *map);
void			rotation(t_point *p, double angle);

#endif
