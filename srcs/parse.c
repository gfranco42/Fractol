/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/14 16:10:49 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	win_create(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->str = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->s_l),
	&(mlx->endian));
}

int		parsing(char *str, t_all *all, t_mlx *mlx, int fr)
{
	if ((ft_strcmp("julia", str) == 0))
	{
		win_create(mlx);
		julia(*all);
		fr = 2;
	}
	else if ((ft_strcmp("mandelbrot", str) == 0))
	{
		win_create(mlx);
		mandelbrot(*all);
		fr = 1;
	}
	else if ((ft_strcmp("brain", str) == 0))
	{
		win_create(mlx);
		brain(*all);
		fr = 3;
	}
	else
	{
		write(1, "usage:\n./fractol  mandelbrot\n\t   julia\n\t   brain\n",
		50);
		exit(0);
	}
	return (fr);
}
