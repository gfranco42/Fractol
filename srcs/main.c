/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 19:12:43 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fail(int i)
{
	if (i == 1)
	{
		write(1, "FAIL TO CREATE THREAD\n", 22);
		exit(0);
	}
	else if (i == 2)
	{
		write(1, "FAIL TO JOIN THREAD\n", 20);
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_all			all;
	t_pos			p;
	t_pos			d;
	int				plan;

	all.mlx.ptr = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	all.mlx.img = mlx_new_image(all.mlx.ptr, WIDTH, HEIGHT);
	all.mlx.str = mlx_get_data_addr(all.mlx.img, &(all.mlx.bpp), &(all.mlx.s_l), &(all.mlx.endian));

	all.point.x = 0;
	all.point.y = 0;
	all.tmp.x = 0;
	all.tmp.y = 0;
	all.p = &p;
	all.d = &d;
	all.plan = &plan;
	all.zoom = 1;


	all.c.x = 0.3;
	all.c.y = 0.3;
	if (ac != 2)
	{
		write(1, "usage:\n./fractol  Mandelbrot\n\t   Julia\n\t   Galaxy\n",
		 50);
		exit(0);
	}
	parsing(av[1], all);
	mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, key, &all);
	mlx_hook(all.mlx.win, 6, 0, mouse_julia, &all);
	mlx_mouse_hook(all.mlx.win, mouse, &all);
	mlx_put_image_to_window(all.mlx.ptr, all.mlx.win, all.mlx.img, 0, 0);
	mlx_loop(all.mlx.ptr);
	return (0);
}
