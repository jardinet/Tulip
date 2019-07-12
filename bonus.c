/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 02:29:13 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 02:29:44 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(t_point *p, double angle)
{
	t_point tmp;

	tmp = *p;
	p->x = tmp.x * cos(angle) - tmp.y * sin(angle);
	p->y = tmp.x * sin(angle) + tmp.y * cos(angle);
}
