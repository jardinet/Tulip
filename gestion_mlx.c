/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:11:47 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 21:09:18 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> // TO REMOVE

int		key_events(int key, t_win *w)
{
	(void)w;
if (key == 53)
	exit(0);

printf("Value of key %d\n", key);	
// mlx_clear_window()

return (0);
}

void	affichage(t_win *w) 
{
	mlx_put_image_to_window(w->id, w->win_ptr, w->mlx_img, 0, 0);
	mlx_key_hook(w->win_ptr, key_events, w);
	mlx_loop(w->id);
}

void	initialisation_window(t_win *w)
{
	w->id = mlx_init();
	w->win_ptr = mlx_new_window(w->id, WINX, WINY, "The Winx adventures");
	w->mlx_img = mlx_new_image(w->id, WINX, WINY);
	w->buff = mlx_get_data_addr(w->mlx_img, &w->bpp, &w->sizeline, &w->endian);
}
