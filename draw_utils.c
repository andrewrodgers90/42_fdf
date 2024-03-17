/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:02:34 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/19 15:26:36 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_point(int c, int x, int y, t_point *point)
{
	if (c == 'h')
	{
		point->x1 = x + 1;
		point->y1 = y;
	}
	else if (c == 'v')
	{
		point->x1 = x;
		point->y1 = y + 1;
	}
}

void	zoom(float *x, float *y, t_point *point, t_map *map)
{
	*x *= map->zoom;
	*y *= map->zoom;
	point->x1 *= map->zoom;
	point->y1 *= map->zoom;
}

void	shift(float *x, float *y, t_point *point, t_var vars)
{
	*x += vars.map->x_offset;
	*y += vars.map->y_offset;
	point->x1 += vars.map->x_offset;
	point->y1 += vars.map->y_offset;
}
