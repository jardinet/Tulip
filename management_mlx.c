/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 02:24:42 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 03:03:00 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_events(int key, t_win *w)
{
	(void)w;
	if (key == 53)
		exit(0);
	return (0);
}

void	fill_img_buffer(t_win *w, int x, int y, int color)
{
	int	position;
	int	*ptr;

	if (0 <= x && x < WINX && 0 <= y && y < WINY)
	{
		position = y * WINX * 4 + x * 4;
		ptr = (int *)(void*)&w->buff[position];
		*ptr = color;
	}
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
	if ((w->win_ptr = mlx_new_window(w->id, WINX, WINY, "FDF")) == NULL)
		ft_strexit("Error : MLX failed to initialise window.");
	if ((w->mlx_img = mlx_new_image(w->id, WINX, WINY)) == NULL)
		ft_strexit("Error : MLX failed to allocate image buffer.");
	w->buff = mlx_get_data_addr(w->mlx_img, &w->bpp, &w->sizeline, &w->endian);
}
