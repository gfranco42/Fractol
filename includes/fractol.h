/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:59:42 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/05 17:51:21 by gfranco          ###   ########.fr       */
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

# define WIDTH 2560
# define HEIGHT 1400
# define MAX_ITER 200

typedef struct	s_z
{
	double x;
	double y;
}				t_z;

typedef struct	s_c
{
	double x;
	double y;
}				t_c;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

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


t_z			calcul_z(t_z z, t_c c); /*		 Z + C /!\ pas au carré ! ! */
t_c			calcul_c(t_c c, int x, int y); /*				 x * width / 2 - 1 && y * height / 2 - 1; */
double		calcul_module_z(t_z z); /*		 x^2 + y^2 */
void		put_color_black(t_point point, int n, char	*str);
void		put_color_white(t_point point, int n, char	*str);

#endif
