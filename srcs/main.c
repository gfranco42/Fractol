/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/07 17:50:26 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(void)
{
	t_all	all;

	all.mlx.ptr = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	all.mlx.img = mlx_new_image(all.mlx.ptr, WIDTH, HEIGHT);
	all.mlx.str = mlx_get_data_addr(all.mlx.img, &(all.mlx.bpp), &(all.mlx.s_l), &(all.mlx.endian));

	all.point.x = 0;
	all.point.y = 0;
	all.tmp.x = 0;
	all.tmp.y = 0;
	all.p.x1 = -2.1;
	all.p.y1 = -1.2;
	all.p.x2 = 0.6;
	all.p.y2 = 1.2;
	all.event_z->x = 0;
	all.event_z->y = 0;

	mandelbrot(all);
/*	while (point.y < HEIGHT)
	{
		while (point.x < WIDTH)
		{
			c = calcul_c(c, point, p, event_m);
			z.x = 0;
			z.y = 0;
			n = 0;
			while (calcul_module_z(z) < 4 && n < MAX_ITER)
			{
				z = calcul_z(z, c, tmp);
				n++;
			}
			if (n == MAX_ITER)
				put_color_inside(point, n, all.mlx.str, degrade);
			else
				put_color_outside(point, n, all.mlx.str, degrade);
			degrade += 10;
			point.x++;
		}
		point.x = 0;
		point.y++;
	}*/
	mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, key, &all);
	mlx_put_image_to_window(all.mlx.ptr, all.mlx.win, all.mlx.img, 0, 0);
	mlx_loop(all.mlx.ptr);
	return (0);
}
