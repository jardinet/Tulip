/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:06:49 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 12:38:19 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project(int x, int y, int z, t_win *w)
{
	t_point point;

	if (w->project == ISO)
	{
		point.x = w->offset_x + ((x + y) * cos(ISO_ANGLE)) * w->zoom;
		point.y = w->offset_y + ((x - y) * sin(ISO_ANGLE) - z * 0.7) * w->zoom;
	}
	if (w->project == CAVALIERE)
	{
		point.x = w->offset_x + (x + PARA_ANGLE * y) * w->zoom;
		point.y = w->offset_y + (y + PARA_ANGLE * -z) * w->zoom;
	}
	if (w->project == PLANETE)
	{
		point.x = w->offset_x + ((x + y) * cos(0.05)) * w->zoom * y * 0.05;
		point.y = w->offset_y + ((x - y) * sin(0.90) - z * 0.7) * w->zoom *
			0.05 * x;
	}
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
		fill_img_buffer(w, a.x, a.y, w->color & 0xFFFFFF);
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
		fill_img_buffer(w, a.x, a.y, w->color & 0xFFFFFF);
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

void	get_coordinates(t_win *w, t_map *m)
{
	t_point	cur;
	t_point	pt_a;
	t_point	pt_b;

	cur.y = -1;
	while (++cur.y < m->y)
	{
		cur.x = -1;
		while (++cur.x < m->x)
		{
			w->color = glow(w->c1, w->c2, w->mgic * (float)cur.y / (float)m->y);
			if (cur.x != m->x - 1)
			{
				pt_a = project(cur.x, cur.y, m->tab[cur.y][cur.x], w);
				pt_b = project(cur.x + 1, cur.y, m->tab[cur.y][cur.x + 1], w);
				octant_management(w, pt_a, pt_b);
			}
			if (cur.y != m->y - 1)
			{
				pt_a = project(cur.x, cur.y, m->tab[cur.y][cur.x], w);
				pt_b = project(cur.x, cur.y + 1, m->tab[cur.y + 1][cur.x], w);
				octant_management(w, pt_a, pt_b);
			}
		}
	}
}
