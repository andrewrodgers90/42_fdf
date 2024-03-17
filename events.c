/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:13:20 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/21 14:24:43 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int key_code, t_map *map)
{
	if (key_code == 17)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
	return (0);
}

void	rotate_image(int key, t_var *vars)
{
	if (key == 0)
		vars->map->angle += 0.1;
	else if (key == 2)
		vars->map->angle -= .1;
}

void	zoom_image(int key, t_var *vars)
{
	if (key == 24)
		vars->map->zoom += vars->map->zoom_factor;
	else if (key == 27)
		vars->map->zoom -= vars->map->zoom_factor;
}

void	move_image(int key, t_var *vars)
{
	if (key == 124)
		vars->map->x_offset += 10;
	else if (key == 126)
		vars->map->y_offset -= 10;
	else if (key == 123)
		vars->map->x_offset -= 10;
	else if (key == 125)
		vars->map->y_offset += 10;
}

int	read_keys(int key, t_var *vars)
{
	mlx_destroy_image(vars->map->mlx_ptr, vars->img.imgptr);
	vars->img.imgptr = mlx_new_image(vars->map->mlx_ptr, 1200, 1200);
	if (key == 124 || key == 126 || key == 123 || key == 125)
	{
		move_image(key, vars);
	}
	else if (key == 24 || key == 27)
	{
		zoom_image(key, vars);
	}
	else if (key == 0 || key == 2)
	{
		rotate_image(key, vars);
	}
	else if (key == 53)
	{
		mlx_destroy_window(vars->map->mlx_ptr, vars->map->win_ptr);
		exit(0);
	}
	mlx_clear_window(vars->map->mlx_ptr, vars->map->win_ptr);
	draw_map(*vars);
	return (0);
}
