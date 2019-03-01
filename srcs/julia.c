/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:49:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/01 17:55:58 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		*julia(void *param)
{
	int		n;
	t_all	*all;

	all = (t_all*)param;
	n = 0;
	all->point.y = 0;
	all->point.x = 0;
	while (all->point.y < HEIGHT)
	{
		while (all->point.x < WIDTH)
		{
			//all->c = calcul_c(all->c, all->point, *all->p);
			all->c.x = 0.3;
			all->c.y = 0.3;
			all->z.x = all->c.x;
			all->z.y = all->c.y;
			n = 0;
			while (calcul_module_z(all->z) < 4 && n < MAX_ITER)
			{
				all->z = calcul_z(all->z, all->c, all->tmp);
				n++;
			}
			if (n == MAX_ITER)
			{
				put_color_outside(all->point, n, all->mlx.str, all->mlx);
			}
			all->point.x += 1;
		}
		all->point.x = 0;
		all->point.y++;
	}
	pthread_exit(NULL);
}
