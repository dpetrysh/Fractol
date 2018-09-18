/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 18:13:37 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/17 18:13:38 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		write_fract(t_inf *inf)
{
	int		i;
	void	*res;

	i = -1;
	if (pthread_create(&inf->thread[0], NULL, write_part0, inf) == -1)
		perror("Can't create thread[0]");
	if (pthread_create(&inf->thread[1], NULL, write_part1, inf) == -1)
		perror("Can't create thread[1]");
	if (pthread_create(&inf->thread[2], NULL, write_part2, inf) == -1)
		perror("Can't create thread[2]");
	if (pthread_create(&inf->thread[3], NULL, write_part3, inf) == -1)
		perror("Can't create thread[3]");
	if (pthread_join(inf->thread[0], &res) == -1)
		perror("Can't join thread[0]");
	if (pthread_join(inf->thread[1], &res) == -1)
		perror("Can't join thread[1]");
	if (pthread_join(inf->thread[2], &res) == -1)
		perror("Can't join thread[2]");
	if (pthread_join(inf->thread[3], &res) == -1)
		perror("Can't join thread[3]");
	mlx_clear_window(inf->env.mlx, inf->env.win);
	mlx_put_image_to_window(inf->env.mlx, inf->env.win, inf->env.img, 0, 0);
	print_iterations(inf);
	return (0);
}

void	*write_part0(void *p)
{
	int		y;
	t_inf	*inf;

	y = -1;
	inf = (t_inf *)p;
	while (++y < inf->h / 4)
	{
		if (inf->fract == 1)
			make_line1(y, inf);
		if (inf->fract == 2)
			make_line2(y, inf);
		if (inf->fract == 3)
			make_line3(y, inf);
		if (inf->fract == 4)
			make_line4(y, inf);
		if (inf->fract == 5)
			make_line5(y, inf);
		if (inf->fract == 6)
			make_line6(y, inf);
		if (inf->fract == 7)
			make_line7(y, inf);
		if (inf->fract == 8)
			make_line8(y, inf);
	}
	return (NULL);
}

void	*write_part1(void *p)
{
	int		y;
	t_inf	*inf;

	inf = (t_inf *)p;
	y = inf->h / 4 - 1;
	while (++y < inf->h / 2)
	{
		if (inf->fract == 1)
			make_line1(y, inf);
		if (inf->fract == 2)
			make_line2(y, inf);
		if (inf->fract == 3)
			make_line3(y, inf);
		if (inf->fract == 4)
			make_line4(y, inf);
		if (inf->fract == 5)
			make_line5(y, inf);
		if (inf->fract == 6)
			make_line6(y, inf);
		if (inf->fract == 7)
			make_line7(y, inf);
		if (inf->fract == 8)
			make_line8(y, inf);
	}
	return (NULL);
}

void	*write_part2(void *p)
{
	int		y;
	t_inf	*inf;

	inf = (t_inf *)p;
	y = inf->h / 2 - 1;
	while (++y < inf->h * 3 / 4)
	{
		if (inf->fract == 1)
			make_line1(y, inf);
		if (inf->fract == 2)
			make_line2(y, inf);
		if (inf->fract == 3)
			make_line3(y, inf);
		if (inf->fract == 4)
			make_line4(y, inf);
		if (inf->fract == 5)
			make_line5(y, inf);
		if (inf->fract == 6)
			make_line6(y, inf);
		if (inf->fract == 7)
			make_line7(y, inf);
		if (inf->fract == 8)
			make_line8(y, inf);
	}
	return (NULL);
}

void	*write_part3(void *p)
{
	int		y;
	t_inf	*inf;

	inf = (t_inf *)p;
	y = inf->h * 3 / 4 - 1;
	while (++y < inf->h)
	{
		if (inf->fract == 1)
			make_line1(y, inf);
		if (inf->fract == 2)
			make_line2(y, inf);
		if (inf->fract == 3)
			make_line3(y, inf);
		if (inf->fract == 4)
			make_line4(y, inf);
		if (inf->fract == 5)
			make_line5(y, inf);
		if (inf->fract == 6)
			make_line6(y, inf);
		if (inf->fract == 7)
			make_line7(y, inf);
		if (inf->fract == 8)
			make_line8(y, inf);
	}
	return (NULL);
}
