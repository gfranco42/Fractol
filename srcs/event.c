/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:58:07 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/01 17:03:13 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int key, void *param)
{
	t_all	*all;
	pthread_t	th;

	all = (t_all*)param;

	if (key == 38) // J
	{
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		all->point.x = 0;
		all->point.y = 0;
		all->tmp.x = 0;
		all->tmp.y = 0;
		all->p->x1 = -2;
		all->p->x2 = 1;
		all->p->y1 = -1;
		all->p->y2 = 1;
		all->new->x1 = -2;
		all->new->y1 = -1;
		all->new->x2 = -2;
		all->new->y2 = 1;
		all->zoom = 1;
		if ((pthread_create(&th, NULL, julia, &all)) != 0)
			fail(1);
		if ((pthread_join(th, NULL) != 0))
			fail(2);
	//	mandelbrot(*all);
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
		all->p->x1 = -2;
		all->p->x2 = 1;
		all->p->y1 = -1;
		all->p->y2 = 1;
		all->new->x1 = -2;
		all->new->y1 = -1;
		all->new->x2 = -2;
		all->new->y2 = 1;
		all->zoom = 1;
		if ((pthread_create(&th, NULL, mandelbrot, &all)) != 0)
			fail(1);
		if ((pthread_join(th, NULL) != 0))
			fail(2);
	//	mandelbrot(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	return (0);
}

int		mouse(int key, int x, int y, void *param)
{
	t_all	*all;
	pthread_t	th;
/*	t_all	*all2;
	t_all	*all3;
	t_all	*all4;
	pthread_t	th2;
	pthread_t	th3;
	pthread_t	th4;*/

	all = (t_all*)param;
/*	all2 = all;
	all3 = all;
	all4 = all;*/
	if (key == 4)
	{
		all->zoom *= 0.95;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	/*	mlx_destroy_image(all->mlx.ptr, all->mlx.img);
		all->mlx.img = mlx_new_image(all->mlx.ptr, WIDTH, HEIGHT);
		all->mlx.str = mlx_get_data_addr(all->mlx.img, &(all->mlx.bpp), &(all->mlx.s_l), &(all->mlx.endian));*/
		zoom_on_mouse(x, y, all);
		if ((pthread_create(&th, NULL, mandelbrot, all)) != 0)
			fail(1);
		if ((pthread_join(th, NULL) != 0))
			fail(2);
	/*	if ((pthread_create(&th2, NULL, mandelbrot2, all2) != 0))
			fail(1);
		if ((pthread_create(&th3, NULL, mandelbrot3, all3)) != 0)
			fail(1);
		if ((pthread_create(&th4, NULL, mandelbrot4, all4) != 0))
			fail(1);
		if ((pthread_join(th2, NULL) != 0))
			fail(2);
		if ((pthread_join(th3, NULL) != 0))
			fail(2);
		if ((pthread_join(th4, NULL) != 0))
			fail(2);*/
	//	mandelbrot(*all);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
	}
	else if (key == 5)
	{
		all->zoom /= 0.95;
		ft_memset(all->mlx.str, 0, HEIGHT * WIDTH * 4);
		mlx_put_image_to_window(all->mlx.ptr, all->mlx.win, all->mlx.img, 0, 0);
		zoom_on_mouse(x, y, all);
		if ((pthread_create(&th, NULL, mandelbrot, all)) != 0)
			fail(1);
		if ((pthread_join(th, NULL) != 0))
			fail(2);
	/*	if ((pthread_create(&th2, NULL, mandelbrot2, all) != 0))
			fail(1);
		if ((pthread_create(&th3, NULL, mandelbrot3, all3)) != 0)
			fail(1);
		if ((pthread_create(&th4, NULL, mandelbrot4, all4) != 0))
			fail(1);
		if ((pthread_join(th2, NULL) != 0))
			fail(2);
		if ((pthread_join(th3, NULL) != 0))
			fail(2);
		if ((pthread_join(th4, NULL) != 0))
			fail(2);*/
	//	mandelbrot(*all);
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
	else if (key == 38 || key == 46)
		zoom(key, param);
	/*ft_putnbr(key);
	ft_putchar('|');*/
	return (0);
}

