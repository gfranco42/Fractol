/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/08 15:23:35 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(void)
{
	t_all	all;
	t_pos	p;
	t_cplx	event_z;

	all.mlx.ptr = mlx_init();
	all.mlx.win = mlx_new_window(all.mlx.ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	all.mlx.img = mlx_new_image(all.mlx.ptr, WIDTH, HEIGHT);
	all.mlx.str = mlx_get_data_addr(all.mlx.img, &(all.mlx.bpp), &(all.mlx.s_l), &(all.mlx.endian));

	all.point.x = 0;
	all.point.y = 0;
	all.tmp.x = 0;
	all.tmp.y = 0;
	all.p = &p;
	all.event_z = &event_z;
	all.p->x1 = -2;
	all.p->y1 = -1;
	all.p->x2 = 1;
	all.p->y2 = 1;
	all.event_z->x = 0;
	all.event_z->y = 0;

	mandelbrot(all);
	printf("a\n");
	mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, key, &all);
	mlx_put_image_to_window(all.mlx.ptr, all.mlx.win, all.mlx.img, 0, 0);
	mlx_loop(all.mlx.ptr);
	return (0);
}
