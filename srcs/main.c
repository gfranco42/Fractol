/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:51 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/06 13:51:03 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(void)
{
	t_c		c;
	t_z		z;
	t_point	point;
	t_mlx	mlx;
	t_tmp	tmp;
	int		n;
	double	module_z;
	double		x1;
	double		y1;
	double		x2;
	double		y2;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "FRACTOL GFRANCO");
	mlx.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.str = mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.s_l), &(mlx.endian));
	/*(x1 * x2 - y1 * y2, x1 * x2 + x2 * y1);

	while ((x`2 + y`2) < 4)



	algo:

	definition: (i*i) = -1;

	iter_max = 50;
	foreach:
	z = x + yi; z= structure contenant double x et double y;

	distance module_z (module de z) = racine(x2 + y2)
	if ( i == iter_max)
		allumer_pixel(x, y);
	i2 = -1; ???

	exemple: 2 + 4i;

	z = 2 + 4i;

	distance module_z = module de z;
	module de z = sqrt(x2 + y2);              */
	x1 = -2.1;
	y1 = 0.6;
	x2 = -1.2;
	y2 = 1.2;
	point.x = 0;
	point.y = 0;
	n = 0;
	z.x = 0.5;
	z.y = 0.5;
	c.x = -1;
	c.y = 1;
	tmp.x = 0;
	tmp.y = 0;
	module_z = calcul_module_z(z);
	while (point.y < HEIGHT)
	{
		while (point.x < WIDTH)
		{
			c = calcul_c(c, point.x, point.y);
			//c.x = x1 + ((point.x + 0.0) * (x2 - x1)) / (WIDTH - 1.0);
		//	c.y = y1 + ((point.y + 0.0) * (y2 - y1)) / (HEIGHT - 1.0);
		//	c.y = y2 -c.y + y1;
			while (module_z < 4 && n < MAX_ITER)
			{
				z = calcul_z(z, c);
				tmp.x = z.x;
				tmp.y = z.y;
				n++;
				module_z = calcul_module_z(z);
			}
			if (n >= MAX_ITER)
				put_color_black(point, n, mlx.str);
			else
				put_color_white(point, n, mlx.str);
			point.x++;
		}
	point.x = 0;
	point.y++;
	}
	mlx_hook(mlx.win, KEYPRESS, KEYPRESSMASK, key, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.ptr);
}
