/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/07 17:51:09 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		mandelbrot(t_all all)
{
	int		degrade;
	int		n;

	degrade = 0;
	n = 0;
	while (all.point.y < HEIGHT)
	{
		while (all.point.x < WIDTH)
		{
			all.c = calcul_c(all.c, all.point, all.p, *all.event_z);
			all.z.x = 0;
			all.z.y = 0;
			n = 0;
			while (calcul_module_z(all.z) < 4 && n < MAX_ITER)
			{
				all.z = calcul_z(all.z, all.c, all.tmp);
				n++;
			}
			if (n == MAX_ITER)
				put_color_inside(all.point, n, all.mlx.str, degrade);
			else
				put_color_outside(all.point, n, all.mlx.str, degrade);
			degrade += 10;
			all.point.x++;
		}
		all.point.x = 0;
		all.point.y++;
	}
}
