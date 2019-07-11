/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:06:49 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/11 15:15:03 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Projection takes 3d coordinates (x, y, z) and gives us 2d ones (x, y)
*/
t_point	projection(int x, int y, int z)
{
	t_point point;

	point.x = OFFSET_X + ((x + y) * cos(ISO_ANGLE)) * DISTANCE;
	point.y = OFFSET_Y + ((x - y) * sin(ISO_ANGLE) - z) * DISTANCE;
	return (point);
}

/*
Iterate the map to get the two points between which we bresenham
*/

void	fill_img_buffer(t_win *w, int x, int y)
{
	int position;
	char color = (char)255;

	if (0 <= x && x < WINX && 0 <= y && y < WINY)
	{
		position = y * w->sizeline + (x * 4);
		w->buff[position] = color;
		w->buff[position + 1] = color;
		w->buff[position + 2] = color;
	}
}

void	bresenham(t_win *w, t_point a, t_point b)
{
	int		di;
	int		dx;
	int		dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	di = 2 * dy - dx;

	while (a.x != b.x && a.y != b.y)
	{
		if (di >= 0)
		{
			di = di + 2 * dy - 2 * dx;
			a.x = a.x + 1;
			a.y = a.y + 1;
		}
		else
		{
		di = di + 2 * dy;
		a.x = a.x + 1;
		a.y = a.y;
		}
		fill_img_buffer(w, a.x, a.y);
	}
}


void	get_coordinates(t_win *w, t_map *map)
{
	int		cur_x;
	int		cur_y;
	t_point	pt_a;
	t_point	pt_b;

	cur_x = 0;
	cur_y = 0;
	while (cur_y < map->y - 1)
	{
		cur_x = 0;
		while(cur_x < map->x - 1)
		{
			if (cur_x != map->x)
			{
				pt_a = projection(cur_x, cur_y, map->tab[cur_y][cur_x]);
				pt_b = projection(cur_x + 1 , cur_y, map->tab[cur_y][cur_x]);
				bresenham(w, pt_a, pt_b);
				// bresenham(cur_x, cur_y, cur_x + 1, cur_y); // droite
			}
			if (cur_y != map->y)
			{
				pt_a = projection(cur_x, cur_y, map->tab[cur_y][cur_x]);
				pt_b = projection(cur_x, cur_y + 1, map->tab[cur_y][cur_x]);
				bresenham(w, pt_a, pt_b);
				// bresenham(cur_x, cur_y, cur_x, cur_y  + 1); // bas
			}
			cur_x++;
		}
		cur_y++;
	}
}


