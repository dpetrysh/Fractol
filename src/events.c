/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:09:25 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/22 15:09:26 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_inf *inf)
{
	if (inf->const_change)
	{
		inf->cre = (double)2 * (x - inf->w / 2) / inf->w;
		inf->cim = (double)2 * (y - inf->h / 2) / inf->h;
	}
	return (0);
}

void	move_picture(int key, t_inf *inf)
{
	if (key == 124)
	{
		inf->xmin -= (double)(inf->xmax - inf->xmin) / inf->w * 10;
		inf->xmax -= (double)(inf->xmax - inf->xmin) / inf->w * 10;
	}
	else if (key == 123)
	{
		inf->xmin += (double)(inf->xmax - inf->xmin) / inf->w * 10;
		inf->xmax += (double)(inf->xmax - inf->xmin) / inf->w * 10;
	}
	else if (key == 126)
	{
		inf->ymin += (double)(inf->ymax - inf->ymin) / inf->h * 10;
		inf->ymax += (double)(inf->ymax - inf->ymin) / inf->h * 10;
	}
	else if (key == 125)
	{
		inf->ymin -= (double)(inf->ymax - inf->ymin) / inf->h * 10;
		inf->ymax -= (double)(inf->ymax - inf->ymin) / inf->h * 10;
	}
}

void	change_color(int key, t_inf *inf)
{
	if (key == 18)
		inf->color_style = 1;
	else if (key == 19)
		inf->color_style = 2;
	else if (key == 20)
		inf->color_style = 3;
	else if (key == 21)
		inf->color_style = 4;
	else if (key == 23)
		inf->color_style = 5;
}

int		key_hook(int key, t_inf *inf)
{
	if (key == 53)
		exit(0);
	if (key == 32 && inf->imax < 1000)
		inf->imax += 20;
	if (key == 2 && inf->imax > 2)
		inf->imax -= 20;
	if (key == 4 && !inf->help)
		inf->help = 1;
	else if (key == 4 && inf->help)
		inf->help = 0;
	move_picture(key, inf);
	change_color(key, inf);
	if (key == 49 && !inf->const_change)
		inf->const_change = 1;
	else if (key == 49 && inf->const_change)
		inf->const_change = 0;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_inf *inf)
{
	double mouse_x;
	double mouse_y;
	double zoom;

	zoom = 1.0;
	mouse_x = (double)x / (inf->w / (inf->xmax - inf->xmin)) + inf->xmin;
	mouse_y = (double)y / (inf->h / (inf->ymax - inf->ymin)) + inf->ymin;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom /= inf->zoom;
		else if (inf->xmax - inf->xmin < 100000)
			zoom *= inf->zoom;
		inf->xmin = interpolate(mouse_x, inf->xmin, zoom);
		inf->ymin = interpolate(mouse_y, inf->ymin, zoom);
		inf->xmax = interpolate(mouse_x, inf->xmax, zoom);
		inf->ymax = interpolate(mouse_y, inf->ymax, zoom);
	}
	return (0);
}
