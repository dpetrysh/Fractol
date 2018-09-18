/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:05:31 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/22 15:05:32 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_line4(int y, t_inf *inf)
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
			nr = or * or * or - 3 * oi * oi * or + inf->cre;
			ni = 3 * or * or * oi - oi * oi * oi + inf->cim;
		}
		get_blue(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}

void	make_line5(int y, t_inf *inf)
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
			nr = or * or * or - 3 * oi * oi * or + inf->cre;
			ni = 3 * or * or * oi - oi * oi * oi + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}

void	make_line6(int y, t_inf *inf)
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
			nr = or * or * or * or * or - 10 * oi * oi * or * or * or +
				5 * or * oi * oi * oi * oi + inf->cre;
			ni = 5 * or * or * or * or * oi - 10 * oi * oi * oi * or * or +
				oi * oi * oi * oi * oi + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}

void	make_line7(int y, t_inf *inf)
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
			nr = ABS(or * or) - ABS(oi * oi) + inf->cre;
			ni = ABS(2 * or * oi) + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}

void	make_line8(int y, t_inf *inf)
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
			nr = ABS(or * or - oi * oi) + inf->cre;
			ni = 2 * or * oi + inf->cim;
		}
		make_color(y * inf->w + bi.x, (double)bi.i / inf->imax, inf);
	}
}
