/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:58:07 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/08 16:00:49 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;

	if (key == 69) // +
	{
		all->p->x1 *= 0.9;
		all->p->x2 *= 0.9;
		all->p->y1 *= 0.9;
		all->p->y2 *= 0.9;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		mandelbrot(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}

	else if (key == 78)// -
	{
		all->p->x1 *= 1.1;
		all->p->x2 *= 1.1;
		all->p->y1 *= 1.1;
		all->p->y2 *= 1.1;
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
	/*ft_putnbr(key);
	ft_putchar('|');*/
	return (0);
}

