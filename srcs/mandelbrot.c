/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/05 15:45:29 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*mandel_th(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	return NULL;
}

void		mandelbrot(t_all all)
{
	int		n;

	n = 1;
	if (*all.plan != 1)
		set_plan(all.p, 1);
	*all.plan = 1;
	all.point.y = 0;
	all.point.x = 0;
	while (all.point.y < HEIGHT)
	{
		while (all.point.x < WIDTH)
		{
			all.c = calcul_c(all.c, all.point, *all.p);
			all.z.x = 0;
			all.z.y = 0;
			n = 0;
			while (all.z.x * all.z.x + all.z.y * all.z.y < 4 && n < MAX_ITER)
			{
				all.z = calcul_z(all.z, all.c, all.tmp);
				n++;
			}
			if (n == MAX_ITER)
				put_color_inside(all.point, n, (unsigned int*)all.mlx.str);
			else
				put_color_outside(all.point, n, (unsigned int*)all.mlx.str);
			all.point.x++;
		}
		all.point.x = 0;
		all.point.y++;
	}
}
