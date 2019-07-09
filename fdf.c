/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:22:14 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/09 21:41:18 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **argv)
{
	t_map	map;
	int		i;
	int		j;

/*	void *mlx_id;    // identitifiant de la connexion au serveur graphique
	void *win_ptr;

	mlx_id = mlx_init();
	win_ptr = mlx_new_window(mlx_id, 500, 500, "My First Window");
	mlx_string_put(mlx_id, win_ptr, 250, 250, 16711680, "Hello there");
	mlx_loop(mlx_id);*/
	if (ac != 2)
		ft_strexit("Invalid number of arguments");
	parsing(argv[1], &map);
	i = 0;
	j = 0;
	ft_putnbr(map.x);
	ft_putchar('\n');
	ft_putnbr(map.y);
	ft_putchar('\n');
	while (i < map.y)
	{
		//ft_putendl("coucou ?");
		while(j < map.x)
		{
		ft_putnbr(map.tab[i][j]);
		ft_putchar(SPACE);
		j++;
		}
		j = 0;
		ft_putendl("");
		i++;
	}
/*	algorithm();*/
	return(0);
}
