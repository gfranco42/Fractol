/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:49:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/06 13:52:55 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		set_plan(t_pos *pos, int plan)
{
	if (plan == 1)
	{
		pos->x1 = -2.1;
		pos->x2 = 0.6;
		pos->y1 = -1.2;
		pos->y2 = 1.2;
	}
	else if (plan == 2)
	{
		pos->x1 = -1.1;
		pos->x2 = 1;
		pos->y1 = -1.2;
		pos->y2 = 1.2;

	}
	else if (plan == 3)
	{
		pos->x1 = -1;
		pos->x2 = 1;
		pos->y1 = -1.5;
		pos->y2 = 1.5;
	}
}

void		julia(t_all all)
{
	int		n;

	n = 1;
	if (*all.plan != 2)
		set_plan(all.p, 2);
	*all.plan = 2;
	while (all.point.y < HEIGHT)
	{
		while (all.point.x < WIDTH)
		{
			all.z.x = all.p->x1 + all.point.x * (all.p->x2 - all.p->x1) / WIDTH;
			all.z.y = all.p->y1 + all.point.y * (all.p->y2 - all.p->y1) / HEIGHT;
			all.z.y = all.p->y2 - all.z.y + all.p->y1;
			n = 1;
			while (all.z.x * all.z.x + all.z.y * all.z.y < 4 && n++ < MAX_ITER)
				all.z = calcul_z(all.z, all.c, all.tmp);
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
