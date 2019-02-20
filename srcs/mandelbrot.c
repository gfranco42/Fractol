/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/20 11:55:53 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		mandelbrot(t_all all)
{
	int		n;

	n = 0;
	while (all.point.y < HEIGHT)
	{
		while (all.point.x < WIDTH)
		{
			all.c = calcul_c(all.c, all.point, *all.p);
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
}
