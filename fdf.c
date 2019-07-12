/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:22:14 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 12:39:03 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **argv)
{
	t_map	map;
	t_win	win;

	if (ac != 2)
		ft_strexit("Invalid number of arguments");
	parsing(argv[1], &map);
	initialisation_window(&win);
	win.project = 1;
	win.c1 = 0x0AC3E0;
	win.c2 = 0xFFC300;
	win.mgic = 1;
	win.offset_x = OFFSET_X;
	win.offset_y = OFFSET_Y;
	win.zoom = DISTANCE;
	get_coordinates(&win, &map);
	affichage(&win, &map);
	return (0);
}
