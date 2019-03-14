/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:55:16 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/14 16:18:21 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		reset(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	if (key == 38)
	{
		set_plan(all->p, 2);
		all->fr = 2;
		julia(*all);
	}
	else if (key == 46)
	{
		set_plan(all->p, 1);
		all->fr = 1;
		mandelbrot(*all);
	}
	else if (key == 11)
	{
		set_plan(all->p, 3);
		all->fr = 3;
		brain(*all);
	}
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	return (0);
}

int		color1(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	if (key == 12)
	{
		all->color = PINK;
		which_fractal(all, all->fr);
	}
	else if (key == 13)
	{
		all->color = DARKGREEN;
		which_fractal(all, all->fr);
	}
	else if (key == 14)
	{
		all->color = WHITE;
		which_fractal(all, all->fr);
	}
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	return (0);
}

int		color2(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	if (key == 15)
	{
		all->color = BLUE;
		which_fractal(all, all->fr);
	}
	else if (key == 16)
	{
		all->color = HIBISCUS;
		which_fractal(all, all->fr);
	}
	else if (key == 17)
	{
		all->color = RED;
		which_fractal(all, all->fr);
	}
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	return (0);
}

int		color3(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	if (key == 31)
	{
		all->color = GREEN;
		which_fractal(all, all->fr);
	}
	else if (key == 32)
	{
		all->color = LIGHTBLUE;
		which_fractal(all, all->fr);
	}
	else if (key == 34)
	{
		all->color = YELLOW;
		which_fractal(all, all->fr);
	}
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	return (0);
}

int		key(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == 53)
		exit(0);
	else if (key == 38 || key == 46 || key == 11)
	{
		all->zoom = 1;
		reset(key, param);
	}
	else if (key == 12 || key == 13 || key == 14)
		color1(key, param);
	else if (key == 15 || key == 16 || key == 17)
		color2(key, param);
	else if (key == 31 || key == 32 || key == 34)
		color3(key, param);
	else if (key == 35)
	{
		all->color = rand();
		which_fractal(all, all->fr);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	return (0);
}
