/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:17:05 by dpetrysh          #+#    #+#             */
/*   Updated: 2018/08/14 16:17:22 by dpetrysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include "libft.h"
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>

# define ABS(x)	((x) < 0 ? -(x) : (x))

union				u_pix
{
	unsigned int	i;
	unsigned char	a[4];
}					t_pix;

typedef struct		s_bi
{
	int				x;
	int				i;
}					t_bi;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_env;

typedef	struct		s_inf
{
	double			dy;
	double			dx;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	pthread_t		thread[4];
	double			cre;
	double			cim;
	double			zoom;
	int				imax;
	int				w;
	int				h;
	int				fract;
	int				color_style;
	bool			const_change;
	bool			help;
	int				bpp;
	int				sizeline;
	int				endian;
	union u_pix		*can;
	t_env			env;
}					t_inf;

void				make_color(int n, double i, t_inf *inf);
int					true_arg(char *arg, t_inf *inf);

int					write_fract(t_inf *inf);
void				*write_part0(void *p);
void				*write_part1(void *p);
void				*write_part2(void *p);
void				*write_part3(void *p);

void				make_line1(int y, t_inf *inf);
void				make_line2(int y, t_inf *inf);
void				make_line3(int y, t_inf *inf);
void				make_line4(int y, t_inf *inf);
void				make_line5(int y, t_inf *inf);
void				make_line6(int y, t_inf *inf);
void				make_line7(int y, t_inf *inf);
void				make_line8(int y, t_inf *inf);

void				get_mix(int n, double i, t_inf *inf);
void				get_blue(int n, double i, t_inf *inf);
void				get_red(int n, double i, t_inf *inf);
void				get_green(int n, double i, t_inf *inf);
void				get_some_color(int n, double i, t_inf *inf);

int					mouse_move(int x, int y, t_inf *inf);
void				move_picture(int key, t_inf *inf);
void				change_color(int key, t_inf *inf);
int					key_hook(int key, t_inf *inf);
int					mouse_hook(int button, int x, int y, t_inf *inf);

int					exit_v(void);
double				interpolate(double st, double end, double i);
void				make_dxdy(t_inf *inf);
void				make_info(t_inf *inf);

void				print_help(t_inf *inf);
void				print_iterations(t_inf *inf);
void				print_usage(void);

#endif
