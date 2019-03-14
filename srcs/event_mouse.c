/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:54:47 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/14 15:59:46 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			mouse_julia(int x, int y, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (all->clic == 'y' && all->fr == 2)
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->mouse.x = (all->p->x2 - all->p->x1) * x / WIDTH + all->p->x1;
		all->mouse.y = (all->p->y2 - all->p->y1) * (HEIGHT - y) / HEIGHT
		+ all->p->y1;
		all->fr = 2;
		julia(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	return (0);
}

void		zoom_in(t_all *all, int x, int y)
{
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	if (all->check_zoom == '-')
		all->zoom = 1;
	all->check_zoom = '+';
	all->zoom /= 1.01;
	if (all->first != all->fr)
		set_plan(all->p, all->fr);
	all->first = all->fr;
	zoom_on_mouse(x, y, all);
	which_fractal(all, all->fr);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
}

void		zoom_out(t_all *all, int x, int y)
{
	ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	if (all->check_zoom == '+')
		all->zoom = 1;
	all->check_zoom = '-';
	all->zoom *= 1.01;
	if (all->first != all->fr)
		set_plan(all->p, all->fr);
	all->first = all->fr;
	zoom_on_mouse(x, y, all);
	which_fractal(all, all->fr);
	mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
}

int			mouse(int key, int x, int y, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == 4)
		zoom_in(all, x, y);
	else if (key == 5)
		zoom_out(all, x, y);
	else if (all->fr == 2 && key == 2)
		all->clic = 'y';
	else if (all->fr == 2 && key == 1)
		all->clic = 'n';
	return (0);
}
