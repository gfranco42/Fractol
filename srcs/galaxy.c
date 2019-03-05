/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   galaxy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:40:30 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/05 15:46:44 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*galaxy_th(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	return NULL;
}

void		galaxy(t_all all)
{
	int		n;

	n = 1;
	if (*all.plan != 3)
		set_plan(all.p, 3);
	*all.plan = 3;
	all.c.x = 0.5898;
	all.c.y = 1.1957;
	while (all.point.y < HEIGHT)
	{
		while (all.point.x < WIDTH)
		{
			all.z.x = all.p->x1 + all.point.x * (all.p->x2 - all.p->x1) / WIDTH;
			all.z.y = all.p->y1 + all.point.y * (all.p->y2 - all.p->y1) / HEIGHT;
			all.z.y = all.p->y2 - all.z.y + all.p->y1;
			n = 1;
			while (all.z.x * all.z.x + all.z.y * all.z.y < 4 && n < MAX_ITER)
			{
				all.z = calcul_z_galaxy(all.z, all.c, all.tmp);
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
