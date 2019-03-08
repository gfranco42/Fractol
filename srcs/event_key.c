/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:55:16 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 18:32:22 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		reset(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	all->zoom = 1;
	if (key == 38) // J
	{
		set_plan(all->p, 2);
		julia(*all);
	}
	else if (key == 46)// M
	{
		set_plan(all->p, 1);
		mandelbrot(*all);
	}
	else if (key == 11)// B
	{
		set_plan(all->p, 3);
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
		all->color = PINK; // chewinggum
		which_fractal(*all, *all->plan);
	}
	else if (key == 13)
	{
		all->color = DARKGREEN; // darkgreen
		which_fractal(*all, *all->plan);
	}
	else if (key == 14)
	{
		all->color = WHITE; // green
		which_fractal(*all, *all->plan);
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
		all->color = BLUE; // chewinggum
		which_fractal(*all, *all->plan);
	}
	else if (key == 16)
	{
		all->color = HIBISCUS; // darkgreen
		which_fractal(*all, *all->plan);
	}
	else if (key == 17)
	{
		all->color = RED; // green
		which_fractal(*all, *all->plan);
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
		all->color = GREEN; // chewinggum
		which_fractal(*all, *all->plan);
	}
	else if (key == 32)
	{
		all->color = LIGHTBLUE; // darkgreen
		which_fractal(*all, *all->plan);
	}
	else if (key == 34)
	{
		all->color = YELLOW; // green
		which_fractal(*all, *all->plan);
	}
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	return (0);
}

int		key(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == 53)
	{
		system("killall afplay");
		exit(0);
	}
	else if (key == 38 || key == 46 || key == 11)
		reset(key, param);
	else if (key == 12 || key == 13 || key == 14)
		color1(key, param);
	else if (key == 15 || key == 16 || key == 17)
		color2(key, param);
	else if (key == 31 || key == 32 || key == 34)
		color3(key, param);
	else if (key == 35)
	{
		all->color = rand();
		which_fractal(*all, *all->plan);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	sound_tool(key, &all->k);
	return (0);
}

