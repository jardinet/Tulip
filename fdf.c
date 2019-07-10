/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:22:14 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 21:12:03 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **argv)
{
	t_map	map;
	t_win	win;

	if (ac != 2)
		ft_strexit("Invalid number of arguments");
	parsing(argv[1], &map);
	initialisation_window(&win);
/*	algorithm();*/
	affichage(&win);
	return(0);
}
