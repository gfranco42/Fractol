/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:54:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/08 14:56:50 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_julia(int x, int y, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (all->clic == 'y' && *all->plan == 2)// si on est dans le plan de julia et qu'on a cliqué
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->mouse.x = (all->p->x2 - all->p->x1) * x / WIDTH + all->p->x1;
		all->mouse.y = (all->p->y2 - all->p->y1) * (HEIGHT - y) / HEIGHT + all->p->y1;
		julia(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	return (0);
}

int		mouse(int key, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == 4)
	{
	//	zoom_in(all);
		if (all->check_zoom == '-')
			all->zoom = 1;
		all->check_zoom = '+';
		all->zoom /= 1.01;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		zoom_on_mouse(x, y, all);
		if (*all->plan == 1)
			mandelbrot(*all);
		else if (*all->plan == 2)
			julia(*all);
		else if (*all->plan == 3)
			brain(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (key == 5)
	{
	//	zoom_out(all);
		if (all->check_zoom == '+')
			all->zoom = 1;
		all->check_zoom = '-';
		all->zoom *= 1.01;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		zoom_on_mouse(x, y, all);
		if (*all->plan == 1)
			mandelbrot(*all);
		else if (*all->plan == 2)
			julia(*all);
		else if (*all->plan == 3)
			brain(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (*all->plan == 2 && key == 1)// clic gauche
		all->clic = 'y';
	else if (*all->plan == 2 && key == 2)// clic droit
		all->clic = 'n';
	return (0);
}
