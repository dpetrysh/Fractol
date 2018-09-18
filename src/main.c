/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:16:57 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/14 16:16:59 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		true_arg(char *arg, t_inf *inf)
{
	if (ft_strstr(arg, "julia") && ft_strstr("julia", arg) &&
		(inf->fract = 1))
		return (1);
	if (ft_strstr(arg, "mandelbrot") && ft_strstr("mandelbrot", arg) &&
		(inf->fract = 2))
		return (1);
	if (ft_strstr(arg, "tricorn") && ft_strstr("tricorn", arg) &&
		(inf->fract = 3))
		return (1);
	if (ft_strstr(arg, "multibrot") && ft_strstr("multibrot", arg) &&
		(inf->fract = 4))
		return (1);
	if (ft_strstr(arg, "multijulia") && ft_strstr("multijulia", arg) &&
		(inf->fract = 5))
		return (1);
	if (ft_strstr(arg, "superstar") && ft_strstr("superstar", arg) &&
		(inf->fract = 6))
		return (1);
	if (ft_strstr(arg, "ship") && ft_strstr("ship", arg) && (inf->fract = 7))
		return (1);
	if (ft_strstr(arg, "mushroom") && ft_strstr("mushroom", arg) &&
		(inf->fract = 8))
		return (1);
	return (0);
}

void	make_color(int n, double i, t_inf *inf)
{
	if (inf->color_style == 1)
		get_mix(n, i, inf);
	if (inf->color_style == 2)
		get_blue(n, i, inf);
	if (inf->color_style == 3)
		get_red(n, i, inf);
	if (inf->color_style == 4)
		get_green(n, i, inf);
	if (inf->color_style == 5)
		get_some_color(n, i, inf);
}

int		main(int ac, char **av)
{
	t_inf	inf;

	if (ac == 2 && true_arg(av[1], &inf))
	{
		make_info(&inf);
		inf.env.mlx = mlx_init();
		inf.env.win = mlx_new_window(inf.env.mlx, inf.w, inf.h, "mlx42");
		inf.env.img = mlx_new_image(inf.env.mlx, inf.w, inf.h);
		inf.can = (union u_pix *)mlx_get_data_addr(inf.env.img, &inf.bpp,
			&inf.sizeline, &inf.endian);
		mlx_mouse_hook(inf.env.win, mouse_hook, &inf);
		mlx_loop_hook(inf.env.mlx, write_fract, &inf);
		mlx_hook(inf.env.win, 2, 5, key_hook, &inf);
		mlx_hook(inf.env.win, 6, 6, mouse_move, &inf);
		mlx_hook(inf.env.win, 17, 1L << 17, exit_v, &inf);
		mlx_loop(inf.env.mlx);
	}
	print_usage();
	return (0);
}
