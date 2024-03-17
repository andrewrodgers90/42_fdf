/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:03:31 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/19 15:26:23 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_max(float x, float y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

float	absolute(float n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}
