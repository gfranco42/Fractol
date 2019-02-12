/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/12 17:34:44 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		mandelbrot(t_all all)
{
	int		n;
	float	zoom_x;
	float	zoom_y;


	zoom_x = all.img_x / (all.p->x2 - all.p->x1);
	zoom_y = all.img_y / (all.p->y2 - all.p->y1);
	n = 0;
	while (all.point.y < all.img_y/*HEIGHT*/)
	{
		while (all.point.x < all.img_x/*WIDTH*/)
		{
			//all.c = calcul_c(all.c, all.point, *all.p, *all.event_z);
			all.c.x = all.point.x / zoom_x + all.p->x1;
			all.c.y = all.point.y / zoom_y + all.p->y1;
			all.z.x = 0;
			all.z.y = 0;
			n = 0;
			while (calcul_module_z(all.z) < 4 && n < MAX_ITER)
			{
				all.z = calcul_z(all.z, all.c, all.tmp);
				n++;
			}
			if (n == MAX_ITER)
				put_color_inside(all.point, n, (unsigned int*)all.mlx.str, all.mlx);
			all.point.x++;
		}
		all.point.x = 0;
		all.point.y++;
	}
	printf("x: %f, y: %f\n", all.img_x, all.img_y);
}
