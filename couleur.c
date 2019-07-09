/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:04:01 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/10 01:13:43 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>


typedef struct s_color
{
	unsigned int R :8;
	unsigned int V :8;
	unsigned int B :8;
	unsigned int alpha :8;
}				t_color;

int main(void){
	t_color yo;
	yo.R = 65;
	int i = 65970;
	char c = 'N';

printf("as an int \t%d\nas a char %c\n", yo.R, (char)yo.R); 
}
