/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:58:07 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/07 17:55:05 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;

	if (key == 69) // +
	{
		all->event_z->x += 0.1;
		all->event_z->y += 0.1;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		mandelbrot(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}

	else if (key == 78)// -
	{
		all->event_z->x -= 0.1;
		all->event_z->y -= 0.1;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		mandelbrot(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}

	return (0);
}

int		key(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == 53)
		exit(0);
	else if (key == 69 || key == 78)
		zoom(key, param);
	ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

