/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:56:18 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/04 15:26:56 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_is_sign(int c)
{
	if (c == '-' || c == '+')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_overflow_check(int sign)
{
	if (sign == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		sign_counter;
	int		i;
	long	num;

	sign = 1;
	num = 0;
	i = 0;
	sign_counter = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		sign_counter++;
	}
	while (ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	if (num < 0)
		return (ft_overflow_check(sign));
	if (sign_counter > 1)
		return (0);
	return (num * sign);
}
