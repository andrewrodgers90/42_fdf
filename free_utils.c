/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:15:44 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/21 14:22:40 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		handle_error(6);
	return (fd);
}

void	free_matrix(int j, t_map *map)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
}

void	free_mlx(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	free(map->mlx_ptr);
}

void	free_all(t_map *map)
{
	free_matrix(map->height, map);
	exit(0);
}
