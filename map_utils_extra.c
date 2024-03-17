/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:42:44 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/19 15:34:17 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_zoom_factor(float zoom)
{
	float	zoom_factor;

	if (zoom == 1.25)
		zoom_factor = 0.05;
	else if (zoom == 3.0)
		zoom_factor = 0.1;
	else if (zoom == 10.0)
		zoom_factor = 0.25;
	else
		zoom_factor = 1;
	return (zoom_factor);
}

float	get_zoom(t_map *map)
{
	float	zoom;

	map->size = map->height * map->width[0];
	if (map->size >= 250000)
		zoom = 1.25;
	else if (250000 > map->size && map->size >= 10000)
		zoom = 3.0;
	else if (10000 > map->size && map->size >= 1000)
		zoom = 10.0;
	else
		zoom = 20;
	return (zoom);
}
