/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:37:11 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/21 14:23:35 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_3d(float *x, float *y, t_point *point, t_map *map)
{
	float	x_temp;
	float	x1_temp;

	x_temp = *x;
	x1_temp = point->x1;
	*x = (x_temp - *y) * cos(map->angle);
	*y = (x_temp + *y) * sin(map->angle) - point->z;
	point->x1 = (x1_temp - point->y1) * cos(map->angle);
	point->y1 = (x1_temp + point->y1) * sin(map->angle) - point->z1;
}

int	get_colour(t_point *point, t_map *map)
{
	double	grad;
	int		red;
	int		blue;
	int		green;
	int		colour;

	grad = (double)(point->z - map->min_z) / (double)(map->max_z - map->min_z);
	if (point->z == 0)
		return (0xffffff);
	if (point->z > 0)
	{
		red = 255;
		green = (int)((1 - grad) * 255);
		blue = 0;
	}
	else
	{
		red = 0;
		green = (int)((1 - grad) * 255);
		blue = 255;
	}
	colour = (red << 16 | green << 8 | blue);
	return (colour);
}

void	my_pixel_put(t_var vars, int x, int y, int color)
{
	char	*dst;

	dst = vars.img.pxls_ptr + (y * vars.img.line_len + x * (vars.img.bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_line(float x, float y, t_point point, t_var vars)
{
	point.z = (vars.map->matrix[(int)y][(int)x]);
	point.z1 = (vars.map->matrix[(int)point.y1][(int)point.x1]);
	zoom(&x, &y, &point, vars.map);
	point.colour = get_colour(&point, vars.map);
	make_3d(&x, &y, &point, vars.map);
	shift(&x, &y, &point, vars);
	point.x_step = point.x1 - x;
	point.y_step = point.y1 - y;
	point.max = get_max(absolute(point.x_step), absolute(point.y_step));
	point.x_step /= point.max;
	point.y_step /= point.max;
	while ((int)(x - point.x1) || (int)(y - point.y1))
	{
		if (x >= 0 && x < 1200 && y >= 0 && y < 1200)
		{
			my_pixel_put(vars, x, y, point.colour);
			x += point.x_step;
			y += point.y_step;
		}
		else
			break ;
	}
}

void	draw_map(t_var v)
{
	t_point	point;
	int		x;
	int		y;

	y = -1;
	while (++y < v.map->height)
	{
		x = -1;
		while (++x < v.map->width[y])
		{
			if (x < v.map->width[0] - 1)
			{
				set_point('h', x, y, &point);
				draw_line(x, y, point, v);
			}
			if (y < v.map->height - 1)
			{
				set_point('v', x, y, &point);
				draw_line(x, y, point, v);
			}
		}
	}
	mlx_put_image_to_window(v.map->mlx_ptr, v.map->win_ptr, v.img.imgptr, 0, 0);
}
