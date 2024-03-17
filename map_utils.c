/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:39:22 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/19 17:12:45 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(char *str, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			word_count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (word_count);
}

int	get_min_z(t_map *map)
{
	int	min;
	int	y;
	int	x;

	min = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width[y])
		{
			if (map->matrix[y][x] < min)
				min = map->matrix[y][x];
			x++;
		}
		y++;
	}
	return (min);
}

int	get_max_z(t_map *map)
{
	int	max;
	int	y;
	int	x;

	max = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width[y])
		{
			if (map->matrix[y][x] > max)
				max = map->matrix[y][x];
			x++;
		}
		y++;
	}
	return (max);
}

int	*get_width(t_map *map)
{
	int		i;
	int		*tab;
	char	*line;

	i = 0;
	tab = (int *)malloc(sizeof(int) * map->height);
	if (NULL == tab)
		handle_error(5);
	map->fd = ft_open(map->file);
	line = get_next_line(map->fd);
	while (line)
	{
		tab[i] = count_words(line, ' ');
		free(line);
		line = get_next_line(map->fd);
		i++;
	}
	free(line);
	close(map->fd);
	return (tab);
}

int	get_height(t_map *map)
{
	int		height;
	char	*line;

	map->fd = ft_open(map->file);
	line = get_next_line(map->fd);
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	close(map->fd);
	return (height);
}
