/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:12:28 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/22 15:12:29 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_v(void)
{
	exit(0);
	return (0);
}

double	interpolate(double st, double end, double i)
{
	return (st + ((end - st) * i));
}

void	make_dxdy(t_inf *inf)
{
	inf->dx = (double)(inf->xmax - inf->xmin) / inf->w;
	inf->dy = (double)(inf->ymax - inf->ymin) / inf->h;
}

void	make_info(t_inf *inf)
{
	inf->color_style = 1;
	inf->xmin = -2;
	inf->xmax = 2;
	inf->ymin = -2;
	inf->ymax = 2;
	inf->cre = -0.7;
	inf->cim = 0.27015;
	inf->w = 1080;
	inf->h = 760;
	inf->imax = 80;
	inf->zoom = 1.05;
	inf->const_change = 0;
	inf->help = 0;
}
