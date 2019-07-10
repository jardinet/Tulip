/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:23:22 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 21:38:31 by mwragg           ###   ########.fr       */
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

# define ISO_ANGLE 0.46373398
# define OFFSET_X 200
# define OFFSET_Y 200
# define WINX 1000
# define WINY 1000
# define DISTANCE 25

typedef struct s_point 
{
	int		x;
	int		y;
}				t_point;

// typedef struct s_coord
// {
// 	int		xs;
// 	int		ys;
// 	int		xe;
// 	int		ye;
// }				t_coord;


typedef struct	s_win
{
	void	*id;
	void	*win_ptr;
	void	*mlx_img;
	char	*buff;
	int		projection; // 0 = conique, 1 = isometrique

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
void			affichage();
int				get_size_map(char *file);
int				*chain_atoi(char *line, t_map *map);
int				valid_char(char *line);

void			initialisation_window(t_win *w);
void			affichage(t_win *w);

void			bresenham(t_win *w, t_point a, t_point b);
void			get_coordinates(t_win *win, t_map *map);



#endif
