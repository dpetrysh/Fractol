/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:13:13 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/22 15:13:14 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_inf *inf)
{
	mlx_string_put(inf->env.mlx, inf->env.win, 10, 30, 0xFFFFFF,
		"Zoom : the weel");
	mlx_string_put(inf->env.mlx, inf->env.win, 10, 50, 0xFFFFFF,
		"Move fractal : direction keys");
	mlx_string_put(inf->env.mlx, inf->env.win, 10, 70, 0xFFFFFF,
		"Change color mode : '1' '2' '3' '4' '5' keys");
	mlx_string_put(inf->env.mlx, inf->env.win, 10, 90, 0xFFFFFF,
		"Make more iterations : 'u' key");
	mlx_string_put(inf->env.mlx, inf->env.win, 10, 110, 0xFFFFFF,
		"Make smaller iterations : 'd' key");
	mlx_string_put(inf->env.mlx, inf->env.win, 10, 130, 0xFFFFFF,
		"Express your delight : clap your hands!");
}

void	print_iterations(t_inf *inf)
{
	char *ch;

	mlx_string_put(inf->env.mlx, inf->env.win, 10, 10, 0xFFFFFF,
		ch = ft_itoa(inf->imax));
	free(ch);
	if (inf->help)
		print_help(inf);
}

void	print_usage(void)
{
	write(2, "usage: fractol arg\n", 19);
	write(2, "    arg: julia\n", 15);
	write(2, "    arg: mandelbrot\n", 20);
	write(2, "    arg: tricorn\n", 17);
	write(2, "    arg: multibrot\n", 19);
	write(2, "    arg: multijulia\n", 20);
	write(2, "    arg: superstar\n", 19);
	write(2, "    arg: ship\n", 14);
	write(2, "    arg: mushroom\n", 18);
	exit(1);
}
