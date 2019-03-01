/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/01 17:01:41 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fail(int i)
{
	if (i == 1)
	{
		write(1, "FAIL TO CREATE FIRST THREAD\n", 28);
		exit(0);
	}
	else if (i == 2)
	{
		write(1, "FAIL TO JOIN FIRST THREAD\n", 26);
		exit(0);
	}
}

int		main(void)
{
	t_all		all;
	t_pos		p;
	t_pos		d;
	t_pos		new;
	pthread_t	th;

/*	t_all		all2;
	t_pos		p2;
	t_pos		d2;
	t_pos		new2;
	pthread_t	th2;*/


	//		MULTI_THREADING

/*	t_all		all3;
	t_pos		p3;
	t_pos		d3;
	t_pos		new3;
	pthread_t	th3;


	t_all		all4;
	t_pos		p4;
	t_pos		d4;
	t_pos		new4;
	pthread_t	th4;*/

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
	all.new = &new;
	all.p->x1 = -2;
	all.p->x2 = 1;
	all.p->y1 = -1;
	all.p->y2 = 1;
	all.new->x1 = -2;
	all.new->y1 = -1;
	all.new->x2 = -2;
	all.new->y2 = 1;
	all.zoom = 1;

	/*all2.point.x = 0;
	all2.point.y = 0;
	all2.tmp.x = 0;
	all2.tmp.y = 0;
	all2.p = &p2;
	all2.d = &d2;
	all2.new = &new2;
	all2.p->x1 = -2;
	all2.p->x2 = 1;
	all2.p->y1 = -1;
	all2.p->y2 = 1;
	all2.new->x1 = -2;
	all2.new->y1 = -1;
	all2.new->x2 = -2;
	all2.new->y2 = 1;
	all2.zoom = 1;*/


	//		MULTI_THREADING

	/*all3.point.x = 0;
	all3.point.y = 0;
	all3.tmp.x = 0;
	all3.tmp.y = 0;
	all3.p = &p3;
	all3.d = &d3;
	all3.new = &new3;
	all3.p->x1 = -2;
	all3.p->x2 = 1;
	all3.p->y1 = -1;
	all3.p->y2 = 1;
	all3.new->x1 = -2;
	all3.new->y1 = -1;
	all3.new->x2 = -2;
	all3.new->y2 = 1;
	all3.zoom = 1;


	all4.point.x = 0;
	all4.point.y = 0;
	all4.tmp.x = 0;
	all4.tmp.y = 0;
	all4.p = &p4;
	all4.d = &d4;
	all4.new = &new4;
	all4.p->x1 = -2;
	all4.p->x2 = 1;
	all4.p->y1 = -1;
	all4.p->y2 = 1;
	all4.new->x1 = -2;
	all4.new->y1 = -1;
	all4.new->x2 = -2;
	all4.new->y2 = 1;
	all4.zoom = 1;*/

	if ((pthread_create(&th, NULL, julia, &all) != 0))
		fail(1);
	if ((pthread_join(th, NULL) != 0))
		fail(2);
	/*if ((pthread_create(&th2, NULL, mandelbrot2, &all) != 0))
		fail(1);


			MULTI_THREADING

	if ((pthread_create(&th3, NULL, mandelbrot3, &all)) != 0)
		fail(1);
	if ((pthread_create(&th4, NULL, mandelbrot4, &all) != 0))
		fail(1);
	if ((pthread_join(th2, NULL) != 0))
		fail(2);
	if ((pthread_join(th3, NULL) != 0))
		fail(2);
	if ((pthread_join(th4, NULL) != 0))
		fail(2);*/
//	mandelbrot(all);
	mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, key, &all);
	mlx_mouse_hook(all.mlx.win, mouse, &all);
	mlx_put_image_to_window(all.mlx.ptr, all.mlx.win, all.mlx.img, 0, 0);
	mlx_loop(all.mlx.ptr);
	return (0);
}
