/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 02:24:42 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 12:39:41 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		reset(t_mlx_data *data)
{
	ft_bzero(data->win->buff, data->win->sizeline * WINY);
	get_coordinates(data->win, data->map);
	mlx_put_image_to_window(data->win->id, data->win->win_ptr,
			data->win->mlx_img, 0, 0);
	return (0);
}

int				key_events(int key, t_mlx_data *data)
{
	if (key == 53)
		exit(0);
	if (key == 49)
		data->win->project = (data->win->project + 1) % 3;
	if (key == 78 && data->win->zoom * 0.85 > 2)
		data->win->zoom *= 0.85;
	if (key == 69 && data->win->zoom < 1500)
		data->win->zoom *= (data->win->zoom > 4 ? 1.15 : 2);
	if (key == 33)
		data->win->c1 += 1111;
	if (key == 30)
		data->win->c2 -= 1111;
	if (key == 42)
		data->win->mgic += 1;
	if (key == 123)
		data->win->offset_x -= 10;
	if (key == 124)
		data->win->offset_x += 10;
	if (key == 125)
		data->win->offset_y += 10;
	if (key == 126)
		data->win->offset_y -= 10;
	if (key == 67)
		data->win->mgic = 1;
	return (reset(data));
}

void			fill_img_buffer(t_win *w, int x, int y, int color)
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

void			affichage(t_win *w, t_map *map)
{
	t_mlx_data data;

	data.win = w;
	data.map = map;
	mlx_put_image_to_window(w->id, w->win_ptr, w->mlx_img, 0, 0);
	mlx_hook(w->win_ptr, 17, (1L << 17), &red_cross, 0);
	mlx_key_hook(w->win_ptr, key_events, &data);
	mlx_loop(w->id);
}

void			initialisation_window(t_win *w)
{
	if ((w->id = mlx_init()) == NULL)
		ft_strexit(" Error : MLX failed to connect to initialise connection.");
	if ((w->win_ptr = mlx_new_window(w->id, WINX, WINY, "FDF")) == NULL)
		ft_strexit("Error : MLX failed to initialise window.");
	if ((w->mlx_img = mlx_new_image(w->id, WINX, WINY)) == NULL)
		ft_strexit("Error : MLX failed to allocate image buffer.");
	w->buff = mlx_get_data_addr(w->mlx_img, &w->bpp, &w->sizeline, &w->endian);
}
