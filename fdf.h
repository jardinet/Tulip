/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:23:22 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 02:19:01 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define SPACE ' '
# define OK 0
# define NOT_OK 1

# define WINX 800
# define WINY 800

typedef struct	s_map
{
	int		x;
	int		y;
	int		**tab;
}				t_map;

void		parsing(char *file, t_map *map);
void		affichage();
int			get_size_map(char *file);
int			*chain_atoi(char *line, t_map *map);
int			valid_char(char *line);

#endif
