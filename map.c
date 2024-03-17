/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:41:45 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/19 17:12:04 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(char *line, int *width)
{
	int		i;
	char	**digits;

	digits = ft_split(line, ' ');
	i = 0;
	while (digits[i])
	{
		width[i] = ft_atoi(digits[i]);
		free(digits[i]);
		i++;
	}
	free(digits);
}

void	allocate_map(t_map *map)
{
	int		i;

	map->matrix = (int **)malloc(sizeof(int *) * map->height);
	if (NULL == map->matrix)
		handle_error(2);
	i = -1;
	while (++i < map->height)
	{
		map->matrix[i] = (int *)malloc(sizeof(int) * map->width[i]);
		if (NULL == map->matrix[i])
		{
			free_matrix(i, map);
			handle_error(2);
		}
	}
	map->line = get_next_line(map->fd);
	i = -1;
	while (++i < map->height)
	{
		fill_map(map->line, map->matrix[i]);
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	free(map->line);
	close(map->fd);
}
