/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:38:06 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 18:48:26 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	win_create(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->str = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->s_l), &(mlx->endian));
}

void	parsing(char *str, t_all *all)
{
	if ((ft_strcmp("Julia", str) == 0) || (ft_strcmp("julia", str) == 0))
	{
		win_create(&all->mlx);
		julia(*all);
	}
	else if ((ft_strcmp("Mandelbrot", str) == 0) || (ft_strcmp("mandelbrot",
	 str) == 0))
	{
		win_create(&all->mlx);
		mandelbrot(*all);
	}
	else if ((ft_strcmp("Brain", str) == 0) || (ft_strcmp("brain", str) == 0))
	{
		win_create(&all->mlx);
		brain(*all);
	}
	else
	{
		write(1, "usage:\n./fractol  Mandelbrot\n\t   Julia\n\t   \n",
		 50);
		exit(0);
	}
}
