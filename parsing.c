/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:35:58 by mwragg            #+#    #+#             */
/*   Updated: 2019/07/12 06:37:09 by mwragg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_char(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == SPACE || (ft_isdigit(line[i]))
				|| (line[i] == '+' && (line[i + 1]
						&& (ft_isdigit(line[i + 1]))))
				|| (line[i] == '-' && (line[i + 1]
						&& (ft_isdigit(line[i + 1])))))
			i++;
		else
			return (NOT_OK);
	}
	return (OK);
}

int		*chain_atoi(char *line, t_map *map)
{
	char	**tmp;
	int		*clean;
	int		i;

	tmp = NULL;
	clean = NULL;
	i = 0;
	if (valid_char(line) == NOT_OK)
		ft_strexit("Error : Invalid map. Only digits please !");
	if (map->x == -1)
		map->x = ft_count_words(line, SPACE);
	if ((map->x == 0) || (map->x != (int)ft_count_words(line, SPACE)))
		ft_strexit("Error : Invalid map");
	tmp = ft_strsplit(line, SPACE);
	clean = (int *)malloc(sizeof(int) * map->x);
	if (clean == NULL || tmp == NULL)
		ft_strexit("Error : Malloc(3) couldn't allocate sufficient memory.");
	while (tmp[i] && i < map->x)
	{
		clean[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (clean);
}

int		get_size_map(char *file)
{
	int	fd;
	int	y;

	y = 0;
	if (((fd = open(file, O_RDONLY)) == -1))
		ft_strexit("Error : Unable to open file");
	while (get_next_line(fd, &file) > 0)
	{
		free(file);
		y++;
	}
	free(file);
	close(fd);
	return (y);
}

void	parsing(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	map->x = -1;
	map->y = get_size_map(file);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_strexit("Error : Unable to open file.");
	if ((map->tab = (int**)malloc(sizeof(int *) * map->y)) == NULL)
		ft_strexit("Error : Malloc(3) was unable to allocate memory.");
	while (get_next_line(fd, &line) > 0)
	{
		map->tab[i] = chain_atoi(line, map);
		free(line);
		i++;
	}
	free(line);
}
