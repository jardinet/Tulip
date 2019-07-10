/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:22:14 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 02:19:15 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **argv)
{
	t_map	map;

/*	void *mlx_id;    // identitifiant de la connexion au serveur graphique
	void *win_ptr;

	mlx_id = mlx_init();
	win_ptr = mlx_new_window(mlx_id, 500, 500, "My First Window");
	mlx_string_put(mlx_id, win_ptr, 250, 250, 16711680, "Hello there");
	mlx_loop(mlx_id);*/
	if (ac != 2)
		ft_strexit("Invalid number of arguments");
	parsing(argv[1], &map);
	affichage();
/*	algorithm();*/
	return(0);
}
