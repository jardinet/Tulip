/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:06:49 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 02:44:29 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	projection(int x, int y, int z)
{
	t_point point;

	point.x = OFFSET_X + ((x + y) * cos(ISO_ANGLE)) * DISTANCE;
	point.y = OFFSET_Y + ((x - y) * sin(ISO_ANGLE) - z) * DISTANCE;
	return (point);
}

void	bresenham(t_win *w, t_point a, t_point b)
{
	int	di;
	int	dx;
	int	dy;
	int	yi;

	dx = b.x - a.x;
	dy = b.y - a.y;
	yi = 1;
	if (dy < 0)
	{
		dy = -dy;
		yi = -1;
	}
	di = 2 * dy - dx;
	while (a.x != b.x || a.y != b.y)
	{
		if (di > 0)
		{
			di -= 2 * dx;
			a.y += yi;
		}
		di += 2 * dy;
		a.x += 1;
		fill_img_buffer(w, a.x, a.y, 0xFFFFFF);
	}
}

void	bresenham_second_case(t_win *w, t_point a, t_point b)
{
	int	di;
	int	dx;
	int	dy;
	int	xi;

	dx = b.x - a.x;
	dy = b.y - a.y;
	xi = 1;
	if (dx < 0)
	{
		dx = -dx;
		xi = -1;
	}
	di = 2 * dx - dy;
	while (a.x != b.x || a.y != b.y)
	{
		if (di > 0)
		{
			di -= 2 * dy;
			a.x += xi;
		}
		di += 2 * dx;
		a.y += 1;
		fill_img_buffer(w, a.x, a.y, 0xFFFFFF);
	}
}

void	octant_management(t_win *w, t_point a, t_point b)
{
	int	dx;
	int	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dy) > abs(dx))
	{
		if (dy < 0)
			bresenham_second_case(w, b, a);
		else
			bresenham_second_case(w, a, b);
	}
	else
	{
		if (dx < 0)
			bresenham(w, b, a);
		else
			bresenham(w, a, b);
	}
}

void	get_coordinates(t_win *w, t_map *map)
{
	int		cur_x;
	int		cur_y;
	t_point	pt_a;
	t_point	pt_b;

	cur_y = -1;
	while (++cur_y < map->y)
	{
		cur_x = -1;
		while (++cur_x < map->x)
		{
			if (cur_x != map->x - 1)
			{
				pt_a = projection(cur_x, cur_y, map->tab[cur_y][cur_x]);
				pt_b = projection(cur_x + 1, cur_y, map->tab[cur_y][cur_x + 1]);
				octant_management(w, pt_a, pt_b);
			}
			if (cur_y != map->y - 1)
			{
				pt_a = projection(cur_x, cur_y, map->tab[cur_y][cur_x]);
				pt_b = projection(cur_x, cur_y + 1, map->tab[cur_y + 1][cur_x]);
				octant_management(w, pt_a, pt_b);
			}
		}
	}
}
