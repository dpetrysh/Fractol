/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:22:00 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/21 15:22:01 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_mix(int n, double i, t_inf *inf)
{
	double	t1;

	t1 = 1 - i;
	inf->can[n].a[1] = (int)(9 * t1 * i * i * i * 255);
	inf->can[n].a[2] = (int)(15 * t1 * t1 * i * i * 255);
	inf->can[n].a[0] = (int)(8.5 * t1 * t1 * t1 * i * 255);
}

void	get_blue(int n, double i, t_inf *inf)
{
	double	t1;

	t1 = 1 - i;
	inf->can[n].a[2] = (int)(9 * t1 * i * i * i * 255);
	inf->can[n].a[1] = (int)(15 * t1 * t1 * i * i * 255);
	inf->can[n].a[0] = (int)(8.5 * t1 * t1 * t1 * i * 255);
}

void	get_red(int n, double i, t_inf *inf)
{
	double	t1;

	t1 = 1 - i;
	inf->can[n].a[0] = (int)(9 * t1 * i * i * i * 255);
	inf->can[n].a[1] = (int)(15 * t1 * t1 * i * i * 255);
	inf->can[n].a[2] = (int)(8.5 * t1 * t1 * t1 * i * 255);
}

void	get_green(int n, double i, t_inf *inf)
{
	double	t1;

	t1 = 1 - i;
	inf->can[n].a[0] = (int)(9 * t1 * i * i * i * 255);
	inf->can[n].a[2] = (int)(15 * t1 * t1 * i * i * 255);
	inf->can[n].a[1] = (int)(8.5 * t1 * t1 * t1 * i * 255);
}

void	get_some_color(int n, double i, t_inf *inf)
{
	if (i < 0.33)
	{
		inf->can[n].a[2] = 255 * i;
		inf->can[n].a[1] = 0;
		inf->can[n].a[0] = 0;
	}
	else if (i >= 0.33 && i < 0.66)
	{
		inf->can[n].a[2] = 255 * i;
		inf->can[n].a[1] = 255 * i;
		inf->can[n].a[0] = 0;
	}
	else if (i >= 0.66 && i < 1)
	{
		inf->can[n].a[2] = 255 * i;
		inf->can[n].a[1] = 255 * i;
		inf->can[n].a[0] = 255 * i;
	}
	else
		inf->can[n].i = 0;
}
