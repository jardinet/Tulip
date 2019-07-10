/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:51:49 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 02:51:53 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // TO REMOVE

int		key_events(int key, void *ptr)
{
(void)ptr;
if (key == 53)
	exit(0);
printf("Value of key %d\n", key);	
return (0);
}

void	affichage() 
{
	void *mlx_id;    // identitifiant de la connexion au serveur graphique
	void *win_ptr;
	void *mlx_img;
	char *buff;

	int bpp;
	int sizeline;
	int endian;

	mlx_id = mlx_init();
	win_ptr = mlx_new_window(mlx_id, WINX, WINY, "Window title: The Winx adventures");
	mlx_img = mlx_new_image(mlx_id, WINX, WINY);
	buff = mlx_get_data_addr(mlx_img, &bpp, &sizeline, &endian);
	mlx_key_hook(win_ptr, key_events, (void*) 0);
	mlx_loop(mlx_id);
}
