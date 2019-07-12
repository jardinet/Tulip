/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 02:29:13 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 12:36:50 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		glow(int c1, int c2, float perc)
{
	return (((int)((c1 & 0xFF) * perc + (c2 & 0xFF) * (1 - perc)) & 0xFF)
		| ((int)((c1 & 0xFF00) * perc + (c2 & 0xFF00) * (1 - perc)) & 0xFF00)
		| ((int)((c1 & 0xFF0000) * perc + (c2 & 0xFF0000) * (1 - perc))
			& 0xFF0000)
		| ((int)((c1 & 0xFF000000) * perc + (c2 & 0xFF000000) * (1 - perc))
			& 0xFF000000));
}

int		red_cross(void)
{
	exit(0);
}
