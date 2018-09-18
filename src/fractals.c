/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:59:34 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/21 14:59:34 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_line1(int y, t_inf *inf)
{
	double	nr;
	double	ni;
	double	or;
	double	oi;
	t_bi	bi;

	make_dxdy(inf);
	bi.x = -1;
	while (++bi.x < inf->w)
	{
		nr = 1.5 * (inf->xmin + inf->dx * bi.x);
		ni = inf->ymin + y * inf->dy;
		bi.i = -1;
		while ((nr * nr + ni * ni) <= 4 && ++bi.i < inf->imax)
		{
			or = nr;
			oi = ni;
			nr = or * or - oi * oi + inf->cre;
			ni = 2 * or * oi + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}

void	make_line2(int y, t_inf *inf)
{
	double	nr;
	double	ni;
	double	or;
	double	oi;
	t_bi	bi;

	make_dxdy(inf);
	bi.x = -1;
	while (++bi.x < inf->w)
	{
		inf->cre = inf->xmin + inf->dx * bi.x;
		inf->cim = inf->ymin + y * inf->dy;
		nr = 0;
		ni = 0;
		bi.i = -1;
		while ((nr * nr + ni * ni) <= 4 && ++bi.i < inf->imax)
		{
			or = nr;
			oi = ni;
			nr = or * or - oi * oi + inf->cre;
			ni = 2 * or * oi + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}

void	make_line3(int y, t_inf *inf)
{
	double	nr;
	double	ni;
	double	or;
	double	oi;
	t_bi	bi;

	make_dxdy(inf);
	bi.x = -1;
	while (++bi.x < inf->w)
	{
		inf->cre = inf->xmin + inf->dx * bi.x;
		inf->cim = inf->ymin + y * inf->dy;
		nr = 0;
		ni = 0;
		bi.i = -1;
		while ((nr * nr + ni * ni) <= 4 && ++bi.i < inf->imax)
		{
			or = nr;
			oi = ni;
			nr = or * or - oi * oi + inf->cre;
			ni = -2 * or * oi + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}
