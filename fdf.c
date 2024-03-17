/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:19:54 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/21 14:22:20 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_instructions(void)
{
	write(1, "\n", 1);
	write(1, "Welcome to Andrew's fdf.\n", 25);
	write(1, "To zoom in or out: '+' or '-'.\n", 31);
	write(1, "To rotate: 'A' or 'D'.\n", 23);
	write(1, "To move: UP/DOWN/LEFT/RIGHT keys.\n", 34);
	write(1, "To close: ESC or 'x' button on 'fdf' window.\n", 45);
	write(1, "\n", 1);
}

void	handle_error(int flag)
{
	if (flag == 1)
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	if (flag == 2)
		ft_putstr_fd("Error allocating memory.\n", 2);
	if (flag == 3)
		ft_putstr_fd("Error initialising mlx pointer.\n", 2);
	if (flag == 4)
		ft_putstr_fd("Error initialising mlx window.\n", 2);
	if (flag == 5)
		ft_putstr_fd("Error initialising array.\n", 2);
	if (flag == 6)
		ft_putstr_fd("Error opening file.\n", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_var	vars;

	if (ac != 2)
		handle_error(1);
	vars.map = (t_map *)malloc(sizeof(t_map));
	if (!vars.map)
		handle_error(2);
	vars.map = init_map(av[1], vars.map);
	init_mlx(&vars);
	print_instructions();
	draw_map(vars);
	mlx_hook(vars.map->win_ptr, 17, 1L << 17, close_window, vars.map);
	mlx_hook(vars.map->win_ptr, 2, 3, read_keys, &vars);
	mlx_loop(vars.map->mlx_ptr);
	return (0);
}
