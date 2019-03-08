/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:59:42 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 18:48:51 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "macros.h"
# include <math.h>
# include <pthread.h>

# define WIDTH 640
# define HEIGHT 569
# define MAX_ITER 500

# define PINK 0xFF0099
# define YELLOW 0xFFF44D
# define LIGHTBLUE 0x4FD2FF
# define BLUE 0x010203
# define RED 0x020301
# define HIBISCUS 0xFA005B
# define GREEN 0x030201
# define WHITE 0x010101
# define DARKGREEN 0x0B8F00


typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_cplx
{
	double	x;
	double	y;
}				t_cplx;

typedef struct	s_pos
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}				t_pos;

typedef struct	s_mlx
{
	void	*ptr;
	void	*img;
	int		*win;
	char	*str;
	int		bpp;
	int		s_l;
	int		endian;
}				t_mlx;

typedef struct	s_all
{
	double		zoom;
	int			*plan;
	char		clic;
	char		check_zoom;
	int			color;
	char		k;
	t_cplx		z;
	t_cplx		c;
	t_cplx		mouse;
	t_cplx		*event_z;
	t_point		point;
	t_pos		*p;
	t_pos		*d;
	t_mlx		mlx;
}				t_all;

void			calcul_c(t_cplx *c, t_point *point, t_pos *p);
void			calcul_first_z_brain(t_point *point, t_cplx *z, t_pos *p);
void			calcul_z(t_cplx *z, t_cplx *c, t_cplx *tmp);
t_cplx			calcul_z_brain(t_cplx z, t_cplx c, t_cplx tmp);
void			calcul_brain(t_all all, unsigned int *str);
void			calcul_julia(t_all all, unsigned int *str);
void			calcul_mandelbrot(t_all all, unsigned int *str);
double			calcul_module_z(t_cplx z);
void			fail(int i);
void			brain(t_all all);
void			julia(t_all all);
int				key(int key, void *param);
void			mandelbrot(t_all all);
int				mouse(int key, int x, int y, void *param);
int				mouse_julia(int x, int y, void *param);
void			parsing(char *str, t_all *all);
void			put_color_inside(t_point point, int n, char *str);
void			put_color_outside(t_point point, int n, unsigned int *str);
void			set_plan(t_pos *pos, int i);
void			sound_tool(int key, char *k);
void			which_fractal(t_all all, int plan);
void			zoom_on_mouse(int x, int y, t_all *all);
#endif
