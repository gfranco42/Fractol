/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:59:42 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/07 17:54:26 by gfranco          ###   ########.fr       */
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

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITER 255

/*typedef struct	s_z
{
	double x;
	double y;
}				t_z;

typedef struct	s_c
{
	double x;
	double y;
}				t_c;

typedef struct	s_tmp
{
	double x;
	double y;
}				t_tmp;

typedef struct s_event_move
{
	double	x;
	double	y;
}				t_event_move;*/

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
	t_cplx		z;
	t_cplx		c;
	t_cplx		tmp;
	t_cplx		*event_z;
	t_point		point;
	t_pos		p;
	t_mlx		mlx;
}				t_all;

t_cplx			calcul_z(t_cplx z, t_cplx c, t_cplx tmp); /* Z + C /!\ pas au carré ! ! */
t_cplx			calcul_c(t_cplx c, t_point point, t_pos p, t_cplx event_m); /* x * width / 2 - 1 && y * height / 2 - 1; */
double			calcul_module_z(t_cplx z); /*		 x^2 + y^2 */
int				key(int key, void *param);
void			mandelbrot(t_all all);
void			put_color_inside(t_point point, int n, char	*str, int degrade);
void			put_color_outside(t_point point, int n, char *str, int degrade);

#endif
