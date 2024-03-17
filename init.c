/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:24:24 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/21 14:24:10 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_var *vars)
{
	vars->map->mlx_ptr = mlx_init();
	if (NULL == vars->map->mlx_ptr)
	{
		free(vars->map);
		handle_error(3);
	}
	vars->map->win_ptr = mlx_new_window(vars->map->mlx_ptr,
			1200, 1200, vars->map->file);
	if (NULL == vars->map->win_ptr)
	{
		free(vars->map->mlx_ptr);
		handle_error(4);
	}
	vars->img.imgptr = mlx_new_image(vars->map->mlx_ptr, 1200, 1200);
	vars->img.pxls_ptr = mlx_get_data_addr(vars->img.imgptr, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
}

t_map	*init_map(char *file, t_map *map)
{
	map->file = file;
	map->height = get_height(map);
	map->width = get_width(map);
	map->angle = 0.5;
	map->x_offset = 600;
	map->y_offset = 400;
	map->zoom = get_zoom(map);
	map->zoom_factor = get_zoom_factor(map->zoom);
	map->fd = ft_open(map->file);
	allocate_map(map);
	map->max_z = get_max_z(map);
	map->min_z = get_min_z(map);
	return (map);
}
