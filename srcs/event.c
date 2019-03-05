/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:58:07 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/05 16:58:53 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;

	if (key == 38) // J
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->point.x = 0;
		all->point.y = 0;
		all->tmp.x = 0;
		all->tmp.y = 0;
		all->zoom = 1;
		julia(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (key == 46)// M
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->point.x = 0;
		all->point.y = 0;
		all->tmp.x = 0;
		all->tmp.y = 0;
		all->zoom = 1;
		mandelbrot(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (key == 5)// G
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->point.x = 0;
		all->point.y = 0;
		all->tmp.x = 0;
		all->tmp.y = 0;
		all->zoom = 1;
		galaxy(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	return (0);
}

int		mouse_julia(int x, int y, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (all->k == 2 && *all->plan == 2)
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->c.x = (all->p->x2 - all->p->x1) * x / WIDTH + all->p->x1;
		all->c.y = (all->p->y2 - all->p->y1) * (HEIGHT - y) / HEIGHT + all->p->y1;
		julia(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	//else
	//	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		//mlx_string_put(all->mlx.ptr, all->mlx.win, 20, 20, 0x9999FF, "MOVING: DESACTIVATED");
	return (0);
}

int		mouse(int key, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	/*if (*all->plan == 1)
		zoom_mandelbrot(all, key, x, y);
	else if (*all->plan == 2)
		zoom_julia(all, key, x, y);*/
	if (key == 4)
	{
		if (all->k == 1)
			all->zoom = 1.0101010101;
		all->k = 2;
		all->zoom *= 0.99;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		zoom_on_mouse(x, y, all);
		if (*all->plan == 1)
			mandelbrot(*all);
		else if (*all->plan == 2)
			julia(*all);
		else if (*all->plan == 3)
			galaxy(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (key == 5)
	{
		if (all->k == 2)
			all->zoom = 0.99;
		all->k = 1;
		all->zoom /= 0.99;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		zoom_on_mouse(x, y, all);
		if (*all->plan == 1)
			mandelbrot(*all);
		else if (*all->plan == 2)
			julia(*all);
		else if (*all->plan == 3)
			galaxy(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (key == 1)
		all->k = 2;
	else if (key == 2)
		all->k = 1;
	return (0);
}

int		key(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == 53)
		exit(0);
	else if (key == 38 || key == 46 || key == 5)
		zoom(key, param);
	ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

